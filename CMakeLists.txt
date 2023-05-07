cmake_minimum_required(VERSION 2.8.12)

# Project dependencies first.
add_subdirectory(external)

# PSvita specifics
if(BUILD_TARGET MATCHES "VITA")

    ## Configuration options for this app
    # Display name (under bubble in LiveArea)
    set(VITA_APP_NAME "Five Nights at Freddy's")

    # Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
    # unique string of developer and Y = a unique number for this app
    set(VITA_TITLEID  "GHNR00001")

    # Optional version string to show in LiveArea's more info screen
    set(VITA_VERSION  "01.00")

else()

    # Project output path for install()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)

endif()

# Project metadata
project(FNAF1)

file(
    GLOB
    EXECUTABLE_FILES
        "src/*.cpp"
        "src/states/*.cpp"
        "src/nodes/WarningState/*.cpp"
        "src/nodes/LoadingState/*.cpp"
)

# Project core
add_executable(
    ${PROJECT_NAME}
    ${EXECUTABLE_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        libStorm
)

# Post build stuff per platform.
if(BUILD_TARGET MATCHES "VITA")

    # Specific project flags.
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
            -Wall
            -O3
    )

    ## Create Vita files
    vita_create_self(
        ${PROJECT_NAME}.self ${PROJECT_NAME}
        SAFE    # Use unsafe if system modules are used.
    )

    vita_create_vpk(
        ${PROJECT_NAME}.vpk
        ${VITA_TITLEID}
        ${PROJECT_NAME}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        FOLDER assets/original/ assets/original/
        # Vita System files need to be separately set
        FILE vita-metadata/icon0.png sce_sys/icon0.png
        FILE vita-metadata/livearea/contents/background.png sce_sys/livearea/contents/background.png
        FILE vita-metadata/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        FILE vita-metadata/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
        
        # Asset files need to be specified manually :c
        FILE assets/assetlist.json assets/assetlist.json
        FILE assets/fonts/list.json assets/fonts/list.json
        FILE assets/fonts/Volter-FNAF1.ttf assets/fonts/Volter-FNAF1.ttf
        FILE assets/original/list.json assets/original/list.json
        FILE assets/original/605.png assets/original/605.png
        FILE assets/images/list.json assets/images/list.json
        FILE assets/images/default.png assets/images/default.png
    )

else()
    # Specific project flags for Debug / Release. (TODO)
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
            -Wall
            -O3
    )

    # Install executables.
    install(TARGETS ${PROJECT_NAME})

    # Copy game assets to output path.
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_directory_if_different
            "../assets/"
            "../bin/assets/"
    )
endif()
