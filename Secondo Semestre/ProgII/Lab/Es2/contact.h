#ifndef CONTACT_H
#define CONTACT_H

typedef struct contact {
   char* name;   
   char* surname;
   char* mobile;
   char* url;
} Contact, *ContactPtr;

_Bool contactEq(Contact c1, Contact c2);
_Bool contactEqEff(const Contact *pc1, const Contact *pc2);
int contactCmp(Contact c1, Contact c2);
int contactCmpEff(const Contact *pc1, const Contact *pc2);

#endif /* CONTACT_H */
