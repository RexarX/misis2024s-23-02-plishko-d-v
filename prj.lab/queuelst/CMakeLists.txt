add_library(queuelst queuelst.hpp queuelst.cpp)

set_property(TARGET queuelst PROPERTY CXX_STANDARD 20)

target_include_directories(queuelst PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS queuelst)

target_link_libraries(queuelst complex)