#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SOCI::soci_core" for configuration "Debug"
set_property(TARGET SOCI::soci_core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/soci_core_4_0.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/soci_core_4_0.dll"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_core )
list(APPEND _cmake_import_check_files_for_SOCI::soci_core "${_IMPORT_PREFIX}/lib/soci_core_4_0.lib" "${_IMPORT_PREFIX}/bin/soci_core_4_0.dll" )

# Import target "SOCI::soci_core_static" for configuration "Debug"
set_property(TARGET SOCI::soci_core_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_core_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsoci_core_4_0.lib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_core_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_core_static "${_IMPORT_PREFIX}/lib/libsoci_core_4_0.lib" )

# Import target "SOCI::soci_empty" for configuration "Debug"
set_property(TARGET SOCI::soci_empty APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_empty PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/soci_empty_4_0.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "SOCI::soci_core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/soci_empty_4_0.dll"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_empty )
list(APPEND _cmake_import_check_files_for_SOCI::soci_empty "${_IMPORT_PREFIX}/lib/soci_empty_4_0.lib" "${_IMPORT_PREFIX}/bin/soci_empty_4_0.dll" )

# Import target "SOCI::soci_empty_static" for configuration "Debug"
set_property(TARGET SOCI::soci_empty_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_empty_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsoci_empty_4_0.lib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_empty_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_empty_static "${_IMPORT_PREFIX}/lib/libsoci_empty_4_0.lib" )

# Import target "SOCI::soci_odbc" for configuration "Debug"
set_property(TARGET SOCI::soci_odbc APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_odbc PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/soci_odbc_4_0.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "SOCI::soci_core;odbc32.lib;odbc32.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/soci_odbc_4_0.dll"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_odbc )
list(APPEND _cmake_import_check_files_for_SOCI::soci_odbc "${_IMPORT_PREFIX}/lib/soci_odbc_4_0.lib" "${_IMPORT_PREFIX}/bin/soci_odbc_4_0.dll" )

# Import target "SOCI::soci_odbc_static" for configuration "Debug"
set_property(TARGET SOCI::soci_odbc_static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SOCI::soci_odbc_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "odbc32.lib;odbc32.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsoci_odbc_4_0.lib"
  )

list(APPEND _cmake_import_check_targets SOCI::soci_odbc_static )
list(APPEND _cmake_import_check_files_for_SOCI::soci_odbc_static "${_IMPORT_PREFIX}/lib/libsoci_odbc_4_0.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
