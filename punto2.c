#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Tarea {
    int tareaID; //Numerado en ciclo iterativo
    char *descripcion; //
    int duracion; // entre 10 – 100
} typedef Tarea;


void cargar(Tarea **, int);
void mostrar(Tarea);
void confirmar(Tarea **, Tarea **, int);
void mostrarConfirmadas(Tarea **, Tarea **, int);


Tarea *buscarTareaPalabraClave(Tarea **, int, char *);


int main(){

    int cantTareas;
    Tarea **tareas, **tareasRealizadas;

    printf("\nIngrese la cantidad de tareas que realizara el empleado: ");
    scanf(" %d", &cantTareas);
    fflush(stdin);

    while (cantTareas <= 0){
        printf("\nError de formato. Ingrese la cantidad de tareas que realizara el empleado: ");
        scanf(" %d", &cantTareas);
        fflush(stdin);
    }
    
    tareas = (Tarea **)malloc(sizeof(Tarea *) * cantTareas);


    printf("\n\n--------CARGA DE TAREAS--------");
    cargar(tareas, cantTareas);


    printf("\n\n\n--------Buscar tarea por palabra:--------");

    if (buscarTareaPalabraClave(tareas, cantTareas, "taller")){

        mostrar(*buscarTareaPalabraClave(tareas, cantTareas, "taller"));

    } else {

        printf("\nNo hay una tarea con esa palabra");

    }



    tareasRealizadas = (Tarea **)malloc(sizeof(Tarea *) * cantTareas);

    for (int i = 0; i < cantTareas; i++){
        tareasRealizadas[i] = NULL;
    }


    printf("\n\n\n--------CONFIRMACION DE TAREAS REALIZADAS--------");
    confirmar(tareas, tareasRealizadas, cantTareas);


    mostrarConfirmadas(tareas, tareasRealizadas, cantTareas);



    return 0;
}


void cargar(Tarea **tareas, int cantTareas){

    char *Buffer = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < cantTareas; i++){

        printf("\n----Tarea [%d]----", i+1);

        tareas[i] = (Tarea *)malloc(sizeof(Tarea) * 1);

        tareas[i]->tareaID = i + 1;

        printf("\nIngrese la descripcion de la tarea [%d]: ", i + 1);
        gets(Buffer);
        fflush(stdin);

        tareas[i]->descripcion = (char *)malloc(strlen(Buffer) + 1);
        strcpy(tareas[i]->descripcion, Buffer);

        printf("\nIngrese la duracion de la tarea, entre 10 y 100: ");
        scanf(" %d", &(tareas[i]->duracion));
        fflush(stdin);

        while (tareas[i]->duracion < 10 || tareas[i]->duracion > 100){
            printf("\nError de formato. Entre 10 y 100: ");
            scanf(" %d", &(tareas[i]->duracion));
            fflush(stdin);
        }
    }

    free(Buffer);
}

void mostrar(Tarea tareas){

     printf("\n----Tarea----");
    printf("\nID: [%d]", tareas.tareaID);
    printf("\nDescripcion: ");
    puts(tareas.descripcion);
    printf("Duracion: %d", tareas.duracion);
}

void confirmar(Tarea **tareas, Tarea **tareasRealizadas, int cantTareas){

    int confirmada;
    int numArreglo = 0;

    for (int i = 0; i < cantTareas; i++){

        mostrar(*tareas[i]);

        printf("\n\nRealizó la tarea [%d]?\nOPCIONES: \n[1]: Si\n[0]: No   : ", tareas[i]->tareaID);
        scanf("%d", &confirmada);
        fflush(stdin);

        while (confirmada < 0 || confirmada > 1){
            printf("\nError de formato.\nOPCIONES: \n[1]: Si\n[0]: No   : ");
            scanf("%d", &confirmada);
            fflush(stdin);
        }

        if (confirmada == 1){

            tareasRealizadas[numArreglo] = tareas[i];
            tareas[i] = NULL;
            numArreglo++;
        }
    }
}

void mostrarConfirmadas(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cantTareas){

    int j = 0;

    printf("\n\n--------TAREAS NO REALIZADAS--------");

    for (int i = 0; i < cantTareas; i++){
        if (tareasPendientes[i] != NULL)
        {
            mostrar(*tareasPendientes[i]);
            printf("\n");
        }
    }


    printf("\n\n--------TAREAS REALIZADAS--------");

    while (tareasRealizadas[j] != NULL){

        mostrar(*tareasRealizadas[j]);
        j++;
        printf("\n");
    }
}


Tarea *buscarTareaPalabraClave(Tarea **tareas, int cantTareas, char *palabra){

    for (int i = 0; i < cantTareas; i++){
        if (strstr(tareas[i]->descripcion, palabra)){

            return tareas[i];
        }

    }

    return 0;
}