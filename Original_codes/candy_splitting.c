#include <stdio.h>
#include <stdlib.h>

int somaBit(int vetorA[], long int C){
            int vetorB[20], i,j;
            long int aux = C;
            for(j=0;j<20;j++)vetorB[j] = 0;
            i = 0;
            while(aux!= 0){
                        vetorB[i] = aux  % 2;
                        aux = aux / 2;
                        i++;
            }
            j=0;
            while(j<20){
                       if(vetorB[j] == vetorA[j])vetorA[j] = 0;
                       else vetorA[j] = 1;
                        j++;
            }
            for(j=0;j<20;j++)
                              if(vetorA[j] == 1)return 0;
            return 1;
}               



int main(){
    int vetorA[20],vetorB[20],T,N,i,j,tam;
    long int C, soma, menor;
    int zero;
    scanf("%d",&T);
    for(i=0;i<T;i++){
                     scanf("%d",&N);
                     soma = 0;
                     for(j=0;j<20;j++)vetorA[j] = 0;
                     menor = 1000001;
                     for(j=0;j<N;j++){
                                      scanf("%ld",&C);
                                      soma = soma + C;
                                      if(C < menor) menor = C;
                                      zero = somaBit(vetorA,C);
                     }                                     
                     if((zero == 1))printf("Case #%d: %ld",i+1,soma - menor);
                     else printf("Case #%d: NO",i+1);
                     if(i < T-1)printf("\n");
    }
}
    
