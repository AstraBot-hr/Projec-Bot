#include "astra.h"
#include <stdlib.h>

/**
 * @brief Drive robot forward
 */
void astra_bot_drive_forward(astra_bot_t* self, int speed) {
    if (!self) return;
    printf("[AstraBot] Driving forward at speed %d\n", speed);
}

/**
 * @brief Stop robot
 */
void astra_bot_stop(astra_bot_t* self) {
    if (!self) return;
    printf("[AstraBot] Stopped\n");
}

/**
 * @brief Main brain loop: reads sensors, decides actions
 */
void astra_bot_brain(astra_bot_t* self) {
    if (!self || !self->config) return;

    printf("[Brain] Running brain logic...\n");

    // Update buttons (simulate presses)
    if (self->start_button) button_module_update(self->start_button);
    if (self->stop_button)  button_module_update(self->stop_button);
    if (self->reset_button) button_module_update(self->reset_button);

    // Read sensors
    if (self->ultrasonic) {
        self->ultrasonic->read_distance(self->ultrasonic);
        int max_distance = config_get_int(self->config, "ultrasonic", "max_distance", 100);
        int min_distance = config_get_int(self->config, "ultrasonic", "min_distance", 5);
        printf("[Brain] Distance: %d cm (min=%d, max=%d)\n",
               self->ultrasonic->distance, min_distance, max_distance);
    }
    if (self->line_tracker) self->line_tracker->read_line(self->line_tracker);
    if (self->edge_detector) self->edge_detector->read_edge(self->edge_detector);
    if (self->nfc_reader) self->nfc_reader->read_tag(self->nfc_reader);

    // Decide movement based on NFC tags
    int red   = self->nfc_reader ? self->nfc_reader->tag_count_red   : 0;
    int green = self->nfc_reader ? self->nfc_reader->tag_count_green : 0;
    int blue  = self->nfc_reader ? self->nfc_reader->tag_count_blue  : 0;

    int default_speed = config_get_int(self->config, "robot", "default_speed", 50);
    const char* red_action   = config_get_string(self->config, "nfc_reader", "red_tag_action", "left");
    const char* green_action = config_get_string(self->config, "nfc_reader", "green_tag_action", "right");
    const char* blue_action  = config_get_string(self->config, "nfc_reader", "blue_tag_action", "stop");

    if (red > green && red > blue) {
        self->display->show_text(self->display, "RED tag detected");
        if (strcmp(red_action, "left") == 0) printf("[Brain] Turning LEFT\n");
        else if (strcmp(red_action, "right") == 0) printf("[Brain] Turning RIGHT\n");
        else self->stop(self);
    } else if (green > red && green > blue) {
        self->display->show_text(self->display, "GREEN tag detected");
        if (strcmp(green_action, "left") == 0) printf("[Brain] Turning LEFT\n");
        else if (strcmp(green_action, "right") == 0) printf("[Brain] Turning RIGHT\n");
        else self->stop(self);
    } else if (blue > red && blue > green) {
        self->display->show_text(self->display, "BLUE tag detected");
        if (strcmp(blue_action, "left") == 0) printf("[Brain] Turning LEFT\n");
        else if (strcmp(blue_action, "right") == 0) printf("[Brain] Turning RIGHT\n");
        else self->stop(self);
    } else {
        self->display->show_text(self->display, "No dominant tag detected");
        self->drive_forward(self, default_speed);
    }
}

/**
 * @brief Create a new AstraBot instance
 */
astra_bot_t* astra_bot_new(config_t* cfg) {
    astra_bot_t* bot = malloc(sizeof(astra_bot_t));
    if (!bot) return NULL;

    bot->config = cfg;

    // Initialize modules
    bot->ultrasonic    = ultrasonic_new();
    bot->line_tracker  = line_tracker_new();
    bot->edge_detector = edge_detector_new();
    bot->nfc_reader    = nfc_reader_new();
    bot->display       = display_module_new();
    bot->start_button  = button_module_new("START", bot);
    bot->stop_button   = button_module_new("STOP", bot);
    bot->reset_button  = button_module_new("RESET", bot);

    // Bind actions
    bot->drive_forward = astra_bot_drive_forward;
    bot->stop          = astra_bot_stop;
    bot->brain         = astra_bot_brain;

    return bot;
}

/**
 * @brief Destroy AstraBot and all its modules
 */
void astra_bot_destroy(astra_bot_t* bot) {
    if (!bot) return;

    if (bot->ultrasonic) ultrasonic_destroy(bot->ultrasonic);
    if (bot->line_tracker) line_tracker_destroy(bot->line_tracker);
    if (bot->edge_detector) edge_detector_destroy(bot->edge_detector);
    if (bot->nfc_reader) nfc_reader_destroy(bot->nfc_reader);
    if (bot->display) display_module_destroy(bot->display);
    if (bot->start_button) button_module_destroy(bot->start_button);
    if (bot->stop_button) button_module_destroy(bot->stop_button);
    if (bot->reset_button) button_module_destroy(bot->reset_button);

    free(bot);
}