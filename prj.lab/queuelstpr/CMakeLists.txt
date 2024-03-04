add_library(queuelstpr queuelstpr.hpp queuelstpr.cpp)

set_property(TARGET queuelstpr PROPERTY CXX_STANDARD 20)

target_include_directories(queuelstpr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(queuelstpr complex)

install(TARGETS queuelstpr)