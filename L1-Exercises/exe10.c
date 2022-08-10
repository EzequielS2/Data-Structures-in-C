#include<stdio.h>
#define tam 3

struct tpilha
{
	int topo;
	int pilha[tam];
};

void inicializar(struct tpilha *a)
{
	a->topo=-1;
}

int pilhaCheia(struct tpilha *a)
{
	if(a->topo==tam-1)
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
	int i, num, x=0, soma=0, soma1=0, maior, menor, maior1, menor1;
	struct tfila b;
	struct tpilha a;
	
	inicializarFila(&b);
	inicializar(&a);

	printf("\nDigite um número: ");
	scanf("%d", &num);
	while(num!=0 && x<tam)	
	{
		empilhar(&a, num);
		printf("\nDigite um número: ");
		scanf("%d", &num);
		x++;
	}
	x=0;

	printf("\nDigite um número: ");
	scanf("%d", &num);

	while(num!=0 && x<tam)	
	{
		inserirFila(&b, num);
		printf("\nDigite um número: ");
		scanf("%d", &num);
		x++;
	}
	maior=a.pilha[0];
	menor=a.pilha[0];
	maior1=b.fila[0];
	menor1=b.fila[0];
	for(i=0; i<=b.R; i++)
	{
		if(a.pilha[i]>maior)
		{
			maior=a.pilha[i];
		}
		else if(menor<a.pilha[i])
		{
			menor=a.pilha[i];
		}
		soma=soma+a.pilha[i];
		if(b.fila[i]>maior1)
		{
			maior1=b.fila[i];
		}
		else if(menor1<b.fila[i])
		{
			menor1=b.fila[i];
		}
		soma1=soma1+b.fila[i];
	}
	printf("\n\nMédia da pilha: %f \nMenor da pilha: %d\n Maior da Pilha: %d", (float)soma/((a.topo)+1), menor, maior);
	printf("\n\nMédia da fila: %f \nMenor da fila: %d\n Maior da fila: %d", (float)soma1/((b.R)+1), menor1, maior1);

}
	
	
	
	
	
	
	
	















