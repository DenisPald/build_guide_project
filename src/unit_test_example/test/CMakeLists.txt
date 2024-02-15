set(SOURCES 
	test_bubble_sort.cpp
)

add_executable(test_bubble_sort ${SOURCES})
target_link_libraries(test_bubble_sort 
	gtest_main 
	gmock_main 
	bubble_sort_lib
)

add_test(test_bubble_sort test_bubble_sort)
