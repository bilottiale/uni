#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// Function to create a new node with given data
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with given data in the binary search tree
TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum element in the binary search tree
int findMin(TreeNode *root)
{
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum element in the binary search tree
int findMax(TreeNode *root)
{
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Function to merge two binary search trees
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
{
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    t1->data += t2->data;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

// Function to perform pre-order traversal of the binary search tree
void preOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the binary search tree
void postOrderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to count the number of leaf nodes in the binary search tree
int nFoglie(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return nFoglie(root->left) + nFoglie(root->right);
}

// Function to print the binary search tree
void printTree(TreeNode *root, int space)
{
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
    TreeNode *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Minimum element in the tree: %d\n", findMin(root));
    printf("Maximum element in the tree: %d\n", findMax(root));

    TreeNode *root2 = NULL;
    root2 = insert(root2, 20);
    insert(root2, 25);
    insert(root2, 30);
    insert(root2, 35);
    insert(root2, 40);
    insert(root2, 45);
    insert(root2, 50);

    printf("In-order Traversal: ");
    inOrderTraversal(root2);
    printf("\n");

    printf("Minimum element in the tree: %d\n", findMin(root2));
    printf("Maximum element in the tree: %d\n", findMax(root2));

    printTree(root, 0);

    TreeNode *mergedTree = mergeTrees(root, root2);

    printf("In-order Traversal of merged tree: ");
    inOrderTraversal(mergedTree);
    printf("\n");

    printf("Merged Tree:\n");
    printTree(mergedTree, 0);

    printf("Number of leaf nodes in the merged tree: %d\n", nFoglie(mergedTree));

    free(root);
    free(root2);

    return 0;
}
