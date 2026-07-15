cmake_minimum_required(VERSION 3.16)

project(university_cpp_exercises VERSION 1.0 LANGUAGES CXX)

add_executable(geometry_calculator src/geometry.cpp)
add_executable(student_records src/student_records.cpp)
add_executable(safe_vector src/safe_vector.cpp)
add_executable(dynamic_vector src/dynamic_vector.cpp)
add_executable(generic_matrix src/generic_matrix.cpp)
add_executable(participant_filter src/participant_filter.cpp)

set(project_targets
    geometry_calculator
    student_records
    safe_vector
    dynamic_vector
    generic_matrix
    participant_filter
)

foreach(target IN LISTS project_targets)
    target_compile_features(${target} PRIVATE cxx_std_17)

    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
