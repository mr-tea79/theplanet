# Install script for directory: C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug")
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
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/lib/tiffd.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug/libtiff/tiffd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/bin/tiffd.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/bin" TYPE SHARED_LIBRARY FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug/libtiff/tiffd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include/tiff.h;C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include/tiffio.h;C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include/tiffvers.h;C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include/tiffconf.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include" TYPE FILE FILES
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiff.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffio.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffvers.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug/libtiff/tiffconf.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/lib/tiffxxd.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug/libtiff/tiffxxd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/bin/tiffxxd.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/bin" TYPE SHARED_LIBRARY FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug/libtiff/tiffxxd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include/tiffio.hxx")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug/include" TYPE FILE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/libtiff/tiffio.hxx")
endif()

