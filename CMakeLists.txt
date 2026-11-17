cmake_minimum_required(VERSION 3.14)
project(ClinicScheduler CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(clinic
    src/main.cpp
    src/Date.cpp
    src/Patient.cpp
    src/Doctor.cpp
    src/Clinic.cpp
)
target_include_directories(clinic PRIVATE include)
