#include <stdbool.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool isValidBST(TreeNode* root) {
    // Implement the validation logic here
    if (root == NULL) {
        return true;
    }
    // Check the left subtree
    if (root->left != NULL && (root->left->val >= root->val || !isValidBST(root->left))) {
        return false;
    }
    // Check the right subtree
    if (root->right != NULL && (root->right->val <= root->val || !isValidBST(root->right))) {
        return false;
    }
    return true;
}

int main() {
    // Construct a binary tree
    TreeNode* root = malloc(sizeof(TreeNode));
    root->val = 2;
    root->left = malloc(sizeof(TreeNode));
    root->left->val = 1;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = malloc(sizeof(TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    // Test the isValidBST function
    bool isValid = isValidBST(root);
    if (isValid) {
        printf("The binary tree is a valid BST.\n");
    } else {
        printf("The binary tree is not a valid BST.\n");
    }

    // Free memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
