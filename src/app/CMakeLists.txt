qt_add_library(${PROJECT_NAME}_app 
    STATIC
        Application.cpp
)

target_link_libraries(${PROJECT_NAME}_app 
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Qml
        ${PROJECT_NAME}_ui
        ${PROJECT_NAME}_render
)

target_include_directories(${PROJECT_NAME}_app
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)