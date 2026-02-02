qt_add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        Qt6::Widgets
        ${PROJECT_NAME}_ui
        ${PROJECT_NAME}_app
)

add_subdirectory(app)
add_subdirectory(ui)
add_subdirectory(render)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)