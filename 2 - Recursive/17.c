#include<stdio.h>
#include<string.h>
 



int ocorrencia(char v[], int i, char chave)
{
		
	if(i<strlen(v))
	{
		if(v[i]==chave)
		{

			return i;
		}
	
		return(ocorrencia(v, i+1, chave));
	}
	
	return 0;

}

 




int main()
{
	int n;
	
	char v[15], b;
	

	printf("\nDiga uma palavra: ");
	gets(v);
	
	printf("\nDiga uma palavra: ");
	scanf("%c", &b);

	if(ocorrencia(v, 0, b)!=0)
	{
		printf("\n\nA letra %c foi encontrada", b);
	}
	else
	{
		printf("\n\nNão foi encontrada");
	}
	

}






