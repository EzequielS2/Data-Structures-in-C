#include<stdio.h>
#include<math.h>


#define tam 3




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

	printf("\n\nVetor na ordem inversa: ");
	inverso(v, tam-1);

}
