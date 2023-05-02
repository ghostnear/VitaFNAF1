cmake_minimum_required(VERSION 2.8)

# Project dependencies first.
add_subdirectory(external)

# PSvita specifics
if(BUILD_TARGET MATCHES "VITA")

    ## Configuration options for this app
    # Display name (under bubble in LiveArea)
    set(VITA_APP_NAME "Storm Test App")

    # Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
    # unique string of developer and Y = a unique number for this app
    set(VITA_TITLEID  "STRM00000")

    # Optional version string to show in LiveArea's more info screen
    set(VITA_VERSION  "01.00")

else()

    # Project output path for install()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)

endif()

# Project metadata
project(exampleApp)

file(
    GLOB
    EXECUTABLE_FILES
        "src/*.cpp"
        "src/states/*.cpp"
        "src/nodes/MainState/*.cpp"
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
    vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})

    # The FILE directive lets you add additional files to the VPK, the syntax is
    # FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
    vita_create_vpk(
        ${PROJECT_NAME}.vpk
        ${VITA_TITLEID}
        ${PROJECT_NAME}.self
        VERSION ${VITA_VERSION}
        NAME ${VITA_APP_NAME}
        # Vita System files need to be separately set
        FILE assets/vita/icon0.png sce_sys/icon0.png
        FILE assets/vita/livearea/contents/background.png sce_sys/livearea/contents/background.png
        FILE assets/vita/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        FILE assets/vita/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
        # TODO: replace some of this with folder copies or something, it's too much work for all of this.
        FILE assets/assetlist.json assets/assetlist.json
        FILE assets/fonts/list.json assets/fonts/list.json
        FILE assets/fonts/SCP/LICENSE.md assets/fonts/SCP/LICENSE.md
        FILE assets/fonts/SCP/SourceCodePro-Light.otf assets/fonts/SCP/SourceCodePro-Light.otf
        FILE assets/fonts/SCP/SourceCodePro-SemiboldIt.otf assets/fonts/SCP/SourceCodePro-SemiboldIt.otf
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

    # Remove Vita assets. (TODO don't copy them in the first place?)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E rm -rf
            "../bin/assets/vita/"
    )
endif()
