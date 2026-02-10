#ifndef BUTTON_MODULE_H
#define BUTTON_MODULE_H

/**
 * @file button_module.h
 * @brief Button abstraction for AstraBot
 *
 * Represents a button with a label and state.
 * On ESP32, this would read GPIO HIGH/LOW.
 * On desktop, we simulate button presses.
 */

#ifdef __cplusplus
extern "C" {
#endif

    struct astra_bot_t;  /**< Forward declaration to avoid circular dependency */

    /**
     * @struct button_module_t
     * @brief Represents a single button
     */
    typedef struct button_module_t {
        const char* label;      /**< Button label (for display) */

        // -------------------
        // Button state
        // -------------------
        int state;              /**< Current button state (0 = LOW, 1 = HIGH) */
        int last_state;         /**< Previous button state */

        // -------------------
        // User data
        // -------------------
        struct astra_bot_t* robot; /**< Pointer to robot using this button */

        // -------------------
        // ESP32 GPIO (commented for desktop)
        // -------------------
        // gpio_num_t pin;      /**< GPIO pin number on ESP32 */

    } button_module_t;

    /**
     * @brief Create a new button
     * @param label Button label
     * @param robot Pointer to AstraBot
     * @return Pointer to button_module_t
     */
    button_module_t* button_module_new(const char* label, struct astra_bot_t* robot);

    /**
     * @brief Destroy a button
     * @param btn Pointer to button_module_t
     */
    void button_module_destroy(button_module_t* btn);

    /**
     * @brief Update button state
     * On ESP32 this would read GPIO HIGH/LOW.
     * On desktop, we simulate pressing manually.
     */
    void button_module_update(button_module_t* btn);

#ifdef __cplusplus
}
#endif

#endif // BUTTON_MODULE_H