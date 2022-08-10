#include<stdio.h>
#include<string.h>
 



int polindromi(char v[], int i, int n, int *quant)
{

	if(i==n)
	{
		if(v[i]==v[n] && v[*quant]==v[i-1])
		{
			
			*quant=i;

			return i;
		}
		return 0;
	}
	else if(v[i]=='\0')
	{
		return 0;
	}
	
	if(v[i]==v[n])
	{
		
		*quant=i;

	}

	return(polindromi(v, i+1, n-1, quant));


	

}

 




int main()
{
	int n, i=0;
	
	char v[15];
	

	printf("\nDiga uma palavra: ");
	gets(v);
	if(polindromi(v, i, strlen(v)-1, &n)==n)
	{
		printf("\n\nA palavra é polindromi");
	}
	else
	{
		printf("\n\nNão é polindromi");
	}
	

}






