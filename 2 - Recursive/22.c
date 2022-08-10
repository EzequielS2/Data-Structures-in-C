#include<stdio.h>
#include<math.h>

void intercala(int v[], int p, int q, int r)
{
 	int i, j, k, *w;
 	w = malloc((r - p) * sizeof(int));
 	for (i = p; i < q; ++i)
 		w[i - p] = v[i];
 	for (j = q; j < r; ++j)
 		w[r - p + q - j - 1] = v[j];
 	i = 0;
 	j = r - p - 1;
 	for (k = p; k < r; ++k)
 	if (w[i] <= w[j])
 	v[k] = w[i++];
 	else
 	v[k] = w[j--];

 	free(w);
}

void margesort(int v[], int i, int f)
{
	int meio;
	
	if(i==f)
	{
		return 0;
	}
	else
	{
		meio=(i+f)/2;
		margesort(v, i, meio);
		marfesort(v, meio+1, f);
		intercala(v, i, meio+1, f);
	}
}


void quicksort()







int main()
{
	int v[tam], i;	
	
	
	for(i=0; i<tam; i++)
	{
		printf("\nDigite um número: ");	
		scanf("%d", &v[i]);
	}
	
	printf("\n\nSoma dos elementos do vetor: %d", soma(v, tam));


	printf("\nMenor: %d", menor(v, 0, 4));
	
	printf("\n\nMaior: %d\n\n", maior(v, 0, 4));


	printf("\n\nVetor na ordem inversa: ");
	inverso(v, tam-1);

}
