#include "../Queue/Queue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, cant_create_queue_with_negatitive_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-10));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue<int> s(MAX_QUEUE_SIZE + 1));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(10);
	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> q(10);
	TQueue<int> q1(q);
	EXPECT_EQ(q, q1);
}

TEST(TQueue, can_set_and_get_element)
{
	TQueue<int> q(10);
	ASSERT_NO_THROW(q.push(5));
	EXPECT_EQ(q.front(), 5);
	EXPECT_EQ(q.back(), 5);
	EXPECT_EQ(q.pop(), 5);
}

TEST(TQueue, can_delete_element)
{
	TQueue<int> q(5);
	q.push(1);
	q.push(2);
	q.pop();
	EXPECT_EQ(q.pop(), 2);
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> q(5); 
	for (int i = 0; i < q.GetMaxSize(); i++) {
		q.push(i);
	}
	q.clear();
	EXPECT_TRUE(q.isEmpty());
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q(4);
	ASSERT_NO_THROW(q = q);
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
	const int size = 4;
	TQueue<int> q1(size), q2(size);
	for (int i = 0; i < size; i++) {
		q1.push(1);
		q2.push(2);
	}
	ASSERT_NO_THROW(q1 = q2);
}

TEST(TQueue, assign_operator_change_queue_size)
{
	const int size1 = 4, size2 = 10;
	TQueue<int> q1(size1), q2(size2);
	q2.push(5);
	q1 = q2;
	EXPECT_EQ(10, q1.GetMaxSize());
	EXPECT_EQ(1, q1.GetCurrentSize());
}

TEST(TQueue, can_assign_queues_of_different_size)
{
	const int size1 = 5, size2 = 10;
	TQueue<int> q1(size1), q2(size2);
	for (int i = 0; i < size1; i++)
	{
		q1.push(i);
	}
	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q2, q1);
}

TEST(TQueue, compare_equal_stacks_with_same_head_and_tail_return_true)
{
	const int size = 10;
	TQueue<int> q1(size), q2(size);
	for (int i = 0; i < size; i++) {
		q1.push(i);
		q2.push(i);
	}
	EXPECT_TRUE(q1 == q2);
}

TEST(TQueue, compare_equal_stacks_with_different_head_and_tail_return_true)
{
	const int size = 10;
	TQueue<int> q1(size), q2(size);
	for (int i = 0; i < 5; i++) {
		q1.push(i);
	}
	q2.push(1);
	q2.push(2);
	for (int i = 0; i < 5; i++) {
		q2.push(i);
	}
	q2.pop();
	q2.pop();
	EXPECT_TRUE(q1 == q2);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
	const int size = 10;
	TQueue<int> q1(size);
	EXPECT_TRUE(q1 == q1);
}

TEST(TQueue, queues_with_different_size_are_not_equal)
{
	const int size1 = 5, size2 = 10;
	TQueue<int> q1(size1), q2(size2);
	for (int i = 0; i < size1; i++) q1.push(i);
	for (int j = 0; j < size2; j++) q2.push(j);
	EXPECT_TRUE(q1 != q2);
}

TEST(TQueue, when_queue_is_full_cant_set_element)
{
	const int size = 5;
	TQueue<int> q(size);
	for (int i = 0; i < size; i++) {
		q.push(i);
	}
	ASSERT_ANY_THROW(q.push(10));
}

TEST(TQueue, when_queue_is_empty_cant_get_element)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop());
}