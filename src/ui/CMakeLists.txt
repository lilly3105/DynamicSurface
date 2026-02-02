qt_add_library(${PROJECT_NAME}_ui
    STATIC
        Main.ui
        MainWindow.cpp
)

target_link_libraries(${PROJECT_NAME}_ui
        PRIVATE
        Qt6::Widgets
)

target_include_directories(${PROJECT_NAME}_ui
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)