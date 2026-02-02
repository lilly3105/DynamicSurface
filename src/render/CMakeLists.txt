qt_add_library(${PROJECT_NAME}_render
    STATIC 
        RenderWorker.cpp
        backend/OsgBackend.cpp
        model/Model.cpp
        model/ModelUpdateCallback.cpp
        model/SurfaceCompute.cpp
)

target_link_libraries(${PROJECT_NAME}_render 
    PRIVATE 
        Qt6::Core
        ${OPENSCENEGRAPH_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}_render
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)