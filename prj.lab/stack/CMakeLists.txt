add_library(stack stack.hpp stack.cpp)

set_property(TARGET stack PROPERTY CXX_STANDARD 20)

target_include_directories(stack PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(stack complex)

install(TARGETS stack)