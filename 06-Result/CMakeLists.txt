cmake_minimum_required(VERSION 2.8)
project( 06-Result )
find_package( OpenCV REQUIRED )
add_executable( 06-Result Result.cpp)
target_link_libraries( 06-Result ${OpenCV_LIBS} )
