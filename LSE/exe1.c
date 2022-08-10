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
		b=p;
		n=1;
		while(n!=k)	
		{
			a=b;
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
				
	
struct lista *inserirNo(struct lista *a, int num)
{
	struct lista *b;
	
	b=(struct lista *)malloc(sizeof(struct lista));
	
	b->valor=num;
	
	if(a!=NULL)
	{
		b->prox=a;
		return b;
	}
	else
	{
		b->prox=NULL;
		return b;
	}
}

struct lista *busca(struct lista *a, int num, int *b)
{
	while(a->prox!=NULL)
	{
		a=a->prox;
		if(a->valor==num)
		{
			*b=1;
		}
	}
	return a;
}		




int main()
{
	int i, x, n;
	
	struct lista *a, *b;
	
	printf("\nDiga quantos nos vai ter a lista: ");
	scanf("%d", &n);

	a=criar(n);
	
	
	do{
		printf("\n\n--------------Menu-------------\n\n 1 - Imprimir lista\n 2 - Inserir um nó na lista\n 3 - Contar os nós da lista\n 4 - Remover o k-esimo no da lista\n 5 - Buscar um nó na lista\n 6 - Copia da lista\n 7 - Sair\n\n");
		scanf("%d", &n);
		switch(n){
				case 1:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\n------------------------------------------\n\n");
					printf("\nElementos: ");
					imprimirLista(a);
					printf("\n\n-----------------------------------------\n\n");
				}
				break;
				
				case 2:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazio\n\n");
				}
				else
				{
					printf("\nDigite o valor para inserir na lista: ");
					scanf("%d", &x);
					a=inserirNo(a, x);
				}
	
				case 3:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					x=quantidadeNos(a);
					printf("\n\nQuantidade de nos da lista: %d\n\n", x);
				}
				break;

				case 4:
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

				case 5:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\nDigite um valor para busca: ");
					scanf("%d",&x);
					i=0;
					busca(a, x, &i);
					if(i==1)
					{
						printf("\nO numero foi encontradao\n\n");
					}
					else
					{
						printf("\nO numero não foi encontrado\n\n");
					}	
				}
				break;

				case 6:
				if(a->prox==NULL)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					b=copia(a);
					printf("\n\nA lista foi copiada\n\n Copia: \n\n");
					imprimirLista(b);
				}
				break;
				
			
				case 7:
				break;

				default:
				printf("\nDigite corretamente\n\n");
			}
	}while(n!=7);
}






