// Escreva um programa que leia 10 números reais e insira-os numa pilha P1 e IMPRIMA P1. Em seguida, gere uma copia
// de P1 numa pilha P3, use uma pilha P2 como estrutura auxiliar, imprima P3.




#include<stdio.h>
#define TAM 10

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
	struct tpilha P1, P2, P3;
	int num, x, i;
	inicializarPilha(&P1); // É pra colocar &a, pois não colocamaos a como *a,  ou seja, ponteiro. 
	inicializarPilha(&P2);
	inicializarPilha(&P3);
	for(i=0; i<TAM; i++)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &num);
		empilha(&P1, num);
	}
	printf("\n\nPilha P1: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d \t", P1.pilha[i]);
	}
	for(i=0; i<TAM; i++)
	{
		desempilhar(&P1, &x);
		empilha(&P2, x);
	}
	for(i=0; i<TAM; i++)
	{
		desempilhar(&P2, &x); // * Tem que usar o auxiliar, pois gravando direto para de P1 para P3
		P3.pilha[i]=x;        //   não fica certo na ordem. Por isso deve-se usar o auxiliar.
	}
	printf("\npilha P3: ");
	for(i=0; i<TAM; i++)
	{
		printf("%d \t", P3.pilha[i]);
	}	
	printf("\n\n");
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
