idf_component_register(
    SRCS
        "main.c"

        # Audio
        "audio/osc.c"
        "audio/mixer.c"
        "audio/audio_engine.c"

        # Drivers
        "drivers/dac.c"
        "drivers/st7789.c"

        # Interface / UI
        "interface/input.c"
        "interface/display.c"

        "input/input.c"

    INCLUDE_DIRS
        "."
        "audio"
        "drivers"
        "interface"
        "input"
)