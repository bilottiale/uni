#include <stdio.h>
#include <string.h>
#include "contact.h"

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

_Bool contactEq(Contact c1, Contact c2) {
    return my_strcasecmp(c1.name, c2.name) == 0 && my_strcasecmp(c1.surname, c2.surname) == 0;
}

_Bool contactEqEff(const Contact *pc1, const Contact *pc2) {
    if (pc1 && pc2) {
        return my_strcasecmp(pc1->name, pc2->name) == 0 && my_strcasecmp(pc1->surname, pc2->surname) == 0;
    }
    return 0;
}

int contactCmp(Contact c1, Contact c2) {
    int cmp = my_strcasecmp(c1.surname, c2.surname);
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

int contactCmpEff(const Contact *pc1, const Contact *pc2) {
    if (pc1 && pc2) {
        int cmp = my_strcasecmp(pc1->surname, pc2->surname);
        if (cmp != 0) {
            return cmp < 0 ? -1 : 1;
        }

        int i = 0;
        while (pc1->name[i] != '\0' && pc2->name[i] != '\0') {
            if (to_lower(pc1->name[i]) != to_lower(pc2->name[i])) {
                return to_lower(pc1->name[i]) < to_lower(pc2->name[i]) ? -1 : 1;
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
