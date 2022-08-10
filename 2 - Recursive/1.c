#include<stdio.h>




int sucessor(int a, int b)
{
	if(b==0)
	{
		return(a);
	}
	
	return(1+sucessor(a,b-1));
}


int main()
{
	int a, b;
	
	printf("\nDigite a e b: ");
	scanf("%d, %d", &a, &b);
	
	printf("\n%d\n\n", sucessor(a,b));
}
