#include<stdio.h>



#define tam 3




int produto(int v[], int a[], int i)
{
	
	if(i==tam)	
	{
		return(0);
	}
	
	return(v[i]*a[i]+produto(v, a, i+1));
}




int main()
{
	int v[tam], a[tam], i, n;	
	
	for(i=0; i<tam; i++)
	{
		printf("\n\nDigite um número: ");
		scanf("%d", &v[i]);
  }
	for(i=0; i<tam; i++)
	{
		printf("\n\nDigite outro número: ");
		scanf("%d", &a[i]);
  }
	
	printf("\n\nPoduto entre os vetores: %d",produto(v, a, 0));
	

}
#include<stdio.h>



#define tam 3




int produto(int v[], int a[], int i)
{
	
	if(i==tam)	
	{
		return(0);
	}
	
	return(v[i]*a[i]+produto(v, a, i+1));
}




int main()
{
	int v[tam], a[tam], i, n;	
	
	for(i=0; i<tam; i++)
	{
		printf("\n\nDigite um número: ");
		scanf("%d", &v[i]);
  }
	for(i=0; i<tam; i++)
	{
		printf("\n\nDigite outro número: ");
		scanf("%d", &a[i]);
  }
	
	printf("\n\nPoduto entre os vetores: %d",produto(v, a, 0));
	

}
