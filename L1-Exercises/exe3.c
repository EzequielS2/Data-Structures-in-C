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

int pilhaVazia(struct tpilha *a)
{
	if(a->topo==-1)
	{
		return 0;
	}
	return 1;
}

int pilhaCheia(struct tpilha *a)
{
	if(a->topo==TAM-1)
	{
		return 0;
	}
	return 1;
}

int empilhar(struct tpilha *a, int valor)
{
	if(pilhaCheia(a)==0)
	{
		return 0;
	}
	
	a->topo++;
	a->pilha[a->topo]=valor;
	return(1);
}

int desempilhar(struct tpilha *a, int *elem)
{
	if(pilhaVazia(a)==0)
	{
		return 0;
	}
	*elem=a->pilha[a->topo];
	a->topo--;
	return 1;
}



int main()
{
	int i, x;
	struct tpilha p1, p2, p3;
	
	inicializarPilha(&p1);
	inicializarPilha(&p2);
	inicializarPilha(&p3);

	for(i=0; i<TAM; i++)
	{
		printf("\nDIgite um número: ");
		scanf("%d", &x);
		empilhar(&p1, x);
	}
	
	for(i=0; i<TAM; i++)
	{	
		desempilhar(&p1, &x);
		empilhar(&p2, x);
	}
	
	for(i=0; i<TAM; i++)
	{
		desempilhar(&p2, &x);
		empilhar(&p3, x);
	}
	printf("\nCopia: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d\t", p3.pilha[i]);
		desempilhar(&p3, &x);
	}
	printf("\n\n");
}
	
	
	
	
	
	
	
	















