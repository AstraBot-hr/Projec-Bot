#ifndef CONFIG_H
#define CONFIG_H

#include "cJSON/cJSON.h"

/**
 * @brief Configuration structure for AstraBot
 *
 * Holds parsed JSON root and provides
 * helper access functions.
 */
typedef struct {
    cJSON* root;
} config_t;

/**
 * @brief Load configuration file
 * @param filename JSON file path
 * @return config_t* (NULL on failure)
 */
config_t* config_load(const char* filename);

/**
 * @brief Get integer value safely
 */
int config_get_int(config_t* config,
                   const char* section,
                   const char* key,
                   int default_value);

/**
 * @brief Get string value safely
 */
const char* config_get_string(config_t* config,
                              const char* section,
                              const char* key,
                              const char* default_value);

/**
 * @brief Free configuration
 */
void config_destroy(config_t* config);

#endif