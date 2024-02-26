add_executable(test_complex test_complex.cpp)

add_executable(test_rational test_rational.cpp)

add_executable(test_dynarr test_dynarr.cpp)

add_executable(test_stack test_stack.cpp)

add_executable(test_stacklst test_stacklst.cpp)

add_executable(test_queuelst test_queuelst.cpp)

add_executable(test_queuearr test_queuearr.cpp)

target_link_libraries(test_complex complex)

target_link_libraries(test_rational rational)

target_link_libraries(test_dynarr dynarr)

target_link_libraries(test_stack stack)

target_link_libraries(test_stacklst stacklst)

target_link_libraries(test_queuelst queuelst)

target_link_libraries(test_queuearr queuearr)