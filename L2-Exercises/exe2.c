#include<stdio.h>
#include<stdlib.h>



struct lista
{
	int valor;
	
	struct lista *prox;
};

void imprimir(struct lista *a)
{
	while(a!=NULL)
	{
		printf("%d\t", a->valor);	
		a=a->prox;
	}
}
struct lista *criar(int n)
{
	struct lista *p, *a, *f;
	
	int i, num;
		
	a=f=NULL;
	
	for(i=0; i<n; i++)
	{
		printf("\nDigite um valor: ");
		scanf("%d", &num);
		p=(struct lista*)malloc(sizeof(struct lista));
		p->valor=num;
		p->prox=NULL;

		if(f!=NULL)
		{
			f->prox=p;		
		}

		else
		{
			a=p;
		}
		f=p;
	}
	
	return a;
}


	
	
struct lista *inserir(struct lista *a,int num)
{
	struct lista *b;

	b=(struct lista*)malloc(sizeof(struct lista));

	b->valor=num;

	if(a==NULL)
	{
		b->prox=NULL;
		return b;
	}
	else
	{
		b->prox=a;
		return b;
	}
}

struct lista *remover(struct lista *a, int num)
{
	struct lista *b, *t;   
	
	if(a==NULL)
	{
		return NULL;
	}
	else
	{
		b=a;
	
		while(b->valor!=num)
		{
			t=b;         // o ponteiro t serve apenas para guardar o endereço de memoria
			b=b->prox;
		}

		t->prox=b->prox;
		free(b);
		return a;
	}
}

struct lista *inserir1(struct lista *a, int num)
{
	struct lista *p, *q, *aux;
	
	q=(struct lista*)malloc(sizeof(struct lista));
	q->valor=num;
	
	if(a==NULL)
	{
		q->prox=NULL;
		return q;
	}
	else
	{	
		p=a;
		while(num>p->valor)
		{
			aux=a;
			a=a->prox;
		}	
		if(num>a->valor)
		{
			aux->prox=q;
			q=a;
			return p;
		}
		else
		{
			aux=q;
			q=p;
			
			return p;
		}
	}
}

int main()
{
	struct lista *a, *b;
			

	a=criar(3);
	imprimir(a);
	printf("\n\nLista modificada:");
	b=inserir1(a, 5);
	imprimir(b);
	printf("\n\n");
}

 	


