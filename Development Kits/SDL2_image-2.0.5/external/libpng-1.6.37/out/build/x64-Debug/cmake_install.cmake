# Install script for directory: C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/install/x64-Debug")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/libpng16d.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/libpng16d.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/libpng16_staticd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/png.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/pngconf.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/pnglibconf.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libpng16" TYPE FILE FILES
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/png.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/pngconf.h"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/pnglibconf.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/pngfix.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/png-fix-itxt.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man3" TYPE FILE FILES
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/libpng.3"
    "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/libpngpf.3"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man5" TYPE FILE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/png.5")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpng/libpng16.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpng/libpng16.cmake"
         "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/CMakeFiles/Export/lib/libpng/libpng16.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpng/libpng16-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpng/libpng16.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/libpng" TYPE FILE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/CMakeFiles/Export/lib/libpng/libpng16.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/libpng" TYPE FILE FILES "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/CMakeFiles/Export/lib/libpng/libpng16-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/admin/C++/ThePlanet/Development Kits/SDL2_image-2.0.5/external/libpng-1.6.37/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
