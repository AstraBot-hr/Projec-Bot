#ifndef ASTRA_H
#define ASTRA_H

/**
 * @file astra.h
 * @brief Main robot abstraction for AstraBot
 *
 * Represents the complete robot, owns all sensors, display, buttons.
 * Provides object-oriented style C interface.
 */

#include "../ultrasonic/ultrasonic.h"
#include "../line_tracker/line_tracker.h"
#include "../edge_detector/edge_detector.h"
#include "../nfc_reader/nfc_reader.h"
#include "../display_module/display_module.h"
#include "../button_module/button_module.h"

/**
 * @struct astra_bot_t
 * @brief Full AstraBot robot
 */
typedef struct astra_bot_t {
    // Sensors
    ultrasonic_t* ultrasonic;
    line_tracker_t* line_tracker;
    edge_detector_t* edge_detector;
    nfc_reader_t* nfc_reader;

    // Display / Output
    display_module_t* display;

    // Buttons
    button_module_t* start_button;
    button_module_t* stop_button;
    button_module_t* reset_button;

    // Robot actions
    void (*drive_forward)(struct astra_bot_t* self, int speed);
    void (*stop)(struct astra_bot_t* self);

    // Brain: sensor-driven decision
    void (*brain)(struct astra_bot_t* self);

} astra_bot_t;

/**
 * @brief Create and initialize AstraBot
 * Allocates all sensors, display, and buttons
 */
astra_bot_t* astra_bot_new(void);

/**
 * @brief Destroy AstraBot and all modules
 */
void astra_bot_destroy(astra_bot_t* bot);

/**
 * @brief Drive the robot forward
 */
void astra_bot_drive_forward(astra_bot_t* self, int speed);

/**
 * @brief Stop the robot
 */
void astra_bot_stop(astra_bot_t* self);

/**
 * @brief Get distance from ultrasonic sensor
 * @return Distance in cm, or -1 if not available
 */
int astra_bot_get_distance(astra_bot_t* self);

/**
 * @brief Brain function: read sensors and decide movement
 */
void astra_bot_brain(astra_bot_t* self);

#endif // ASTRA_H