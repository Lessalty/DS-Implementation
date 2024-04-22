//A Binary Tree is a fundamental data structure in computer science, consisting of nodes, each having up to two children referred to as the left child 
// and the right child.It is a specialized form of a tree structure with properties that facilitate quick lookup, addition, and deletion of items.
//
//A Binary Search Tree(BST) is a type of binary tree where each node contains a key greater than all the keys in the node's left subtree and less 
// than those in its right subtree. This property makes BSTs efficient for operations like search, insert, and delete, all of which can be performed in 
//𝑂(log𝑛)
//
//    
//    ⁡
//    
//
//O(logn) time in average scenarios.


#include <iostream>

// Node structure for Binary Search Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a new node into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function to perform in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Helper function to delete a node from the BST
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function to find the node with the minimum value in the BST
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Public method to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to perform in-order traversal
    void inOrder() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    // Public method to delete a value from the BST
    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal of the BST: ";
    bst.inOrder();

    bst.remove(50);
    std::cout << "In-order traversal after deleting 50: ";
    bst.inOrder();

    return 0;
}
