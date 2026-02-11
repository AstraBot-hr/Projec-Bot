#ifndef COMPONENTS_H
#define COMPONENTS_H

/**
 * @file components.h
 * @brief Umbrella header including all robot modules
 *
 * Use this **only in main.c** or other top-level orchestration files.
 * Do NOT include this inside individual module headers.
 */
#include "app/astra.h"
#include "ultrasonic/ultrasonic.h"
#include "line_tracker/line_tracker.h"
#include "edge_detector/edge_detector.h"
#include "nfc_reader/nfc_reader.h"
#include "display_module/display_module.h"
#include "button_module/button_module.h"
#include "config/config.h"
#endif // COMPONENTS_H