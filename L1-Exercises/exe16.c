#include<stdio.h>

#define tam 3

struct tno
{
	int numero;
};



struct tlista
{
	int qtnos;
	struct tno lista[tam];
};



void inicializarLista(struct tlista *a)
{
	a->qtnos=0;
}

int listaCheia(struct tlista *a)
{
	if(a->qtnos==tam)
	{
		return 0;
	}
	
	return 1;
}

int listaVazia(struct tlista *a)
{
	if(a->qtnos==0)
	{
		return 0;
	}
	
	return 1;
}

int buscaLista(struct tlista *a, int num)
{
	int i;

	for(i=0; i<a->qtnos; i++)
	{
		if(a->lista[i].numero==num)
		{
			return i;
		}
	}
	return -1;
}


void imprimirLista(struct tlista *a)
{
	int i;

	for(i=0; i<a->qtnos; i++)
	{
		printf("%d\t", a->lista[i].numero);
	}
	printf("\n\n");
}


int inserirLista(struct tlista *a, int num)
{
	int i;

	if(listaCheia(a)==0)
	{
		return 0;	
	}
	
	i=buscaLista(a, num);
	
	if(i>=0)	
	{
		return 0;
	}
	
	a->lista[a->qtnos].numero=num;
	
	a->qtnos++;

	return 1;
}

int removerLista(struct tlista *a, int num)
{
	int i;

	if(listaVazia(a)==0)
	{
		return 0;
	}
	
	i=buscaLista(a, num);

	if(i<0)
	{
		return 0;
	}
	
	a->qtnos--;
	
	a->lista[i].numero=a->lista[a->qtnos].numero;
			
	return 1;
}

int desemfilar(struct tlista *a, int *num)
{
	if(listaVazia(a)==0)
	{
		return 0;
	}
	
	a->qtnos--;

	*num=a->lista[a->qtnos].numero;

}	
	

void inverterLista(struct tlista *a, struct tlista *b)
{
	int i;
	
	for(i=0; i<tam; i++)
	{
		inserirLista(a, b->lista[i].numero);
	}
		
}

int main()
{
	int i, num;
	
	struct tlista a, b;

	inicializarLista(&a);
	
	inicializarLista(&b);
	
	for(i=0; i<tam; i++)
	{
		printf("Digite um numero: ");
		scanf("%d", &num);
		inserirLista(&a, num);
	}

	for(i=0; i<tam; i++)
	{
		
		desemfilar(&a, &num);
		inserirLista(&b, num);
	}

	inverterLista(&a,&b);

	printf("\nLista invertida: ");
	imprimirLista(&a);
}
	
	
	















