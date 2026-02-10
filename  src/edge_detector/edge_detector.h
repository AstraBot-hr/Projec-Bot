#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include <stdbool.h>

/**
 * @file edge_detector.h
 * @brief Edge detection sensor module
 *
 * Simulates a sensor that detects edges or drop-offs.
 * Used to prevent the robot from falling off edges.
 */

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct edge_detector_t {
        bool edge_detected; /**< True if an edge is detected */
        void (*read_edge)(struct edge_detector_t* self); /**< Updates edge_detected */
    } edge_detector_t;

    edge_detector_t* edge_detector_new(void);
    void edge_detector_destroy(edge_detector_t* sensor);

#ifdef __cplusplus
}
#endif

#endif // EDGE_DETECTOR_H