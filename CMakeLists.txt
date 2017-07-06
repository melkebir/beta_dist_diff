CMAKE_MINIMUM_REQUIRED( VERSION 2.8.3 )

PROJECT( beta_diff )

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

# find required python packages
FIND_PACKAGE(Boost COMPONENTS python REQUIRED )
MESSAGE( STATUS "found boost:"
  "\nINCLUDE: ${Boost_INCLUDE_DIRS}"
  "\nLIB: ${Boost_LIBRARIES}"
)

FIND_PACKAGE(PythonInterp REQUIRED)
FIND_PACKAGE(PythonLibsNew REQUIRED)

if (NOT WIN32)
  add_definitions(-fPIC)
endif()

# custom macro with most of the redundant code for making a python example module
MACRO( addPythonExe _name _srccpp )
  ADD_EXECUTABLE(${_name} ${_srccpp} ${beta_diff_src})

  # make the pyd library link against boost_numpy python and boost
  TARGET_LINK_LIBRARIES(${_name} ${CommonLibs})
ENDMACRO()

MACRO( addPythonMod _name _srccpp )
  PYTHON_ADD_MODULE(${_name} ${_srccpp} src/beta.cpp )

  # make the pyd library link against boost_numpy python and boost
  TARGET_LINK_LIBRARIES(${_name} ${CommonLibs})
ENDMACRO()

SET( beta_diff_src
  src/main.cpp
  src/beta.cpp
)

SET( beta_diff_hdr
  src/beta.h
)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  MESSAGE(STATUS "Setting build type to 'Release' as none was specified.")
  SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
ENDIF()

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings -std=c++11" )

# global settings for include paths
INCLUDE_DIRECTORIES(
  "${PROJECT_SOURCE_DIR}/src"
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS} 
)

LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS} )
SET( CommonLibs
  boost_python
  ${Boost_LIBRARIES} ${PYTHON_LIBRARIES}
)

ADD_EXECUTABLE( beta_diff ${beta_diff_hdr} ${beta_diff_src} src/main.cpp )
TARGET_LINK_LIBRARIES( beta_diff ${CommonLibs} )

addPythonMod(beta_difference src/python.cpp src/beta.cpp )
