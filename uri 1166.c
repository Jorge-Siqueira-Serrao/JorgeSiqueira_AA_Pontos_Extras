#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int ehquadradoperfeito(int n){
    int SR = sqrt(n);
    int QP = SR*SR==n;
    return QP;
}

int calculaMax(int V){
    int maximo[V],ultimaBola[50] = {0}; //zera todos os indices

    int proximaBola=1, vareta=0;

    while(vareta<=V){
        int usarProximaVareta = 1;
        for(int i=0; i<=vareta; i++){
            if(ehquadradoperfeito(ultimaBola[i] + proximaBola)){
                usarProximaVareta=0;
                ultimaBola[i]=proximaBola;
            }
        }

        if(usarProximaVareta){
            maximo[vareta] = proximaBola-1;
            vareta++;
            ultimaBola[vareta] = proximaBola;
        }

        proximaBola++;
    }
    return maximo[V-1];
}

int main(){
    int T,V;
    scanf(" %d",&T);
    for(int i=0;i<T;i++){
        scanf(" %d",&V);
        printf("%d\n",calculaMax(V));
    }
    return 0;
}
