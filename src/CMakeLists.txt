add_library(tools STATIC "")
target_sources(tools
  PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/filetool.cpp
      ${CMAKE_CURRENT_LIST_DIR}/timetool.cpp
      ${CMAKE_CURRENT_LIST_DIR}/stringtool.cpp
      ${CMAKE_CURRENT_LIST_DIR}/systemtool.cpp
      
)



set_target_properties(tools
  PROPERTIES
    CXX_STANDARD 17
    POSITION_INDEPENDENT_CODE 1
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME "tools"
    DEBUG_POSTFIX "_d"
    PUBLIC_HEADER "filetool.h;ClassInstance.h;timetool.h;stringtool.h;systemtool.h"
    MACOSX_RPATH ON
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)

find_package(OpenSSL REQUIRED)
set(DEP_LIBS
  OpenSSL::Crypto
)

target_compile_options(tools PUBLIC "--std=c++17")
target_link_libraries(tools PUBLIC "-lstdc++fs")
target_link_libraries(tools PUBLIC ${DEP_LIBS})




add_executable(tooltest main.cpp)

target_link_libraries(tooltest
  PUBLIC
  tools
)

target_compile_options(tooltest PRIVATE "--std=c++17")
target_link_libraries(tooltest PRIVATE "-lstdc++fs")



file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${INSTALL_BINDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
    set(_rpath "@loader_path/${_rel}")
else()
    set(_rpath "\$ORIGIN/${_rel}")
endif()
file(TO_NATIVE_PATH "${_rpath}/${INSTALL_LIBDIR}" tools_RPATH)

set_target_properties(tooltest
  PROPERTIES
    MACOSX_RPATH ON
    SKIP_BUILD_RPATH OFF
    BUILD_WITH_INSTALL_RPATH OFF
    INSTALL_RPATH "${tools_RPATH}"
    INSTALL_RPATH_USE_LINK_PATH ON
)



set(USE_OPENSSL ON)


install(
  TARGETS
      tools
  EXPORT tools
  ARCHIVE
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
  RUNTIME
    DESTINATION ${INSTALL_BINDIR}
    COMPONENT bin
  LIBRARY
    DESTINATION ${INSTALL_LIBDIR}
    COMPONENT lib
  PUBLIC_HEADER
    DESTINATION ${INSTALL_INCLUDEDIR}/tools
    COMPONENT dev
  
)
