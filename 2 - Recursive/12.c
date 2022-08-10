#include<stdio.h>

 



float serie(int n, int i, float soma)
{
	int a, k;

	if(i>n)
	{	
		return(0);
	}
	
		k=1;
		a=1;

		while(k<=i)
		{
			a=a*(k++);
		}
		soma = (float)1/a;

		printf("%d\t", a);

		
	
	return(soma +serie(n, i+1, soma));

	

}

 




int main()
{
	int n;
	

	printf("\nDiga a serie: ");
	scanf("%d", &n);
	
	printf("\n\nTamanho de letras: %f", serie(n, 1, 0));

}






