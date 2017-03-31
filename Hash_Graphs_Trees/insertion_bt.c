#include <stdio.h>
#include <stdlib.h>

struct binary_tree {
int item;
binary_tree *left;
binary_tree *right;
}; typedef struct binary_tree binary_tree;

binary_tree* create_empty_binary_tree()
{
return NULL;
}

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right)
{
binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));
new_binary_tree->item = item;
new_binary_tree->left = left;
new_binary_tree->right = right;
return new_binary_tree;
}

int main() {

}
