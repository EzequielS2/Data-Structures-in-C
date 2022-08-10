#include<stdio.h>
#include<math.h>



int serie(int n, int i, int num)
{
	if(i>n)
	{
		return 0;
	}
	
	num=pow(i, 3);

	
	return(num+serie(n, i+1, num));			

}

 




int main()
{
	int n, num;
	
	printf("\nDigite um número (para a serie): ");
	scanf("%d", &n);

	printf("\n\nSoma da serie: %d\n\n", serie(n, 1, num));
	

}






