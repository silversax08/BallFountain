cmake_minimum_required(VERSION 3.4)
project(Ball_Fountain)

FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer osgText)
FIND_PACKAGE(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
INCLUDE_DIRECTORIES( ${OPENSCENEGRAPH_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

add_library(BallMotion STATIC
    BallMotion.hpp
    BallMotion.cpp
  )

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    OSGWidget.h
    OSGWidget.cpp
    sphereupdatecallback.h
    sphereupdatecallback.cpp
)

add_executable(Unit_Tests
    calculate_new_acceleration.cpp
    calculate_new_velocity.cpp
    calculate_new_position.cpp
    )

target_link_libraries(${PROJECT_NAME}
    ${OPENSCENEGRAPH_LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
    ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES}
)

