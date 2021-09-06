
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char direccion[] = "peliculasFavoritasESD135_2021.csv";
    leer_archivo(direccion);
    extraer(direccion);
    transponer();
    Multiplicacion();
    carnes();

    return (EXIT_SUCCESS);
}

