add_executable(vec_tests vector_tests.cpp)

target_link_libraries(vec_tests
	gtest_main
	gmock_main
	scl_lib
)

add_test(vec_tests vec_tests)