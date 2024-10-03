#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sortedSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   void* elem;
   ListNodePtr next;
};

struct sortedSetADT {
    ListNodePtr first; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    ListNodePtr last; /* Punta all'ultimo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
};

// for debug: stampa un insieme
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    ListNodePtr cur;
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d)", ss->size);
        for(cur = ss->first; cur; cur=cur->next) (*stampaelem)(cur->elem);
        printf("\n");
    }
}    

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
    SortedSetADTptr ss = (SortedSetADTptr)malloc(sizeof(SortedSetADT));
    if(ss != NULL) {
        ss->first = NULL;
        ss->last = NULL;
        ss->compare = compare;
        ss->size = 0;
    }
    return ss;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
    if(ssptr == NULL || *ssptr == NULL){
        return false;
    }
    SortedSetADTptr ss = *ssptr;
    ListNodePtr current = ss->first;
    while (current != NULL) {
        ListNodePtr temp = current;
        current = current->next;
        free(temp);
    }
    ss->first = NULL;
    ss->last = NULL;
    ss->size = 0;
    free(ss);
    *ssptr = NULL;
    return true;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current != NULL && ss->compare(current->elem, elem) < 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && ss->compare(current->elem, elem) == 0) {
        return false;
    }
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->elem = elem;
    newNode->next = current;
    if (previous == NULL) {
        ss->first = newNode;
    } else {
        previous->next = newNode;
    }
    ss->size++;
    return true;
}  

// toglie un elemento all'insieme 
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current != NULL && ss->compare(current->elem, elem) < 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL || ss->compare(current->elem, elem) != 0) {
        return false;
    }
    if (previous == NULL) {
        ss->first = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    ss->size--;
    return true;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
    if(ss == NULL) {
        return -1;
    }
    ListNodePtr current = ss->first;
    while (current != NULL && ss->compare(current->elem, elem) < 0) {
        current = current->next;
    }
    return current != NULL && ss->compare(current->elem, elem) == 0;
}
    
// controlla se l'insieme e' vuoto    
int isEmptySSet(const SortedSetADT* ss) {
    if(ss == NULL) {
        return -1;
    }
    return ss->size == 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
    if(ss == NULL) {
        return -1;
    }
    return ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
    if(ss == NULL || ss->size == 0) {
        return false;
    }
    *ptr = ss->first->elem;
    ListNodePtr temp = ss->first;
    ss->first = ss->first->next;
    free(temp);
    ss->size--;
    return true;
} 

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if(s1 == NULL || s2 == NULL) {
        return -1;
    }
    if(s1->size != s2->size) {
        return 0;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if(s1->compare(current1->elem, current2->elem) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return 1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL) {
        return -1;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if(s1->compare(current1->elem, current2->elem) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if(current1 == NULL) {
        return 1;
    }
    return 0;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL) {
        return -1;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if(s1->compare(current1->elem, current2->elem) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if(current1 == NULL && current2 != NULL) {
        return 1;
    }
    return 0;
} 

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr ss = mkSSet(s1->compare);
    if(ss == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL) {
        if(current2 == NULL || s1->compare(current1->elem, current2->elem) < 0) {
            sset_add(ss, current1->elem);
            current1 = current1->next;
        } else if(s1->compare(current1->elem, current2->elem) > 0) {
            current2 = current2->next;
        } else {
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    return ss;
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr ss = mkSSet(s1->compare);
    if(ss == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL) {
        sset_add(ss, current1->elem);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        sset_add(ss, current2->elem);
        current2 = current2->next;
    }
    return ss;
} 

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    SortedSetADTptr ss = mkSSet(s1->compare);
    if(ss == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if(s1->compare(current1->elem, current2->elem) < 0) {
            current1 = current1->next;
        } else if(s1->compare(current1->elem, current2->elem) > 0) {
            current2 = current2->next;
        } else {
            sset_add(ss, current1->elem);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    return ss;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
    if(ss == NULL || ss->size == 0) {
        return false;
    }
    *ptr = ss->first->elem;
    return true;
}

// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
    if(ss == NULL || ss->size == 0) {
        return false;
    }
    if(ss->size == 1) {
        *ptr = ss->first->elem;
        return true;
    }
    ListNodePtr current = ss->first;
    while (current->next != NULL) {
        current = current->next;
    }
    *ptr = current->elem;
    return true;
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
    if(ss == NULL || ss->size == 0) {
        return false;
    }
    *ptr = ss->first->elem;
    ListNodePtr temp = ss->first;
    ss->first = ss->first->next;
    free(temp);
    ss->size--;
    return true;
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
    if(ss == NULL || ss->size == 0) {
        return false;
    }
    if(ss->size == 1) {
        *ptr = ss->first->elem;
        free(ss->first);
        ss->first = ss->last = NULL;
        ss->size = 0;
        return true;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    *ptr = current->elem;
    free(current);
    previous->next = NULL;
    ss->last = previous;
    ss->size--;
    return true;
}
