#include<stdio.h>
#include<stdlib.h>

void merge_sort(int matriz[][2], int ini, int fim){
    int meio;
    if(ini<fim){
        meio = floor((ini+fim)/2);
        merge_sort(matriz,ini,meio);
        merge_sort(matriz,meio+1,fim);
        Merge(matriz,ini,meio,fim);
    }
}

void Merge(int matriz[][2],int ini, int meio, int fim){
    int *temp, *temp2, p1, p2, tamanho, i, j ,k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-ini+1;
    p1=ini;
    p2=meio+1;
    temp = (int*)malloc(sizeof(int)*tamanho);
    temp2 = (int*)malloc(sizeof(int)*tamanho);
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(matriz[p1][0]>matriz[p2][0]){
                    temp[i]=matriz[p1][0];
                    temp2[i]=matriz[p1++][1];
                }else{
                    temp[i]=matriz[p2][0];
                    temp2[i]=matriz[p2++][1];
                }
                if(p1>meio)
                    fim1=1;
                if(p2>fim)
                    fim2=1;
            }
            else{
                if(!fim1){
                    temp[i]=matriz[p1][0];
                    temp2[i]=matriz[p1++][1];
                }else{
                    temp[i]=matriz[p2][0];
                    temp2[i]=matriz[p2++][1];
                }
            }
        }
        for(j=0, k=ini;j<tamanho; j++, k++){
            matriz[k][0]=temp[j];
            matriz[k][1]=temp2[j];
        }
    }
    free(temp);
    free(temp2);
}

int main(){
    int N,P;
    while (1){
        scanf(" %d",&N);
        if(N==0)
            break;
        scanf(" %d",&P);

        int i,i2,timePizza[N][2],cont=0,matriz[N][2],flag;
        timePizza[0][0] = timePizza[0][1] = 0;
        for(i=0;i<N;i++){
            scanf(" %d %d",&matriz[i][0], &matriz[i][1]);
        }
        merge_sort(matriz,0,N-1);

        for(i=0;i<N;i++){
            flag=1;
            if((matriz[i][1]+timePizza[cont][1]) <= P){
                flag=0;
                for(i2=0;i2<=cont;i2++){
                    if(matriz[i][1]+timePizza[i2][1] <= P){
                        timePizza[i2][0]+=matriz[i][0];
                        timePizza[i2][1]+=matriz[i][1];
                    }else{
                        flag=1;
                    }
                }
            }else if(flag==1){
                cont++;
                timePizza[cont][0] = timePizza[cont][1] = 0;
                if(matriz[i][1]+timePizza[cont][1] < P){
                    timePizza[cont][0]+=matriz[i][0];
                    timePizza[cont][1]+=matriz[i][1];
                }
            }
        }

        i2=timePizza[0][0];
        for(i=0;i<=cont;i++){
            if(timePizza[i][0]>i2)
                i2=timePizza[i][0];
        }

        printf("%d min.\n",i2);
    }
}
