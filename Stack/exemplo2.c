#include<stdio.h>
#define TAM 4


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

int empilha(struct tpilha *a, int valor)
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
	struct tpilha a;
	int soma, media, pares, impares, i, num, x;
	inicializarPilha(&a); // É pra colocar &a, pois não colocamaos a como *a,  ou seja, ponteiro. 
	for(i=0; i<TAM; i++)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &num);
		empilha(&a, num);
	}
	printf("\n\nElementos da pilha: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d \t", a.pilha[i]); // A 
	}
	printf("\n\n");
	for(i=0; i<TAM; i++)
	{
		desempilhar(&a, &x);
		soma=soma+x;
		if(x%2==0)
		{
			pares++;
		}
		else
		{
			impares++;
		}
	}
	printf("\nQuantidade pares: %d e quantidade de impares: %d, Soma: %d e media: %f", pares, impares, soma, (float)soma/TAM);
}

	














