#include "../components.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @file astra.c
 * @brief AstraBot implementation
 *
 * Initializes robot modules, buttons, and brain loop.
 * Desktop version simulates buttons (no ESP32 GPIO).
 */

// -------------------
// Drive forward
// -------------------
void astra_bot_drive_forward(astra_bot_t* self, int speed) {
    if (!self) return;
    printf("[AstraBot] Driving forward at speed %d\n", speed);
}

// -------------------
// Stop robot
// -------------------
void astra_bot_stop(astra_bot_t* self) {
    if (!self) return;
    printf("[AstraBot] Stopped\n");
}

// -------------------
// Brain: read sensors and decide movement
// -------------------
void astra_bot_brain(astra_bot_t* self) {
    if (!self) return;

    printf("[Brain] Running brain logic...\n");

    // -------------------
    // Update buttons (simulate press)
    // -------------------
    if (self->start_button) button_module_update(self->start_button);
    if (self->stop_button)  button_module_update(self->stop_button);
    if (self->reset_button) button_module_update(self->reset_button);

    // -------------------
    // Read sensors (simulation)
    // -------------------
    if (self->ultrasonic) {
        self->ultrasonic->read_distance(self->ultrasonic);
        printf("[Brain] Distance: %d cm\n", self->ultrasonic->distance);
    }

    if (self->line_tracker) self->line_tracker->read_line(self->line_tracker);
    if (self->edge_detector) self->edge_detector->read_edge(self->edge_detector);
    if (self->nfc_reader) self->nfc_reader->read_tag(self->nfc_reader);

    // -------------------
    // Example decision (based on simulated NFC)
    // -------------------
    int red = self->nfc_reader ? self->nfc_reader->tag_count_red : 0;
    int green = self->nfc_reader ? self->nfc_reader->tag_count_green : 0;
    int blue = self->nfc_reader ? self->nfc_reader->tag_count_blue : 0;

    if (red > green && red > blue) {
        self->display->show_text(self->display, "Turning LEFT (Red tag)");
        printf("[Brain] Decision: Turn LEFT\n");
    } else if (green > red && green > blue) {
        self->display->show_text(self->display, "Turning RIGHT (Green tag)");
        printf("[Brain] Decision: Turn RIGHT\n");
    } else if (blue > red && blue > green) {
        self->display->show_text(self->display, "STOP (Blue tag)");
        self->stop(self);
    } else {
        self->display->show_text(self->display, "Going straight (No dominant tag)");
        self->drive_forward(self, 40);
    }
}

// -------------------
// Create AstraBot
// -------------------
astra_bot_t* astra_bot_new(void) {
    astra_bot_t* bot = (astra_bot_t*)malloc(sizeof(astra_bot_t));
    if (!bot) return NULL;

    // -------------------
    // Initialize sensors (simulation)
    // -------------------
    bot->ultrasonic    = ultrasonic_new();
    bot->line_tracker  = line_tracker_new();
    bot->edge_detector = edge_detector_new();
    bot->nfc_reader    = nfc_reader_new();
    bot->display       = display_module_new();

    // -------------------
    // Initialize buttons (desktop-friendly)
    // -------------------
    bot->start_button = button_module_new("START", bot);
    bot->stop_button  = button_module_new("STOP", bot);
    bot->reset_button = button_module_new("RESET", bot);

    // -------------------
    // Bind actions
    // -------------------
    bot->drive_forward = astra_bot_drive_forward;
    bot->stop          = astra_bot_stop;
    bot->brain         = astra_bot_brain;

    return bot;
}

// -------------------
// Destroy AstraBot
// -------------------
void astra_bot_destroy(astra_bot_t* bot) {
    if (!bot) return;

    if (bot->ultrasonic) ultrasonic_destroy(bot->ultrasonic);
    if (bot->line_tracker) line_tracker_destroy(bot->line_tracker);
    if (bot->edge_detector) edge_detector_destroy(bot->edge_detector);
    if (bot->nfc_reader) nfc_reader_destroy(bot->nfc_reader);
    if (bot->display) display_module_destroy(bot->display);

    if (bot->start_button) button_module_destroy(bot->start_button);
    if (bot->stop_button)  button_module_destroy(bot->stop_button);
    if (bot->reset_button) button_module_destroy(bot->reset_button);

    free(bot);
}