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
	while (actual->siguiente != NULL) {
		printf("%d -> ", *(actual->numero));
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

void moverValoresHaciaAbajo(Nodo *cabeza) {
	if (cabeza == NULL || cabeza->siguiente == NULL) {
		// Si la lista está vacía o tiene un solo nodo, no se hace nada
		return;
	}

	// Paso 1: Guardar los valores de la lista en un arreglo
	Nodo *actual = cabeza;
	int size = 0;
	
	// Contamos cuántos nodos hay en la lista
	while (actual != NULL) {
		size++;
		actual = actual->siguiente;
	}
	
	int valores[size];
	actual = cabeza;
	
	// Guardamos los valores en el arreglo
	for (int i = 0; i < size; i++) {
		valores[i] = *(actual->numero);
		actual = actual->siguiente;
	}

	// Paso 2: Mover los valores hacia Abajo en el arreglo
	int tmp = valores[size - 1];
	for (int i = size; i > 0 ; i--) {
		valores[i] = valores[i - 1];
	}
	valores[0] = tmp;

	// Paso 3: Asignar los valores movidos de vuelta a los nodos
	actual = cabeza;
	for (int i = 0; i < size; i++) {
		*(actual->numero) = valores[i];
		actual = actual->siguiente;
	}
}

void ft_push(Nodo *dst, Nodo *src)
{
	if (dst == NULL || dst->siguiente == NULL) {
		// Si la lista está vacía o tiene un solo nodo, no se hace nada
		return;
	}

	// Paso 1: Guardar los valores de la lista en un arreglo
	Nodo *actual = dst;
	int size = 0;
	
	// Contamos cuántos nodos hay en la lista
	while (actual != NULL) {
		size++;
		actual = actual->siguiente;
	}
	
	int valores[size];
	actual = dst;
	
	// Guardamos los valores en el arreglo
	for (int i = 0; i < size; i++) {
		valores[i] = *(actual->numero);
		actual = actual->siguiente;
	}

	Nodo *nuevo = src;
	int finval[size + 1];
	int newval[1];
	newval[0] = *(nuevo->numero);
	Nodo *temp = nuevo;
	nuevo = nuevo->siguiente;
	free(temp);

	// Paso 2: Mover los valores hacia Abajo en el arreglo
	int tmp = newval[0];
	for (int i = size + 1; i > 0 ; i--) {
		finval[i] = valores[i - 1];
	}
	finval[0] = tmp;

	// Paso 3: Asignar los valores movidos de vuelta a los nodos
	actual = dst;
	for (int i = 0; i < size; i++) {
		*(actual->numero) = finval[i];
		actual = actual->siguiente;
	}
}

int main() {
	int numeros[] = {10, 20, 30, 40, 50};  // ejemplo de números
	int añadir[] = {60};
	int cantidad = sizeof(numeros) / sizeof(numeros[0]);  // determinar la cantidad de elementos
	int cantidbd = sizeof(añadir) / sizeof(añadir[0]);

	Nodo *cabeza = NULL;
	Nodo *cabezb = NULL;
	
	// Crear la lista de nodos utilizando doble puntero
	printf("\nCreando lista a:\n");
	for (int i = 0; i < cantidad + 1; i++) {
		agregarNodo(&cabeza, &numeros[i]);  // Pasamos la dirección de la cabeza
		imprimirLista(cabeza);
	}
	
	printf("\nCreando lista b:\n");
		for (int i = 0; i < cantidad + 1; i++) {
		agregarNodo(&cabezb, &añadir[0]);  // Pasamos la dirección de la cabeza
		imprimirLista(cabezb);
	}
	
	// Imprimir la lista original
	printf("\nListas originales:\n");
	imprimirLista(cabeza);
	imprimirLista(cabezb);
	
	// Mover los valores hacia arriba
	ft_push(cabeza, cabezb);
	
	// Imprimir la lista después del movimiento
	printf("\nListas después de push:\n");
	imprimirLista(cabeza);
	
	// Liberar memoria de los nodos
	Nodo *actual = cabeza;
	printf("\nBorrando lista:\n");
	while (actual != NULL) {
		imprimirLista(actual);
		Nodo *temp = actual;
		actual = actual->siguiente;
		free(temp);
	}
	Nodo *actualb = cabezb;
	printf("\nBorrando listb:\n");
	while (actualb != NULL) {
		imprimirLista(actualb);
		Nodo *tempb = actualb;
		actualb = actualb->siguiente;
		free(tempb);
	}

	return 0;
}
