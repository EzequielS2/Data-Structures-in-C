#include<stdio.h>
#include<stdlib.h>   // ***Usar para alocar memoria.

int tam, complexidade;

void trocar(int *a, int *b)
{
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

void OrdenacaoTroca(int *k)
{
	int i, trocou;
	trocou=1;
	while(trocou==1)
	{
		trocou=0;
		for(i=0; i<tam-1; i++)
		{
			if(*(k+i)>*(k+i+1))
			{
				trocar((k+i), (k+i+1));
				trocou=1;
			}
		}
		
	}
	for(i=0; i<tam; i++)
	{
		printf("%d \t", *(k+i));

	}
}

void OrdenacaoSelecao(int *k)
{
	int i, j, menor;
	for(j=0; j<tam-1; j++)
	{
		menor=j;
		for(i=j+1; i<tam; i++)
		{
			if(*(k+i)<*(k+menor))
			{
				menor=i;
			}
		}
		trocar((k+j), (k+menor));
	}	
}

		

void OrdenacaoIsencao(int *k)
{
	int i, j;
	for(j=1; j<tam; j++)
	{
		for(i=j; i>0 && *(k+i-1)>*(k+i); i--)
		{
			trocar((k+i-1), (k+i));
		}
	}
}




int BuscaSequencial(int *p, int chave, int *pos) //Chave é o valor que eu quero buscar.
{
	int i;
	for(i=0; i<tam && chave>*(p+i); i++);
	*pos=i;
	complexidade=0;
	complexidade++;
	complexidade=complexidade+i;
	if(i==tam || chave!=*(p+i))
	{
		return 0;
	}
	else
	{
		return 1;
	}
	complexidade=complexidade+2;
}
	
int BuscaBinaria(int *p, int chave)
{
	int inicio, me, fim;
	complexidade=2;
	inicio=0;
	fim=tam-1;
	while(inicio<=fim)
	{
		me=(inicio+fim)/2;
		if(chave==*(p+me))   // Se ele encontar o numero(chave) que eu quero, ele retorna meio.
		{
			return me;
		}
		if(chave<*(p+me))
		{	
			fim=me-1;
		}
		else
		{
			inicio=me+1;
		}
		complexidade++;
		complexidade=complexidade+4;
	}
	complexidade++;
	return -1;
	complexidade++;
}






int main()
{
	int *p, op, num, tam1, i, posicao;
	printf("\nDigite o tamnho do vetor: ");
	scanf("%d", &tam1);
	tam=tam1;
	p=(int *)malloc(tam1 * sizeof(int));
	if(p==NULL)
	{
		printf("\nImpossivel alocar memória\n\n");
		return 0;
	}
	for(i=0; i<tam1; i++)
	{
		printf("Digite um numero: ");
		scanf("%d", &*(p+i));
	}
	printf("\nVetor Lido: \n\n");
	for(i=0; i<tam1; i++)
	{
		printf("%d \t", *(p+i));
	}
	do{
		printf("\n\nMenu\n\n 1 - Ordenacao Por Troca\n 2 - Ordenacao Por Selecao\n 3 - Ordenacao Por Isencao\n 4 - Sair\n\n");
		scanf("%d", &op);
		switch(op){
				case 1:
				printf("\n\n");
				OrdenacaoTroca(p);
				break;

				case 2:
				printf("\n\n");
				OrdenacaoSelecao(p);
				for(i=0; i<tam; i++)
				{
					printf("%d \t", *(p+i));
					
				}
				break;

				case 3:
				printf("\n\n");
				OrdenacaoIsencao(p);
				for(i=0; i<tam; i++)
				{
					printf("%d \t", *(p+i));
				
				}
				break;
			
				case 4:
				break;
	
				default:
				printf("\n\nDigite corretamente\n\n");
			}
	}while(op!=4);
	
	do{
		printf("\n\nMenu:\n\n 1 - Busca Sequencail\n 2 - Busca Bianria\n 3 - Sair\n\n");
		scanf("%d", &op);
		switch(op){
				case 1:
				printf("\nDigite um numero para busca: ");
				scanf("%d", &num);
				if(BuscaSequencial(p, num, &posicao)==0)
				{
					printf("\n\nNão achou\n\n");
				}
				else
				{
					printf("\nAchou na posição %d", posicao);
;
				}
				printf("\n\nTempo de execução(complexidade): %d", complexidade);
				break;
			
				case 2:
				printf("\nDigite um numero para busca Binaria: ");
				scanf("%d", &num);
				printf("Valor: %d", BuscaBinaria(p, num));
				printf("\n\nComplexidade: %d", complexidade);
				break;
				
				case 3:
				break;

				default:
				printf("\n\nDigite corretamente\n\n");
			}	
	}while(op!=3);
				
}






















