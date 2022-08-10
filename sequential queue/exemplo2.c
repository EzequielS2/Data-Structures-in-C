#include<stdio.h>
#define TAM 7

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

struct tfila
{
	int F, R;
	int fila[TAM];
};

void inicializarFila(struct tfila *a)
{
	a->F=0;
	a->R=-1;
}


int filaVazia(struct tfila *a)
{
	if(a->F>a->R)
	{
		return 0;
	}
	return 1;
}


int filaCheia(struct tfila *a)
{
	if(a->R==TAM-1)
	{
		return 0;
	}
	return 1;
}


int inserirFila(struct tfila *a, int x)
{
	if(filaCheia(a)==0)
	{
		return 0;
	}
	a->R++;
	a->fila[a->R]=x;
	return 1;
}

int retirarFila(struct tfila *a, int *num)
{
	if(filaVazia(a)==0)
	{
		return 0;
	}
	*num=a->fila[a->F];
	a->F++;
	return 1;

}

int main()
{
	int num, i, x;
	struct tfila f1;
	struct tpilha a;
	
	inicializarPilha(&a);
	inicializarFila(&f1);
	for(i=0; i<TAM; i++)
	{
		printf("digite um numero: ");
		scanf("%d", &x);
		inserirFila(&f1, x);
	}
	printf("\nVetor lido: ")
	for(i=0; i<TAM; i++)
	{
		retirarFila(&f1, &x); // ** Não esquecer o & nas structs, pois elas não estão como ponteiros.
		printf("%d\t", x);
		empilhar(&a, x);
	}
	printf("\n\n");
	inicializarFila(&f1);
	for(i=0; i<TAM; i++)
	{
		desempilhar(&a, &x);
		printf("%d\n", x);
		inserirFila(&f1, x);
	}
	printf("\n\nValor da fila invertida: ");	
	for(i=0; i<TAM; i++)
	{
		printf("%d\t", f1.fila[i]);
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	















