#include<stdio.h>

#define tam 10

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

int filaCheia(struct tlista *a)
{
	if(a->qtnos==tam)
	{
		return 0;
	}
	return 1;
}


int filaVazia(struct tlista *a)
{
	if(a->qtnos==0)
	{
		return 0;
	}
	
	return 1;
}

void imprimirLista(struct tlista *a)
{
	int i;

	for(i=0; i<a->qtnos; i++)
	{
		printf("%d\t", a->lista[i].numero);
	}
	
	pintf("\n\n");
}


int buscaLista(struct tlista *a, int num)
{
	int i;
	
	for(i=0;i<a->qtnos; i++)	
	{
		if(a->lista[i].numero==num)
		{
			return i;
		}
	}
	return -1;
}

int inserirLista1(struct tlista *a, int num) // **Esse insere pode inserir numeros já inseridos**
{
	if(listaCheia(a)==0)
	{
		return 0;
	}
	
	a->lista[a->qtnos].numero=num;
	
	a->qtnos++;
}

int inserirLista2(struct tlista *a, int num) // **Esse insere não insere numeros já colocados**
{
	if(listaCheia(a)==0)
	{
		return 0;
	}

	i=buscaLista(a, num);

	if(i>=0)
	{
		return 0;
	}

	a->lista[a->qtnos]=num;

	a->qtnos++;
}

int ordenacaoLista(struct tlista *a)
{
	int i, j, soma=0, soma1=0;
	
	for(j=1; j<a->qtnos; j++)
	{
		for(i=j; i>0 && a->lista[i-1]>a->lista[i] ; i--)
		{
			if(a->lista[i-1]<a->lista[i])
			{
				soma++;
			}
		}	
	
	}
	

	for(j=1; j<a->qtnos; j++)
	{
		for(i=j; i>0 && a->lista[i-1]<a->lista[i] ; i--)
		{
			if(a->lista[i-1]>a->lista[i])
			{
				soma1++;
			}
		}	
	
	}

	if(soma==0)
	{
		return 1;
	}
	if(soma1===0)
	{
		return 1;
	}
	
	return 0;
}

void copiarComRepeticao(struct tlista *a, struct tlista *b)
{
	
	for(i=0; i<a->qtnos; i++)	
	{
		inserirLista1(b, a->lista[i].numero);
	}
}


void copiarSemRepeticao(struct tlista *a, struct tlista *b)
{
	
	for(i=0; i<a->qtnos; i++)	
	{
		inserirLista2(b, a->lista[i].numero);
	}
}

void desemlistar(struct tlista *a, int *num)
{
	if(listaVazia(a)==0)
	{
		return 0;
	}
	a->qtnos--;
	
	*num=a->lista[a->qtnos].numero
	
	
void inverterLista(struct tlista *a)
{
	struct tlista *b;
	
	int i, k, num;

	k=a->qtnos;
	
	for(i=0; i<k; i++)
	{
		desemlista(a, &num);
		inserirLista1(b, num);
	}
		
	for(i=0; i<b->qtnos; i++)
	{
		inserirLista1(a, b->lista[i].numero);
	}
	
}
	
void intercalarSemRepeticaoLista(struct tlista *a, struct tlista *b, struct tlista *c)
{
	int i;

	for(i=0; i<a->qtnos; i++)	
	{
		inserirLista2(c, a->lista[i].numero);
		inserirLista2(c, b->lista[i].numero);
	}


}
	
void intercalarComRepeticaoLista(struct tlista *a, struct tlista *b, struct tlista *c)
{
	int i;

	for(i=0; i<a->qtnos; i++)	
	{
		inserirLista1(c, a->lista[i].numero);
		inserirLista1(c, b->lista[i].numero);
	}
}	
	
	
	

int main()

{
	int i;

	struct tlista L1, L2, L3, L4, aux;
	
	for(i=0; i<tam; i++)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &num);
		inserirLista1(&L1, num);
	}
	
	if(ordenacaoLista(&L1)==1)
	{
		printf("\nA lista está ordenada\n\n");
	}
	else
	{
		printf("\n\nA lista não está ordenada\n\n");
	}


	copiarComRepeticao(&L1, &L2);

	copiarSemRepeticao(&L1, &L2);

	inverterLista(&L1);

	intercalarSemRepeticaoLista(&L1, &L2, &L3);

	intercalarComRepeticaoLista(&L1, &L2, &L4);
}

	












