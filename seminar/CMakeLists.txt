cmake_minimum_required(VERSION 3.18)

# Название проекта и стандарт C++
project(seminar_app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Собираем все .cpp в текущей директории
file(GLOB SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(seminar_app ${SOURCES})

# (Опционально) для более подробного вывода компиляции на macOS
if(APPLE)
    target_compile_options(seminar_app PRIVATE -Wall -Wextra -Wpedantic)
else()
    target_compile_options(seminar_app PRIVATE -Wall -Wextra)
endif()