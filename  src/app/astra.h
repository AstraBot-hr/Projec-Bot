#ifndef ASTRA_H
#define ASTRA_H

#include "../ultrasonic/ultrasonic.h"
#include "../line_tracker/line_tracker.h"
#include "../edge_detector/edge_detector.h"
#include "../nfc_reader/nfc_reader.h"
#include "../display_module/display_module.h"
#include "../button_module/button_module.h"
#include "../config/config.h"
#include <stdio.h>
#include <string.h> // For strcmp in brain logic

/**
 * @struct astra_bot_t
 * @brief Full AstraBot robot with sensors, display, buttons, and brain.
 */
typedef struct astra_bot_t {
    // Sensors
    ultrasonic_t* ultrasonic;
    line_tracker_t* line_tracker;
    edge_detector_t* edge_detector;
    nfc_reader_t* nfc_reader;

    // Display
    display_module_t* display;

    // Buttons
    button_module_t* start_button;
    button_module_t* stop_button;
    button_module_t* reset_button;

    // Robot actions
    void (*drive_forward)(struct astra_bot_t* self, int speed);
    void (*stop)(struct astra_bot_t* self);

    // Brain function
    void (*brain)(struct astra_bot_t* self);

    // Configuration pointer for thresholds, speeds, etc.
    config_t* config;

} astra_bot_t;

// Public functions
astra_bot_t* astra_bot_new(config_t* cfg);
void astra_bot_destroy(astra_bot_t* bot);
void astra_bot_drive_forward(astra_bot_t* self, int speed);
void astra_bot_stop(astra_bot_t* self);
void astra_bot_brain(astra_bot_t* self);

#endif // ASTRA_H