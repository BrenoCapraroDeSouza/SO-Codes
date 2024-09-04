//Implemente um sistema em que há três threads que tem a responsabilidade de 
//ler o valor de um sensor e some ao valor de uma variável global e em uma 
//variável local. Você deve simular a contagem com operação de incremento simples (+=1 ou ++).
//Print a variável local a cada 1 segundo e incremente a variável a cada 1 segundo. O programa 
//deve chegar ao fim quando a soma da variável global chegar a 100. Ao fim, você consegue observar qual condição:

// a)Todas as threads tem o mesmo valor na variável interna?

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

#define COUNT_READ 100
int contadorGlobal = 0;

pthread_mutex_t exclusao_mutua = PTHREAD_MUTEX_INITIALIZER;


void *contarAteCem(void *arg){
    int threadID = *(int*)arg;
    int contadorLocal = 0;
    while(1){
        contadorLocal++;
        pthread_mutex_lock( &exclusao_mutua);
        if(contadorGlobal<COUNT_READ){
            contadorGlobal++;
            pthread_mutex_unlock( &exclusao_mutua);
        }else {
            pthread_exit(0);
        }

        sleep(1);

        printf("Thread %d - Local: %d\n", threadID, contadorLocal);
        printf("Thread %d - Global: %d\n", threadID, contadorGlobal);
    }
}


int main(){
    pthread_t thread1, thread2, thread3;
    int id1 = 0, id2 = 1, id3 = 2;

    pthread_create(&thread1, NULL, contarAteCem, &id1);
    pthread_create(&thread2, NULL, contarAteCem, &id2);
    pthread_create(&thread3, NULL, contarAteCem, &id3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);



    return 0;
}
