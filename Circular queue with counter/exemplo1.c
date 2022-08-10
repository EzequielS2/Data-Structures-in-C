#include<stdio.h>

#define TAM 3

struct tfila1
{	
	int inicio, fim, contador;
	int fila1[TAM];
};

void inicializarFila1(struct tfila1 *a)
{
	a->inicio=0;
	a->contador=0;
	a->fim=-1;
}

int filaVazia1(struct tfila1 *a)
{
	if(a->contador==0)
	{
		return 0;
	}
	return 1;
}

int filaCheia1(struct tfila1 *a)
{
	if(a->contador==TAM)
	{
		return 0;
	}
	return 1;
}

int inserirFila1(struct tfila1 *a, int x)
{
	if(filaCheia1(a)==0)
	{
		return 0;
	}
	a->contador++;
	a->fim=a->fim+1;
	a->fila1[a->fim]=x;
	return 1;
}

int removerFila1(struct tfila1 *a, int *num)
{
	if(filaVazia1(a)==0)
	{
		return 0;
	}
	a->contador--;
	*num=a->fila1[a->inicio];
	a->inicio=a->inicio+1;
	return 1;
}



struct tfila
{
	int f,r;
	int fila[TAM];
	
};

void inicializar(struct tfila *a)
{
	a->f=0;
	a->r=0;
}

int filaVazia(struct tfila *a)
{
	if(a->f==a->r)
	{
		return 0;
	}
	return 1;
}

int filaCheia(struct tfila *a)
{
	if((a->r+1)%TAM==a->f)
	{
		return 0;
	}
	return 1;
}	

int inserefilacircular(struct tfila *pf, int valor)
{
     if(filaCheia(pf)==0)
     {
	return(0);
     }
     pf->r=(pf->r+1)%TAM;
     pf->fila[pf->r]=valor;
     return(1);
}

int removerFila(struct tfila *pf, int *elem )
{
      if(filaVazia(pf)==0)
      {
        return(0);
        }
      pf->f=(pf->f+1)%TAM;
      *elem=pf->fila[pf->f];
      return(1);
}




int main()
{
	int num, x, m, i;
	
	struct tfila a;
	struct tfila1 b;
	
	
	inicializar(&a);
	inicializarFila1(&b);
	
	do{
		printf("\n\nMenu\n 1 - Inserir\n 2 - Remoção\n 3 - Impressaão\n 4 - Sair\n");
		scanf("%d", &num);
		switch(num){
				case 1:
				if(filaCheia1(&b)!=0)
				{
					printf("\nDigite um numero: ");
					scanf("%d", &x);
					inserirFila1(&b, x);
				}
				else if(filaCheia(&a)!=0)
				{
					printf("\nDigite um numero: ");
					scanf("%d", &x);
					inserefilacircular(&a, x);
				}
				else
				{
					printf("\n\nAs filas estão cheias\n\n");
				}
				break;
				
				
				case 2:
				if(filaVazia1(&b)==1)
				{		
					removerFila1(&b, &m);
				}
				else if(filaVazia(&a)==1)
				{
					removerFila(&a, &m);
				}
				else
				{
					printf("\n\nAs filas estão vazias\n\n");
				}
				break;
				
				case 3:
				printf("\nFila 1: ");
				if(filaVazia1(&b)==1)
				{	for(i=0; i<b.contador; i++)
					{
						printf("%d\t", b.fila1[i]);
					}
				}
				else
				{
					printf("\nFila Vazia\n");
				}
				
				printf("\nFila 2: ");
				if(filaVazia(&a)==1)
				{	for(i=1%TAM; i<=a.r; i++)
					{
						printf("%d\t", a.fila[i]);
					}
				}
				else
				{
					printf("\nFila Vazia\n");
				}
				break;
				
				case 4:
				break;
			}
	}while(num!=4);
	
}
				
				
				
				
				
					
				
				
				
				
				
				
				
				
				
				
				



































	
	
	
	
	
	
	
	
