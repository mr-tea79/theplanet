# Install script for directory: F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9

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
   "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib/pkgconfig/libtiff-4.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/install/x64-Debug (default)/lib/pkgconfig" TYPE FILE FILES "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff-4.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/port/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/libtiff/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/tools/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/test/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/contrib/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/build/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/man/cmake_install.cmake")
  include("F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/html/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "F:/Microsoft/Repos/theplanet/Development Kits/SDL2_image-2.0.5/external/tiff-4.0.9/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
