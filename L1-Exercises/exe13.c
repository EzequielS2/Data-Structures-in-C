#include<stdio.h>
#include<string.h>

#define tam 3


struct tno
{
	float saldo;
	char nome[100];
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

int listaVazia(struct tlista *a)
{
	if(a->qtnos==0)
	{
		return 0;
	}
	
	return 1;
}

int listaCheia(struct tlista *a)
{
	if(a->qtnos==tam)
	{
		return 0;
	}
	
	return 1;
}


void impressao(struct tlista *a)
{
	int i;

	for(i=0; i<a->qtnos; i++)
	{
		printf("\n\nnome: %s, saldo: %f\n\n", a->lista[i].nome, a->lista[i].saldo);
	}
}


int buscar(struct tlista *a, char nome1[])
{
	int i;

	for(i=0; i<a->qtnos; i++)
	{
		if(strcmp(a->lista[a->qtnos].nome, nome1)==0)
		{
			return i;
		}
	}
	return -1;

int inserirLista1(struct tlista *a, float saldo1, char nome1[])
{
	if(listaCheia(a)==0)
	{
		return 0;
	}

	a->lista[a->qtnos].saldo=saldo1;
	strcpy(a->lista[a->qtnos].nome, nome1);
	a->qtnos++;
	return 1;
}

int inserirLista2(struct tlista *a, float saldo1, char nome1[])
{
	int i;
	
	if(listaCheia(a)==0)
	{
		return 0;
	}

	i=buscar(a, nome1);
	
	if(i>=0)
	{
		return 0;
	}
	
	a->lista[a->qtnos].saldo=saldo1;
	strcpy(a->lista[a->qtnos].nome, nome1);
	a->qtnos++;
	return 1;
}

int retirarLista(struct tlista *a, char nome1[])
{
	if(listaVazia(a)==0)
	{
		return 0;
	}
	
	i=buscar(a, nome1);
	
	if(i<0)
	{
		return 0;
	}

	a->qtnos--;

	strcpy(a->lista[i].nome,a->lista[a->qtnos].nome);

	return 1;	
}




int main()
{

	int i, num; 
  	char nome1[100];
	float saldo1;
	struct tlista a;
	


	inicializarLista(&a);

	for(i=0; i<tam; i++)
	{
		printf("\nDigite o saldo: ");
		scanf("%f", &saldo1);
		printf("\nDigite o nome: ");
		fgetc(stdin);
		gets(nome1);
		inserirLista1(&a, saldo1, nome1);
	}
	
	do{
		printf("\n1 - Inserir\n 2 - Busca\n 3- Sair\n");
		scanf("%d", &num);

		switch(num)
   		{
			case 1:
			if(listaCheia(&a)==0)
			{
				printf("\nA lista está cheia\n\n");
			}
			else
			{
				printf("\n\nDigite o nome: ");
				gets(nome1);
				printf("\nDigite o saldo: ");
				scanf("%f", &saldo1);
				inserirLista1(&a, saldo1, nome1);
				fgetc(stdin);
			}
			break;
			
			case 2:
			fgetc(stdin);
			printf("\nDigite o nome para buscar: ");
			gets(nome1);
	
			if(buscar(&a, nome1)>=0)
			{
		
				printf("\nNome: %s, Saldo: %f", a.lista[i].nome, a.lista[i].saldo);
			}
			else
			{
				printf("\nO nome não está na lista\n\n");
			}
			break;
				
			case 3:
			break;

			default:
			printf("\nDigite corretamente\n\n");
		}

	  }while(num!=3);

}