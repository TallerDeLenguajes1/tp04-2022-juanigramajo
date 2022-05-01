printf("\n\n\n--------Buscar tarea por palabra:--------");

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
    liberarMemoria(tareasRealizadas, cantTareas);