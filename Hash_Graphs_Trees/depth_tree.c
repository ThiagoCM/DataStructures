#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

struct binary_tree {
	int item;
	int depth;
	struct binary_tree *left;	
	struct binary_tree *right;
};typedef struct binary_tree binary_tree;

binary_tree* create_empty_binary_tree() {
return NULL;
}

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right) {
binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
new_binary_tree->item = item;
new_binary_tree->left = left;
new_binary_tree->right = right;
new_binary_tree->depth = 0;
new_binary_tree->depth++;
return new_binary_tree;
}

binary_tree* add(binary_tree *bt, int item, char character, int depth)
{
if (bt == NULL) {
bt = create_binary_tree(item, NULL, NULL);
} else if (character != ')') {
bt->left = add(bt->left, item, character);
} else {
bt->right = add(bt->right, item, character);
}
return bt;
}

int add_bt(binary_tree *bt, int item, char character, int depth, int depth_result) {
	binary_tree *aux = bt;
	int depth_aux = depth_result;
	if(bt == NULL) {
		bt->item = item;
		bt->left = NULL;
		bt->right = NULL;
		bt->depth = 1;
		depth_aux = 1;
	}
	if(bt != NULL) {
		
	}
	
}

void print_pre_order(binary_tree *bt)
{
if (bt != NULL) {
printf("%d\n", bt->item);
print_pre_order(bt->left);
printf("parou!");
print_pre_order(bt->right);
}
}

//int GetNumber(char *str) {
//  while (!(*str >= '0' && *str <= '9') && (*str != '-') && (*str != '+')) str++;
//  int number;
//  if (sscanf(str, "%d", &number) == 1) {
//    return number;
//  }
  // No int found
//  return -1;
//}

main(){
	char character, string[MAX];
	int i = 0, value, size, flag;
	int contador_aberto = 0;
	//int contador_fechado = 0;
	//fgets(string, MAX, stdin);
	binary_tree *bt = create_empty_binary_tree();
//	size = strlen(string);
	scanf(" %d", &value);
//	printf("%d", value);
	//for(i=0;i<size;i++){
		while(scanf("%c", &character) != EOF)
		{
		string[i] = character;
			if(character == '(') {
				++contador_aberto;
				if(scanf("%d", &value) > 0){
				bt = add(bt, value, string[i-2], contador_aberto);			
				}
			}
			else if(character == ')') {
			//	contador_aberto--;
			//	contador_fechado++;
			}
			else if(character == '\n' || character == '\0' || character == '\t'){
			}
			else{
			}
		i++;
		}
		//}
	print_pre_order(bt);
}
