qt_add_qml_module(${PROJECT_NAME}_ui
    URI ${PROJECT_NAME}.UI
    OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/imports/${PROJECT_NAME}/UI"
    VERSION 1.0
    QML_FILES
        Main.qml
)