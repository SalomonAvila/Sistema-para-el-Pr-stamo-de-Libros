#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    char tipo;
    char nombreLibro[100];
    long ISBN;
} Peticion;

void menuGeneral(){
    printf("De donde quiere obtener su archivo\n");
    printf("1. A traves de un menu");
    printf("2. Mediante un archivo de texto\n");
}

void menu(){
    printf("Menu de opciones\n");
}


int main(int argc, char *argv[]) {
    char miPipe[100];
    //printf("El argc es de: %d\n",argc);
    if(argc == 3){
        //printf("El argv[1] es de: %s\n",argv[1]);
        if(argv[1][0] == '-' && argv[1][1] == 'p'){
            strcpy(miPipe, argv[2]);
            int res = access(miPipe, F_OK);
            //printf("El resultado de la busqueda con access es: %d\n", res);
            if(res == 0){
                //printf("Ya existe\n");
                //Enviar la informacion
                // No le corresponde a ps elimuinar un pipe unlink(miPipe);
            }else{
                printf("No existe el pipe, recuerde que tiene que ser igual al proceso receptor");
                //mkfifo(miPipe,0777);
            }
        }else{
            printf("Comando erroneo, debería ser solicitante [–i file] –p pipeReceptor");
        }
    }else if(argc == 5){
        
    }else{
        printf("Comando erroneo, debería ser solicitante [–i file] –p pipeReceptor");
        return 0;
    }
    while(true){
        
    }
}