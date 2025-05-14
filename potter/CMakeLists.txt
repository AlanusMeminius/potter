
add_library(${PROJECT_NAME} SHARED)


set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC
        "${SOURCE_DIR}/*.cpp"
        "${SOURCE_DIR}/*.h"
)

file(GLOB_RECURSE HEADER
        "${INCLUDE_DIR}/*.h"
)

source_group(include FILES ${HEADER})

target_sources(
        ${PROJECT_NAME}
        PRIVATE
        ${SRC}
        ${RESOURCES}
        ${HEADER}
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        AUTOMOC ON
        AUTORCC ON
        OUTPUT_NAME ${PROJECT_NAME}
        PROJECT_LABEL ${PROJECT_NAME}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        IMPORTED_CONFIGURATIONS "RELEASE;DEBUG"
        DEBUG_POSTFIX _debug
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

if (USE_MUPDF)
    message(=======Using MuPDF======)
    target_link_libraries(${PROJECT_NAME} PRIVATE MuPDF::MuPDF)
endif ()

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)


include(GNUInstallDirs)
include(Installing)

include(GenerateExportHeader)
generate_export_header(
        ${PROJECT_NAME}
        EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/potterExport.h"
)
install(
        FILES ${PROJECT_BINARY_DIR}/potterExport.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)