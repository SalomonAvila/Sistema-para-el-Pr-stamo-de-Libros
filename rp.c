#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct
{
    char tipo;
    char nombreLibro[100];
    long ISBN;
} Peticion;

Peticion buffer[11];

void imprimirRegistro()
{
    FILE *registros = fopen("registros.txt", "w");
}

void *recibirComandos(char comando, pthread_t pt)
{
    if (comando == 's')
    {
        pthread_exit(pthread_self());
        pthread_exit(pt);
    }
    else if (comando == 'r')
    {
    }
}

void *operaciones(Peticion peticion)
{
    printf("El tipo de peticion es: %c\n", peticion.tipo);
}

int main(int argc, char *argv[])
{
    pthread_t auxiliar1, auxiliar2;
    printf("El argc es de: %d\n", argc);
    mkfifo(argv[2], 0666);
    int fd = open(argv[2], O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el pipe para lectura");
        return 1;
    }
    pthread_create(&auxiliar1, NULL, operaciones, NULL);
    pthread_create(&auxiliar2, NULL, recibirComandos, NULL);
    Peticion peticion;
    peticion.ISBN = -1;
    while (true)
    {
        ssize_t bytesLeidos = read(fd, &peticion, sizeof(peticion));
        if (bytesLeidos > 0 && peticion.ISBN != -1)
        {
            printf("El ISBN es: %ld\n", peticion.ISBN);
            printf("El tipo de peticion es: %c\n", peticion.tipo);
            printf("El nombre del libro es: %s\n", peticion.nombreLibro);
            printf("El ISBN del libro es: %ld\n", peticion.ISBN);
        }
    }
}