#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge_sort(int vet[], int ini, int fim){
    int meio;
    if(ini<fim){
        meio = floor((ini+fim)/2);
        merge_sort(vet,ini,meio);
        merge_sort(vet,meio+1,fim);
        Merge(vet,ini,meio,fim);
    }
}

void Merge(int vet[],int ini, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j ,k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-ini+1;
    p1=ini;
    p2=meio+1;
    temp = (int*)malloc(sizeof(int)*tamanho);
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vet[p1]>vet[p2])
                    temp[i]=vet[p1++];
                else
                    temp[i]=vet[p2++];

                if(p1>meio)
                    fim1=1;
                if(p2>fim)
                    fim2=1;
            }
            else{
                if(!fim1)
                    temp[i]=vet[p1++];
                else
                    temp[i]=vet[p2++];
            }
        }
        for(j=0, k=ini;j<tamanho; j++, k++)
            vet[k]=temp[j];
    }
    free(temp);
}

int main ( ) {
    int N, K, a, i, sum;

    while (scanf( "%d %d", &N, &K) != EOF) {
        int vet[N], temp[N];
        vet[0] = 0; //A primeira posição é zero.
        temp[0]= 0;
        for ( i=1;i<N;i++) {
            scanf ( "%d", &temp[i] );
			// Guarda no vetor vet a distância entre i e i-1 na fila.
            vet[i] = temp[i] - temp[i - 1];
        }

		// Ordena o vetor de distâncias em ordem decrescente.
        merge_sort(vet,0,N-1);

		// Soma as distâncias pedidas que estarão entre K e N.
        sum = 0;
        for (i=K - 1;i<N;i++)
            sum += vet[i];
        printf ("%d\n", sum );
    }
    return 0;
}
