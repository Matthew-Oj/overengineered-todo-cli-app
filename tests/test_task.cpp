#include <gtest/gtest.h>
#include "task.h"

// Test that a newly created task is incomplete
TEST(TaskTest, InitiallyIncomplete) {
    Task task("Test task");
    EXPECT_FALSE(task.isComplete());
}

// Test marking a task complete
TEST(TaskTest, MarkComplete) {
    Task task("Test task");
    task.toggleComplete();
    EXPECT_TRUE(task.isComplete());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
