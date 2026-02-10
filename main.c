#include " src/components.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include " src/cJSON.h"      // cJSON library to parse JSON config

/**
 * @file main.c
 * @brief Controller / mediator for AstraBot
 *
 * Main program initializes the robot and reads configuration.
 * All decision-making is delegated to astra_bot_brain().
 */

int main() {
    // -------------------
    // Load JSON configuration
    // -------------------
    FILE* fp = fopen("config.json", "r");
    if (!fp) {
        fprintf(stderr, "Failed to open config.json\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* data = (char*)malloc(length + 1);
    if (!data) {
        fclose(fp);
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    fread(data, 1, length, fp);
    data[length] = '\0';
    fclose(fp);

    cJSON* config = cJSON_Parse(data);
    if (!config) {
        fprintf(stderr, "Failed to parse config.json\n");
        free(data);
        return 1;
    }

    // -------------------
    // Initialize AstraBot
    // -------------------
    astra_bot_t* robot = astra_bot_new();
    if (!robot) {
        fprintf(stderr, "Failed to initialize AstraBot\n");
        cJSON_Delete(config);
        free(data);
        return 1;
    }

    // Display initial message
    robot->display->show_text(robot->display, "AstraBot initialized");

    // -------------------
    // Determine brain loop iterations from JSON
    // -------------------
    int iterations = 100; // default value
    cJSON* brain_iter = cJSON_GetObjectItem(config, "robot");
    if (brain_iter) {
        cJSON* loop = cJSON_GetObjectItem(brain_iter, "brain_loop_iterations");
        if (cJSON_IsNumber(loop)) iterations = loop->valueint;
    }

    // -------------------
    // Main brain loop (mediator)
    // -------------------
    for (int i = 0; i < iterations; i++) {
        printf("\n--- Brain loop iteration %d ---\n", i + 1);
        robot->brain(robot);  // Brain handles all logic
    }

    // -------------------
    // Cleanup
    // -------------------
    astra_bot_destroy(robot);
    cJSON_Delete(config);
    free(data);

    return 0;
}