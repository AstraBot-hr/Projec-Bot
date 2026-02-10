#include "display_module.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Simulate showing text on the display
 *
 * Prints the text to the console as a placeholder.
 * @param self Pointer to display_module_t
 * @param text Text to display
 */
static void display_module_show_text_impl(display_module_t* self, const char* text) {
    if (!self || !text) return;
    printf("[Display] %s\n", text);
}

/**
 * @brief Allocate and initialize a new display module
 *
 * Sets up the function pointer for displaying text.
 */
display_module_t* display_module_new(void) {
    display_module_t* display = (display_module_t*)malloc(sizeof(display_module_t));
    if (!display) return NULL;

    display->show_text = display_module_show_text_impl;
    return display;
}

/**
 * @brief Free a display module instance
 */
void display_module_destroy(display_module_t* display) {
    if (display) free(display);
}