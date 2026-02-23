cmake_minimum_required(VERSION 3.24)
project(infinimap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(GNUInstallDirs)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(infinimap
        main.cpp
        src/core/world/world_state.cpp
)
target_include_directories(infinimap PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(infinimap
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

install(TARGETS infinimap
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (COMMAND qt_generate_deploy_app_script)
    qt_generate_deploy_app_script(
            TARGET infinimap
            OUTPUT_SCRIPT qt_deploy_script
            NO_UNSUPPORTED_PLATFORM_ERROR
    )
    install(SCRIPT "${qt_deploy_script}")
endif ()
