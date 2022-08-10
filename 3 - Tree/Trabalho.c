#include<stdio.h>
#include<stdlib.h>


struct arvore
{ 
	struct arvore *esq;
	int chave;
	struct arvore *dir;

};



struct arvore *MaiorElemento(struct arvore *T) 
{
	if(T == NULL)
	{
		return NULL;
	}

	if(T->dir == NULL)	
	{
		return T;
	}
	return MaiorElemento(T->dir);
} 




struct arvore *MenorElemento(struct arvore *T) 
{
	if (T == NULL)
	{
		return NULL;
	}

	if (T->esq==NULL)
	{
		return T;
	}

	return MenorElemento(T->esq);
}


int ContaFolhas(struct arvore *raiz)
{
	if(!raiz)
	{
		return 0;
	}
	
	if(!raiz->esq && !raiz->dir)
	{
		return 1;
	}
	else
	{
		return(ContaFolhas(raiz->esq)+ContaFolhas(raiz->dir));
	}
}


int ContaNos(struct arvore *raiz)
{
	if(!raiz)
	{
		return 0;
	}
	
	return(1+ContaNos(raiz->esq)+ContaNos(raiz->dir));
}




int ContaPais(struct arvore *raiz)
{
	if(!raiz)
	{
		return 0;
	}
	
	if(!raiz->esq && !raiz->dir)
	{
		return 0;
	}
	else
	{
		return(1+ContaPais(raiz->esq)+ContaPais(raiz->dir));
	}
}


int altura(struct arvore *raiz) 
{
   int he, hd;
   
   if (raiz == NULL) 
   {  return 0; // altura da árvore vazia
      
   }    
   else 
   {
      he = altura(raiz->esq);
      hd = altura(raiz->dir);

      if (he < hd) 
      {
      	return (hd+1);
      }
      else 
      {
      	return (he+1);
      }
    }
    
    if(he==hd)
    {
	return(he+1);
    }
  
    
}



struct arvore *inserir(struct arvore *raiz, int n)
{
	struct arvore *t;
	
	if(raiz==NULL)
	{
		t=(struct arvore*)malloc(sizeof(struct arvore));
		t->chave=n;
		t->esq=t->dir=NULL;
		return(t);
	}
	else
	{
		if(n<raiz->chave)
		{
			t=inserir(raiz->esq, n);
			if(!raiz->esq)
			{
				raiz->esq=t;
			}
		}
		else
		{
			if(n>raiz->chave)
			{
				t=inserir(raiz->dir, n);	
				if(!raiz->dir)
				{
					raiz->dir=t;
				}
			}
		}
	}
		
	return(raiz);
}

void Inoder(struct arvore *raiz)
{
	if(raiz)
	{
		Inoder(raiz->esq);
		printf("%d\t", raiz->chave);
		Inoder(raiz->dir);
	}
}


void Preorder(struct arvore *raiz)
{
	if(raiz)
	{
		printf("%d\t", raiz->chave);
		Preorder(raiz->esq);
		Preorder(raiz->dir);
	}
}



void Postorder(struct arvore *raiz)
{
	if(raiz)
	{	
		Postorder(raiz->esq);
		Postorder(raiz->dir);
		printf("%d\t", raiz->chave);
	}
}


void remover(struct arvore *raiz, int n)
{
	struct arvore *t, *q, *a, *b, *c;
	
	t=raiz;
	q=NULL;
	
	while(t && n!=t->chave)
	{
		q=t;
		
		q=(n<t->chave) ? t->esq : t->dir;
	}
	if(!t)
	{
		return;
	}
	if(!t->esq)
	{
		a=t->dir;
	}
	else
	{
		if(!t->dir)	
		{
			a=t->esq;
		}
		else
		{
			b=t;
			a=t->dir;
			c=a->esq;
			
			while(b!=t)
			{
				b->esq=a->dir;
				a->dir=t->dir;
			}
		
			a->esq=t->esq;
		}
	}
		
	if(!q)
	{
		raiz=a;
	}
	else
	{
		(t==q->esq) ? (q->esq=a) : (q->dir=a);
	}
	
	free(t);
		
		
}



struct arvore *busca(struct arvore *raiz, int n)
{
	if(raiz) // raiz!=NULL
	{
		if(n==raiz->chave)
		{
			return(raiz);
		}
		else if(n<raiz->chave)
		{
			return(busca(raiz->esq, n));
		}
		else
		{
			return(busca(raiz->dir, n));
		}
	}
	
	return(NULL);
}


int ParesImpares(struct arvore *raiz, int *impares)
{
	int par;
	
	if(raiz)
	{
		if(raiz->chave%2==0)
		{
			par++;
		}
		else
		{
			impares++;
		}
	}
	else
	{
		return 0;
	}

	ParesImpares(raiz->esq, *impares)
	ParesImparesa(raiz->dir, *impares);
		
	return par;
}






int main()
{
	int i, n, par;
	
	struct arvore *raiz, *aux;	
	
	
	do{
		printf("\n\n--------------Menu-------------\n\n 1 - Inserir Nó\n 2 - Imprimir árvore\n 3 - Buscar chave\n 4 - Remover nó\n 5 - Contar nós\n 6 - Contar folhas\n 7 - Maior elemento\n 8 - Menor elemento\n 9 - Contar pais\n 10 - Mostrar a quantidade de chaves pares e ímpares\n 11 - Altura da árvore\n 12 - Sair\n\n");
		scanf("%d", &n);
		switch(n){
				case 1:
				printf("\n\nDigite um número: ");
				scanf("%d", &i);
				
				raiz=inserir(raiz, i);

				break;
				
				case 2:
				printf("\n\nDigite 1 para Inoder, 2 para Preorder e 3 para Postorder: ");
				scanf("%d", &i);
				
				if(i==1)
				{
					Inoder(raiz);

				}
				else if(i==2)
				{
					Preorder(raiz);
				}
				else if(i==3)
				{
					Postorder(raiz);
				}
				else
				{
					printf("\n\nDigite corretamente\n\n");
				}
				break;
				
				case 3:
				printf("\n\nDigite um número para busca: ");
				scanf("%d", &i);
				
				if(busca(raiz, i)==NULL)
				{
					printf("\n\nNúmero não encontrado\n\n");
				}
				else
				{
					printf("\n\nO número %d foi encontrado\n\n", i);
				}
				
				break;
	
				case 4:
				printf("\n\nDigite o nó para remover: ");
				scanf("%d", &i);
			
        if(busca(raiz, i)==NULL)
        {
            printf("\n\nElemento não encontrado\n\n");
        }
        else
        {
          				remover(raiz, i);
                  printf("\n\nElemento removido\n\n");


        }
			


				break;

				case 5:
				printf("\n\nQuantidade de nós na árvore: %d", ContaNos(raiz));

				break;

				case 6:
				printf("\n\nQuantidade de nós na árvore: %d", ContaFolhas(raiz));
				break;

				case 7:
				if(MaiorElemento(raiz)==NULL)
				{
					printf("\n\nNão tem maior\n\n");
				}
				else
				{
					aux=MaiorElemento(raiz);
						
					printf("\n\nMaior elemento: %d", aux->chave);
				}
				break;
				
			
				case 8:
				if(MenorElemento(raiz)==NULL)
				{
					printf("\n\nNão tem maior\n\n");
				}
				else
				{
					aux=MenorElemento(raiz);
						
					printf("\n\nMaior elemento: %d", aux->chave);
				}
				break;
				
				case 9:
					
				printf("\n\nQuantidade de pais: %d", ContaPais(raiz));
					
				break;

				case 10:
					
				printf("\n\nQuantidade de chaves pares: %d\n\n Quantidade de ímpares: %d\n\n", ParesImpares(raiz, &i), i);

					
				break;

	
				case 11:
					
				printf("\n\nAltura da árvore: %d\n\n", altura(raiz));

				break;
			
				case 12:
				break;

				default:
				printf("\nDigite corretamente\n\n");
			}
	}while(n!=11);
}
