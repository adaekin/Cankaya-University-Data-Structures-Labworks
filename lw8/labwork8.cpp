#include <iostream>
using namespace std;

class BTNode
{
	public:
		int data;
		BTNode* left;
		BTNode* right;
		BTNode(int d = -1) :data(d), left(nullptr), right(nullptr) {}
};
class BinaryTree {
public:
	BTNode* root;
	void printPreorder();
	void printInorder();
	void printPostorder();
	void printLevelorder();
	int CountNodes();
	void terminalNodes();
	int CountOdds();
	int LongestPath();
private:
	void Preorder(BTNode* node) {
		// print data, check left, check right
		cout << node->data << " ";
		if (node->left != nullptr) Preorder(node->left);
		if (node->right != nullptr) Preorder(node->right);
	}
	void Inorder(BTNode* node) {
		// check left, print data, check right
		if (node->left != nullptr) Inorder(node->left);
		cout << node->data << " ";
		if (node->right != nullptr) Inorder(node->right);
	}
	void Postorder(BTNode* node){
		// check left, check right, print data
		if (node->left != nullptr) Postorder(node->left);
		if (node->right != nullptr) Postorder(node->right);
		cout << node->data << " ";

	}
	int height(BTNode* node) {
		if (node == nullptr) return 0;
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
	void Levelorder(BTNode* node, int level) { // 4 satır varsa level 4 ten başlasa
		if (node == nullptr)return;
		if (level == 1) cout << node->data << " ";
		else if (level > 1) {
			Levelorder(node->left, level - 1);
			Levelorder(node->right, level - 1);
		}

	}
	int CountNodes(BTNode* node) {
		if (node == nullptr) return 0;
		int i = 0;
		if (node->left != nullptr) {
			i++;
			i += CountNodes(node->left);
		}
		if (node->right != nullptr) {
			i++;
			i += CountNodes(node->right);
		}
		return i;

	}
	void terminalNodes(BTNode* node) {
		if (node->left == nullptr && node->right == nullptr) cout << node->data << " ";
		else
		{
			if (node->left != nullptr) terminalNodes(node->left);
			if (node->right != nullptr) terminalNodes(node->right);
		}
	}
	int CountOdds(BTNode* node) {
		if (node == nullptr) return 0;
		int i = node->data % 2;
		if (node->left != nullptr) {
			i += CountOdds(node->left);
		}
		if (node->right != nullptr) {
			i += CountOdds(node->right);
		}
		return i;
	}
	int LongestPath(BTNode* node) {
		if (node == nullptr) return 0;
		int left = 1;
		int right = 1;
		if (node->left != nullptr) {
			left += LongestPath(node->left);
		}
		if (node->right != nullptr) {
			right += LongestPath(node->right);
		}
		if (left == right || left > right) return left;
		else return right;
	}
};


int main()
{
	//TASK 1: BUILD THE FOLLOWING BINARY TREE
	/*
	*				9
	*			   / \
	*             4   5
	*            / \   
	*            3  7
	*/
	BinaryTree myTree;
	myTree.root = new BTNode(9);
	myTree.root->right = new BTNode(5);
	myTree.root->left = new BTNode(4);
	myTree.root->left->right = new BTNode(7);
	myTree.root->left->left = new BTNode(3);
	//TASK 2: Write necessary recursive function to traverse and print the above binary tree in: a)Preorder b) Inorder c)Postorder d)Level Order Traversal
	cout << endl << "Preorder:"; // a)
	myTree.printPreorder();
	cout << endl << "Inorder:";  // b)
	myTree.printInorder(); 
	cout << endl << "Postorder:"; // c)
	myTree.printPostorder();
	cout << endl << "Level Traversal:"; // d)
	myTree.printLevelorder();
	//TASK 3: Write function that will return: a) Number of nodes of a given binary tree. b) Number of terminal(leaf) nodes of a given binary tree. c) Number of nodes 
	// that contain odd number as their data field of a given binary tree. d) The height or depth of a tree is defined to be the maximum level of any node in the tree. (depth=the
	//longest path from root to any leaf node).Write a function that will return height of a given binary tree.
	cout << endl << "Counted Nodes:" << myTree.CountNodes();// a)
	cout << endl << "Terminal Nodes:";
	myTree.terminalNodes(); // b)
	cout << endl << "Odd Nodes Count:" << myTree.CountOdds(); //c)
	cout << endl << "Longest Height:" << myTree.LongestPath(); //d
}

void BinaryTree::printPreorder()
{
	if (root == nullptr) return;
	Preorder(root);
}
void BinaryTree::printInorder()
{
	if (root == nullptr) return;
	Inorder(root);
}
void BinaryTree::printPostorder()
{
	if (root == nullptr) return;
	Postorder(root);
}
void BinaryTree::printLevelorder()
{

	int h = height(root);
	for (int i = 1; i <= h; i++) {
		Levelorder(root, i);
	}
}
int BinaryTree::CountNodes()
{

	return 1 + CountNodes(root);
}
void BinaryTree::terminalNodes() {
	terminalNodes(root);
}
int BinaryTree::CountOdds() {
	return CountOdds(root);
}
int BinaryTree::LongestPath() {
	return LongestPath(root);
}