//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	char value[30];
	struct node* prev;
	struct node* next;
};
struct list {
	struct node* head;
	int size;
};
struct wrd {
	char* string;
	int length;
};

int getSize(char* array) {
	int strsize = 0;
	while ((array[strsize] != '\n') && (array[strsize] != 0)) {
		strsize++;
	}
	return strsize;
}


void init(struct list* l) {
	l->head = NULL;
	l->size = 0;
}

void destroy(struct list* l) {
	struct node* cur = l->head;
	struct node* prev = NULL;
	while (cur != NULL) {
		prev = cur;
		cur = cur->next;
		free(prev);
	}
}

struct list* push_back(struct list* l, char val[30]) {
	struct node* n, * cur;
	n = (struct node*)malloc(sizeof(struct node) + 1);
	if (n) {
		int i = 0;
		do {
			n->value[i] = val[i];
			i++;
		} while (i <= 30);
		n->next = NULL;
		if (l->head == NULL) {
			n->prev = NULL;
			l->head = n;
		}
		else {
			cur = l->head;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = n;
			n->prev = cur;
		}
		l->size++;
	}
	return l;
}

void print(struct list* l) {
	struct node* cur = l->head;
	while (cur != NULL) {
		int i = 0;
		do {
			printf("%c", cur->value[i]);
			i++;
		} while (cur->value[i] != 0);
		printf(" ");
		cur = cur->next;
	}
	printf(" \n ");
}

/*void set(struct list* l, int i, char val) {
	struct node* cur = l->head; int count = 0;
	if (i < 0 || i >= l->size) return;
	while (count != i) {
		cur = cur->next;
		count++;
	}
	cur->value = val;
}*/
int get(struct list* l, int i) {
	struct node* cur = l->head; int count = 0;
	if (i < 0 || i >= l->size) return -1;
	while (count != i) {
		cur = cur->next;
		count++;
	}
	return cur->value[0];
}

/*void insert(struct list* l, struct node* cur, char val) {
	struct node* n = (struct node*)malloc(sizeof(struct node));
	if (n) {
		n->value = val;
		n->next = cur->next;
		n->prev = cur;
		cur->next->prev = n;
		cur->next = n;
		l->size++;
	}
}

void erase(struct list* l, struct node* cur) {
	if (cur == l->head) {
		l->head = cur->next;
		if (cur->next != NULL) cur->next->prev = NULL;
		free(cur);
	}
	else {
		cur->prev->next = cur->next;
		if (cur->next != NULL) cur->next->prev = cur->prev;
		free(cur);
	}
	l->size--;
}*/

int isLetter(char x)
{
	return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'));
}

int main() {
	//FILE* file = fopen("words.txt", "r");
	char string[] = "beware our creature has escaped from this prison";
	//fgets(string, 1000, file);
	struct list l1, l2;
	init(&l1); init(&l2);
	int wordsize = 0, wordcount = 0;
	//char* word;
	char word[30];
	int strsize = getSize(string);

	for (int i = 0; i < strsize + 1; i++) {
		if (isLetter(string[i])) {
			wordsize++;
		}
		else {
			wordcount++;
			//word = (char*)realloc(tmp, (wordsize + 1) * sizeof(char));
			if (word == NULL)
			{
				return 1;
			}
			//if (word) {
			int k = 0;
			printf("%d", wordsize);
			for (int j = i - wordsize; j < i; j++) {

				word[k] = string[j];
				k++;
			}

			word[wordsize] = 0;
			for (int i = 0; word[i] != 0; i++) printf("%c", word[i]);
			push_back(&l1, word);
			wordsize = 0;
			//}
		}
	}
	printf("%c \n", get(&l1, 100));
	print(&l1);
	destroy(&l1);
	destroy(&l2);
	return 0;
}