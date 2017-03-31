#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
	char string[50];
	int element_number;
	struct element *next;
}; typedef struct element element;

struct hash_table {
		element *table[100];
}; typedef struct hash_table hash_table;


hash_table* create_hash_table();
int hash(hash_table *ht, int key);
element* put(hash_table *ht, int key, char* string, int element_number);


int main()
{
int N, L, number_of_words = 0, words_hash = 0;
int i = 0, j = 0;
	char string[50];
scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d ", &L);
		
			hash_table *ht = create_hash_table();
			for(j = 0; j < L; j++)
			{
				fgets(string, 50, stdin);
				put(ht, words_hash, string, number_of_words);
				number_of_words++;
			}
			printf("%d\n", hash(ht, words_hash));
						
			words_hash++;
			number_of_words = 0;
			free(ht);
	}
	return 0;
}

//criar uma ht com apenas 1 espa�o, apontado p/ lista encadeada. a lista vai crescer e ter as vari�veis de posi��o

	

hash_table* create_hash_table(){
	hash_table *new_hash_table =(hash_table*) malloc(sizeof(hash_table));

	int i;
	for (i = 0; i < 100; i++) {
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

int hash(hash_table *ht, int key){
	element* current = ht->table[key];
//	int value;
	int result = 0;
	int size = strlen(current->string);
	int i = 0;
	while(current != NULL){
		for(i = 0; i < size;i++){
			if(current->string[i] != '\n'){
			//value = (int) current->string[i] - 'A';
			result += ((int) current->string[i]) - 65 + i + current->element_number;
			}
		}
	current = current->next;
	}
	return result;		
	
}

element* put(hash_table *ht, int key, char* string, int element_number){
	element* prev = NULL;
	element* current = ht->table[key];
	while(current != NULL){
	prev = current;
	current = current->next;
	}
	current = (element*) malloc(sizeof(element));
	strcpy(current->string,string);
	current->next = NULL;
	current->element_number = element_number;
	if(prev == NULL)
		ht->table[key] = current;
	else
		prev->next = current;
	return current;
	
}
