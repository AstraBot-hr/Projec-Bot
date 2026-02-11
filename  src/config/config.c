#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Load entire file into memory
 */
static char* load_file(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Config error: Could not open %s\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    rewind(fp);

    if (length <= 0) {
        fclose(fp);
        return NULL;
    }

    char* buffer = malloc(length + 1);
    if (!buffer) {
        fclose(fp);
        return NULL;
    }

    fread(buffer, 1, length, fp);
    buffer[length] = '\0';
    fclose(fp);

    return buffer;
}

config_t* config_load(const char* filename)
{
    char* json_data = load_file(filename);
    if (!json_data)
        return NULL;

    cJSON* root = cJSON_Parse(json_data);
    free(json_data);

    if (!root) {
        fprintf(stderr, "Config error: Invalid JSON format\n");
        return NULL;
    }

    config_t* config = malloc(sizeof(config_t));
    if (!config) {
        cJSON_Delete(root);
        return NULL;
    }

    config->root = root;
    return config;
}

int config_get_int(config_t* config,
                   const char* section,
                   const char* key,
                   int default_value)
{
    if (!config || !config->root)
        return default_value;

    cJSON* sec = cJSON_GetObjectItem(config->root, section);
    if (!cJSON_IsObject(sec))
        return default_value;

    cJSON* item = cJSON_GetObjectItem(sec, key);
    if (cJSON_IsNumber(item))
        return item->valueint;

    return default_value;
}

const char* config_get_string(config_t* config,
                              const char* section,
                              const char* key,
                              const char* default_value)
{
    if (!config || !config->root)
        return default_value;

    cJSON* sec = cJSON_GetObjectItem(config->root, section);
    if (!cJSON_IsObject(sec))
        return default_value;

    cJSON* item = cJSON_GetObjectItem(sec, key);
    if (cJSON_IsString(item))
        return item->valuestring;

    return default_value;
}

void config_destroy(config_t* config)
{
    if (!config)
        return;

    if (config->root)
        cJSON_Delete(config->root);

    free(config);
}