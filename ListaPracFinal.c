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
int insertarNodoOrdenadoCreditos(struct Nodo** cabeza, struct Nodo* nodo);
void imprimirLista(const struct Nodo* cabeza);


struct Nodo* crearNodo(const Alumno* alumno) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = *alumno;
    nodo->siguiente = NULL;
    return nodo;
}

int main() {
    struct Nodo* lista = NULL;

    // 5 pruebas
    insertarNodoOrdenadoCreditos(&lista, crearNodo(crearAlumno("Victor Hugo Rosado", 110, 4)));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(crearAlumno("Emiliano Arceo Marquez", 75, 3)));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(crearAlumno("Carlos Ek Raigoza", 150, 5)));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(crearAlumno("David ALfaro Siqueiros", 65, 2)));
    insertarNodoOrdenadoCreditos(&lista, crearNodo(crearAlumno("Ramses Rodriguez Morales", 130, 4)));

    printf("Lista de alumnos ordenada por creditos:\n");
    imprimirLista(lista);

    // Libera memoria
    while (lista) {
        struct Nodo* tempNodo = lista;
        lista = lista->siguiente;
        free(tempNodo->dato.NombreC);
        free(tempNodo);
    }

    return 0;
}


Alumno* crearAlumno(const char* NombreC, int CreditosAp, int Semestre) {
    Alumno* alumno = (Alumno*)malloc(sizeof(Alumno));
    printf("Se ha creado un nodo en la lista de alumnos en la direccion %p\n",(void*)alumno);
    alumno->NombreC = strdup(NombreC);
    alumno->CreditosAp = CreditosAp;
    alumno->Semestre = Semestre;
    return alumno;
}

void imprimirAlumno(const Alumno* alumno) {
    printf("Nombre Completo: %s, Creditos Aprobador: %d, Semestre: %d\n", alumno->NombreC, alumno->CreditosAp, alumno->Semestre);
}

int insertarNodoOrdenadoCreditos(struct Nodo** cabeza, struct Nodo* nodo) {
    if (!(*cabeza) || nodo->dato.CreditosAp >= (*cabeza)->dato.CreditosAp) {
        nodo->siguiente = *cabeza;
        *cabeza = nodo;
        return 0; 
    }

    struct Nodo* actual = *cabeza;
    while (actual->siguiente && actual->siguiente->dato.CreditosAp > nodo->dato.CreditosAp) {
        actual = actual->siguiente;
    }

    nodo->siguiente = actual->siguiente;
    actual->siguiente = nodo;
    return 0; 
}

void imprimirLista(const struct Nodo* cabeza) {
    const struct Nodo* actual = cabeza;
    while (actual) {
        imprimirAlumno(&actual->dato);
        actual = actual->siguiente;
    }
}