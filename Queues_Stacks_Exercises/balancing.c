#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct no No;
typedef struct pilha Pilha;

struct no {
char info;
struct no* prox;
};


struct pilha {
No* prim;
};

Pilha* cria (void)
{
Pilha* p = (Pilha*) malloc(sizeof(Pilha));
p->prim = NULL;
return p;
}

/* fun??o auxiliar: insere no in?cio */
No* ins_ini (No* l, char v)
{
No* p = (No*) malloc(sizeof(No));
p->info = v;
p->prox = l;
return p;
}

/* fun??o auxiliar: retira do in?cio */
No* ret_ini (No* l)
{
No* p = l->prox;
free(l);
return p;
}


void push (Pilha* p, char v)
{
p->prim = ins_ini(p->prim,v);
}


char pop (Pilha* p)
{
char v;
if (vazia(p)) {
//printf("Pilha vazia.\n");
exit(1);
/* aborta programa */
}
v = p->prim->info;
p->prim = ret_ini(p->prim);
return v;
}

int vazia (Pilha* p)
{
return (p->prim==NULL);
}

void libera (Pilha* p)
{
No* q = p->prim;
while (q!=NULL) {
No* t = q->prox;
free(q);
q = t;
}
free(p);
}

/* imprime: vers?o com lista */
void imprime (Pilha* p)
{
No* q;
for (q=p->prim; q!=NULL; q=q->prox)
printf("%c\n",q->info);
}

char mostra (Pilha* p)
{
No* q = p->prim;
return q->info;
}

int igual(char a, char b)
{
	if(a == '[' && b == ']')
	{
		return 1;
	}
	else if(a == '{' && b == '}')
	{
		return 1;	
	}
	else if(a == '(' && b == ')')
	{
		return 1;
	}
	return 0;
}

int main()
{
	char entrada[255];
	int n = 0, var , i = 0, cont = 0;
	char temp;
	Pilha* p = cria();
	scanf("%d ", &n);
	while(n > 0)
	{
    	fgets(entrada, 255, stdin);
		for(i = 0; i < strlen(entrada); i++)
			{
				if(entrada[i] == '(' || entrada[i] == '{' || entrada[i] == '[')
				{
					push(p,entrada[i]);
					cont++;
				}
				if(entrada[i] == ')' || entrada[i] == '}' || entrada[i] == ']')
				{
					if(vazia(p))
					{
						printf("No\n");
						break;
					}
					else
					{
						temp = pop(p);
						if(!igual(temp, entrada[i]))
						{
							printf("No\n");
							break;						
						}
					}
				}
			}
			if(vazia(p))
			{
				printf("Yes\n");
			}else
			{
				printf("No\n");
			}
	n--;
	}
	return 0;
}
