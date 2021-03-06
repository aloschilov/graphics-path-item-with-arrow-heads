set(CMAKE_PREFIX_PATH "/Users/aloschil/Qt/5.3/clang_64/lib/cmake")

cmake_minimum_required(VERSION 2.8.11)
project(graphics-path-item-with-arrows)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES})

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(graphics_path_item_with_arrows main.cpp mainwindow.cpp graphicspathitemwitharrowheads.cpp graphicspathitemwitharrowheads.h)

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
target_link_libraries(graphics_path_item_with_arrows ${Qt5Widgets_LIBRARIES})
