#include "line_tracker.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Simulate reading the line tracker
 *
 * Updates left and right sensor values with placeholder data.
 */
static void line_tracker_read_line(line_tracker_t* self) {
    if (!self) return;

    self->left_sensor = 1;   // Placeholder value
    self->right_sensor = 0;  // Placeholder value

    printf("[LineTracker] Left=%d Right=%d\n", self->left_sensor, self->right_sensor);
}

/**
 * @brief Allocate and initialize a line tracker
 */
line_tracker_t* line_tracker_new(void) {
    line_tracker_t* sensor = (line_tracker_t*)malloc(sizeof(line_tracker_t));
    if (!sensor) return NULL;

    sensor->left_sensor = 0;
    sensor->right_sensor = 0;
    sensor->read_line = line_tracker_read_line;

    return sensor;
}

/**
 * @brief Free a line tracker instance
 */
void line_tracker_destroy(line_tracker_t* sensor) {
    if (sensor) free(sensor);
}