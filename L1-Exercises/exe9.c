#include<stdio.h>

#define tam 3
#define tam1 6

struct tpilha
{
	int topo;
	int pilha[tam1];
};

void inicializar(struct tpilha *a)
{
	a->topo=-1;
}

int pilhaCheia(struct tpilha *a)
{
	if(a->topo==tam1-1)
	{
		return 0;
	}

	return 1;
}

int pilhaVazia(struct tpilha *a)
{	
	if(a->topo==-1)
	{
		return 0;
	}

	return 1;
}

int empilhar(struct tpilha *a, int num)
{
	if(pilhaCheia==0)
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

int retirarFila(struct tfila *a, int *aux)
{
	if(filaVazia(a)==0)
	{
		return 0;
	}

	*aux=a->fila[a->F];
	a->F++;
	return 1;
}


int main()
{
	int i, num, x=0;

	struct tfila par, impar;
	struct tpilha a;

	inicializarFila(&par);
	inicializarFila(&impar);
	inicializar(&a);

	printf("\nDigite um número: ");
	scanf("%d", &i);
	while(i!=0 && x<2*tam)
	{
		if(i%2==0)
		{	
			inserirFila(&par, i);
		}
		else if(i%2!=0)
		{
			inserirFila(&impar, i);
		}
		printf("\n Digite um número: ");
		scanf("%d", &i);
		x++;
	}
		
	for(i=0; i<tam; i++)	
	{
		
		printf("%d , %d\t", impar.fila[i], par.fila[i]);
		retirarFila(&impar, &num);
		if(num>0)
		{
			empilhar(&a, num);
		}
		retirarFila(&par, &num);
		if(num>0)
		{
			empilhar(&a, num);
		}
	}
	
	printf("\nPilha preenchida: ");
	for(i=0; i<=a.topo; i++)
	{
		printf("%d\t", a.pilha[i]);
	}
	printf("\n\n");
}
	

	




