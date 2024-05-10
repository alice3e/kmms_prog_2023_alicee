//
// Created by Andrei Sulimov on 10.05.2024.
//
#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"
#include "doubly_linked_list.cpp"


TEST(deque_list_push_back, one_time_test) {
	IBusko::DoublyLinkedList<int> list;
	list.push_back(1);
	ASSERT_EQ(1, list.size()) << "Size error" << list.size();
}


TEST(deque_list_push_back, two_time_tests) {
	IBusko::DoublyLinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	ASSERT_EQ(2, list.size()) << "Size error" << list.size();
}


TEST(deque_list_remove_first, one_time_test) {
	IBusko::DoublyLinkedList<int> list;
	list.push_back(1);
	list.remove_first(1);
	ASSERT_EQ(0, list.size()) << "Size error" << list.size();
}


TEST(deque_list_remove_first, zero_tests) {
	IBusko::DoublyLinkedList<int> list;
	list.push_back(1);
	list.remove_first(0);
	ASSERT_EQ(1, list.size()) << "Size error" << list.size();
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}