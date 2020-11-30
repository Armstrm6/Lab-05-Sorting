// tests.cpp
#include "BinaryTree.h"
#include <gtest/gtest.h>


	TEST(EmptyTest, PositiveTest){
		BinaryNodeTree tree1;
		ASSERT_TRUE(tree1.isEmpty());
	}
	TEST(EmptyTest, NegativeTest){
		BinaryNodeTree tree1;
		tree1.add("randVal");
		ASSERT_FALSE(tree1.isEmpty());
	}
	TEST(TreeHeight, PositiveTest){
		BinaryNodeTree tree1;
		tree1.add("rand");
		tree1.add("rand2");
		tree1.add("rand3");
		ASSERT_EQ(3, tree1.getHeight());
	}
	TEST(TreeHeight, NegativeTest){
		BinaryNodeTree tree1;
		tree1.add("rand");
		tree1.add("rand2");
		ASSERT_FALSE(0==tree1.getHeight());
	}
	TEST(Find, PositiveTest){
		BinaryNodeTree tree1;
		tree1.add("fakeval1");
		tree1.add("fakeVal2");
		tree1.add("targetVal");
		tree1.add("fakeVal3");
		ASSERT_EQ("targetVal", tree1.Find(tree1.getRoot(), "targetVal"));
	}
 	TEST(Find, NegativeTest){
		BinaryNodeTree tree1;
		tree1.add("fakeval1");
		tree1.add("fakeVal2");
		tree1.add("targetVal");
		tree1.add("fakeVal3");
		ASSERT_FALSE(tree1.Find(tree1.getRoot(), "not here") != nullptr);
	}
	TEST(Ascending, PositiveTest){
		BinaryNodeTree tree1;
		std::vector<std::string> storage;
		tree1.add("star wars");
		tree1.add("Star Trek");
		tree1.add("Space Balls");
		tree1.add("Galaxy Quest");
		storage = tree1.getAllAscending(tree1.getRoot());
		ASSERT_EQ("Space Balls" , storage.at(1));
	}
	TEST(Ascending, NegativeTest){
		BinaryNodeTree tree1;
		std::vector<std::string> storage;
		tree1.add("Cars");
		tree1.add("Monster's Inc.");
		tree1.add("The Incredibles");
		tree1.add("Wall-E");
		storage = tree1.getAllAscending(tree1.getRoot());
		ASSERT_FALSE(storage.at(2)!="The Incredibles");
	}
	TEST(Descenging, PositiveTest){
		BinaryNodeTree tree1;
		std::vector<std::string> storage;
		tree1.add("Halloween");
		tree1.add("Beetle Juice");
		tree1.add("Hocus Pocus");
		tree1.add("A Nightmare On Elm's Street");
		storage = tree1.getAllDescending(tree1.getRoot());
		ASSERT_EQ("Halloween", storage.at(1));
	}
	TEST(Descenging, NegativeTest){
		BinaryNodeTree tree1;
		std::vector<std::string> storage;
		tree1.add("Halloween");
		tree1.add("Beetle Juice");
		tree1.add("Hocus Pocus");
		tree1.add("A Nightmare On Elm's Street");
		storage = tree1.getAllDescending(tree1.getRoot());
		ASSERT_TRUE("Halloween"!=storage.at(1));
	}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
