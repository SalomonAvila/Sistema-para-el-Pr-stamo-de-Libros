#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void menuGeneral(){
    printf("De donde quiere obtener su archivo\n");
    printf("1. A traves de un menu");
    printf("2. Mediante un archivo de texto\n");
}

void menu(){
    printf("Menu de opciones\n");
}


int main() {
    printf("Bienvenido al programa\n Codigo de proceso: %d\n", getpid());
    int ans = -1;
    int ansInt = 0;
    char nomArch[100];
    while(ans != 0){
        menuGeneral();
        scanf("%d",&ans);
        getchar();
        switch (ans){
            case 1:
                menu();
                break;
            case 2:
                fgets(nomArch,sizeof(nomArch),stdin);
        }
    }

    return 0;
}