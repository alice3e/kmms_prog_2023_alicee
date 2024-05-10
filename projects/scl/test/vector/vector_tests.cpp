//
// Created by Andrei Sulimov on 10.05.2024.
//
#include <gtest/gtest.h>
#include "vector.hpp"
#include "vector.cpp"


TEST(vector_push_back, once) {
	IBusko::Vector<int> vec;
	vec.push_back(1);
	ASSERT_EQ(1, vec.get_size())
		<< "Vector size error" << vec.get_size();
}


TEST(vector_insert, once) {
	IBusko::Vector<int> vec;
	vec.insert(0, 1);
	ASSERT_EQ(1, vec.get_size())
		<< "Vector size error" << vec.get_size();
}


TEST(vector_remove_first, once) {
	IBusko::Vector<int> vec;
	vec.push_back(1);
	vec.remove_first(1);
	ASSERT_EQ(0, vec.get_size())
		<< "Vector size error" << vec.get_size();
}

TEST(vector_remove_first, zero_tests) {
	IBusko::Vector<int> vec;
	vec.push_back(1);
	vec.remove_first(2);
	ASSERT_EQ(1, vec.get_size())
		<< "Vector size error" << vec.get_size();
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}