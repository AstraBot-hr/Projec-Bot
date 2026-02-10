#ifndef DISPLAY_MODULE_H
#define DISPLAY_MODULE_H

/**
 * @file display_module.h
 * @brief Display module for showing text on screen
 *
 * This module simulates a robot display where text can be printed.
 * It uses an object-oriented style in C with a function pointer
 * to display text.
 */

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct display_module_t
     * @brief Represents a display module
     *
     * Members:
     *  - show_text: Function pointer to print a string to the display
     */
    typedef struct display_module_t {
        void (*show_text)(struct display_module_t* self, const char* text); /**< Print text */
    } display_module_t;

    /**
     * @brief Allocate and initialize a new display module
     * @return Pointer to a new display_module_t instance, or NULL if allocation fails
     */
    display_module_t* display_module_new(void);

    /**
     * @brief Free a display module instance
     * @param display Pointer to the display_module_t to free
     */
    void display_module_destroy(display_module_t* display);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_MODULE_H