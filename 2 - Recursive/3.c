#include<stdio.h>
#include<math.h>



int bin(int a)
{	
	int n;
	
	n=0;
	if(a<=0)
	{
		return(n);
	}
	
	n=a%2;
	
	a=a/2;


	printf("%d", n);

	bin(a);
	return(0);
}


int main()
{
	int a, b;
	
	printf("\nDigite a: ");
	scanf("%d", &a);
	
	bin(a);

}
