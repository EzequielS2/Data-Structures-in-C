#include<stdio.h>


//Não consegui fazer






#define tam 4


int dobro(int n, int v[])
{
	if(n==-1)
	{
		return(0);
	}
	v[n]=2*v[n];
	dobro(n-1, v);

        return(0);
}


int main()
{
	int a, b, v[tam];
	
	for(a=0; a<4; a++)
	{
		printf("\nDigite b: ");
		scanf("%d", &v[a]);
	}

	dobro(tam-1, v);

	for(a=0; a<4; a++)
	{
		printf("%d\t ", v[a]);
	}
}
