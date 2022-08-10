#include<stdio.h>
#include<string.h>
#define TAM 100

struct tpilha
{
	int topo;
	char pilha[TAM];
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

int empilhar(struct tpilha *a, char letra)
{
	if(pilhaCheia(a)==0)
	{
		return 0;
	}
	
	a->topo++;
	a->pilha[a->topo]=letra;

	return(1);
}

int desempilhar(struct tpilha *a, char *elem)
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
	int num=0, i;
	struct tpilha a;
	char nome[100], n;

	inicializarPilha(&a);

	printf("\nDigite uma palavra: ");
	gets(nome);
	for(i=0; i<strlen(nome); i++)
	{
		empilhar(&a, nome[i]);
		printf("%c\t", a.pilha[i]);
	}
	
	for(i=0; i<strlen(nome); i++)
	{
		if(a.pilha[a.topo]!=nome[i])
		{
			num++;
		}
		desempilhar(&a, &n);
	}
	if(num==0)
	{
		printf("\nA aplavra é políndromi 1\n\n");
	}
	else
	{
		printf("\nA palvra não é políndromi\n");
	}
	printf("\n\n");
}
	
	
	
	
	
	
	
	















