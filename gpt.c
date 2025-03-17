#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    
    while (current != NULL) {
        printf("[%d] \n", current->data);
        printList(current);
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL; // Initialize the list as empty
    
    // Insert nodes
    insertAtBeginning(&head, 10);
    printList(head);
    insertAtBeginning(&head, 20);
    printList(head);
    insertAtBeginning(&head, 30);
    
    // Print the list
    printList(head);
    
    // Free the memory
    freeList(head);
    
    return 0;
}
