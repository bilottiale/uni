#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

// typedef struct contact {
//     char* name;   
//     char* surname;
//     char* mobile;
//     char* url;
//     int phone;
// } Contact, *ContactPtr;

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int my_strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char c1 = to_lower(*s1);
        char c2 = to_lower(*s2);
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

_Bool contactEq(Contact c1, Contact c2){
    return my_strcasecmp(c1.name, c2.name) == 0 && my_strcasecmp(c1.surname, c2.surname) == 0;
}

_Bool contactEqEff(const Contact *pc1, const Contact *pc2){
    if (pc1 && pc2) {
        return my_strcasecmp(pc1->name, pc2->name) == 0 && my_strcasecmp(pc1->surname, pc2->surname) == 0;
    }
    return 0;
}

int contactCmp(Contact c1, Contact c2){
    int cmp = my_strcasecmp(c1.surname, c2.surname); // check if the surnames are the same
    if (cmp != 0) {
        return cmp < 0 ? -1 : 1;
    }

    int i = 0;
    while (c1.name[i] != '\0' && c2.name[i] != '\0') {
        char lc1 = to_lower(c1.name[i]);
        char lc2 = to_lower(c2.name[i]);
        if (lc1 != lc2) {
            return lc1 < lc2 ? -1 : 1;
        }
        i++;
    }

    if (c1.name[i] != '\0') {
        return 1;
    } else if (c2.name[i] != '\0') {
        return -1;
    }

    return 0;
}

int contactCmpEff(const Contact *pc1, const Contact *pc2){
    if (pc1 && pc2) {
        int cmp = my_strcasecmp(pc1->surname, pc2->surname);
        if (cmp != 0) {
            return cmp < 0 ? -1 : 1;
        }

        int i = 0;
        while (pc1->name[i] != '\0' && pc2->name[i] != '\0') {
            char lc1 = to_lower(pc1->name[i]);
            char lc2 = to_lower(pc2->name[i]);
            if (lc1 != lc2) {
                return lc1 < lc2 ? -1 : 1;
            }
            i++;
        }

        if (pc1->name[i] != '\0') {
            return 1;
        } else if (pc2->name[i] != '\0') {
            return -1;
        }

        return 0;
    }
    return pc1 ? 1 : pc2 ? -1 : 0;
}

int main() {
    printf("Passed by Value:\n");
    Contact c1 = {"Mario", "Rossi", "1234567890", "www.mario.it"};
    // Contact c3 = {"Mario", "Rossi", "1234567890", "www.mario.it"};

    printf("Name: %s\n", c1.name);
    printf("Surname: %s\n", c1.surname);
    printf("Mobile: %s\n", c1.mobile);
    printf("Url: %s\n", c1.url);

    printf("\n");

    printf("Passed by Pointer:\n");
    ContactPtr c2 = malloc(sizeof(Contact)); // Allocate memory for c2
    c2->name = "Luca";
    c2->surname = "Bianchi";
    c2->mobile = "0987654321";
    c2->url = "www.luca.it";

    printf("Name: %s\n", c2->name);
    printf("Surname: %s\n", c2->surname);
    printf("Mobile: %s\n", c2->mobile);
    printf("Url: %s\n", c2->url);

    free(c2); // Free the memory allocated for c2

    Contact c3 = {"Luca", "Bianchi", "0987654321", "www.luca.it"};

    printf("\n");
    printf("-------------------\n");
    printf("\n");

    printf("contactEq: %d\n", contactEq(c1, c3));

    if(contactEq(c1, c3)){
        printf("The two contacts are equal.\n");
    } else {
        printf("The two contacts are different.\n");
    }

    printf("\n");
    printf("-------------------\n");
    printf("\n");

    printf("contactEqEff: %d\n", contactEqEff(&c1, &c3));

    if(contactEqEff(&c1, &c3)){
        printf("The two contacts are equal.\n");
    } else {
        printf("The two contacts are different.\n");
    }

    printf("\n");
    printf("-------------------\n");
    printf("\n");

    printf("contactCmp: %d\n", contactCmp(c1, c3));

    if(contactCmp(c1, c3) == 0){
        printf("The two contacts are equal.\n");
    } else if(contactCmp(c1, c3) == -1){
        printf("The first contact is less than the second contact.\n");
    } else {
        printf("The first contact is greater than the second contact.\n");
    }

    printf("\n");
    printf("-------------------\n");
    printf("\n");

    printf("contactCmpEff: %d\n", contactCmpEff(&c1, &c3));

    if(contactCmpEff(&c1, &c3) == 0){
        printf("The two contacts are equal.\n");
    } else if(contactCmpEff(&c1, &c3) == -1){
        printf("The first contact is less than the second contact.\n");
    } else {
        printf("The first contact is greater than the second contact.\n");
    }

    printf("\n");
    printf("-------------------\n");
    printf("\n");

    return 0;
}
