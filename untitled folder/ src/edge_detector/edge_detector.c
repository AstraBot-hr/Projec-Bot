#include "edge_detector.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Simulate edge detection
 *
 * Updates edge_detected with a placeholder value.
 */
static void edge_detector_read_edge(edge_detector_t* self) {
    if (!self) return;

    self->edge_detected = false; // Placeholder: no edge
    printf("[EdgeDetector] Edge detected: %s\n", self->edge_detected ? "YES" : "NO");
}

/**
 * @brief Allocate and initialize an edge detector
 */
edge_detector_t* edge_detector_new(void) {
    edge_detector_t* sensor = (edge_detector_t*)malloc(sizeof(edge_detector_t));
    if (!sensor) return NULL;

    sensor->edge_detected = false;
    sensor->read_edge = edge_detector_read_edge;

    return sensor;
}

/**
 * @brief Free an edge detector instance
 */
void edge_detector_destroy(edge_detector_t* sensor) {
    if (sensor) free(sensor);
}