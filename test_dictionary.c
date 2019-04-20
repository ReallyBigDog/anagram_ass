#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

void print_list(VNode *head){
	VNode *cur = head;
	while(cur){
		printf("%s ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int compare(const void *l1, const void *l2) {
	return *(char*)l1 - *(char*)l2;
}

int main (int argc, char ** argv) {
	/*
	DNode* result;

	//either static or use calloc - to set all bytes initially to 0
	static DNode* dictionary [DEFAULT_HASH_SIZE];


	set(dictionary, DEFAULT_HASH_SIZE, "pore", "repo");
	set(dictionary, DEFAULT_HASH_SIZE, "pore", "rope");


	result = get (dictionary, DEFAULT_HASH_SIZE, "pore");
	if (result != NULL) {
		printf("Anagrams for 'pore':\n");
		print_list (result->values);
	}
	else
		printf ("'pore' not found\n");

	set(dictionary, DEFAULT_HASH_SIZE, "bore", "robe");
	result = get (dictionary, DEFAULT_HASH_SIZE, "bore");
	if (result != NULL) {
		printf("Anagrams for 'bore':\n");
		print_list (result->values);
	}
	else
		printf ("'bore' not found\n");

	free_dictionary(dictionary, DEFAULT_HASH_SIZE);*/

	DNode* result;
	static DNode* dictionary [DEFAULT_HASH_SIZE];

	FILE *f = fopen("words.txt", "r");
	char buffer[25];
	while (fscanf(f, "%s", buffer) != EOF) {
		char* word = copystr(buffer);
		qsort(word, strlen(word), sizeof(char), compare);
		set(dictionary, DEFAULT_HASH_SIZE, word, buffer);

		free(word);
	}

	int total = 0;
	for (int i = 0; i < DEFAULT_HASH_SIZE; i++) {
		if (dictionary[i] != NULL) {
			result = get(dictionary, DEFAULT_HASH_SIZE, dictionary[i]->key);
			VNode* head = (result->values)->next;

			if (head) {
				printf("%s\n", (result->values)->value);
				while (head) {
					printf("%s\n\n", head->value);
					head = head->next;
				}
				total++;
			}
		}
	}

	printf("%d\n", total);
	free_dictionary(dictionary, DEFAULT_HASH_SIZE);

	return 0;
}
