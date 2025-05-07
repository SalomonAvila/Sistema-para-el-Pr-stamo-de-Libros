#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    char tipo;
    char nombreLibro[100];
    long ISBN;
} Peticion;
 
Peticion buffer[11];

void imprimirRegistro(){
    FILE* registros = fopen("registros.txt", "w");

}

void *recibirComandos(char comando, pthread_t pt){
    if(comando == 's'){
        pthread_exit(pthread_self());
        pthread_exit(pt);
    }else if(comando == 'r'){

    }
}

void *operaciones(Peticion peticion){

}

int main(int argc, char *argv[]) {
    pthread_t auxiliar1,auxiliar2;
    pthread_create(auxiliar1,NULL,operaciones,NULL);
    pthread_create(auxiliar2,NULL,recibirComandos,NULL);
}