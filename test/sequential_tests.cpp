#include "../sequential.cpp"
#include <gtest/gtest.h>

TEST(sequential, creation) {
    // Arrange
    SequentialContainer<int> sequentialContainer;

    // Assert
    ASSERT_EQ(sequentialContainer.size(), 0);
}

TEST(sequential, push_back) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    sequentialContainer.push_back(30);

    // Assert
    EXPECT_EQ(sequentialContainer[0], 30);
}

TEST(sequential, push_front) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }
    sequentialContainer.insert(0, 10);

    // Assert
    EXPECT_EQ(sequentialContainer[0], 10);
}

TEST(sequential, push_half) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }
    int index = sequentialContainer.size() / 2;
    sequentialContainer.insert(index, 20);

    // Assert
    EXPECT_EQ(sequentialContainer[index], 20);
}

TEST(sequential, delete_back) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }
    int index = sequentialContainer.size()-1;
    sequentialContainer.erase(index);

    // Assert
    EXPECT_EQ(sequentialContainer[(sequentialContainer.size()-1)], 8);
}

TEST(sequential, delete_front) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }

    sequentialContainer.erase(0);

    // Assert
    EXPECT_EQ(sequentialContainer[0], 1);
}

TEST(sequential, delete_half) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }

    sequentialContainer.erase(5);

    // Assert
    EXPECT_EQ(sequentialContainer[5], 6);
}

TEST(sequential, get_elements) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }

    // Assert
    EXPECT_EQ(sequentialContainer[0], 0);
    EXPECT_EQ(sequentialContainer[5], 5);
    EXPECT_EQ(sequentialContainer[9], 9);
}

TEST(sequential, get_size) {
    // Arrange
    SequentialContainer<int> sequentialContainer;
    for (int value = 0; value < 10; value++)
    {
        sequentialContainer.push_back(value);
    }

    // Assert
    EXPECT_EQ(sequentialContainer.size(), 10);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}