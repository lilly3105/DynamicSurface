cmake_minimum_required(VERSION 3.22)

project(DynamicSurface VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Widgets Qml)
find_package(OpenSceneGraph REQUIRED COMPONENTS osgViewer osgGA)

qt_standard_project_setup()

add_subdirectory(src)