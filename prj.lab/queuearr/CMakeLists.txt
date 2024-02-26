add_library(queuearr queuearr.hpp queuearr.cpp)

set_property(TARGET queuearr PROPERTY CXX_STANDARD 20)

target_include_directories(queuearr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(queuearr complex)

install(TARGETS queuearr)