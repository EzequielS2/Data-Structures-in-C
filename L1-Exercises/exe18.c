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

	
	
int main()
{
	int i, x, num;
	
	struct tlista a;
	
	inicializarLista(&a);

	do{		
		printf(" \n----------------Menu--------------\n\n 1 - Exibir lista\n 2 - Inserir lista\n 3 - Remover lista\n 4 - Exibir elementos da lista\n 5 - Exibir posição do elemento da lista\n 6 - Esvaziar lista\n 7 - Sair\n\n");	
		scanf("%d", &x);
	
		switch(x){
				case 1: 
				if(listaVazia(&a)==0)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\n\nElementos da lista: ");
					imprimirLista(&a);
				}
				printf("\n\n");
				break;


				case 2:
				if(listaCheia(&a)==0)
				{
					printf("\nA lista está cheia\n");
				}
				else
				{
					printf("\nDigite um número: ");
					scanf("%d", &num);
					inserirLista(&a, num);
				}
				break;


				case 3:
				if(listaVazia(&a)==0)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\nDigite o numero que deseja retirar da lista: ");
					scanf("%d", &num);
					if(buscaLista(&a, num)==0)
					{
							printf("\nO numero não foi encontrado\n\n");		
					}
					printf("\nNumero removido\n\n");	
					removerLista(&a, num);
				}
				break;

				case 4:
				printf("\nDiga a posição do numero para busca: ");
				scanf("%d", &num);
				if(buscaLista(&a, a.lista[num].numero)==-1)
				{
					printf("\nNumeor nao encontrado\n");
				}
				else
				{
					printf("\nO numero %d foi encontrado\n\n", a.lista[num].numero);
				}
				break;

				case 5:
				printf("\nDiga o numero para busca: ");
				scanf("%d", &num);
				if(buscaLista(&a, num)==0)
				{
					printf("\nNumeor nao encontrado\n");
				}
				else
				{
					printf("\nO numero está na posição %d foi encontrado\n\n", buscaLista(&a, num));
				}
				break;


				case 6:
				while(a.qtnos>0)
				{
					a.qtnos--;
				}
				if(a.qtnos==0)
				{
					printf("\nA lista foi esvaziada\n\n");
				}
				else if(a.qtnos>0)
				{
					while(a.qtnos>0)
					{
						a.qtnos--;
					}
				}
				else
				{
					printf("\nA lista foi esvaziada\n\n");
				}

				break;

				case 7:
				break;


				default:
				printf("\n\nDigite corretamente\n\n");
			}
	}while(x!=7);
}	

		
	
	































