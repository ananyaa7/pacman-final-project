get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../" ABSOLUTE)
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")
# include("${FinalProject_SOURCE_DIR}/cmake/make_cinder_library.cmake")


file(GLOB SOURCE_LIST CONFIGURE_DEPENDS
        "${FinalProject_SOURCE_DIR}/src/*.h"
        "${FinalProject_SOURCE_DIR}/src/*.hpp"
        "${FinalProject_SOURCE_DIR}/src/*.cc"
        "${FinalProject_SOURCE_DIR}/src/*.cpp")


ci_make_app(
        APP_NAME final-project
        CINDER_PATH  ${CINDER_PATH}
        SOURCES      ${SOURCE_LIST}
        INCLUDES     "${FinalProject_SOURCE_DIR}/include"
        LIBRARIES
        BLOCKS
)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})