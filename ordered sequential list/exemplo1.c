//ESCREVA UM PROGRAMA USANDO UMA LISTA SEQUENCIAL ORDENADA CONTENDO OS SEGUINTES DADOS DE CLIENTES DE UMA LIVRARIA : NOME,CODIGO DE IDENTIFICACAO,E TIPO DE LEITURA PREFERIDO.
//CREI A ESTRUTURA PARA 10 CLIENTES E MOSTRE O MENU ABAIXO :
//1-INSERÇÃO
//2-IMPRESSÃO
//3-BUSCAR CLIENTE NA LISTA
//4-REMOVER CLIENTE DA LISTA
//5-SAIR


#include<stdio.h>
#include<string.h>



#define tam 10

struct livraria
{
	int codigo, idade;
	char nome[60], tipo[60];
};

struct tlista
{
	int qtnos;
	struct livraria lista[tam];
};

void inicializarLista(struct tlista *pl)
{
	pl->qtnos=0;
}

int listaCheia(struct tlista *pl)
{
	if(pl->qtnos==0)
	{
		return 0;
	}
	return 1;
}

int listaVazia(struct tlista *pl)
{
	if(pl->qtnos==tam)
	{
		return 0;
	}
	return 1;
}

int buscaSequencial(struct tlista *pl, int codigo1, int *posicao)
{
	int i;

	for(i=0; (i<pl->qtnos)&&(codigo1>pl->lista[i].codigo); i++);
	
	if((i==pl->qtnos)||(codigo1!=pl->lista[i].codigo))
	{
		return 0;
	}
	return 1;
}

int inserirLista(struct tlista *pl, int codigo1, int idade1, char nome1[], char tipo1[])
{
	int i, posicao;
	if(listaCheia(pl)==0)
	{
		return 0;
	}
	
	if(buscaSequencial(pl, codigo1, &posicao)==0)
	{
		return -1;
	}
	
	for(i=pl->qtnos; i>posicao; i--)
	{
		pl->lista[i].codigo=pl->lista[i-1].codigo;
		pl->lista[i].idade=pl->lista[i-1].idade;
		strcpy(pl->lista[i].nome,pl->lista[i-1].nome);
		strcpy(pl->lista[i].tipo,pl->lista[i-1].tipo);
	}

	pl->lista[posicao].codigo=codigo1;
	pl->lista[posicao].idade=idade1;
	strcpy(pl->lista[posicao].nome, nome1);
	strcpy(pl->lista[posicao].tipo, tipo1);
	
	pl->qtnos++;
	return 1;
}


int removerLista(struct tlista *pl, int codigo1)
{
	int i, posicao;
	
	if(listaVazia(pl)==0)
	{
		return 0;
	}
	
	if(buscaSequencial(pl, codigo1, &posicao)==-1)
	{
		return -1;
	}
	for(i=posicao; i<pl->qtnos-1; i++)
	{
		pl->lista[i].codigo=pl->lista[i+1].codigo;
		pl->lista[i].idade=pl->lista[i+1].idade;
		strcpy(pl->lista[i].nome,pl->lista[i+1].nome);
		strcpy(pl->lista[i].tipo,pl->lista[i+1].tipo);
	}

	pl->qtnos--;


	return 1;
}








int main()
{
	struct tlista a;
	int num, i, codigo1, idade1, posicao;
	char p[60], tipo[60];
	inicializarLista(&a);
	for(i=0; i<tam; i++)
	{
		printf("\nDigite o nome: ");
		gets(p);
		printf("\nDigite a matricula: ");
		scanf("%d", &codigo1);
		printf("\nDigite a nota 1: ");
		scanf("%f", &idade1);
		printf("\nDigite o tipo do livro: ");
		gets(tipo);
		inserirLista(&a, codigo1, idade1, p, tipo);
		fgetc(stdin);
	}
	
	
	
	do{
		printf("\n\nMenu\n 1 - Inserção\n 2 - Impressão\n 3 - Busca de cliente\n 4 - Remover \n 5 - Sair\n\n");
		scanf("%d", &num);
		switch(num){
				case 1:
				if(listaCheia==0)
				{
					printf("\n\nA lista está cheia\n\n");
				}
				else
				{
					printf("\nDigite o nome: ");
					gets(p);
					printf("\nDigite a matricula: ");
					scanf("%d", &codigo1);
					printf("\nDigite a nota 1: ");
					scanf("%f", &idade1);
					printf("\nDigite o tipo do livro: ");
					gets(tipo);
					inserirLista(&a, codigo1, idade1, p, tipo);
					fgetc(stdin);
				}

				case 2:

				if(listaVazia(&a)!=0)
				{
					imprimir(&a);
				}
				else
				{
					printf("\nA turma está vazia\n\n");
				}
				break;
				
				
				case 3:
				printf("\nDigite o codigo do cliente para busca: ");
				scanf("%d", &codigo1);
				if(listaVazia(&a)!=0)
				{	if(i=buscaSequencial(&a, codigo1, &posicao)!=0)
					{
						printf("\nMatricula encontrada\n\n");
						printf("\n\nnome: %s \n codigo: %d \n Tipo de livro: %s \nIdade: %d", a.lista[i].nome, a.lista[i].codigo, a.lista[i].tipo, a.lista[i].idade);
					}
					else
					{
						printf("\n\nMatricula não encontrada\n\n");
					
					}
				}
				else
				{
					printf("\n\nA turma está vazia\n\n");
				}

				break;

				case 4:
				printf("\n\nDigite o codigo do cliente que deseja remover: ");
				scanf("%d", &codigo1);
				
				if(listaVazia(&a)!=0)
				{
					if(i=removerLista(&a, codigo1)!=-1)
					{
						printf("\nMatricula removida\n\n");
					}
					else
					{
						printf("\n\nMatricula não encontrada\n\n");
					}
				}
				else
				{
					printf("\n\nA turma está vazia\n\n");
				}
				break;
				
				case 5:
				break;
				
				default:
				printf("\n\nDigite corretamente\n\n");
			}
	}while(num!=5);
	
}