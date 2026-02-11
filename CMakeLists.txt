cmake_minimum_required(VERSION 4.1)
project(Project_Ep20 C)

set(CMAKE_C_STANDARD 23)

add_executable(Project_Ep20 main.c
        " src/display_module/display_module.c"
        " src/button_module/button_module.c"
        " src/app/astra.c"
        " src/edge_detector/edge_detector.c"
        " src/line_tracker/line_tracker.c"
        " src/config/cJSON/cJSON.h"
        " src/config/cJSON/cJSON.h"
        " src/config/config.c"
        " src/config/config.h"
        " src/ultrasonic/ultrasonic.c")
