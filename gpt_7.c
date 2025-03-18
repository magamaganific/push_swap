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

// Función para agregar un nodo al principio de la lista
void agregarNodoAlPrincipio(Nodo **cabeza, int *numero) {
    Nodo *nuevoNodo = crearNodo(numero);
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
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

// Función para mover el primer número de la lista "a" a la lista "b"
void moverPrimerNodo(Nodo **cabezaA, Nodo **cabezaB) {
    if (*cabezaA == NULL) {
        // Si la lista "a" está vacía, no hay nada que mover
        return;
    }

    // Paso 1: Tomamos el valor del primer nodo de la lista "a"
    Nodo *primerNodoA = *cabezaA;
    *cabezaA = primerNodoA->siguiente;  // Movemos la cabeza de "a" al siguiente nodo

    // Paso 2: Creamos un nuevo nodo en la lista "b" con el valor del primer nodo de "a"
    agregarNodoAlPrincipio(cabezaB, primerNodoA->numero);

    // Paso 3: Liberamos el nodo que ya no es necesario
    free(primerNodoA);
}

// Función para mover el primer número de la lista "b" a la lista "a"
void moverPrimerNodoB(Nodo **cabezaB, Nodo **cabezaA) {
    if (*cabezaB == NULL) {
        // Si la lista "b" está vacía, no hay nada que mover
        return;
    }

    // Paso 1: Tomamos el valor del primer nodo de la lista "b"
    Nodo *primerNodoB = *cabezaB;
    *cabezaB = primerNodoB->siguiente;  // Movemos la cabeza de "b" al siguiente nodo

    // Paso 2: Creamos un nuevo nodo en la lista "a" con el valor del primer nodo de "b"
    agregarNodoAlPrincipio(cabezaA, primerNodoB->numero);

    // Paso 3: Liberamos el nodo que ya no es necesario
    free(primerNodoB);
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};  // ejemplo de números
    int cantidad = sizeof(numeros) / sizeof(numeros[0]);  // determinar la cantidad de elementos
    
    Nodo *cabezaA = NULL;  // Lista A
    Nodo *cabezaB = NULL;  // Lista B
    
    // Crear la lista "a" de nodos utilizando doble puntero
    for (int i = 0; i < cantidad; i++) {
        agregarNodoAlPrincipio(&cabezaA, &numeros[i]);  // Insertar al principio de "A"
    }
    
    // Imprimir la lista original "a"
    printf("Lista A original:\n");
    imprimirLista(cabezaA);
    
    // Mover el primer nodo de la lista "a" a la lista "b"
    moverPrimerNodo(&cabezaA, &cabezaB);
    
    // Imprimir la lista "a" después de mover el primer nodo
    printf("\nLista A después de mover el primer nodo a B:\n");
    imprimirLista(cabezaA);
    
    // Imprimir la lista "b" después de agregar el primer nodo
    printf("\nLista B después de mover el primer nodo de A a B:\n");
    imprimirLista(cabezaB);
    
    // Ahora mover el primer nodo de la lista "b" de vuelta a "a"
    moverPrimerNodoB(&cabezaB, &cabezaA);
    
    // Imprimir la lista "a" después de mover el primer nodo de vuelta desde B
    printf("\nLista A después de mover el primer nodo de B de vuelta a A:\n");
    imprimirLista(cabezaA);
    
    // Imprimir la lista "b" después de mover el primer nodo de vuelta a A
    printf("\nLista B después de mover el primer nodo de vuelta a A:\n");
    imprimirLista(cabezaB);
    
    // Liberar memoria de los nodos
    Nodo *actual = cabezaA;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    actual = cabezaB;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}
