#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura de un nodo en la cola
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Definicion de la estructura de la cola
struct Cola {
    struct Nodo* frente;
    struct Nodo* trasero;
};

// Funcion para crear una cola vacia
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->frente = cola->trasero = NULL;
    return cola;
}

// Funcion para insertar un elemento en la cola
void encolar(struct Cola* cola, int dato) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (cola->trasero == NULL) {
        cola->frente = cola->trasero = nuevoNodo;
    } else {
        cola->trasero->siguiente = nuevoNodo;
        cola->trasero = nuevoNodo;
    }
}

// Funcion para eliminar un elemento de la cola
int desencolar(struct Cola* cola) {
    if (cola->frente == NULL) {
        printf("La cola esta vacia.\n");
        return -1;
    }

    struct Nodo* temp = cola->frente;
    int dato = temp->dato;
    cola->frente = temp->siguiente;

    if (cola->frente == NULL) {
        cola->trasero = NULL;
    }

    free(temp);
    return dato;
}

// Funcion para mostrar la cola
void mostrarCola(struct Cola* cola) {
    if (cola->frente == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    struct Nodo* actual = cola->frente;

    printf("Elementos en la cola: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }

    printf("\n");
}

int main() {
    struct Cola* cola = crearCola();
    int opcion, valor;

    while (1) {
        printf("--------------------------\n");
        printf("1. Insertar en la cola\n");
        printf("2. Eliminar de la cola\n");
        printf("3. Mostrar la cola\n");
        printf("4. Salir\n");
        printf("Elije una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%d", &valor);
                encolar(cola, valor);
                break;
            case 2:
                valor = desencolar(cola);
                if (valor != -1) {
                    printf("Elemento eliminado de la cola: %d\n", valor);
                }
                break;
            case 3:
                mostrarCola(cola);
                break;
            case 4:
                exit(0);
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
    }

    return 0;
}
