#pragma once



struct binaryTree
{
    int data;
    binaryTree* rightNode;
    binaryTree* leftNode;
};


binaryTree* createNode(int data_);
int deleteNode(binaryTree* node);
int deleteTree(binaryTree* root);
int insertNode(binaryTree* root, int data_);  //insert node with level order traversal
int printTree(binaryTree* root);
int printLevelOrder(binaryTree* root);
int printLevelOrderReverse(binaryTree* root);
int treeSize(binaryTree* root);    //with recursion
int treeSize2(binaryTree* root);   //without recursion
int findMaxElement(binaryTree* root);



