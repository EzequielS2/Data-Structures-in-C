#include<stdio.h>
#include<string.h>

#define tam 3

struct tno{

	int codigo;
	char nome[100];
};

struct tlivraria
{
	int qtnos;
	
	struct tno livraria[tam];
};


void inicializarLista(struct tlivraria *a)
{
	a->qtnos=0;
}

int listaCheia(struct tlivraria *a)
{
	if(a->qtnos==tam)
	{
		return 0;
	}
	return 1;
}

int listaVazia(struct tlivraria *a)
{
	if(a->qtnos==0)
	{
		return 0;
	}
	return 1;
}

int buscaBinaria(struct tlivraria *a, int codigo1)
{
	int ini, fim, meio;
	
	ini=0;
	fim=a->qtnos-1;

	while(ini<=fim)
	{
		meio=(ini+fim)/2;
		if(codigo1==a->livraria[meio].codigo)
		{
			return meio;
		}
	
		if(codigo1<a->livraria[meio].codigo)
		{
			fim=meio-1;
		}
		else
		{
			ini=meio+1;
		}
	}
	return -1;
}

void impressao(struct tlivraria *a)
{
	int i;
	for(i=0; i<a->qtnos; i++)
	{
		printf("\nNome: %s, Codigo: %d\n", a->livraria[i].nome, a->livraria[i].codigo);
	}
}
			


int inserirLista1(struct tlivraria *a, int codigo1, char nome1[])
{
	if(listaCheia(a)==0)	
	{
		return 0;
	}
	
	a->livraria[a->qtnos].codigo=codigo1;
	strcpy(a->livraria[a->qtnos].nome, nome1);
	a->qtnos++;
}


int removerLista(struct tlivraria *a, int codigo1)
{
	int i;
	if(listaVazia(a)==0)
	{
		return 0;
	}

	i=buscaBinaria(a, codigo1);

	if(i<0)
	{
		return 0;
	}
	
	a->qtnos--;

	a->livraria[i].codigo=a->livraria[a->qtnos].codigo;
	
	strcpy(a->livraria[i].nome, a->livraria[a->qtnos].nome);
	return 1;
}


int main()
{
	int i, x, codigo1;
	char nome1[100];
	struct tlivraria a;

	inicializarLista(&a);

	for(i=0; i<1; i++)
	{
		printf("\nDigite o nome: ");
		gets(nome1);
		printf("\nDigite o codigo: ");
		scanf("%d", &codigo1);
		fgetc(stdin);
		inserirLista1(&a, codigo1, nome1);
	}

	do{
		printf("\n1 - Ler e Buscar o cliente\n 2 - Inserir novo cliente\n 3 - Retirar cliente\n 4 - Sair\n");
		scanf("%d", &x);
		switch(x){
				case 1:
				fgetc(stdin);
				printf("\nDigite o codigo do cliente: ");
				scanf("%d", &codigo1);
				i=buscaBinaria(&a, codigo1);
				if(listaVazia(&a)==0)
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					if(i>=0)
					{
						printf("\nO cliente foi encontrado\n\n");
						printf("\nNome: %s, codigo: %d\n\n", a.livraria[i].nome, a.livraria[i].codigo);
					}
					else
					{
						printf("\nO cliente não foi achado\n\n");
					}
				}
				break;

				case 2:
					
				if(listaCheia(&a)==0)	
				{
					printf("\nA lista está cheia\n\n");
				}
				else
				{
					printf("\nDigite o codigo do cliente para inserir: ");
					scanf("%d", &codigo1);
					fgetc(stdin);
					printf("\nDigite o nome: ");
					gets(nome1);
					inserirLista1(&a, codigo1, nome1);
				}
				break;
				
				case 3:
				if(listaVazia(&a)==0)	
				{
					printf("\nA lista está vazia\n\n");
				}
				else
				{
					printf("\nDigite o codigo do cliente para remoção: ");
					scanf("%d", &codigo1);
					removerLista(&a, codigo1);
				}
				break;

				case 4:
				break;
				
				default:
				printf("\n\nDigite corretamente\n\n");
			}
		}while(x!=4);
}




	
	



				
	











