cmake_minimum_required(VERSION 3.16)
project(qt_hieronymus_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.8 REQUIRED COMPONENTS Core Widgets Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(qt_hieronymus_desktop_pets
    main.cpp
)

qt_add_qml_module(qt_hieronymus_desktop_pets
    URI qt_hieronymus_app
    VERSION 1.0
    QML_FILES
        Main.qml
        MenuWindow.qml
        Avatar.qml
        Naxida.qml
    #RESOURCES
     #   logo.svg
      #  logo.png
       # burger.svg
    SOURCES
        mainwindow_events.h
        naxida_actions.h
)

set_target_properties(qt_hieronymus_desktop_pets PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(qt_hieronymus_desktop_pets
    PRIVATE Qt6::Core Qt6::Widgets Qt6::Quick
)

install(TARGETS qt_hieronymus_desktop_pets
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_custom_command(
    TARGET qt_hieronymus_desktop_pets POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:qt_hieronymus_desktop_pets>/assets
    COMMENT "Copying assets folder to build output directory"
)
