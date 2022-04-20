cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

cmake_policy(SET CMP0048 NEW) # for version
project (Observer_mode VERSION 1.0.0)

SET(CMAKE_BUILE_TYPE "build")

find_package(Qt5 COMPONENTS Widgets  REQUIRED)

include_directories (${CMAKE_SOURCE_DIR}/include)

# Tell CMake to run moc when necessary:
SET(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET  (PROJECT_SOURCES
	${CMAKE_SOURCE_DIR}/src/main.cpp
  ${CMAKE_SOURCE_DIR}/src/observer.cpp
  ${CMAKE_SOURCE_DIR}/src/subject.cpp
	) 

SET  (PROJECT_HEADERS
  ${CMAKE_SOURCE_DIR}/include/base.h
  ${CMAKE_SOURCE_DIR}/include/observer.h
  ${CMAKE_SOURCE_DIR}/include/subject.h
	)

INCLUDE_DIRECTORIES(src include ${CMAKE_CURRENT_BINARY_DIR} ${Qt5_INCLUDE_DIRS})
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib/linux)
ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Gui )


