#include <stdlib.h>
#include <string.h>

#include "contactOpq.h"

struct contact
{
	char *name;
	char *surname;
	char *mobile;
	char *url;
};

ContactPtr mkContact(char *name, char *surname, char *mobile, char *url)
{
	if ((name == NULL) || (surname == NULL))
		return NULL;

	ContactPtr newContact = (ContactPtr)malloc(sizeof(Contact));
	if (newContact == NULL)
		return NULL;

	if (name != NULL)
	{
		newContact->name = (name == NULL) ? NULL : (char *)malloc(strlen(name) + 1);
		if (newContact->name == NULL)
		{
			free(newContact);
			return NULL;
		}
		strcpy(newContact->name, name);
	}

	if (surname != NULL)
	{
		newContact->surname = (surname == NULL) ? NULL : (char *)malloc(strlen(surname) + 1);
		if (newContact->surname == NULL)
		{
			free(newContact);
			return NULL;
		}
		strcpy(newContact->surname, surname);
	}

	if (mobile != NULL)
	{
		newContact->mobile = (mobile == NULL) ? NULL : (char *)malloc(strlen(mobile) + 1);
		if (newContact->mobile == NULL)
		{
			free(newContact);
			return NULL;
		}
		strcpy(newContact->mobile, mobile);
	}

	if (url != NULL)
	{
		newContact->url = (url == NULL) ? NULL : (char *)malloc(strlen(url) + 1);
		if (newContact->url == NULL)
		{
			free(newContact);
			return NULL;
		}
		strcpy(newContact->url, url);
	}

	return newContact;
}

void dsContact(ContactPtr *cntptr)
{
	free(*cntptr);
	*cntptr = NULL;
}

void updateMobile(ContactPtr cnt, char* newMobile)
{
	if(cnt == NULL){
	    return;
	}
	
	if(newMobile != NULL){
	    cnt->mobile = (char*)malloc(strlen(newMobile) +1);
	    if(cnt->mobile == NULL){
		    return;
	    }
	    strcpy(cnt->mobile, newMobile);
	} else {
	    cnt->mobile = NULL;
	}
}

void updateUrl(ContactPtr cnt, char *newUrl) {
	if (cnt == NULL) {
		return;
	}

	if (newUrl != NULL) {
		cnt->url = (char *)malloc(strlen(newUrl) + 1);
		if (cnt->url == NULL) {
			return;
		}
		strcpy(cnt->url, newUrl);
	} else {
		cnt->url = NULL;
	}
}

char *getName(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}
	return cnt->name;
}

char *getSurname(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}
	return cnt->surname;
}

char *getMobile(const ContactPtr cnt) {
	if (cnt == NULL) {
		return NULL;
	}
	return cnt->mobile;
}

char *getUrl(const ContactPtr cnt) {
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
