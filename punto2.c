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



    // esta parte del trabajo la había realizado antes de las funciones de buscar pero me di cuenta que me quedaba sin memoria y me daba un segmentation fault

    tareasRealizadas = (Tarea **)malloc(sizeof(Tarea *) * cantTareas);

    for (int i = 0; i < cantTareas; i++){
        tareasRealizadas[i] = NULL;
    }


    printf("\n\n\n--------CONFIRMACION DE TAREAS REALIZADAS--------");
    confirmar(tareas, tareasRealizadas, cantTareas);

    mostrarConfirmadas(tareas, tareasRealizadas, cantTareas);


    liberarMemoria(tareas, cantTareas);
    liberarMemoria(tareasRealizadas, cantTareas); */

    return 0;
}


Lista crearListaVacia(){

    return NULL;
}

Lista crearNodo(int cantTareas, int i){

    char *Buffer = (char *)malloc(100 * sizeof(char));

    printf("\n----Tarea [%d]----", i+1);

    Lista tarea = (Lista)malloc(sizeof(Lista));


    printf("\nIngrese la descripcion de la tarea [%d]: ", i + 1);
    gets(Buffer);
    fflush(stdin);

    tarea->t.descripcion = (char *)malloc(strlen(Buffer) + 1);
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
