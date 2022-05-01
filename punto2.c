#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Tarea {
    int tareaID; //Numerado en ciclo iterativo
    char *descripcion; //
    int duracion; // entre 10 – 100
} typedef Tarea;

struct Nodo{
    Tarea t;
    struct Nodo *siguiente;
};
typedef struct Nodo *Lista;


Lista crearListaVacia();
Lista crearNodo(int, int);
void insertarNodo(Lista *, int);
void mostrarTareas(Lista);
void mostrarTarea(Lista);
void confirmar(Lista *, Lista *);
Lista insertarListasConfirmadas(Lista *, Lista *);

int main(){

    int cantTareas;
    Lista tareas, tareasRealizadas;
    
    tareas = crearListaVacia();
    tareasRealizadas = crearListaVacia();


    printf("\nIngrese la cantidad de tareas que realizara el empleado: ");
    scanf(" %d", &cantTareas);
    fflush(stdin);

    while (cantTareas <= 0){
        printf("\nError de formato. Ingrese la cantidad de tareas que realizara el empleado: ");
        scanf(" %d", &cantTareas);
        fflush(stdin);
    }


    printf("\n\n--------CARGA DE TAREAS--------");
    insertarNodo(&tareas, cantTareas);

    printf("\n\n--------MOSTRAR TAREAS--------");
    mostrarTareas(tareas);

    printf("\n\n\n--------CONFIRMACION DE TAREAS REALIZADAS--------");
    confirmar(&tareas, &tareasRealizadas);

    printf("\n\n------TAREAS REALIZADAS------");
    mostrarTareas(tareasRealizadas);

    printf("\n\n------TAREAS PENDIENTES------");
    mostrarTareas(tareas);


    /* printf("\n\n\n--------Buscar tarea por palabra:--------");

    if (buscarTareaPalabraClave(tareas, cantTareas, "taller")){

        mostrar(*buscarTareaPalabraClave(tareas, cantTareas, "taller"));

    } else {

        printf("\nNo hay una tarea con esa palabra");
    }
    


    printf("\n\n\n--------Buscar tarea por ID:--------");

    // acá podría implementar solicitar por pantalla el ID a buscar.
    
    if (buscarTarea(tareas, cantTareas, 2)){

        mostrar(*buscarTarea(tareas, cantTareas, 2));

    } else {

        printf("\nNo hay una tarea con ese ID");
    }


    liberarMemoria(tareas, cantTareas);
    liberarMemoria(tareasRealizadas, cantTareas); */

    free(tareas);
    free(tareasRealizadas);

    return 0;
}


Lista crearListaVacia(){

    return NULL;
}

Lista crearNodo(int cantTareas, int i){

    char *Buffer = (char *)malloc(100 * sizeof(char));

    printf("\n----Tarea [%d]----", i+1);

    Lista tarea = (Lista)malloc(sizeof(struct Nodo));


    printf("\nIngrese la descripcion de la tarea [%d]: ", i + 1);
    fflush(stdin);
    gets(Buffer);

    tarea->t.descripcion = (char *)malloc(strlen(Buffer + 1) * sizeof(char));
    strcpy(tarea->t.descripcion, Buffer);


    printf("\nIngrese la duracion de la tarea, entre 10 y 100: ");
    scanf(" %d", &(tarea->t.duracion));
    fflush(stdin);

    while (tarea->t.duracion < 10 || tarea->t.duracion > 100){
        printf("\nError de formato. Entre 10 y 100: ");
        scanf(" %d", &(tarea->t.duracion));
        fflush(stdin);
    }

    tarea->t.tareaID = i + 1;
    tarea->siguiente = NULL;

    free(Buffer);
    return tarea;
}

void insertarNodo(Lista *tareas, int cantTareas){

    for (int i = 0; i < cantTareas; i++){

        Lista nuevo;
        nuevo = crearNodo(cantTareas, i);

        nuevo->siguiente = *tareas;
        *tareas = nuevo;
    }
}

void mostrarTareas(Lista tareas){

    Lista puntero;
    puntero = tareas;

    while (puntero != NULL){

        printf("\n----Tarea----");
        printf("\nID: [%d]", puntero->t.tareaID);
        printf("\nDescripcion: ");
        puts(puntero->t.descripcion);
        printf("Duracion: %d", puntero->t.duracion);

        puntero = puntero->siguiente;
    }
}

void mostrarTarea(Lista tareas){

    printf("\n----Tarea [%d]----", tareas->t.tareaID);
    printf("\nDescripcion: ");
    puts(tareas->t.descripcion);
    printf("Duracion: %d", tareas->t.duracion);
    printf("\n");
}

void confirmar(Lista *tareas, Lista *tareasRealizadas){

    Lista noRealizadas, puntero;
    int confirmada;

    noRealizadas = crearListaVacia();


    while (*tareas != NULL){

        mostrarTarea(*tareas);

        printf("\n\n¿Realizó la tarea?\nOPCIONES: \n[1]: Si    |    [0]: No   : ");
        scanf(" %d", &confirmada);
        fflush(stdin);

        while (confirmada < 0 || confirmada > 1){
            printf("\nError de formato.\nOPCIONES: \n[1]: Si\n[0]: No   : ");
            scanf("%d", &confirmada);
            fflush(stdin);
        }

        puntero = (*tareas)->siguiente;

        if (confirmada == 1){

            (*tareas)->siguiente = *tareasRealizadas;
            *tareasRealizadas = *tareas; 
        } else {

            (*tareas)->siguiente = noRealizadas;
            noRealizadas = *tareas; 
        }

        *tareas = puntero;
    }

    *tareas = noRealizadas;
}
