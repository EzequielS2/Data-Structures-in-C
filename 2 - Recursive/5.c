#include<stdio.h>
#include<math.h>


#define tam 3


int soma(int v[], int n)  //Soma dos elemntos do vetor
{
	if(n==0)
	{
		return 0;
	}
	
	return(v[n-1]+soma(v, n-1));
}


int menor(int v[], int ini, int fim) // Usaremos Divisão e Conquista para achar o menor
{
	int n1, n2, meio;
	
	if(ini==fim)
	{
		return(v[ini]);
	}
	
	meio=(ini+fim)/2;   //Pois o meio deve ser inteiro.
	
	n1=menor(v, ini, meio);
	n2=(v, meio+1, fim);
	
	if(n1<n2)
	{
		return(n1);
	}
	
	return(n2);
}

int maior(int v[], int ini, int fim) // Usaremos Divisão e Conquista para achar o maior
{
	int n1, n2, meio;
	
	if(fim-ini<=1)
	{
		if(v[ini]>v[fim])
		{
			return(v[ini]);
		}
		return(v[fim]);
		
	}

	meio=(ini+fim)/2;   //Pois o meio deve ser inteiro.

	n1=menor(v, ini, meio);
	n2=(v, meio+1, fim);
	
	if(n1>n2)
	{
		return(n1);
	}
	
	return(n2);
}

int media(int v[], int n)  //media dos elemntos do vetor
{
	if(n==0)
	{
		return 0;
	}
	
	return((v[n-1]+soma(v, n-1))/n);
}


int inverso(int v[], int n)
{
	if(n==-1)
	{
		return 0;
	}
	
	printf("%d\t", v[n]);
	
	inverso(v, n-1);

}




int main()
{
	int v[tam], i;	
	
	
	for(i=0; i<tam; i++)
	{
		printf("\nDigite um número: ");	
		scanf("%d", &v[i]);
	}
	
	printf("\n\nSoma dos elementos do vetor: %d", soma(v, tam));


	printf("\nMenor: %d", menor(v, 0, 4));
	
	printf("\n\nMaior: %d\n\n", maior(v, 0, 4));


	printf("\n\nVetor na ordem inversa: ");
	inverso(v, tam-1);

}
