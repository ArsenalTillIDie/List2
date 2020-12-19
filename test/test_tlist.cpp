#include "utlist.h"

#include <gtest.h>

TEST(List, list_empty_upon_creation) {
	List<int> lst;
	ASSERT_TRUE(lst.empty());
}

TEST(List, can_access_front) {
	List<int> lst;
	lst.push_front(1);
	ASSERT_EQ(lst.front(), 1);
}

TEST(List, can_copy_empty_list) {
	List<int> lst;
	List<int> lst2(lst);
	ASSERT_TRUE(lst2.empty());
}

TEST(List, can_copy_list) {
	List<int> lst;
	lst.push_front(1);
	List<int> lst2(lst);
	ASSERT_EQ(lst2.front(), 1);
}

TEST(List, can_clear_list) {
	List<int> lst;
	lst.push_front(1);
	lst.push_front(2);
	lst.clear();
	ASSERT_TRUE(lst.empty());
}

TEST(List, can_insert) {
	List<int> lst;
	lst.push_front(1);
	lst.insert_after(2, lst.getFirst());
	lst.pop_front();
	ASSERT_EQ(lst.front(), 2);
}

TEST(List, can_erase) {
	List<int> lst;
	lst.push_front(1);
	lst.insert_after(2, lst.getFirst());
	lst.erase_after(lst.getFirst());
	lst.pop_front();
	ASSERT_TRUE(lst.empty());
}

TEST(List, iterator_works) {
	List<int> lst;
	Node<int>* current = nullptr;
	for (int i = 1; i <= 10; i++) {
		current = lst.insert_after(i, current);
	}
	int sum = 0;
	for (List<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		sum += it->data;
	}
	ASSERT_EQ(sum, 55);
}