#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;          // The data part
    struct Node* next; // Pointer to the next node in the list
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // Create a new node
    newNode->next = *head;  // Point the new node to the current head
    *head = newNode;        // Update the head pointer to the new node
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	// Allocate memory for the new node
    if (newNode == NULL) // Check if malloc was successful
	{
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if memory allocation fails
    }
    
    newNode->data = value;  // Set the data of the node
    newNode->next = NULL;    // Initially, the next pointer is NULL
    return newNode;          // Return the pointer to the new node
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    
    while (current != NULL) { // Continue until the end of the list
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}
// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next; // Save the next node
        free(current);             // Free the current node
        current = nextNode;        // Move to the next node
    }
}

