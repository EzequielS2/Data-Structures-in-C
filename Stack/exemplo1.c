#include<stdio.h>
#define TAM 5

struct tpilha
{
	int topo;
	int pilha[TAM];
};

void inicializa(struct tpilha *a)
{
	a->topo=-1;
}


int vazio(struct tpilha *a)
{
	if(a->topo==-1)
	{
		return 0;
	}
	return 1;
}

int cheio(struct tpilha *a)
{
	if(a->topo==TAM-1)
	{
		return 0;
	}
	return 1;
}

int empilhar(struct tpilha *a, int num)
{
	if(cheio(a)==0)
	{
		return 0;
	}
	
	a->topo++;
	a->pilha[a->topo]=num;
	return 1;
}

int desempilhar(struct tpilha *a, int *num)
{
	if(vazio(a)==0)
	{
		return 0;
	}
	*num=a->pilha[a->topo];
	a->topo--;

	return 1;
}



int main()
{
	int i, num;
	struct tpilha a;
	
	inicializa(&a);
	
	for(i=0; i<TAM; i++)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &num);
		empilhar(&a, num);
	}
	
	printf("\n\nElementos no vetor: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d \t", a.pilha[i]);
	}
}
	
















