#include <stdlib.h>
#include <stdbool.h>

#include "intSetADT.h"
#include "intLinkedListSet.h"

// restituisce un insieme vuoto
IntSetADT mkSet() {
    IntSetADT set = (IntSetADT) malloc(sizeof(struct intSet));
    if (set == NULL) {
        return NULL;
    }

    set->front = NULL;
    set->size = 0;

    return set;
}
// distrugge l'insieme (inclusi i suoi elementi), recuperando la memoria
_Bool dsSet(IntSetADT *sp) {
    if (sp == NULL) {
        return false;
    }

    ListNodePtr curr = (*sp)->front;
    ListNodePtr next = NULL;

    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(*sp);
    *sp = NULL;
    return true;
}

_Bool set_add(IntSetADT set, const int elem) {
    if (set == NULL) {
        return 0;
    }

    // Se l'elemento è già presente, esci
    if (set_member(set, elem)) {
        return 0;
    }

    ListNodePtr new_node = (ListNodePtr)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        return 0;
    }

    new_node->data = elem;
    new_node->next = set->front;
    set->front = new_node;
    set->size++;
    return 1;
}



// toglie un elemento all'insieme (restituisce 0 se l'elemento non era presente, 1 altrimenti)
_Bool set_remove(IntSetADT set, const int elem) {
    if (set == NULL || set->front == NULL) {
        return false;
    }

    // Caso particolare: l'elemento da rimuovere è il primo nella lista
    if (set->front->data == elem) {
        ListNodePtr temp = set->front;
        set->front = set->front->next;
        free(temp);
        set->size--;
        return true;
    }

    // Cerca elemento nella lista
    ListNodePtr prev = set->front;
    ListNodePtr curr = prev->next;
    while (curr != NULL) {
        if (curr->data == elem) {
            prev->next = curr->next;
            free(curr);
            set->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
}

// controlla se un elemento appartiene all'insieme
_Bool set_member(const IntSetADT set, const int elem) {
    if(set == NULL) {
        return false;
    }

    ListNodePtr curr = set->front;
    while(curr != NULL) {
        if (curr->data == elem) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

// controlla se l'insieme e' vuoto
_Bool isEmptySet(const IntSetADT set) {
    if(set == NULL) {
        return false;
    } else {
        return set->front == NULL;
    }
}

// restituisce il numero di elementi presenti nell'insieme, -1 se NULL
int set_size(const IntSetADT set) {
    if(set == NULL) {
        return -1;
    } else {
        return set->size;
    }
}

// toglie e restituisce un elemento a caso dall'insieme
_Bool set_extract(IntSetADT set, int *datap) {
    if(set == NULL || set->front == NULL) {
        return false;
    }

    int random_numer = rand() % set->size;

    ListNodePtr prev = NULL;
    ListNodePtr curr = set->front;
    for (int i = 0; i < random_numer; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        set->front = curr->next;
    } else {
        prev->next = curr->next;
    }

    *datap = curr->data;
    free(curr);
    set->size--;
    return true;
}

// controlla se due insiemi sono uguali
_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }

    if (set1->size != set2->size) {
        return false;
    }

    ListNodePtr curr1 = set1->front;
    ListNodePtr curr2 = set2->front;

    while(curr1 != NULL) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return true;
}

// controlla se il primo insieme e' incluso nel secondo
_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }

    ListNodePtr curr1 = set1->front;
    while(curr1 != NULL) {
        if (!set_member(set2, curr1->data)) {
            return false;
        }
        curr1 = curr1->next;
    }

    return true;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return false;
    }

    ListNodePtr curr1 = set1->front;
    while (curr1 != NULL) {
        if (!set_member(set2, curr1->data)) {
            return false;
        }
        curr1 = curr1->next;
    }

    if (set_size(set1) >= set_size(set2)) {
        return false;
    }

    return true;
}

// restituisce l'unione di due insiemi
IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }

    IntSetADT union_set = mkSet();
    if (union_set == NULL) {
        return NULL;
    }

    ListNodePtr curr1 = set1->front;
    while (curr1 != NULL) {
        set_add(union_set, curr1->data);
        curr1 = curr1->next;
    }

    ListNodePtr curr2 = set2->front;
    while (curr2 != NULL) {
        set_add(union_set, curr2->data);
        curr2 = curr2->next;
    }

    return union_set;
}

// restituisce l'intersezione di due insiemi
IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }

    IntSetADT intersection_set = mkSet();
    if (intersection_set == NULL) {
        return NULL;
    }

    ListNodePtr curr1 = set1->front;
    while (curr1 != NULL) {
        if (set_member(set2, curr1->data)) {
            set_add(intersection_set, curr1->data);
        }
        curr1 = curr1->next;
    }

    return intersection_set;
}


IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    if(set1 == NULL || set2 == NULL) {
        return NULL;
    }

    IntSetADT subtraction_set = mkSet();
    if (subtraction_set == NULL) {
        return NULL;
    }

    ListNodePtr curr1 = set1->front;
    while (curr1 != NULL) {
        if (!set_member(set2, curr1->data)) {
            set_add(subtraction_set, curr1->data);
        }
        curr1 = curr1->next;
    }

    return subtraction_set;
}
