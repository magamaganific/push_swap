#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int *numero;  // puntero a un número
    struct Nodo *siguiente;  // puntero al siguiente nodo
} Nodo;

// Función para crear un nodo
Nodo* crearNodo(int *numero) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->numero = numero;  // asigna el puntero al número
        nuevoNodo->siguiente = NULL;  // inicializa el siguiente como NULL
    }
    return nuevoNodo;
}

// Función para agregar un nodo al final de la lista usando un doble puntero
void agregarNodo(Nodo **cabeza, int *numero) {
    Nodo *nuevoNodo = crearNodo(numero);
    
    if (*cabeza == NULL) {
        // Si la lista está vacía, el nuevo nodo será la cabeza
        *cabeza = nuevoNodo;
    } else {
        // Si la lista no está vacía, encontrar el último nodo y agregar el nuevo
        Nodo *actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir los valores de los nodos
void imprimirLista(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", *(actual->numero));
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para mover los valores hacia arriba en la lista
void moverValoresHaciaArriba(Nodo **cabeza) {
    if (*cabeza == NULL || (*cabeza)->siguiente == NULL) {
        // Si la lista está vacía o tiene un solo nodo, no se hace nada
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;

    // Iteramos hasta llegar al último nodo
    while (actual->siguiente != NULL) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Hacemos que el segundo nodo sea el nuevo cabeza de la lista
    *cabeza = (*cabeza)->siguiente;
    
    // El último nodo apunta al primero
    anterior->siguiente = NULL;
    actual->siguiente = *cabeza;
    *cabeza = actual;
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};  // ejemplo de números
    int cantidad = sizeof(numeros) / sizeof(numeros[0]);  // determinar la cantidad de elementos
    
    Nodo *cabeza = NULL;
    
    // Crear la lista de nodos utilizando doble puntero
    for (int i = 0; i < cantidad; i++) {
        agregarNodo(&cabeza, &numeros[i]);  // Pasamos la dirección de la cabeza
    }
    
    // Imprimir la lista original
    printf("Lista original:\n");
    imprimirLista(cabeza);
    
    // Mover los valores hacia arriba
    moverValoresHaciaArriba(&cabeza);
    
    // Imprimir la lista después del movimiento
    printf("\nLista después de mover los valores hacia arriba:\n");
    imprimirLista(cabeza);
    
    // Liberar memoria de los nodos
    Nodo *actual = cabeza;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}

