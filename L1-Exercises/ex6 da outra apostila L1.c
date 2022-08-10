#include<stdio.h>

#define tam 3




struct tpilha
{
	int topo;
	int pilha[tam];
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
	if(a->topo==tam-1)
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
	int fila[tam];
};

void inicializarFila(struct tfila *a)
{
	a->R=-1;
	a->F=0;
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
	if(a->R==tam-1)
	{
		return 0;
	}
	
	return 1;
}

int inserirFila(struct tfila *a, int num)
{
	if(filaCheia(a)==0)
	{
		return 0;
	}
	a->R++;
	a->fila[a->R]=num;
	return 1;
}



int desemfilar(struct tfila *a, int *n)
{
	
	if(filaVazia(a)==0)
	{
		return 0;
	}
	
	*n=a->fila[a->R];
		
	a->R--;
}



int main()
{

	int i, n;
	struct tpilha b;

	struct tfila a;
	
	inicializarPilha(&b);
	
	inicializarFila(&a);

	for(i=0; i<tam; i++)
	{
		printf("\nDigia n: ");
		scanf("%d", &n);
	
		inserirFila(&a, n);
	}
	
	for(i=0; i<tam; i++)
	{
		desemfilar(&a, &n);
		empilhar(&b, n);
	}

	for(i=0; i<tam; i++)
	{
		inserirFila(&a, b.pilha[i]);
	}
	printf("\n\n");
	for(i=0; i<tam; i++)
	{
		printf("%d\t", a.fila[i]);
	}
}
	






	


















