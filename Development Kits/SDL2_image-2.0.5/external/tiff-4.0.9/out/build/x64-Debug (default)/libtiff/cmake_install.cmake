# Install script for directory: F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib/tiffd.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/tiffd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/bin/tiffd.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/bin" TYPE SHARED_LIBRARY FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/tiffd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include/tiff.h;F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include/tiffio.h;F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include/tiffvers.h;F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include/tiffconf.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include" TYPE FILE FILES
    "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiff.h"
    "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffio.h"
    "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffvers.h"
    "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/tiffconf.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib/tiffxxd.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/tiffxxd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/bin/tiffxxd.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/bin" TYPE SHARED_LIBRARY FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/tiffxxd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include/tiffio.hxx")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/include" TYPE FILE FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffio.hxx")
endif()

