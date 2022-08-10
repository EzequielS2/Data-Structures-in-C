#include<stdio.h>

#define tam 10

struct tpilha{

	int topo;
	int pilha[tam];
};


void inicializarPilha(struct tpilha *a)
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
	if(pilhaCheia(a)==0)
	{
		return 0;
	}
	a->topo++;
	a->pilha[a->topo]=num;
    return 1;
}

int removerPilha(struct tpilha *a, int *aux)
{
	if(pilhaVazia(a)==0)
	{
		return 0;
	}
	*aux=a->pilha[a->topo];
	a->topo--;
	return 1;
}

void trocar(int *a, int *b)
{
	int *aux;

	*aux=*a;
	*a=*b;
	*b=*aux;
}

int buscaBinaria(struct tpilha *a, int num)
{
	int ini, meio, fim, i;
	ini=0;
	fim=(a->topo)-1;
	while(ini<=fim)
	{
		meio=(ini+fim)/2;
		if(a->pilha[meio]==num)
		{
			i=meio;
		}
		
		if(a->pilha[meio]<num)
		{
			ini=meio+1;
		}
		else
		{
			fim=meio-1;
		}
	}
	if(i>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void ordenarPilha(struct tpilha *a)
{	
	int i, j, aux;
	


	for(j=1; j<tam; j++)
	{
		for(i=j; i>0 && a->pilha[i]>a->pilha[i-1]; i--)
		{
     		 	aux=a->pilha[i];
	    		a->pilha[i]=a->pilha[i-1];
	    		a->pilha[i-1]=aux;
		}
	}
}
	
	
	


int main()
{
	int i, num;

	struct tpilha a;

	inicializarPilha(&a);
	
	for(i=0; i<tam; i++)
	{
		printf("\nDigite um número: ");
		scanf("%d", &num);
		empilhar(&a, num);
	}	
	printf("\n\nVetor não ordenado: ");
	for(i=0; i<tam; i++)
	{
		printf("%d\t", a.pilha[i]);
	}
	printf("\n\n");


	printf("\nDigite um número para buscar: ");
	scanf("%d", &num);

	ordenarPilha(&a);

	printf("\n\nVetor ordenado: ");
	for(i=0; i<tam; i++)
	{
		printf("%d\t", a.pilha[i]);
	}

	i=buscaBinaria(&a, num);
	
	if(i>=0)
	{
		printf("\nO número foi encontrado\n\n");
		printf("\nRtorno: %d", i);
	}
	else
	{
		printf("\nO número não foi encontrado\n\n");
		printf("\nRetorno: %d", i);
	}
}
















