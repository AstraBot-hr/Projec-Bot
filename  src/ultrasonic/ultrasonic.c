#include "ultrasonic.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Simulate reading the ultrasonic sensor
 *
 * Updates the distance field with a placeholder value.
 * In a real implementation, this would trigger hardware
 * measurement (GPIO, timer, etc.).
 */
static void ultrasonic_read_distance(ultrasonic_t* self) {
    if (!self) return;

    self->distance = 42; // Placeholder distance
    printf("[Ultrasonic] Distance: %d cm\n", self->distance);
}

/**
 * @brief Allocate and initialize an ultrasonic sensor
 *
 * Sets default values and assigns function pointer.
 */
ultrasonic_t* ultrasonic_new(void) {
    ultrasonic_t* sensor = (ultrasonic_t*)malloc(sizeof(ultrasonic_t));
    if (!sensor) return NULL;

    sensor->distance = 0;
    sensor->max_range = 200;
    sensor->read_distance = ultrasonic_read_distance;

    return sensor;
}

/**
 * @brief Free an ultrasonic sensor instance
 */
void ultrasonic_destroy(ultrasonic_t* sensor) {
    if (sensor) free(sensor);
}