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

// Función para intercambiar los valores a los que apuntan dos nodos
void intercambiarNodos(Nodo *nodo1, Nodo *nodo2) {
    int *temp = nodo1->numero;
    nodo1->numero = nodo2->numero;
    nodo2->numero = temp;
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
    
    // Supón que quieres intercambiar el primer nodo con el segundo nodo
    intercambiarNodos(cabeza, cabeza->siguiente);
    
    // Imprimir la lista después del intercambio
    printf("\nLista después de intercambiar:\n");
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
