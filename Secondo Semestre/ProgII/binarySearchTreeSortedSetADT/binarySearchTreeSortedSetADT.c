#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sortedSetADT.h"

typedef struct treeNode TreeNode, *TreeNodePtr;

struct treeNode {
    void* elem;
    TreeNodePtr left, right;
};

struct sortedSetADT {
    TreeNodePtr root; /* Punta alla radice dell'albero, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
};

void stampaSet_rec(TreeNodePtr cur, void (*stampaelem)(void*)) {
    #ifdef DEBUG
    printf("( ");
    #endif
    if (cur) {
        stampaSet_rec(cur->left, stampaelem);
        (*stampaelem)(cur->elem);
        stampaSet_rec(cur->right, stampaelem);
    }
    #ifdef DEBUG
    printf(") ");
    #endif
}

// stampa i contenuti dell'insieme, data la funzione di stampa di un elemento
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d) ",ss->size);
        stampaSet_rec(ss->root, stampaelem);
        printf("\n");
    }
}

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
    SortedSetADTptr ss = (SortedSetADTptr) malloc(sizeof(SortedSetADT));
    if (ss) {
        ss->root = NULL;
        ss->compare = compare;
        ss->size = 0;
    }
    return ss;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
    if(ssptr == NULL){
        return false;
    }
    SortedSetADTptr ss = *ssptr;
    if(ss == NULL){
        return false;
    }
    TreeNodePtr cur = ss->root;
    while(cur){
        TreeNodePtr tmp = cur;
        cur = cur->right;
        free(tmp);
    }
    ss->root = NULL;
    ss->size = 0;
    free(ss);
    *ssptr = NULL;
    return true;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
    if(ss == NULL){
        return false;
    }
    TreeNodePtr cur = ss->root;
    TreeNodePtr prev = NULL;
    while(cur){
        int r = ss->compare(elem, cur->elem);
        if(r < 0){
            prev = cur;
            cur = cur->left;
        } else if(r > 0){
            prev = cur;
            cur = cur->right;
        } else {
            return false;
        }
    }
    TreeNodePtr new = (TreeNodePtr) malloc(sizeof(TreeNode));
    if(new == NULL){
        return false;
    }
    new->elem = elem;
    new->left = NULL;
    new->right = NULL;
    if(prev == NULL){
        ss->root = new;
    } else if(ss->compare(elem, prev->elem) < 0){
        prev->left = new;
    } else {
        prev->right = new;
    }
    ss->size++;
    return true;
}  

void sset_extractMin_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)){
    if(*cur == NULL){
        return;
    }
    if((*cur)->left == NULL){
        *ptr = (*cur)->elem;
        TreeNodePtr tmp = *cur;
        *cur = (*cur)->right;
        free(tmp);
    } else {
        sset_extractMin_rec(&((*cur)->left), ptr, compare);
    }
}

void sset_extractMax_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*)){
    if(*cur == NULL){
        return;
    }
    if((*cur)->right == NULL){
        *ptr = (*cur)->elem;
        TreeNodePtr tmp = *cur;
        *cur = (*cur)->left;
        free(tmp);
    } else {
        sset_extractMax_rec(&((*cur)->right), ptr, compare);
    }
}

// funzione ausiliaria che toglie un elemento da un sottoalbero
_Bool sset_remove_rec(TreeNodePtr* cur, void* elem, int (*compare)(void*, void*)) {
    if (*cur == NULL) return false;
    int r = compare(elem, (*cur)->elem);
    if (r < 0) return sset_remove_rec(&((*cur)->left), elem, compare);
    if (r > 0) return sset_remove_rec(&((*cur)->right), elem, compare);
    void* ptr;
    if ((*cur)->left == NULL) {
        sset_extractMin_rec(cur, &ptr, compare);
    } else if ((*cur)->right == NULL) {
        sset_extractMax_rec(cur, &ptr, compare);
    } else {
        sset_extractMax_rec(&((*cur)->left), &ptr, compare);
        (*cur)->elem = ptr;
    }
    return true;
}

// toglie un elemento all'insieme
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if (ss && sset_remove_rec(&(ss->root), elem, ss->compare)) {
        ss->size--;
        return true;
    }
    return false;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
    if(ss == NULL){
        return -1;
    }
    TreeNodePtr cur = ss->root;
    while(cur){
        int r = ss->compare(elem, cur->elem);
        if(r < 0){
            cur = cur->left;
        } else if(r > 0){
            cur = cur->right;
        } else {
            return 1;
        }
    }
    return 0;
}

// cerca un elemento nell'insieme che si compara uguale a quello dato, NULL se non trovato
void* sset_search(const SortedSetADT* ss, void* elem) {
    if(ss == NULL){
        return NULL;
    }
    TreeNodePtr cur = ss->root;
    while(cur){
        int r = ss->compare(elem, cur->elem);
        if(r < 0){
            cur = cur->left;
        } else if(r > 0){
            cur = cur->right;
        } else {
            return cur->elem;
        }
    }
    return NULL;
}

// controlla se l'insieme e' vuoto
int isEmptySSet(const SortedSetADT* ss) {
    if(ss == NULL){
        return -1;
    }
    return ss->size == 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
    if(ss == NULL){
        return -1;
    }
    return ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
    if(ss == NULL){
        return false;
    }
    if(ss->size == 0){
        return false;
    }
    sset_extractMin_rec(&(ss->root), ptr, ss->compare);
    ss->size--;
    return true;
} 

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if(s1 == NULL || s2 == NULL){
        return -1;
    }
    if(s1->size != s2->size){
        return 0;
    }
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    for(int i = 0; i < s1->size; i++){
        if(s1->compare(arr1[i], arr2[i]) != 0){
            free(arr1);
            free(arr2);
            return 0;
        }
    }
    free(arr1);
    free(arr2);
    return 1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL){
        return -1;
    }
    if(s1->size > s2->size){
        return 0;
    }
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    int i = 0;
    int j = 0;
    while(i < s1->size && j < s2->size){
        if(s1->compare(arr1[i], arr2[j]) == 0){
            i++;
        }
        j++;
    }
    free(arr1);
    free(arr2);
    return i == s1->size;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL){
        return -1;
    }
    if(s1->size >= s2->size){
        return 0;
    }
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    int i = 0;
    int j = 0;
    while(i < s1->size && j < s2->size){
        if(s1->compare(arr1[i], arr2[j]) == 0){
            i++;
        }
        j++;
    }
    free(arr1);
    free(arr2);
    return i == s1->size;
} 

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL){
        return NULL;
    }
    SortedSetADTptr res = mkSSet(s1->compare);
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    int i = 0;
    int j = 0;
    while(i < s1->size && j < s2->size){
        if(s1->compare(arr1[i], arr2[j]) < 0){
            sset_add(res, arr1[i]);
            i++;
        } else if(s1->compare(arr1[i], arr2[j]) > 0){
            j++;
        } else {
            i++;
            j++;
        }
    }
    while(i < s1->size){
        sset_add(res, arr1[i]);
        i++;
    }
    free(arr1);
    free(arr2);
    return res;
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL){
        return NULL;
    }
    SortedSetADTptr res = mkSSet(s1->compare);
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    int i = 0;
    int j = 0;
    while(i < s1->size && j < s2->size){
        if(s1->compare(arr1[i], arr2[j]) < 0){
            sset_add(res, arr1[i]);
            i++;
        } else if(s1->compare(arr1[i], arr2[j]) > 0){
            sset_add(res, arr2[j]);
            j++;
        } else {
            sset_add(res, arr1[i]);
            i++;
            j++;
        }
    }
    while(i < s1->size){
        sset_add(res, arr1[i]);
        i++;
    }
    while(j < s2->size){
        sset_add(res, arr2[j]);
        j++;
    }
    free(arr1);
    free(arr2);
    return res;
} 

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL){
        return NULL;
    }
    SortedSetADTptr res = mkSSet(s1->compare);
    void** arr1 = sset_toArray(s1);
    void** arr2 = sset_toArray(s2);
    int i = 0;
    int j = 0;
    while(i < s1->size && j < s2->size){
        if(s1->compare(arr1[i], arr2[j]) < 0){
            i++;
        } else if(s1->compare(arr1[i], arr2[j]) > 0){
            j++;
        } else {
            sset_add(res, arr1[i]);
            i++;
            j++;
        }
    }
    free(arr1);
    free(arr2);
    return res;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if(ss->root == NULL) {
        return false;
    }
    TreeNodePtr cur = ss->root;
    while(cur->left) {
        cur = cur->left;
    }
    *ptr = cur->elem;
    return true;
}


// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
    if (ss == NULL || ptr == NULL) {
        return false;
    }
    if (ss->root == NULL) {
        return false;
    }
    TreeNodePtr cur = ss->root;
    while (cur->right) {
        cur = cur->right;
    }
    *ptr = cur->elem;
    return true;
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
    if(ss == NULL){
        return false;
    }
    if(ss->size == 0){
        return false;
    }
    sset_extractMin_rec(&(ss->root), ptr, ss->compare);
    ss->size--;
    return true;
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
    if(ss == NULL){
        return false;
    }
    if(ss->size == 0){
        return false;
    }
    sset_extractMax_rec(&(ss->root), ptr, ss->compare);
    ss->size--;
    return true;
}

// crea un array con i contenuti del set in ordine di visita pre-order, NULL se errore
void** sset_toArray(const SortedSetADT* ss) {
    if(ss == NULL){
        return NULL;
    }
    void** arr = (void**) malloc(ss->size * sizeof(void*));
    if(arr == NULL){
        return NULL;
    }
    int i = 0;
    TreeNodePtr cur = ss->root;
    while(cur){
        if(cur->left == NULL){
            arr[i++] = cur->elem;
            cur = cur->right;
        } else {
            TreeNodePtr prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                arr[i++] = cur->elem;
                cur = cur->right;
            }
        }
    }
    return arr;
}
