#include "button_module.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @file button_module.c
 * @brief Implementation of button module
 *
 * Simulates button presses on desktop.
 * On ESP32, we would use gpio_get_level(pin).
 */

// -------------------
// Create button
// -------------------
button_module_t* button_module_new(const char* label, struct astra_bot_t* robot) {
    button_module_t* btn = (button_module_t*)malloc(sizeof(button_module_t));
    if (!btn) return NULL;

    btn->label = label;
    btn->state = 0;       // default LOW
    btn->last_state = 0;
    btn->robot = robot;

    // -------------------
    // ESP32 GPIO initialization (commented out for desktop)
    // -------------------
    /*
    btn->pin = pin;
    gpio_pad_select_gpio(btn->pin);
    gpio_set_direction(btn->pin, GPIO_MODE_INPUT);
    */

    return btn;
}

// -------------------
// Destroy button
// -------------------
void button_module_destroy(button_module_t* btn) {
    if (!btn) return;
    free(btn);
}

// -------------------
// Update button state
// -------------------
void button_module_update(button_module_t* btn) {
    if (!btn) return;

    // -------------------
    // Desktop simulation: user manually sets state
    // -------------------
    // Example: we just toggle the state for testing
    btn->last_state = btn->state;
    btn->state = 1; // simulate pressed

    if (btn->state && !btn->last_state) {
        // Rising edge detected
        printf("[Button] '%s' pressed (simulated)\n", btn->label);

        // Here you can call a callback or set a flag in robot
        // Example: robot->drive_forward(robot, 50);
    }

    // Reset state to LOW for next loop (simulation)
    btn->state = 0;

    // -------------------
    // ESP32 GPIO reading (commented)
    // -------------------
    /*
    btn->last_state = btn->state;
    btn->state = gpio_get_level(btn->pin);

    if (btn->state && !btn->last_state) {
        // Rising edge detected
        printf("[Button] '%s' pressed\n", btn->label);
        // trigger robot callback
    }
    */
}