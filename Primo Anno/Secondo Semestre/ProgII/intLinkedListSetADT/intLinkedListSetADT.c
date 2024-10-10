#include <stdlib.h>
#include <stdbool.h>

#include "intSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int data;
   ListNodePtr next;
};

struct intSet {
    ListNodePtr front; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    int size; /* Numero di elementi presenti nell'insieme */
};

IntSetADT mkSet() {
    IntSetADT newSet = (IntSetADT)malloc(sizeof(struct intSet));
    if (newSet == NULL) {
        return NULL;
    }
    newSet->front = NULL;
    newSet->size = 0;
    return newSet;
}

_Bool dsSet(IntSetADT *sp) {
    if(sp == NULL) {
        return false;
    }
    IntSetADT s = *sp;
    if(s == NULL) {
        return false;
    }
    ListNodePtr current = s->front;
    while (current != NULL) {
        ListNodePtr temp = current;
        current = current->next;
        free(temp);
    }
    s->front = NULL;
    s->size = 0;
    free(s);
    *sp = NULL;
    return true;
}

_Bool set_add(IntSetADT set, const int elem) {
    if(set == NULL) {
        return false;
    }
    ListNodePtr current = set->front;
    ListNodePtr previous = NULL;
    while (current != NULL && current->data < elem) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->data == elem) {
        return false;
    }
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->data = elem;
    newNode->next = current;
    if (previous == NULL) {
        set->front = newNode;
    } else {
        previous->next = newNode;
    }
    set->size++;
    return true;
}

_Bool set_remove(IntSetADT set, const int elem) {
    if(set == NULL) {
        return false;
    }
    ListNodePtr current = set->front;
    ListNodePtr previous = NULL;
    while (current != NULL && current->data < elem) {
        previous = current;
        current = current->next;
    }
    if (current == NULL || current->data != elem) {
        return false;
    }
    if (previous == NULL) {
        set->front = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    set->size--;
    return true;
}

_Bool set_member(const IntSetADT set, const int elem) {
    if(set == NULL) {
        return false;
    }
    ListNodePtr current = set->front;
    while (current != NULL && current->data < elem) {
        current = current->next;
    }
    return current != NULL && current->data == elem;
}

_Bool isEmptySet(const IntSetADT set) {
    // nota: restituire false se l'insieme non esiste, anche se ambiguo con caso di insieme non vuoto
    if(set == NULL) {
        return false;
    }
    return set->size == 0;
}

int set_size(const IntSetADT set) {
    if(set == NULL) {
        return -1;
    }
    return set->size;
}

_Bool set_extract(IntSetADT set, int *datap) {
    if(set == NULL || set->size == 0) {
        return false;
    }
    ListNodePtr current = set->front;
    set->front = current->next;
    *datap = current->data;
    free(current);
    set->size--;
    return true;
}

_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }
    if(set1->size != set2->size) {
        return false;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == NULL;
}

_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == NULL && current2 != NULL;
}

IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }
    IntSetADT newSet = mkSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            set_add(newSet, current1->data);
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            set_add(newSet, current2->data);
            current2 = current2->next;
        } else {
            set_add(newSet, current1->data);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    while (current1 != NULL) {
        set_add(newSet, current1->data);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        set_add(newSet, current2->data);
        current2 = current2->next;
    }
    return newSet;
}

IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }
    IntSetADT newSet = mkSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            current2 = current2->next;
        } else {
            set_add(newSet, current1->data);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    return newSet;
}

IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }
    IntSetADT newSet = mkSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = set1->front;
    ListNodePtr current2 = set2->front;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            set_add(newSet, current1->data);
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            current2 = current2->next;
        } else {
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    while (current1 != NULL) {
        set_add(newSet, current1->data);
        current1 = current1->next;
    }
    return newSet;
}