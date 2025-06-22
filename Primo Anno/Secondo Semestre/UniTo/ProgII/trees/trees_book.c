#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// struttura autoreferenziale
struct treeNode{
    struct treeNode *leftPtr; // puntatore al sottoalbero sinistro
    int data; // valore del nodo
    struct treeNode *rightPtr; // puntatore al sottoalbero destro
};

typedef struct treeNode TreeNode; // sinonimo di struct treeNode
typedef TreeNode *TreeNodePtr; // sinonimo di TreeNode*

// prototipi
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);


int main(void){
    TreeNodePtr rootPtr = NULL; // albero inizialmente vuoto

    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    // inserisce valori casuali nell'albero
    for(size_t i = 1; i <= 10; i++){
        int item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    // attraversa l'albero in ordine
    puts("\n\nThe preOrder traversal is:");
    preOrder(rootPtr);

    // attraversa l'albero in preordine
    puts("\n\nThe inOrder traversal is:");
    inOrder(rootPtr);

    // attraversa l'albero in postordine
    puts("\n\nThe postOrder traversal is:");
    postOrder(rootPtr);
}

// inserisce un nodo nell'albero
void insertNode(TreeNodePtr *treePtr, int value){
    // se l'albero è vuoto
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));

        // se l'allocazione è riuscita
        if(*treePtr != NULL){
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%d not inserted. No memory available.\n", value);
        }
    } else {
        // dati da inserire sono minori del nodo corrente
        if(value < (*treePtr)->data){
            insertNode(&((*treePtr)->leftPtr), value);
        } else if(value > (*treePtr)->data){
            insertNode(&((*treePtr)->rightPtr), value);
        } else {
            printf("dup");
        }
    }
}

// inizia l'attraversamento in ordine dell'albero
void inOrder(TreeNodePtr treePtr){
    // se l'albero non è vuoto
    if(treePtr != NULL){
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

// inizia l'attraversamento in pre-ordine dell'albero
void preOrder(TreeNodePtr treePtr){
    // se l'albero non è vuoto
    if(treePtr != NULL){
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// inizia l'attraversamento in post-ordine dell'albero
void postOrder(TreeNodePtr treePtr){
    // se l'albero non è vuoto
    if(treePtr != NULL){
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}
