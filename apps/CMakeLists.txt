get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../" ABSOLUTE)
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

file(GLOB SOURCE_LIST CONFIGURE_DEPENDS
        "${FinalProject_SOURCE_DIR}/apps/*.h"
        "${FinalProject_SOURCE_DIR}/apps/*.hpp"
        "${FinalProject_SOURCE_DIR}/apps/*.cc"
        "${FinalProject_SOURCE_DIR}/apps/*.cpp")


ci_make_app(
        APP_NAME    cinder-myapp
        CINDER_PATH ${CINDER_PATH}
        SOURCES     ${SOURCE_LIST}
        LIBRARIES   mylibrary gflags sqlite-modern-cpp sqlite3
        BLOCKS      Choreograph
)
