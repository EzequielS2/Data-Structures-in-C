#include<stdio.h>
#include<math.h>







int mdc(int a, int b, int i)
{
	
	if(a%i==0 && b%i==0)	
	{
		return(i);
	}
	
	return(mdc(a, b, i-1));
}




int main()
{
	int a, b, i;	
	
	
	printf("\nDigite a e b: ");	
	scanf("%d, %d", &a, &b);
	
	
	printf("\n\nMdc(%d, %d): %d", a, b, mdc(a, b, i=b));
	

}
