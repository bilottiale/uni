#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int value;
} Node, *tree;

void init(tree *T){
    *T = NULL;
}

tree createNode(int value){
    tree newNode = (tree)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// vista in profondità
// pre-order
void preOrder(tree T){
    if(T){
        printf("%d\n", T->value);
        preOrder(T->left);
        preOrder(T->right);
    }
}

// in-order
void inOrder(tree T){
    if(T){
        inOrder(T->left);
        printf("%d\n", T->value);
        inOrder(T->right);
    }
}

// post-order
void postOrder(tree T){
    if(T){
        postOrder(T->left);
        postOrder(T->right);
        printf("%d\n", T->value);
    }
}

// vista in ampiezza
typedef struct StackNode {
    tree treeNode;
    struct StackNode *next;
} StackNode;

StackNode* createStackNode(tree treeNode){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

void push(StackNode** top, tree treeNode){
    StackNode* newNode = createStackNode(treeNode);
    newNode->next = *top;
    *top = newNode;
}

tree pop(StackNode** top){
    if(*top == NULL){
        return NULL;
    }
    StackNode* temp = *top;
    tree treeNode = temp->treeNode;
    *top = (*top)->next;
    free(temp);
    return treeNode;
}

int isStackEmpty(StackNode* top){
    return top == NULL;
}

void depthFirstTraversal(tree T){
    if(T == NULL){
        return;
    }
    StackNode* stack = NULL;
    push(&stack, T);
    while(!isStackEmpty(stack)){
        tree currentNode = pop(&stack);
        printf("%d\n", currentNode->value);
        if(currentNode->right){
            push(&stack, currentNode->right);
        }
        if(currentNode->left){
            push(&stack, currentNode->left);
        }
    }

}

int main(void) {
    tree MT;
    init(&MT);
    tree n1 = createNode(1);
    tree n2 = createNode(2);
    tree n3 = createNode(3);
    tree n4 = createNode(4);
    tree n5 = createNode(5);

    MT = n1;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    
    printf("Pre-order\n");
    preOrder(MT);
    printf("In-order\n");
    inOrder(MT);
    printf("Post-order\n");
    postOrder(MT);
    printf("Depth-First Traversal using Stack\n");
    depthFirstTraversal(MT);

    // Free memory (Note: proper memory management would require freeing all nodes)
    free(n5);
    free(n4);
    free(n3);
    free(n2);
    free(n1);

    return 0;
}