// Desenvolver uma aplicação de leia uma entrada do teclado, some com uma constante 
// e imprima na tela o dado resultante da soma. Divida as tarefas em threads usando 
// a biblioteca pthread (preferencialmente).

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int var = 0;

void *teclado(void *param){
    printf("Digite algum número: ");
    scanf("%d", &var);
}

void *soma(void *param){
    var = var + 10;
}

void *imprime(void *param){
    printf("Valor final: %d\n", var);
}

int main(){ 
    pthread_t th_t, th_s, th_i;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&th_t, &attr, teclado, NULL);
    pthread_create(&th_s, &attr, soma, NULL);
    pthread_create(&th_i, &attr, imprime, NULL);

    pthread_join(th_t, NULL);
    pthread_join(th_s, NULL);
    pthread_join(th_i, NULL);

    printf("Proceso Finalizou\n");
}