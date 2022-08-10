#include<stdio.h>
#define TAM 4


struct tfila
{
	int R, F;
	int fila[TAM];
};

void inicializar(struct tfila *a)
{
	a->R=-1;
	a->F=0;
}

void vazio(struct tfila *a)
{
	if(a->F>a->R)
	{
		return 0;
	}
	return 1;
}

void cheio(struct tfila *a)
{
	if(a->R==TAM-1)
	{
		return 0;
	}
	return 1;
}

void inserir(struct tfila *a, int num)
{
	if(cheio(a)==0)
	{
		return 0;
	}
	a->R++;
	a->fila[a->R]=num;
}

void remover(struct tfila *a, int *aux)
{
	if(vazio(a)==0)
	{
		return 0;
	}
	*aux=a->fila[a->F];
	a->F++;
}



