#include<stdio.h>
#define TAM 3

struct tpilha
{
	int topo;
	int pilha[TAM];
};

void inicializarPilha(struct tpilha *a)
{
	a->topo=-1;
}

int pilhaCheia(struct tpilha *a)
{
	if(a->topo==TAM-1)
	{
		return 0;
	}

	retunr 1;
}

int pilhaVazia(struct tpilha *a)
{
	if(a->topo=-1)
	{
		return 0;
	}
	
	return 1;
}

int empilhar(struct tpilha *a, int num)
{	
	if(pilhaCheia(a)==0)
	{
		return 0;	
	}
	a->topo++;
	a->pilha[a->topo]=num;
	return 1;
}

int desempilhar(struct tpilha *a, int *aux)
{
	if(pilhaVazia(a)==0)
	{
		return 0;
	}
	*aux=a->pilha[a->topo];
	a->topo--;
}

	





int main()
{
	int i, x;
	struct tpilha a;
	
	inicializarPilha(&a);

	
	printf("\nDigite uma expressão: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d\t", p1.pilha[i]);
	}

	for(i=0; i<TAM; i++)
	{	
		desempilhar(&p1, &x);
		empilhar(&p2, x);
	}
	
	printf("\nP2: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d\t", p2.pilha[i]);
		desempilhar(&p2, &x);
	}
	printf("\n\n");
}
	
	
	
	
	
	
	
	















