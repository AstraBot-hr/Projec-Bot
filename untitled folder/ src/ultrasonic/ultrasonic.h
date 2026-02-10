#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/**
 * @file ultrasonic.h
 * @brief Ultrasonic distance sensor module
 *
 * This module simulates an ultrasonic distance sensor.
 * It stores the last measured distance and allows reading
 * via a function pointer, using an object-oriented style in C.
 *
 * This simulation can later be replaced with real hardware code
 * (HC-SR04, ESP32, etc.) without changing user code.
 */

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct ultrasonic_t
     * @brief Represents an ultrasonic sensor instance
     *
     * Members:
     *  - distance: Last measured distance in centimeters
     *  - max_range: Maximum measurable distance
     *  - read_distance: Function pointer to trigger a measurement
     */
    typedef struct ultrasonic_t {
        int distance;     /**< Last measured distance in cm */
        int max_range;    /**< Maximum measurable distance in cm */

        void (*read_distance)(struct ultrasonic_t* self); /**< Reads distance and updates 'distance' */
    } ultrasonic_t;

    /**
     * @brief Create and initialize a new ultrasonic sensor
     * @return Pointer to a new ultrasonic_t instance, or NULL if allocation fails
     */
    ultrasonic_t* ultrasonic_new(void);

    /**
     * @brief Free an ultrasonic sensor instance
     * @param sensor Pointer to the sensor to free
     */
    void ultrasonic_destroy(ultrasonic_t* sensor);

#ifdef __cplusplus
}
#endif

#endif // ULTRASONIC_H