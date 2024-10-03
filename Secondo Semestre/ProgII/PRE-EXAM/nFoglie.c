#include<stdlib.h>
#include<stdio.h>

typedef struct charTreeNode CharTreeNode, *CharTree;

struct charTreeNode {
    CharTree left;
    char data;
    CharTree right;
};

/*
* @brief Dato un albero binario restituisce:
*  il numero di foglie (se l’albero è vuoto, restituisce 0).
*/

int nfoglie(CharTree tree){
    if(tree == NULL){
        return 0;
    }
    if(tree->left == NULL && tree->right == NULL){
        return 1;
    }
    return nfoglie(tree->left) + nfoglie(tree->right);
}

int main(){
    CharTree tree = (CharTree)malloc(sizeof(CharTreeNode));
    tree->data = 'A';
    tree->left = (CharTree)malloc(sizeof(CharTreeNode));
    tree->left->data = 'B';
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->right = (CharTree)malloc(sizeof(CharTreeNode));
    tree->right->data = 'C';
    tree->right->left = (CharTree)malloc(sizeof(CharTreeNode));
    tree->right->left->data = 'D';
    tree->right->left->left = NULL;
    tree->right->left->right = NULL;
    tree->right->right = (CharTree)malloc(sizeof(CharTreeNode));
    tree->right->right->data = 'E';
    tree->right->right->left = NULL;
    tree->right->right->right = NULL;

    printf("Numero di foglie: %d\n", nfoglie(tree));

    return 0;
}
