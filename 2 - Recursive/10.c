#include<stdio.h>
#include<string.h>



#define tam 10


int tamanho(char v[], int quant)
{
	if(v[quant]=='\0')
	{
		return(quant);
	}
	
	return(tamanho(v, quant+1));		

}






int main()
{
	char v[tam], d;	

	printf("\nDida uma frase: ");
	gets(v);
	

	
	printf("\n\nTamanho de letras: %d", tamanho(v, 0));

}






