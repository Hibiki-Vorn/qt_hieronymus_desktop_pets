cmake_minimum_required(VERSION 3.16)
project(qt_hieronymus_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.8 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appqt_hieronymus_app
    main.cpp
)

qt_add_qml_module(appqt_hieronymus_app
    URI qt_hieronymus_app
    VERSION 1.0
    QML_FILES
        Main.qml
    RESOURCES
        logo.svg
        logo.png
        burger.svg
        SOURCES
        SOURCES mainwindow_events.h
        SOURCES
        QML_FILES MenuWindow.qml
        QML_FILES Avatar.qml
)

set_target_properties(appqt_hieronymus_app PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqt_hieronymus_app
    PRIVATE Qt6::Quick
)
target_link_libraries(appqt_hieronymus_app PRIVATE Qt6::Core Qt6::Widgets Qt6::Quick)

install(TARGETS appqt_hieronymus_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
