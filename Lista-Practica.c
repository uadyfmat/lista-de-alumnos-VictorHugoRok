#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* NombreC;
    int CreditosAp;
    int Semestre;
} Alumno;

typedef Alumno *AlumnoPtr;

struct Nodo {
    Alumno dato;
    struct Nodo* siguiente;
};

// Firmas
Alumno* crearAlumno(const char* NombreC, int CreditosAp, int Semestre);
void imprimirAlumno(const Alumno* alumno);
void imprimirLista(const struct Nodo* cabeza);


struct Nodo* crearNodo(const Alumno* alumno) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = *alumno;
    nodo->siguiente = NULL;
    return nodo;
}

int main() {
    struct Nodo* lista = NULL;

    // *5 pruebas*
    //Sin terminar aun no se implementa la funcion de insertar ordenado los creditos
    
    printf("Lista de alumnos ordenada por creditos:\n");
    imprimirLista(lista);

    return 0;
}


Alumno* crearAlumno(const char* NombreC, int CreditosAp, int Semestre) {
    Alumno* alumno = (Alumno*)malloc(sizeof(Alumno));
    alumno->NombreC = strdup(NombreC);
    alumno->CreditosAp = CreditosAp;
    alumno->Semestre = Semestre;
    return alumno;
}

void imprimirAlumno(const Alumno* alumno) {
    printf("Nombre Completo: %s, Creditos: %d, Semestre: %d\n", alumno->NombreC, alumno->CreditosAp, alumno->Semestre);
}

void imprimirLista(const struct Nodo* cabeza) {
    const struct Nodo* actual = cabeza;
    while (actual) {
        imprimirAlumno(&actual->dato);
        actual = actual->siguiente;
    }
}