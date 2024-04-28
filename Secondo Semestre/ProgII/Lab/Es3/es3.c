#include "contactOpq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
	char* name;
	char* surname;
	char* mobile;
	char* url;
};

ContactPtr mkContact(char* name, char* surname, char* mobile, char* url) {
	if (name == NULL || surname == NULL) {
		return NULL;
	}

	ContactPtr newContact = (ContactPtr)malloc(sizeof(Contact));
	if (newContact == NULL) {
		return NULL;
	}

	newContact->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (newContact->name == NULL) {
		free(newContact);
		return NULL;
	}
	strcpy(newContact->name, name);

	newContact->surname = (char*)malloc((strlen(surname) + 1) * sizeof(char));
	if (newContact->surname == NULL) {
		free(newContact->name);
		free(newContact);
		return NULL;
	}
	strcpy(newContact->surname, surname);

	newContact->mobile = (char*)malloc((strlen(mobile) + 1) * sizeof(char));
	if (newContact->mobile == NULL) {
		free(newContact->surname);
		free(newContact->name);
		free(newContact);
		return NULL;
	}
	strcpy(newContact->mobile, mobile);

	newContact->url = (char*)malloc((strlen(url) + 1) * sizeof(char));
	if (newContact->url == NULL) {
		free(newContact->mobile);
		free(newContact->surname);
		free(newContact->name);
		free(newContact);
		return NULL;
	}
	strcpy(newContact->url, url);

	return newContact;
}

void dsContact(ContactPtr* cntptr) {
	if (cntptr == NULL || *cntptr == NULL) {
		return;
	}

	free(*cntptr);

	*cntptr = NULL;
}

void updateMobile(ContactPtr cnt, char* newMobile) {
    if (cnt == NULL) {
        return;
    }

    if (newMobile != NULL) {
        cnt->mobile = (char*)malloc((strlen(newMobile) + 1) * sizeof(char));
        if (cnt->mobile == NULL) {
            return;
        }
        strcpy(cnt->mobile, newMobile);
    } else {
        cnt->mobile = NULL;
    }
}

void updateUrl(ContactPtr cnt, char* newUrl) {
	if (cnt == NULL) {
		return;
	}

	if (newUrl != NULL) {
		cnt->url = (char*)malloc((strlen(newUrl) + 1) * sizeof(char));
		if (cnt->url == NULL) {
			return;
		}
		strcpy(cnt->url, newUrl);
	} else {
		cnt->url = NULL;
	}
}

char* getName(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}

	return cnt->name;
}

char* getSurname(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}

	return cnt->surname;
}

char* getMobile(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}

	return cnt->mobile;
}

char* getUrl(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}

	return cnt->url;
}

_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2) {
	if (cnt1 == NULL || cnt2 == NULL) {
		return 0;
	}

	if (strcmp(cnt1->name, cnt2->name) == 0 && strcmp(cnt1->surname, cnt2->surname) == 0) {
		return 1;
	}

	return 0;
}

int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2) {
	if (cnt1 == NULL || cnt2 == NULL) {
		return 0;
	}

	int cmp = strcmp(cnt1->surname, cnt2->surname);
	if (cmp == 0) {
		cmp = strcmp(cnt1->name, cnt2->name);
	}

	if (cmp < 0) {
		return -1;
	} else if (cmp > 0) {
		return 1;
	}

	return 0;
}
