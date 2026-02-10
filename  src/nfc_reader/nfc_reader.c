#include "nfc_reader.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Simulate reading an NFC tag
 *
 * Increments red tag as a placeholder.
 */
static void nfc_reader_read_tag(nfc_reader_t* self) {
    if (!self) return;

    self->tag_count_red++; // Placeholder increment

    printf("[NFCReader] Tags read: R=%d G=%d B=%d\n",
           self->tag_count_red, self->tag_count_green, self->tag_count_blue);
}

/**
 * @brief Allocate and initialize a new NFC reader
 */
nfc_reader_t* nfc_reader_new(void) {
    nfc_reader_t* sensor = (nfc_reader_t*)malloc(sizeof(nfc_reader_t));
    if (!sensor) return NULL;

    sensor->tag_count_red = 0;
    sensor->tag_count_green = 0;
    sensor->tag_count_blue = 0;
    sensor->read_tag = nfc_reader_read_tag;

    return sensor;
}

/**
 * @brief Free an NFC reader instance
 */
void nfc_reader_destroy(nfc_reader_t* sensor) {
    if (sensor) free(sensor);
}