#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "elector.h"

///ESTRUCTURA Lista Secuencial Ordenada de Busqueda Binaria

typedef struct {
    Elector elementos[MAX];
    int cantidad;

    /// Contadores de métricas para el análisis de costos
    /// Se usan float para estandarizar con las estructuras vinculadas que sumarán 0.5 por puntero
    float costo_ingresos;
    float costo_eliminaciones;
    float costo_consultas;
} LSOBB;

///init

static void init_LSOBB(LSOBB *lista) {
    lista->cantidad = 0;
    lista->costo_ingresos = 0.0;
    lista->costo_eliminaciones = 0.0;
    lista->costo_consultas = 0.0;
}

/// Control de elementos (vacia / llena)

int isempty_LSOBB(LSOBB lista) {
    return (lista.cantidad == 0);
}

int isfull_LSOBB(LSOBB lista) {
    return (lista.cantidad >= MAX);
}

///LOCALIZACIÓN (BÚSQUEDA BINARIA)

// Retorna 1 si lo encuentra, 0 si no.
static int localizar_LSOBB(LSOBB *lista, int dni_buscado, int *pos) {
    ///Pmi dice = limites inclusivos

    int li = 0;
    int ls = lista->cantidad - 1;
    int m;

    while (li <= ls) { ///segmento mas grande a la izquierda
        m = (li + ls + 1) / 2;

        lista->costo_consultas += 1.0; ///consultas tiene costo 1 por celda

        int dni_actual = elector_get_dni(lista->elementos[m]);

        if (dni_actual == dni_buscado) {
            *pos = m;
            return 1; /// exito (elemento encontrado)
        } else if (dni_actual < dni_buscado) {
            /// testigo a izquierda (en la biseccion el elemento n-1 del limite inclusivo)
            li = m + 1;
        } else {
            ls = m - 1;
        }
    }

    /// Si no lo encuentra, el limite inf. contiene la posición exacta donde tendria q estar para mantener el orden.
    *pos = li;
    return 0; /// aca fracasaria
}

/*
///alta
// Retorna 1 si inserta, 0 si ya existe o está llena
static int insert_LSOBB(LSOBB *lista, Elector aux_datos) {
    if (isfull_LSOBB(*lista)) {
        return 0;
    }

    int pos;
    // Si la localización da 1, el DNI ya existe (el padrón no admite duplicados).
    if (localizar_LSOBB(lista, elector_get_dni(aux_datos), &pos)) {
        return 0;
    }

    // Corrimientos hacia la derecha para hacer el "hueco"
    for (int i = lista->cantidad; i > pos; i--) {
        lista->elementos[i] = lista->elementos[i - 1];

        // En la lista secuencial la función de costo será la cantidad de corrimientos y cada corrimiento de elemento tiene costo 1
        lista->costo_ingresos += 1.0;
    }

    // Insertamos el nuevo elector en el hueco
    lista->elementos[pos] = aux_datos;
    lista->cantidad++;

    // Se suma el ingreso efectivo del dato a la celda como un corrimiento más (escribir el dato cuesta 1)
    lista->costo_ingresos += 1.0;

    return 1;
}

///baja
// Retorna 1 si suprime, 0 si no lo encuentra o no coincide la nupla
static int supress_LSOBB(LSOBB *lista, Elector aux_datos) {
    if (isempty_LSOBB(*lista)) {
        return 0;
    }

    int pos;
    // Buscamos por DNI
    if (localizar_LSOBB(lista, elector_get_dni(aux_datos), &pos)) {

        // Usamos el comparador del elector.h que evalúa todos los campos y no es sensible a mayúsculas/minúsculas.
        if (elector_es_igual(lista->elementos[pos], aux_datos)) {

            // Corrimientos hacia la izquierda para tapar el hueco
            for (int i = pos; i < lista->cantidad - 1; i++) {
                lista->elementos[i] = lista->elementos[i + 1];

                // ESTRATEGIA PMI: Costo 1 por cada corrimiento[cite: 1].
                lista->costo_eliminaciones += 1.0;
            }

            lista->cantidad--;
            return 1; // Baja exitosa
        }
    }

    return 0; // Fracaso: No se encontró o los datos no coinciden
}

/// evoca
// Retorna 1 y copia el dato si lo encuentra, 0 si no.
static int evocar_LSOBB(LSOBB *lista, int dni, Elector *resultado) {
    int pos;
    // La localización ya se encarga de sumar el costo de las celdas consultadas internamente
    if (localizar_LSOBB(lista, dni, &pos)) {
        *resultado = lista->elementos[pos];
        return 1; // Éxito
    }
    return 0; // Fracaso
}
*/

#endif // LSOBB_H_INCLUDED
