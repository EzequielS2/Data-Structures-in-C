#include<stdio.h>

#define tam 100


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

void teste(int aux, int aux1)
{
	
	if(aux==aux1)
	{
		printf("\nAs filas tem elemntos iguais\n\n");
	}
	else if(aux>aux1)
	{
		printf("\nA fila 1 é maiorque a fila 2\n\n");
	}
	else
	{
		printf("\nA fila 2 é maior que a fila 1\n\n");
	}
}


int main()
{
	int aux=0, aux1=0, i;	

	struct tfila a, b;
	
	inicializarFila(&a);
	inicializarFila(&b);

	a.fila[0]=1;
	a.fila[1]=2;
	a.fila[2]=4;

	b.fila[0]=5;
	b.fila[1]=3;
	b.fila[2]=6;
	b.fila[3]=7;

	a.R=2;
	b.R=3;

	while(filaVazia(&a)!=0)
	{
		retirarFila(&a, &i);
		aux++;
	}
	
	while(filaVazia(&b)!=0)
	{
		retirarFila(&b, &i);
		aux1++;
	}
	
	teste(aux, aux1);
}	














