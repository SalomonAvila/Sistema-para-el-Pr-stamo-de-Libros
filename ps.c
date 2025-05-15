#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

typedef struct
{
    char tipo;
    char nombreLibro[100];
    long ISBN;
} Peticion;

void menuGeneral()
{
    printf("De donde quiere obtener su archivo\n");
    printf("1. A traves de un menu");
    printf("2. Mediante un archivo de texto\n");
}

void menu()
{
    printf("Menu de opciones\n");
}

int main(int argc, char *argv[])
{
    char miPipe[100];

    if (argc == 3)
    {
        if (argv[1][0] == '-' && argv[1][1] == 'p')
        {
            strcpy(miPipe, argv[2]);
            if (access(miPipe, F_OK) != 0)
            {
                fprintf(stderr, "Error: El pipe '%s' no existe. Asegúrese de que el proceso receptor esté en ejecución.\n", miPipe);
                return 1;
            }
        }
        else
        {
            printf("Comando erroneo, debería ser solicitante [–i file] –p pipeReceptor\n");
            return 1;
        }
    }
    else
    {
        printf("Comando erroneo, debería ser solicitante [–i file] –p pipeReceptor\n");
        return 1;
    }

    while (true)
    {
        menuGeneral();
        int opcionUno, opcionDos;
        Peticion peticion;
        scanf("%d", &opcionUno);
        switch (opcionUno)
        {
        case 1:
            menu();
            scanf("%d", &opcionDos);
            switch (opcionDos)
            {
            case 1:
                printf("Devolviendo un libro\n");
                scanf("%s", peticion.nombreLibro);
                printf("El nombre es: %s \n", peticion.nombreLibro);
                scanf("%ld", &peticion.ISBN);
                printf("El ISBN es: %ld \n", peticion.ISBN);
                scanf(" %c", &peticion.tipo);
                printf("El tipo es: %c \n", peticion.tipo);

                int fd = open(miPipe, O_WRONLY);
                if (fd == -1)
                {
                    perror("Error al abrir el pipe para escritura");
                    break;
                }

                if (write(fd, &peticion, sizeof(Peticion)) == -1)
                {
                    perror("Error al escribir en el pipe");
                }
                else
                {
                    printf("Se ha escrito en el pipe\n");
                }
                close(fd);
                break;

            case 2:
                printf("Renovando un libro\n");
                break;

            case 3:
                printf("Solicitando un libro\n");
                break;

            default:
                printf("Opcion no valida\n");
                break;
            }
            break;

        case 2:
            printf("Opcion no implementada\n");
            break;

        default:
            printf("Opcion no valida\n");
            break;
        }
    }
}