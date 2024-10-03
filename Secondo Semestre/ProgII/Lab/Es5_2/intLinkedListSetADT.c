#include <stdlib.h>
#include <stdbool.h>
#include "intSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode
{
	int data;
	ListNodePtr next;
};

struct intSet
{
	ListNodePtr front; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
	int size;		   /* Numero di elementi presenti nell'insieme */
};

// inverte il set
IntSetADT reverse_set(const IntSetADT set)
{
	if (set == NULL)
	{
		return NULL;
	}

	IntSetADT reversed_set = mkSet();
	if (reversed_set == NULL)
	{
		return NULL;
	}

	ListNodePtr current = set->front;
	while (current != NULL)
	{
		if (!set_add(reversed_set, current->data))
		{
			dsSet(&reversed_set);
			return NULL;
		}
		current = current->next;
	}

	return reversed_set;
}

// restituisce un insieme vuoto
IntSetADT mkSet()
{
	IntSetADT set = malloc(sizeof(struct intSet));
	if (set == NULL)
	{
		return NULL;
	}
	set->front = NULL;
	set->size = 0;
	return set;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSet(IntSetADT *sp)
{
	if (sp == NULL)
	{
		return false;
	}
	free(*sp);
	*sp = NULL;
	return true;
}

// aggiunge un elemento all'insieme (restituisce 0 se l'elemento era gia' presente, 1 altrimenti)
_Bool set_add(IntSetADT set, const int elem)
{
	if (set == NULL)
	{
		return false;
	}

	ListNodePtr current = set->front;
	while (current != NULL)
	{
		if (current->data == elem)
		{
			return false;
		}
		current = current->next;
	}

	ListNodePtr new = malloc(sizeof(ListNode));
	if (new == NULL)
	{
		return false;
	}

	new->data = elem;
	new->next = set->front;
	set->front = new;
	set->size++;

	return true;
}

// toglie un elemento all'insieme (restituisce 0 se l'elemento non era presente, 1 altrimenti)
_Bool set_remove(IntSetADT set, const int elem)
{
	if (set == NULL)
	{
		return false;
	}

	ListNodePtr current = set->front;
	ListNodePtr prev = NULL;
	while (current != NULL)
	{
		if (current->data == elem)
		{
			if (prev == NULL)
			{
				set->front = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current);
			set->size--;
			return true;
		}
		prev = current;
		current = current->next;
	}

	return false;
}

// controlla se un elemento appartiene all'insieme
_Bool set_member(const IntSetADT set, const int elem)
{
	if (set == NULL)
	{
		return false;
	}

	ListNodePtr current = set->front;
	while (current != NULL)
	{
		if (current->data == elem)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}

// controlla se l'insieme e' vuoto
_Bool isEmptySet(const IntSetADT set)
{
	// nota: restituire false se l'insieme non esiste, anche se ambiguo con caso di insieme non vuoto
	if (set == NULL)
	{
		return false;
	}

	return set->size == 0;
}

// restituisce il numero di elementi presenti nell'insieme, -1 se NULL
int set_size(const IntSetADT set)
{
	if (set == NULL)
	{
		return -1;
	}
	return set->size;
}

// toglie e restituisce un elemento a caso dall'insieme
_Bool set_extract(IntSetADT set, int *datap)
{
	if (set == NULL || set->size == 0)
	{
		return false;
	}

	ListNodePtr current = set->front;
	ListNodePtr prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	if (prev == NULL)
	{
		set->front = NULL;
	}
	else
	{
		prev->next = NULL;
	}

	*datap = current->data;
	free(current);
	set->size--;

	return true;
}

// controlla se due insiemi sono uguali
_Bool set_equals(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return false;
	}

	if (set1->size != set2->size)
	{
		return false;
	}

	ListNodePtr current1 = set1->front;
	ListNodePtr current2 = set2->front;
	while (current1 != NULL)
	{
		if (current1->data != current2->data)
		{
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}

	return true;
}

// controlla se il primo insieme e' incluso nel secondo
_Bool subseteq(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return false;
	}

	ListNodePtr current1 = set1->front;
	while (current1 != NULL)
	{
		if (!set_member(set2, current1->data))
		{
			return false;
		}
		current1 = current1->next;
	}

	return true;
}

// contr. se il primo ins. e' incluso strettamente nel secondo
_Bool subset(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return false;
	}

	ListNodePtr current1 = set1->front;
	while (current1 != NULL)
	{
		if (!set_member(set2, current1->data))
		{
			return false;
		}
		current1 = current1->next;
	}

	return set1->size < set2->size;
}

// restituisce l'unione di due insiemi
IntSetADT set_union(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	IntSetADT unionSet = mkSet();
	if (unionSet == NULL)
	{
		return NULL;
	}

	ListNodePtr current1 = set1->front;
	ListNodePtr current2 = set2->front;

	while (current1 != NULL && current2 != NULL)
	{
		if (current1->data > current2->data)
		{
			if (!set_add(unionSet, current1->data))
			{
				dsSet(&unionSet);
				return NULL;
			}
			current1 = current1->next;
		}
		else if (current1->data < current2->data)
		{
			if (!set_add(unionSet, current2->data))
			{
				dsSet(&unionSet);
				return NULL;
			}
			current2 = current2->next;
		}
		else
		{
			if (!set_add(unionSet, current1->data))
			{
				dsSet(&unionSet);
				return NULL;
			}
			current1 = current1->next;
			current2 = current2->next;
		}
	}

	while (current1 != NULL)
	{
		if (!set_add(unionSet, current1->data))
		{
			dsSet(&unionSet);
			return NULL;
		}
		current1 = current1->next;
	}

	while (current2 != NULL)
	{
		if (!set_add(unionSet, current2->data))
		{
			dsSet(&unionSet);
			return NULL;
		}
		current2 = current2->next;
	}

	return unionSet;
}

// restituisce l'intersezione di due insiemi
IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	IntSetADT intersection = mkSet();
	if (intersection == NULL)
	{
		return NULL;
	}

	ListNodePtr current1 = set1->front;
	while (current1 != NULL)
	{
		if (set_member(set2, current1->data))
		{
			if (!set_add(intersection, current1->data))
			{
				dsSet(&intersection);
				return NULL;
			}
		}
		current1 = current1->next;
	}

	IntSetADT reversed_intersection = reverse_set(intersection);
	if (reversed_intersection == NULL)
	{
		dsSet(&intersection);
		return NULL;
	}

	dsSet(&intersection);

	return reversed_intersection;
}

// restituisce l’insieme ottenuto dal primo togliendo gli elementi del secondo
IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2)
{
	if (set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	IntSetADT subtraction = mkSet();
	if (subtraction == NULL)
	{
		return NULL;
	}

	ListNodePtr current1 = set1->front;
	while (current1 != NULL)
	{
		if (!set_member(set2, current1->data))
		{
			if (!set_add(subtraction, current1->data))
			{
				dsSet(&subtraction);
				return NULL;
			}
		}
		current1 = current1->next;
	}

	IntSetADT reversed_subtraction = reverse_set(subtraction);
	if (reversed_subtraction == NULL)
	{
		dsSet(&subtraction);
		return NULL;
	}

	dsSet(&subtraction);

	return reversed_subtraction;
}
