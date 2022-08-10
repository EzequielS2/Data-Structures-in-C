#include<stdio.h>

#include<string.h>

#define tam 2

struct tno
{
	int matricula;
	float n1, n2, media;
	char nome[60];
};

struct tlista
{
	int qtnos;
	
	struct tno turma[tam];
};

void inicializarLista(struct tlista *pl)
{
	pl->qtnos=0;
}

int listaVazia(struct tlista *pl)
{
	if(pl->qtnos==0)
	{
		return 0;
	}
	return 1;
}

int listaCheia(struct tlista *pl)
{
	if(pl->qtnos==tam)
	{
		return 0;
	}
	return 1;
}

void imprimir(struct tlista *pl)
{
	int i;
	for(i=0; i<pl->qtnos; i++)
	{
		printf("\n\nnome: %s \n matricula: %d \n notas: n1: %f - n2: %f \n media: %f\n\n", pl->turma[i].nome, pl->turma[i].matricula, pl->turma[i].n1, pl->turma[i].n2, pl->turma[i].media);
	}
}
int buscaMatricula(struct tlista *pl, int matricula1)
{
	int i;
	for(i=0; i<pl->qtnos; i++)
	{
		if(matricula1==pl->turma[i].matricula)
		{
			return i;
		}
	}
	return -1;
}


int insererirLista1(struct tlista *pl, int matricula1, float nota1, float nota2, char *nome1)
{
	 if(listaCheia(pl)==0)
	 {
	 	return 0;
	 }
	 pl->turma[pl->qtnos].matricula=matricula1;
	 pl->turma[pl->qtnos].n1=nota1;
	 pl->turma[pl->qtnos].n2=nota2;
	 pl->turma[pl->qtnos].media=(nota1+nota2)/2.0;
	 strcpy(pl->turma[pl->qtnos].nome, nome1);
	 pl->qtnos++;
	 return 1;
}

int inserirLista2(struct tlista *pl,  int matricula1, float nota1, float nota2, char *nome1)
{
	int i;
	
	if(listaCheia(pl)==0)
	{
		return 0;
	}
	i=buscaMatricula(pl, matricula1);
	
	if(i>=0)
	{
		return 0;
	}
	
	
	pl->turma[pl->qtnos].matricula=matricula1;
	pl->turma[pl->qtnos].n1=nota1;
	pl->turma[pl->qtnos].n2=nota2;
	pl->turma[pl->qtnos].media=(nota1+nota2)/2.0;
	strcpy(pl->turma[pl->qtnos].nome, nome1);
	pl->qtnos++;
	return 1;
}

	
int removerLista(struct tlista *pl, int matricula1)
{
	int i;
	
	if(listaVazia(pl)==0)
	{
		return 0;
	}
	
	
	i=buscaMatricula(pl, matricula1);
	
	if(i<0)
	{
		return -1;
	}
	
	pl->qtnos--;
	
	pl->turma[i].matricula=pl->turma[pl->qtnos].matricula;
	pl->turma[i].n1=pl->turma[pl->qtnos].n1;
	pl->turma[i].n2=pl->turma[pl->qtnos].n2;
	pl->turma[i].media=pl->turma[pl->qtnos].media;
	strcpy(pl->turma[i].nome, pl->turma[pl->qtnos].nome);

	return i;
}

	 

void copiar(struct tlista *pl, struct tlista *pl1)
{
	int i;
	if(listaVazia(pl)!=0)
	{
		for(i=0; i<pl->qtnos; i++)
		{
			strcpy(pl1->turma[i].nome, pl->turma[i].nome);
			pl1->turma[i].matricula=pl->turma[i].matricula;
			pl1->turma[i].n1=pl->turma[i].n1;
			pl1->turma[i].n2=pl->turma[i].n2;
			pl1->turma[i].media=pl->turma[i].media;
		}
	}
	else
	{
		printf("\nA turma está vazia\n\n");
	}
}	


int main()
{
	struct tlista a, b;
	int num, i, matricula1;
	float nota1, nota2, media;
	char p[60];
	inicializarLista(&a);
	inicializarLista(&b);
	for(i=0; i<tam; i++)
	{
		printf("\nDigite o nome: ");
		gets(p);
		printf("\nDigite a matricula: ");
		scanf("%d", &matricula1);
		printf("\nDigite a nota 1: ");
		scanf("%f", &nota1);
		printf("\nDigite a nota 2: ");
		scanf("%f", &nota2);
		inserirLista2(&a, matricula1, nota1, nota2, p);
		printf("\n\n%s\n\n", a.turma[i].nome);
		fgetc(stdin);
	}
	
	
	
	do{
		printf("\n\nMenu\n 1 - Impressão\n 2 - Buscar matricula\n 3 - Remover\n 4 - Mostrar média da turma\n 5 - Gerar e Imprimir\n 6 - Sair\n\n");
		scanf("%d", &num);
		switch(num){
				case 1:
				if(listaVazia(&a)!=0)
				{
					imprimir(&a);
				}
				else
				{
					printf("\nA turma está vazia\n\n");
				}
				break;
				
				
				case 2:
				printf("\nDigite a matricula de busca: ");
				scanf("%d", &matricula1);
				if(listaVazia(&a)!=0)
				{	if(i=buscaMatricula(&a, matricula1)!=-1)
					{
						printf("\nMatricula encontrada\n\n");
						printf("\n\nnome: %s \n matricula: %d \n notas: n1: %f - n2: %f \n media: %f\n\n", a.turma[i].nome, a.turma[i].matricula, a.turma[i].n1, a.turma[i].n2, a.turma[i].media);
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

				case 3:
				printf("\n\nDigite a matricula que deseja remover: ");
				scanf("%d", &matricula1);
				
				if(listaVazia(&a)!=0)
				{
					if(i=removerLista(&a, matricula1)!=-1)
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
				
				case 4:
				media=0;
				if(listaVazia(&a)!=0)
				{
					for(i=0; i<a.qtnos; i++)
					{
						media=a.turma[i].n1+a.turma[i].n2+media;
					}
				}
				else
				{	
					printf("\n\nA turma está vazia\n\n");
				}
				if(listaVazia(&a)!=0)
				{
					printf("\n\nMedia da turma: %f", (float)media/a.qtnos);
				}
				
				break;
				
				case 5:
				copiar(&a, &b);
				printf("\n\nCópia da turma:\n\n");
				for(i=0; i<a.qtnos; i++)
				{
					printf("\n\nnome: %s \n matricula: %d \n notas: n1: %f - n2: %f \n media: %f\n\n", b.turma[i].nome, b.turma[i].matricula, b.turma[i].n1, b.turma[i].n2, b.turma[i].media);
				}
				break;
				
				
				case 6:
				
				break;
				
				default:
				printf("\n\nDigite corretamente\n\n");
			}
	}while(num!=6);
	
}