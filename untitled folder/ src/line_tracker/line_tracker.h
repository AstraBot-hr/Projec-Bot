#ifndef LINE_TRACKER_H
#define LINE_TRACKER_H

/**
 * @file line_tracker.h
 * @brief Line tracking sensor module
 *
 * This module simulates a robot line tracker with left and right sensors.
 * It can detect the robot’s position relative to a line and provide values
 * for path correction.
 */

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct line_tracker_t {
        int left_sensor;   /**< Left sensor value (0 or 1) */
        int right_sensor;  /**< Right sensor value (0 or 1) */

        void (*read_line)(struct line_tracker_t* self); /**< Reads line and updates sensors */
    } line_tracker_t;

    /**
     * @brief Allocate and initialize a new line tracker
     * @return Pointer to line_tracker_t or NULL if allocation fails
     */
    line_tracker_t* line_tracker_new(void);

    /**
     * @brief Free a line tracker instance
     */
    void line_tracker_destroy(line_tracker_t* sensor);

#ifdef __cplusplus
}
#endif

#endif // LINE_TRACKER_H