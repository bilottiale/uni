#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    IntSortedSetADT newSet = (IntSortedSetADT)malloc(sizeof(IntSortedSetADT));
    if (newSet == NULL) {
        return NULL;
    }
    newSet->first = NULL;
    newSet->size = 0;
    return newSet;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if(ssptr == NULL) {
        return false;
    }
    IntSortedSetADT ss = *ssptr;
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    while (current != NULL) {
        ListNodePtr temp = current;
        current = current->next;
        free(temp);
    }
    ss->first = NULL;
    ss->size = 0;
    free(ss);
    *ssptr = NULL;
    return true;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current != NULL && current->elem < elem) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->elem == elem) {
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

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current != NULL && current->elem < elem) {
        previous = current;
        current = current->next;
    }
    if (current == NULL || current->elem != elem) {
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

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if(ss == NULL) {
        return false;
    }
    ListNodePtr current = ss->first;
    while (current != NULL && current->elem < elem) {
        current = current->next;
    }
    return current != NULL && current->elem == elem;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if(ss == NULL) {
        return false;
    }
    return ss->size == 0;
}

int sset_size(const IntSortedSetADT ss) {
    if(ss == NULL) {
        return -1;
    }
    return ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if (isEmptySSet(ss)) {
        return false;
    }
    ListNodePtr current = ss->first;
    *ptr = current->elem;
    ss->first = current->next;
    free(current);
    ss->size--;
    return true;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return false;
    }
    if (s1->size != s2->size) {
        return false;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem != current2->elem) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return false;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem < current2->elem) {
            return false;
        }
        if (current1->elem == current2->elem) {
            current1 = current1->next;
        }
        current2 = current2->next;
    }
    return current1 == NULL;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return false;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem < current2->elem) {
            return false;
        }
        if (current1->elem == current2->elem) {
            current1 = current1->next;
        }
        current2 = current2->next;
    }
    return current1 == NULL && current2 != NULL;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem < current2->elem) {
            sset_add(newSet, current1->elem);
            current1 = current1->next;
        } else if (current1->elem > current2->elem) {
            sset_add(newSet, current2->elem);
            current2 = current2->next;
        } else {
            sset_add(newSet, current1->elem);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    while (current1 != NULL) {
        sset_add(newSet, current1->elem);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        sset_add(newSet, current2->elem);
        current2 = current2->next;
    }
    return newSet;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem < current2->elem) {
            current1 = current1->next;
        } else if (current1->elem > current2->elem) {
            current2 = current2->next;
        } else {
            sset_add(newSet, current1->elem);
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    return newSet;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL) {
        return NULL;
    }
    IntSortedSetADT newSet = mkSSet();
    if (newSet == NULL) {
        return NULL;
    }
    ListNodePtr current1 = s1->first;
    ListNodePtr current2 = s2->first;
    while (current1 != NULL && current2 != NULL) {
        if (current1->elem < current2->elem) {
            sset_add(newSet, current1->elem);
            current1 = current1->next;
        } else if (current1->elem > current2->elem) {
            current2 = current2->next;
        } else {
            current1 = current1->next;
            current2 = current2->next;
        }
    }
    while (current1 != NULL) {
        sset_add(newSet, current1->elem);
        current1 = current1->next;
    }
    return newSet; 
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if (isEmptySSet(ss)) {
        return false;
    }
    *ptr = ss->first->elem;
    return true;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if (isEmptySSet(ss)) {
        return false;
    }
    ListNodePtr current = ss->first;
    while (current->next != NULL) {
        current = current->next;
    }
    *ptr = current->elem;
    return true;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if (isEmptySSet(ss)) {
        return false;
    }
    *ptr = ss->first->elem;
    ListNodePtr current = ss->first;
    ss->first = current->next;
    free(current);
    ss->size--;
    return true;
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL) {
        return false;
    }
    if (isEmptySSet(ss)) {
        return false;
    }
    ListNodePtr current = ss->first;
    ListNodePtr previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    *ptr = current->elem;
    if (previous == NULL) {
        ss->first = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
    ss->size--;
    return true;
}
