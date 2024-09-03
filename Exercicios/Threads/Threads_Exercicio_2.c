// Faça uma aplicação que tenha um vetor de 10 valores, gerados randomicamente 
// ou com entrada do usuário. Com o vetor preenchido, eles devem gerar uma soma 
// e um produto (resultado de uma multiplicação). Você deve usar pelo menos duas 
// threads para cada operação (soma e multiplicação) e utilizar os dados no vetor original.

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int vet[10] = {0,1,2,3,4,5,6,7,8,9};
int result_soma = 0;
int result_mult = 0;

void *soma(void *param){
    int i;
    for(i=0; i<10; i++){
        result_soma+=vet[i];
    }
    
}

void *mult(void *param){
    int i;
    for(i=0; i<10; i++){
        result_mult *= vet[i];
    }
}

int main(){ 
    pthread_t tid_soma, tid_mult;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid_soma, &attr, soma, NULL);
    pthread_create(&tid_mult, &attr, mult, NULL);

    pthread_join(tid_soma, NULL);
    pthread_join(tid_mult, NULL);

    printf("Soma resultande: %d\n", result_soma);
    printf("Produto resultande: %d\n", result_mult);

}