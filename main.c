#include " src/components.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("==== AstraBot Starting ====\n");

    // Load configuration
    config_t* config = config_load("config.json");
    if (!config) {
        fprintf(stderr, "Failed to load config\n");
        return EXIT_FAILURE;
    }

    // Initialize robot with dependency injection
    astra_bot_t* robot = astra_bot_new(config);
    if (!robot) {
        fprintf(stderr, "Failed to initialize AstraBot\n");
        config_destroy(config);
        return EXIT_FAILURE;
    }

    robot->display->show_text(robot->display, "AstraBot initialized");

    // Brain loop
    int iterations = config_get_int(config, "robot", "brain_loop_iterations", 100);
    for (int i = 0; i < iterations; i++) {
        printf("\n--- Brain Loop %d ---\n", i + 1);
        robot->brain(robot);
    }

    // Cleanup
    astra_bot_destroy(robot);
    config_destroy(config);

    printf("==== AstraBot Shutdown ====\n");
    return EXIT_SUCCESS;
}