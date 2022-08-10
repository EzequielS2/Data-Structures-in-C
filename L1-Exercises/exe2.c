#include<stdio.h>
#define TAM 100

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
	int num=0, i, x;
	struct tpilha a;
	
	inicializarPilha(&a);

	printf("\nDigite um número decimal: ");
	scanf("%d", &x);

	while(x>0)
	{
		empilhar(&a, x%2);
		x=x/2;
		num++;
	}
	printf("\nNúmero em binário: ");
	for(i=0; i<num; i++)
	{
		printf("%d", a.pilha[i]);
		desempilhar(&a, &x);
	}
	printf("\n\n");
}
	
	
	
	
	
	
	
	















