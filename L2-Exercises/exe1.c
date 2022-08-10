#include<stdio.h>
#include<stdlib.h>



struct lista
{
	int valor;
	
	struct lista *prox;
};


struct lista *criar(int n)
{
	int i, x;
	
	struct lista *nl, *f, *p;
	
	nl=f=NULL;
	
	for(i=0; i<n; i++)
	{
		printf("\nDigite um numero: ");
		scanf("%d", &x);
		
		p=(struct lista*)malloc(sizeof(struct lista));
	
		p->valor=x;

		p->prox=NULL;
	
		if(f!=NULL)
		{
			f->prox=p;
		}
		else
		{
			nl=p;
		}
		f=p;
	}
	return nl;
}

void imprimirLista(struct lista *a)
{

	while(a!=NULL)
	{
		printf("%d\t", a->valor);
		a=a->prox;
	}
	printf("\n\n");
}	
	
int quantidadeNos(struct lista *a)
{	
	int n=0;

	while(a!=NULL)	
	{
		n++;
		a=a->prox;
	}
	
	return n;
}


struct lista *removerkTermo(struct lista *p, int k)
{
	struct lista *a, *b;
	int n;
	
	if(k==1)
	{
		if(p->prox==NULL)
		{
			free(p);
			return 	NULL;
		}
		else
		{
			a=p->prox;
			p->prox=NULL;
			free(p);
			return a;
		}
	}
	else 
	{
		a=b;
		b=p;
		n=1;
		while(n!=k)	
		{
			b=b->prox;
			n++;
		}
		a->prox=b->prox;
		free(b);
		return p;
	
	}
}
		


	
struct lista *copia(struct lista *a)
{
	struct lista *p, *nl, *aux, *q;

	p=a;
	
	nl=q=NULL;
	
	while(p!=NULL)
	{
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=p->valor;
		aux->prox=NULL;
		
		if(nl==NULL)
		{
			nl=aux;
		}
		else
		{
			q->prox=aux;
		}	
		q=aux;
		p=p->prox;
		
	}

	return nl;
}
				
	
struct lista *par(struct lista *a)
{
	struct lista *nl, *aux, *q, *p;

	nl=q=NULL;
	
	p=a;
	
	while(p!=NULL)
	{
		aux=(struct lista*)malloc(sizeof(struct lista));
		if(p->valor%2==0)
		{
			aux->valor=p->valor;
		}
		aux->prox=NULL;
		
		if(nl==NULL)
		{
			nl=aux;
		}
		else
		{
			q->prox=aux;
		}
		q=aux;
		p=p->prox;
		
	}
	return nl;
}

			

struct lista *impar(struct lista *a)
{
	struct lista *nl, *aux, *q, *p;

	nl=q=NULL;
	
	p=a;
	
	while(p!=NULL)
	{
		aux=(struct lista*)malloc(sizeof(struct lista));
		if(p->valor%2!=0)
		{
			aux->valor=p->valor;
		}
		aux->prox=NULL;
		
		if(nl==NULL)
		{
			nl=aux;
		}
		else
		{
			q->prox=aux;
		}	
		q=aux;
		p=p->prox;
		
	}
	return nl;
}



int main()
{
	int i, x, n;
	
	struct lista *a, *b, *pares, *impares;
	
	printf("\nDiga quantos nos vai ter a lista: ");
	scanf("%d", &n);

	a=criar(n);
	
	do{
		printf("\n\n--------------Menu-------------\n\n 1 - Imprimir os elemntos da lista\n 2 - Contar os elemntos da lista\n 3 - Remover o k-esimo no da lista\n 4 - Copia da lista\n 5 - Inverter a lista\n 6 - Gerar uma lista com elemntos pares\n 7 - Gerar uma lista com elemntos impares\n 8 - Sair\n\n");
		scanf("%d", &n);
		switch(n){
				case 1:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					imprimirLista(a);
				}
				break;

	
				case 2:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					x=quantidadeNos(a);
					printf("\nQuantidade de nos da lista: %d", x);
				}
				break;

				case 3:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\nDiga qual o no que deseja remover: ");
					scanf("%d", &x);
					a=removerkTermo(a, x);
				}
				break;


				case 4:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					b=copia(a);
				}
				break;

				case 5:
				break;

				case 6:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					pares=par(a);
				}
				break;

				case 7:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					impares=impar(a);
				}
				printf("\nDeus esta vivio\n\n");
				break;
			
				case 8:
				break;

				default:
				printf("\nDigite corretamente\n\n");
			}
	}while(n!=8);
}






