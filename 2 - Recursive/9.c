#include<stdio.h>
#include<string.h>



#define tam 10


int caractere(char v[], int i, char b, int n)
{
	int quant=0;
	
	if(i<n)
	{
		if(v[i]==b)
		{
			quant=1;
		}
		return(quant+caractere(v, i+1, b, n));
	}
	
	return 0;

}






int main()
{
	char v[tam], d;	
	int f=0, i=0;

	printf("\nDida uma frase: ");
	gets(v);
	
	printf("\nDiga uma letra: ");
	scanf("%c", &d);

	
	printf("\n\nQuantidade de letra %c: %d", d, caractere(v, i, d, strlen(v)));

}






