#include<stdio.h>
#define TAM 4


struct tfila
{
	int R, F;
	int fila[TAM];
};

void inicializar(struct tfila *a)
{
	a->R=0;
	a->F=0;
}

void vazio(struct tfila *a)
{
	if(a->F==a->R)
	{
		return 0;
	}
	return 1;
}

void cheio(struct tfila *a)
{
	if((a->R+1)%TAM==a->F)
	{
		return 0;
	}
	return 1;
}

void inserir(struct tfila *a, int num)
{
	if(cheio(a))
	{
		return 0;
	}
	a->R=(a->R+1)%TAM;
	a->tfila[a->R]=num;
	return 1;
}

void retirar(struct tfila *a, *aux)
{
	if(vazio(a))
	{
		return 0;
	}
	a->F=(a->F+1)%TAM;
	*aux=a->tfila[a->F];
	return 1;
}



















	






