cmake_minimum_required(VERSION 3.27)
 
project(lunchcalculator
    VERSION 1.0.0
    LANGUAGES CXX)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
 
find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(QSkinny REQUIRED)
 
add_executable(lunchcalculator
    src/main.cpp
    src/CalculatorButtonSkinFactory.cpp
    src/DisplayLabel.cpp
    src/NumberButtons.cpp
    src/OperationButtons.cpp
    src/OtherButtons.cpp
    src/ButtonsGridBox.cpp)
 
target_link_libraries(lunchcalculator PRIVATE
    Qt6::Quick
    Qsk::QSkinny)
