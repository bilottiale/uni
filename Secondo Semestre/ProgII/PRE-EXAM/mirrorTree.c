#include <stdlib.h>
#include <stdio.h>

typedef struct IntNode
{
    int value;
    struct IntNode *left;
    struct IntNode *right;
} IntNode;

typedef IntNode *IntTree;

// @brief Trasforma un albero nella sua versione speculare.*/
void mirror(IntTree tree)
{
    if (tree)
    {
        IntTree temp = tree->left;

        tree->left = tree->right;
        tree->right = temp;

        mirror(tree->left);
        mirror(tree->right);
    }
}

int main()
{
    IntNode n1 = {1, NULL, NULL};
    IntNode n2 = {2, NULL, NULL};
    IntNode n3 = {3, NULL, NULL};
    IntNode n4 = {4, NULL, NULL};
    IntNode n5 = {5, NULL, NULL};
    IntNode n6 = {6, NULL, NULL};
    IntNode n7 = {7, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    IntTree tree = &n1;

    printf("Root: %d\n", tree->value);
    printf("Left: %d\n", tree->left->value);
    printf("Right: %d\n", tree->right->value);

    mirror(tree);

    printf("Root: %d\n", tree->value);
    printf("Left: %d\n", tree->left->value);
    printf("Right: %d\n", tree->right->value);

    return 0;
}
