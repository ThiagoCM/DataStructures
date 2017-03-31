#include <stdio.h>
#include <stdlib.h>

struct element{
	int value;
	struct element *next;
}; typedef struct element element;

struct hash_table {
		element *table[100];
}; typedef struct hash_table hash_table;

hash_table* create_hash_table();
int hash(hash_table *ht, int key);
element* put(hash_table *ht, int key, int value);
void print_table(hash_table *ht, int size_hash);

int main(){
	int N, M, C, key, value;
	scanf("%d", &N);
	int i, j, k;
	for(i = 0; i < N; i++) {
		scanf("%d %d", &M, &C);
		hash_table *ht = create_hash_table();			
			for(k = 0; k < C; k++) {
				scanf("%d", &value);
				put(ht, M, value);
			}
		print_table(ht, M);
		free(ht);
	}
}

void print_table(hash_table *ht, int size_hash){
	element* current = (element*) malloc(sizeof(element));
	int i;
	for(i = 0; i < size_hash; i++) {
	current = ht->table[i];
	printf("%d ->", i);
	while(current != NULL) {
		printf(" %d ->", current->value);
		current = current->next;	
	}
	printf(" %c\n", 92);
	}
	printf("\n");
}

hash_table* create_hash_table(){
	hash_table *new_hash_table =(hash_table*) malloc(sizeof(hash_table));

	int i;
	for (i = 0; i < 100; i++) {
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

element* put(hash_table *ht, int key, int value){
	int h;	
	h = value % key;	
	element* prev = NULL;
	element* current = ht->table[h];
	while(current != NULL){
	prev = current;
	current = current->next;
	}
	current = (element*) malloc(sizeof(element));
	current->next = NULL;
	current->value = value;
	if(prev == NULL)
		ht->table[h] = current;
	else
		prev->next = current;
	return current;
	
}
