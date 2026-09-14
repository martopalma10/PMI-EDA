#ifndef ELECTOR_H_INCLUDED
#define ELECTOR_H_INCLUDED
#include <string.h>

#define MAX 2500 //Maximo de electores 2000, margen de 500
#define Infinito_LVO 999999999 //funcionaria como "infinito"

typedef struct {
    int dni;                   /// dni es un entero.
    char nombre_apellido[51];  /// Apellido de hasta 50 caracteres
    char domicilio[81];        /// Domicilio hasta 80 caracteres
    int cod_postal;            /// codigo postal es un entero
    int mesa;                  /// Núm. de mesa es un entero
    int circuito;              /// El Circuito es un entero (no se a que se refiere con circuito)
} Elector;

/// init
inline void init_elector(Elector *e) {
        if (e == NULL)
            return;

        e->dni = 0;
        strcpy(e->nombre_apellido, "Sin aclarar");
        strcpy(e->domicilio, "Sin aclarar");
        e->cod_postal = 0;
        e->mesa = 0;
        e->circuito = 0;

}

///getter y setters no son necesarios 
/*
/// getters
 int elector_get_dni(Elector e) {
    return e.dni;
}

 char* elector_get_nombre_apellido(Elector e) {
    char *N = (char*) malloc(sizeof(char) * 51);
    if (N != NULL) {
        strcpy(N, e.nombre_apellido);
    }
    return N; ///utiliza memoria dinamica para obtener el string, luego libera.
}

 char* elector_get_domicilio(Elector e) {
    char *N = (char*) malloc(sizeof(char) * 81);
    if (N != NULL) {
        strcpy(N, e.domicilio);
    }
    return N;
}

 int elector_get_cod_postal(Elector e) {
    return e.cod_postal;
}

 int elector_get_mesa(Elector e) {
    return e.mesa;
}

 int elector_get_circuito(Elector e) {
    return e.circuito;
}

///Setters

void elector_set_dni(Elector *e, int dni) {
    e->dni = dni;
}

void elector_set_nombre_apellido(Elector *e, char aux_nombre[]) {
    strcpy(e->nombre_apellido, aux_nombre);
}

void elector_set_domicilio(Elector *e, char aux_domicilio[]) {
    strcpy(e->domicilio, aux_domicilio);
}

void elector_set_cod_postal(Elector *e, int cod_postal) {
    e->cod_postal = cod_postal;
}

void elector_set_mesa(Elector *e, int mesa) {
   e->mesa = mesa;
}

void elector_set_circuito(Elector *e, int circuito) {
    e->circuito = circuito;
}
*/

static void MostrarElector(Elector elector)
{
    printf("DNI: %d\n", elector.dni);
    printf("Nombre y Apellido: %s\n", elector.nombre_apellido);
    printf("Domicilio: %s\n", elector.domicilio);
    printf("Codigo Postal: %d\n", elector.cod_postal);
    printf("Mesa: %d\n", elector.mesa);
    printf("Circuito: %d\n\n", elector.circuito);
}

#endif // ELECTOR_H_INCLUDED
