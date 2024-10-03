#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#include "contactBook.h"
#include "sortedSetADT.h"

struct contactBookADT {
    SortedSetADTptr contacts; // All needed operations are already implemented in the SortedSetADT
};

void stampaContact(void* elem) {
    ContactPtr contact = (ContactPtr)elem;
    if (contact != NULL)
    {
        printf("%s %s: %s (%s)\n", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
    }
}

int contact_cmp(void* c1, void* c2) {
    return cmpContact((ContactPtr)c1, (ContactPtr)c2);
}

// return a new empty book, NULL if error
ContactBookADTptr mkCBook()
{
    ContactBookADTptr book = (ContactBookADTptr)malloc(sizeof(ContactBookADT));
    if (book == NULL) {
        return NULL;
    }
    book->contacts = mkSSet(contact_cmp);
    if (book->contacts == NULL) {
        free(book);
        return NULL;
    }
    return book;
}

// destroy the book, freeing the memory
_Bool dsCBook(ContactBookADTptr *book)
{
    if (book == NULL || *book == NULL) {
        return false;
    }
    dsSSet(&((*book)->contacts));
    free(*book);
    *book = NULL;
    return true;
}

// check if the book is empty, -1 if NULL
int isEmptyCBook(const ContactBookADT *book)
{
    if (book == NULL) {
        return -1;
    }
    return isEmptySSet(book->contacts);
}

// return the number of contacts in the book, -1 if NULL
int cbook_size(const ContactBookADT *book)
{
    if (book == NULL) {
        return -1;
    }
    return sset_size(book->contacts);
}

// add a contact to the book (return false if the element was already present, true otherwise)
_Bool cbook_add(ContactBookADTptr book, ContactPtr cnt)
{
    if (book == NULL || cnt == NULL)
    {
        return false;
    }
    if (cbook_search(book, getName(cnt), getSurname(cnt)) != NULL)
    {
        return false;
    }
    return sset_add(book->contacts, cnt);
}

// remove an element from the set (return false if the element was not present, true otherwise)
_Bool cbook_remove(ContactBookADTptr book, char *name, char *surname)
{
    if (book == NULL)
    {
        return false;
    }
    ContactPtr contact = mkContact(name, surname, "", "");
    if (contact == NULL)
    {
        return false;
    }
    _Bool result = sset_remove(book->contacts, contact);
    dsContact(&contact);
    return result;
}

// return a pointer to the contact with the given name and surname (can be used to access or modify the number and url of the contact), NULL if not present
ContactPtr cbook_search(const ContactBookADT *book, char *name, char *surname)
{
    if (book == NULL)
    {
        return NULL;
    }
    ContactPtr contact = mkContact(name, surname, "", "");
    if (contact == NULL)
    {
        return NULL;
    }
    ContactPtr result = (ContactPtr)sset_search(book->contacts, contact);
    dsContact(&contact);
    return result;
}

// carica una rubrica da file, NULL se errore
ContactBookADTptr cbook_load(FILE *fin)
{
    if (fin == NULL)
    {
        return NULL;
    }
    ContactBookADTptr book = mkCBook();
    if (book == NULL)
    {
        return NULL;
    }
    char name[100], surname[100], mobile[100], url[100];
    while (fscanf(fin, "%99[^,],%99[^,],%99[^,],%99[^\n]\n", name, surname, mobile, url) > 1)
    {
        ContactPtr contact = mkContact(name, surname, mobile, url);
        if (contact == NULL)
        {
            dsCBook(&book);
            return NULL;
        }
        if (!cbook_add(book, contact))
        {
            dsContact(&contact);
            dsCBook(&book);
            return NULL;
        }
    }
    return book;
}

// save a phone book to a file, false if error
_Bool cbook_dump(const ContactBookADT *book, FILE *fout)
{
    if (book == NULL || fout == NULL)
    {
        return false;
    }
    void **contacts = sset_toArray(book->contacts);
    if (contacts == NULL)
    {
        return false;
    }
    for (int i = 0; i < sset_size(book->contacts); i++)
    {
        ContactPtr contact = (ContactPtr)contacts[i];
        fprintf(fout, "%s,%s,%s,%s\n", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
    }
    free(contacts);
    return true;
}

// ContactBookADTptr cbook_load(FILE *fin)
// {
//     if (fin == NULL)
//     {
//         return NULL;
//     }
//     ContactBookADTptr book = mkCBook();
//     if (book == NULL)
//     {
//         return NULL;
//     }
//     char name[100], surname[100], mobile[100], url[100];

//     while (fscanf(fin, "%99[^,],%99[^,],%99[^,],%99[^\n]\n", name, surname, mobile, url) > 1)
//     {
//         ContactPtr contact = mkContact(name, surname, mobile, url);
//         if (contact == NULL)
//         {
//             dsCBook(&book);
//             return NULL;
//         }
//         if (!cbook_add(book, contact))
//         {
//             dsContact(&contact);
//             dsCBook(&book);
//             return NULL;
//         }
//     }
//     return book;
// }

// // salva una rubrica su file, false se errore
// bool cbook_dump(const ContactBookADT *book, FILE *fout)
// {
//     if (book == NULL || fout == NULL)
//     {
//         return false;
//     }
//     ContactPtr *contacts = (ContactPtr *)sset_toArray(book->contacts);
//     if (contacts == NULL)
//     {
//         return false;
//     }
//     for (int i = 0; i < sset_size(book->contacts); i++)
//     {
//         fprintf(fout, "%s,%s,%s,%s\n", getName(contacts[i]), getSurname(contacts[i]), getMobile(contacts[i]), getUrl(contacts[i]));
//     }
//     free(contacts);
//     return true;
// }

// int main()
// {
//     ContactBookADTptr book = mkCBook();
//     if (book == NULL)
//     {
//         return -1;
//     }
//     ContactPtr contact1 = mkContact("Mario", "Rossi", "1234567890", "");
//     ContactPtr contact2 = mkContact("Luca", "Bianchi", "0987654321", "www.luca.it");
//     ContactPtr contact3 = mkContact("Giovanni", "Verdi", "6789012345", "www.giovanni.it");
//     cbook_add(book, contact1);
//     cbook_add(book, contact2);
//     cbook_add(book, contact3);
//     cbook_dump(book, stdout);

//     // load and show the contacts from a file

//     FILE *fout = fopen("contacts.csv", "w");
//     if (fout == NULL)
//     {
//         dsCBook(&book);
//         return -1;
//     }
//     cbook_dump(book, fout);
//     fclose(fout);

//     FILE *fin = fopen("contacts.csv", "r");
//     if (fin == NULL)
//     {
//         dsCBook(&book);
//         return -1;
//     }
//     ContactBookADTptr book2 = cbook_load(fin);
//     fclose(fin);
//     if (book2 == NULL)
//     {
//         dsCBook(&book);
//         return -1;
//     }

//     return 0;
// }
