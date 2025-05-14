# cmake/FindMuPDF.cmake

# 查找头文件
find_path(MUPDF_INCLUDE_DIR
        NAMES mupdf/fitz.h
        PATHS
        ${MUPDF_ROOT}/include
        $ENV{MUPDF_ROOT}/include
        /usr/include
        /usr/local/include
        /opt/local/include
        PATH_SUFFIXES mupdf
        DOC "MuPDF 头文件目录"
)

# 查找库文件
find_library(MUPDF_LIBRARY
        NAMES mupdf
        PATHS
        ${MUPDF_ROOT}/lib
        $ENV{MUPDF_ROOT}/lib
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        DOC "MuPDF 主库"
)

find_library(MUPDF_THIRD_LIBRARY
        NAMES mupdf-third
        PATHS
        ${MUPDF_ROOT}/lib
        $ENV{MUPDF_ROOT}/lib
        /usr/lib
        /usr/local/lib
        /opt/local/lib
        DOC "MuPDF 第三方依赖库"
)

# 设置库列表
set(MUPDF_LIBRARIES ${MUPDF_LIBRARY} ${MUPDF_THIRD_LIBRARY})

# 检查组件
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MuPDF
        DEFAULT_MSG
        MUPDF_INCLUDE_DIR
        MUPDF_LIBRARY
)

# 标记为高级变量
mark_as_advanced(MUPDF_INCLUDE_DIR MUPDF_LIBRARY MUPDF_THIRD_LIBRARY)

# 创建导入目标
if(MUPDF_FOUND AND NOT TARGET MuPDF::MuPDF)
    add_library(MuPDF::MuPDF UNKNOWN IMPORTED)
    set_target_properties(MuPDF::MuPDF PROPERTIES
            IMPORTED_LOCATION "${MUPDF_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${MUPDF_INCLUDE_DIR}"
    )
    if(MUPDF_THIRD_LIBRARY)
        set_property(TARGET MuPDF::MuPDF APPEND PROPERTY
                INTERFACE_LINK_LIBRARIES "${MUPDF_THIRD_LIBRARY}"
        )
    endif()
endif()
