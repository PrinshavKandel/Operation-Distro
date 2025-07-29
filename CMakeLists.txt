cmake_minimum_required(VERSION 3.16)
project(BellCurveMac LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

qt_standard_project_setup()

qt_add_executable(BellCurveMac
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    qcustomplot.cpp
    qcustomplot.h
)

target_include_directories(BellCurveMac PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BellCurveMac PRIVATE Qt6::Widgets Qt6::PrintSupport)
target_compile_options(BellCurveMac PRIVATE -Wno-deprecated-declarations)
