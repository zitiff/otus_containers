#include "../linkedlist.cpp"
#include <gtest/gtest.h>

TEST(linkedlist, creation) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    
    // Assert
    ASSERT_EQ(linkedListContainer.size(), 0);
}

TEST(linkedlist, push_back) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    linkedListContainer.push_back(30);

    // Assert
    EXPECT_EQ(linkedListContainer[0], 30);
}

TEST(linkedlist, push_front) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }
    linkedListContainer.insert(0, 10);

    // Assert
    EXPECT_EQ(linkedListContainer[0], 10);
}

TEST(linkedlist, push_half) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }
    int index = linkedListContainer.size()/2;
    linkedListContainer.insert(index, 20);

    // Assert
    EXPECT_EQ(linkedListContainer[index], 20);
}

TEST(linkedlist, delete_back) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }
    int index = linkedListContainer.size()-1;
    linkedListContainer.erase(index);

    // Assert
    EXPECT_EQ(linkedListContainer[(linkedListContainer.size()-1)], 8);
}

TEST(linkedlist, delete_front) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }
    
    linkedListContainer.erase(0);

    // Assert
    EXPECT_EQ(linkedListContainer[0], 1);
}

TEST(linkedlist, delete_half) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }

    linkedListContainer.erase(5);

    // Assert
    EXPECT_EQ(linkedListContainer[5], 6);
}

TEST(linkedlist, get_elements) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }

    // Assert
    EXPECT_EQ(linkedListContainer[0], 0);
    EXPECT_EQ(linkedListContainer[5], 5);
    EXPECT_EQ(linkedListContainer[9], 9);
}

TEST(linkedlist, get_size) {
    // Arrange
    LinkedListContainer<int> linkedListContainer;
    for (int value = 0; value < 10; value++)
    {
        linkedListContainer.push_back(value);
    }

    // Assert
    EXPECT_EQ(linkedListContainer.size(), 10);
}
