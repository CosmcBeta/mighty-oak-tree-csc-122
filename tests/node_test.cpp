#include "../src/node.hpp"
#include "../src/squirrel.hpp"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("Node can be created with a Squirrel")
{
	Squirrel squirrel("Nutkin");
	Node node(&squirrel);

	REQUIRE(node.getData()->getName() == "Nutkin");
}

TEST_CASE("Node starts with no left child")
{
	Squirrel squirrel("Nutkin");
	Node node(&squirrel);

	REQUIRE(node.left() == nullptr);
}

TEST_CASE("Node starts with no right child")
{
	Squirrel squirrel("Nutkin");
	Node node(&squirrel);

	REQUIRE(node.right() == nullptr);
}

TEST_CASE("Node can set left child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel left_child("LeftChild");
	Node leftNode(&left_child);

	parentNode.setLeft(&leftNode);

	REQUIRE(parentNode.left() != nullptr);
	REQUIRE(parentNode.left()->getData()->getName() == "LeftChild");
}

TEST_CASE("Node can set right child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel right_child("RightChild");
	Node rightNode(&right_child);

	parentNode.setRight(&rightNode);

	REQUIRE(parentNode.right() != nullptr);
	REQUIRE(parentNode.right()->getData()->getName() == "RightChild");
}

TEST_CASE("Node can have both left and right children")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel left_child("LeftChild");
	Node leftNode(&left_child);

	Squirrel right_child("RightChild");
	Node rightNode(&right_child);

	parentNode.setLeft(&leftNode);
	parentNode.setRight(&rightNode);

	REQUIRE(parentNode.left()->getData()->getName() == "LeftChild");
	REQUIRE(parentNode.right()->getData()->getName() == "RightChild");
}

TEST_CASE("Binary tree with three levels can be created")
{
	Squirrel root_squirrel("Root");
	Node root(&root_squirrel);

	Squirrel left_squirrel("Left");
	Node left(&left_squirrel);

	Squirrel right_squirrel("Right");
	Node right(&right_squirrel);

	Squirrel left_left_squirrel("LeftLeft");
	Node left_left(&left_left_squirrel);

	Squirrel left_right_squirrel("LeftRight");
	Node left_right(&left_right_squirrel);

	root.setLeft(&left);
	root.setRight(&right);
	left.setLeft(&left_left);
	left.setRight(&left_right);

	REQUIRE(root.left()->getData()->getName() == "Left");
	REQUIRE(root.right()->getData()->getName() == "Right");
	REQUIRE(root.left()->left()->getData()->getName() == "LeftLeft");
	REQUIRE(root.left()->right()->getData()->getName() == "LeftRight");
}

TEST_CASE("Node can access grandchildren")
{
	Squirrel grandparent("Grandparent");
	Node grandparentNode(&grandparent);

	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel child("Child");
	Node childNode(&child);

	grandparentNode.setLeft(&parentNode);
	parentNode.setLeft(&childNode);

	REQUIRE(grandparentNode.left()->left()->getData()->getName() == "Child");
}

TEST_CASE("Node with only left child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel left_child("LeftChild");
	Node leftNode(&left_child);

	parentNode.setLeft(&leftNode);

	REQUIRE(parentNode.left() != nullptr);
	REQUIRE(parentNode.right() == nullptr);
}

TEST_CASE("Node with only right child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel right_child("RightChild");
	Node rightNode(&right_child);

	parentNode.setRight(&rightNode);

	REQUIRE(parentNode.left() == nullptr);
	REQUIRE(parentNode.right() != nullptr);
}

TEST_CASE("Complete binary tree structure")
{
	Squirrel root_squirrel("Root");
	Node root(&root_squirrel);

	Squirrel left_squirrel("Left");
	Node left(&left_squirrel);

	Squirrel right_squirrel("Right");
	Node right(&right_squirrel);

	Squirrel ll_squirrel("LL");
	Node ll(&ll_squirrel);

	Squirrel lr_squirrel("LR");
	Node lr(&lr_squirrel);

	Squirrel rl_squirrel("RL");
	Node rl(&rl_squirrel);

	Squirrel rr_squirrel("RR");
	Node rr(&rr_squirrel);

	root.setLeft(&left);
	root.setRight(&right);
	left.setLeft(&ll);
	left.setRight(&lr);
	right.setLeft(&rl);
	right.setRight(&rr);

	REQUIRE(root.left()->left()->getData()->getName() == "LL");
	REQUIRE(root.left()->right()->getData()->getName() == "LR");
	REQUIRE(root.right()->left()->getData()->getName() == "RL");
	REQUIRE(root.right()->right()->getData()->getName() == "RR");
}

TEST_CASE("Leaf node has no children")
{
	Squirrel leaf("Leaf");
	Node leafNode(&leaf);

	REQUIRE(leafNode.left() == nullptr);
	REQUIRE(leafNode.right() == nullptr);
}

TEST_CASE("Can create unbalanced tree")
{
	Squirrel root_squirrel("Root");
	Node root(&root_squirrel);

	Squirrel left1("Left1");
	Node left1Node(&left1);

	Squirrel left2("Left2");
	Node left2Node(&left2);

	Squirrel left3("Left3");
	Node left3Node(&left3);

	root.setLeft(&left1Node);
	left1Node.setLeft(&left2Node);
	left2Node.setLeft(&left3Node);

	REQUIRE(root.left()->left()->left()->getData()->getName() == "Left3");
	REQUIRE(root.right() == nullptr);
}

TEST_CASE("Can update left child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel first_child("FirstChild");
	Node firstNode(&first_child);

	Squirrel second_child("SecondChild");
	Node secondNode(&second_child);

	parentNode.setLeft(&firstNode);
	parentNode.setLeft(&secondNode);

	REQUIRE(parentNode.left()->getData()->getName() == "SecondChild");
}

TEST_CASE("Can update right child")
{
	Squirrel parent("Parent");
	Node parentNode(&parent);

	Squirrel first_child("FirstChild");
	Node firstNode(&first_child);

	Squirrel second_child("SecondChild");
	Node secondNode(&second_child);

	parentNode.setRight(&firstNode);
	parentNode.setRight(&secondNode);

	REQUIRE(parentNode.right()->getData()->getName() == "SecondChild");
}
