# Install script for directory: C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SOCI")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/soci" TYPE FILE FILES
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/backend-loader.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/bind-values.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/blob-exchange.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/blob.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/boost-fusion.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/boost-gregorian-date.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/boost-optional.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/boost-tuple.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/callbacks.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/column-info.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/connection-parameters.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/connection-pool.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/error.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/exchange-traits.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/into-type.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/into.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/logger.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/noreturn.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/once-temp-type.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/prepare-temp-type.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/procedure.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/query_transformation.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/ref-counted-prepare-info.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/ref-counted-statement.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/row-exchange.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/row.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/rowid-exchange.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/rowid.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/rowset.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/session.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/soci-backend.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/soci-platform.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/soci-simple.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/soci.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/statement.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/transaction.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/type-conversion-traits.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/type-conversion.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/type-holder.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/type-ptr.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/type-wrappers.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/unsigned-types.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/use-type.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/use.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/values-exchange.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/values.h"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/include/soci/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/Debug/soci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/Release/soci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/MinSizeRel/soci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/RelWithDebInfo/soci_core_4_0.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/bin/Debug/soci_core_4_0.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/bin/Release/soci_core_4_0.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/bin/MinSizeRel/soci_core_4_0.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/bin/RelWithDebInfo/soci_core_4_0.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/Debug/libsoci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/Release/libsoci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/MinSizeRel/libsoci_core_4_0.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/lib/RelWithDebInfo/libsoci_core_4_0.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake"
         "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/SOCIConfig.cmake"
    "C:/Programming/HoseoServer/HoseoServer/trd/SOCI/soci-4.0.3/src/core/SOCIConfigVersion.cmake"
    )
endif()

