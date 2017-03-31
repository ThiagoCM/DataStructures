#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "binary_tree.h"

typedef struct binary_tree {

int item;

struct binary_tree *left;

struct binary_tree *right;

}binary_tree;

binary_tree* create_empty_binary_tree()

{

	return NULL;

}


binary_tree* create_binary_tree( int item, binary_tree *left, binary_tree *right)

{

			binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));

			new_binary_tree->item = item;

			new_binary_tree->left = left;

			new_binary_tree->right = right;

			return new_binary_tree;

 }
 bool is_empty(binary_tree *bt)
 {
 	return (bt == NULL);
 }

 int search_binary(binary_tree *bt, int item)

{
	if(bt == NULL)
		return 0;

	else if ( (bt->item == item))
		      return 1;

    else if(bt != NULL)
    {

		 if (bt->item > item) 
			return search_binary(bt->left, item);
 
		 else 
			return search_binary(bt->right, item);
    }
   

}



int altura_binary_tree( binary_tree *arvore)
{
	binary_tree *bt = arvore;
	if (bt != NULL)
	{
			int alt_left = altura_binary_tree(bt -> left);
		int alt_right = altura_binary_tree(bt -> right);
		if(alt_left >= alt_right)
			 return (alt_left + 1);

		else
			return (alt_right +1);
	}

}

int max(int a, int b)

{

    return (a > b) ? a : b;

}

int h(binary_tree *bt)

{

	if (bt == NULL)
	     return -1;

	else 
	   return 1 + max(h(bt->left), h(bt->right));
 

}
void procura(binary_tree *bt, int num, int *altura)
{
	 if (bt != NULL)
	{
		if(bt->item == num)
			  (*altura) = h(bt);
		procura(bt -> left, num,altura);
		procura(bt -> right, num,altura);
	}
}

	



void add(binary_tree **bt, int item)

{

	if (*bt == NULL)
		*bt = create_binary_tree(item, NULL, NULL);
	else if ((*bt)->item > item)
		add(&(*bt)->left, item);
	 else 
		add(&(*bt)->right, item);

}


 binary_tree* insert(binary_tree * bt, int *array,int *current,int size);
int main(int argc, char const *argv[])
{

    int vetor[10000],cont= 0,cont2 = 0, funcao=0;
    char char1,char2;
    binary_tree *aux = create_empty_binary_tree();

    while(scanf("%c", &char1) != EOF)
	 {
	        if(char1 == '(')
	        {
	           int value;
	           if(scanf("%d", &value)> 0){
	            	vetor[cont++] = value;
	            	add(&aux, value);
	            	cont2++;

	           }
	               	 
	        }

	        else if(char1 == ')' && char2 == '(')
	            vetor[cont++] = -1;

	        if(char1 == '\n') 
	              break; 
	        char2 = char1;

    }

   int n,altura;
   scanf("%d",&n);
   int veri = search_binary(aux,n);
   if (veri )
   {
   	   printf("ESTA NA ARVORE\n");
       binary_tree *arvore = create_empty_binary_tree();
	   arvore = insert(arvore,vetor,&funcao,cont);
	    procura(arvore, n, &altura);
	     printf("%d\n",h(arvore) - altura);
   
   }
   else
   	printf("-1\n");
  
   
}





 binary_tree* insert(binary_tree * bt, int *array,int *current,int size)
 {
    if( array[*current]==-1 || *current>size ){
        return NULL;
    }

    if(bt == NULL){
        bt = create_binary_tree(array[*current],NULL,NULL);
        (*current)++;
    }

    if(array[*current] != -1){
        bt->left = insert(bt->left,array,current,size);
    }
    
    else{
        (*current)++;
    }
    
    if(array[*current]!=-1){
        bt->right = insert(bt->right,array,current,size);
    }
    else{
        (*current)++;    
    }
    

    return bt;
}
