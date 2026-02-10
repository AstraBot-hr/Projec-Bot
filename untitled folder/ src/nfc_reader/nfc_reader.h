#ifndef NFC_READER_H
#define NFC_READER_H

/**
 * @file nfc_reader.h
 * @brief NFC reader module
 *
 * Simulates reading NFC tags with color counts (red, green, blue).
 * Useful for counting colored blocks or tracking objects.
 */

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct nfc_reader_t {
        int tag_count_red;
        int tag_count_green;
        int tag_count_blue;

        void (*read_tag)(struct nfc_reader_t* self); /**< Updates tag counts */
    } nfc_reader_t;

    nfc_reader_t* nfc_reader_new(void);
    void nfc_reader_destroy(nfc_reader_t* sensor);

#ifdef __cplusplus
}
#endif

#endif // NFC_READER_H