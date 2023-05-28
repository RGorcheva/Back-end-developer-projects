
/*Write me a program in c that is given a linked list Aand, indexNand size M.
Extract M elements into a second given linked list B, starting at position N of A.
The algorithm reseives three input parameters : -Head A - a pointer to the A list, 
N - index at A list, M - size(count) if elements to be extract into Band head B - a pointer to the B list.
In case of an error, output an error massage on the standart outputand exit.Do not use any library functions for list manipulation.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list* next;
}list;

void list_pushback(list** lis, int a)
{
	list* new = (list*)malloc(sizeof(list));
    if (new == NULL)
    {
        printf("Cannot alocate memory!\n");
        return;
    }
    new->data = a;
    new->next = NULL;
    if (*lis == NULL)
    {
        *lis = new;
        return;
    }
    list* it = *lis;
    while (it->next != NULL)
    {
        it = it->next;
    }
    it->next = new;
}
list_deleteInd(list** lis, int idx)
{
    list* prev = *lis;
    for (int i = 0; i < idx-1; i++)
    {
        prev = prev->next;
    }
    list* curr = prev->next;
    prev->next = curr->next;
    free(curr);
}
int list_countElements(list** lis)
{
    list* it = *lis;
    int count = 0;
    while (it->next != NULL)
    {
        it = it->next;
        count++;
    }
    return count;
}
void list_extract(list** A, list** B, int N, int M)
{
    int count = list_countElements(A);
    if (count < N)
    {
        printf("N is out of range!\n");
        return;
    }
    else if (count < N + M)
    {
        printf("M is out of range!\n");
        return;
    }
    list* itA = *A;
    if (itA == NULL)
    {
        printf("ListA is empty!\n");
    }
    for (int i = 0; i < N - 1; i++)
    {
        itA = itA->next;
    }
    for (int i = 0; i < M; i++)
    {
        list_pushback(B, itA->next->data);
        list_deleteInd(A, N);
    }
}
void list_print(list** lis)
{
    list* it = *lis;
    if (it == NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    while (it != NULL)
    {
        printf("%d -> ", it->data);
        it = it->next;
    }
    printf("NULL");
}

int main(void)
{
	int M = 5;
	int N = 3;
    list* headA = NULL;
    list* headB = NULL;
	list_pushback(&headA, 18);
    list_pushback(&headA, 3);
    list_pushback(&headA, 4);
    list_pushback(&headA, 7);
    list_pushback(&headA, 10);
    list_pushback(&headA, 9);
    list_pushback(&headA, 23);
    list_pushback(&headA, 25);
    list_pushback(&headA, 0);
    list_pushback(&headA, 1);
    printf("List A: ");
    list_print(&headA);
    list_extract(&headA, &headB, N, M);
    printf("\nList A: ");
    list_print(&headA);
    printf("\nList B: ");
    list_print(&headB);
	return 0;
}


//// Define a node for the linked list
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//// Function to insert a node at the end of the list
//void insertAtEnd(struct Node** head, int data) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = data;
//    newNode->next = NULL;
//    if (*head == NULL) {
//        *head = newNode;
//        return;
//    }
//    struct Node* current = *head;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    current->next = newNode;
//}
//
//// Function to extract M elements from linked list A
//void extractElements(struct Node** headA, int N, int M, struct Node** headB) {
//    // Check if headA is NULL
//    if (*headA == NULL) {
//        printf("Error: Head A is NULL\n");
//        exit(1);
//    }
//    // Traverse to the Nth node
//    struct Node* current = *headA;
//    int count = 1;
//    while (count < N && current != NULL) {
//        current = current->next;
//        count++;
//    }
//    // Check if N is a valid index
//    if (current == NULL) {
//        printf("Error: Index N is out of range\n");
//        exit(1);
//    }
//    // Extract M elements into linked list B
//    struct Node* currentB = NULL;
//    for (int i = 0; i < M && current != NULL; i++) {
//        if (i == 0) {
//            *headB = current;
//        }
//        else {
//            currentB->next = current;
//        }
//        currentB = current;
//        current = current->next;
//    }
//    // Check if M is valid
//    if (currentB == NULL) {
//        printf("Error: Size M is zero\n");
//        exit(1);
//    }
//    // Set the next pointer of the last node in linked list B to NULL
//    currentB->next = NULL;
//}
//
//// Function to print the linked list
//void printList(struct Node* head) {
//    struct Node* current = head;
//    while (current != NULL) {
//        printf("%d ", current->data);
//        current = current->next;
//    }
//    printf("\n");
//}
//
//// Main function
//int main() {
//    // Initialize linked list A
//    struct Node* headA = NULL;
//    insertAtEnd(&headA, 1);
//    insertAtEnd(&headA, 2);
//    insertAtEnd(&headA, 3);
//    insertAtEnd(&headA, 4);
//    insertAtEnd(&headA, 5);
//    insertAtEnd(&headA, 6);
//    insertAtEnd(&headA, 7);
//    // Print linked list A
//    printf("Linked List A: ");
//    printList(headA);
//    // Extract M elements from linked list A
//    int N = 3, M = 4;
//    struct Node* headB = NULL;
//    extractElements(&headA, N, M, &headB);
//    // Print linked list B
//    printf("Linked List B: ");
//    printList(headB);
//    // Print updated linked list A
//    printf("Updated Linked List A: ");
//    printList(headA);
//    return 0;
//}


////CPP
//#include <stdio.h>
//#include <stdlib.h>
//
//// Define a node for the linked list
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//// Function to insert a node at the end of the list
//void insertAtEnd(struct Node** head, int data) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = data;
//    newNode->next = NULL;
//    if (*head == NULL) {
//        *head = newNode;
//        return;
//    }
//    struct Node* current = *head;
//    while (current->next != NULL) {
//        current = current->next;
//    }
//    current->next = newNode;
//}
//
//// Function to extract M elements from linked list A
//void extractElements(struct Node** headA, int N, int M, struct Node** headB) {
//    // Check if headA is NULL
//    if (*headA == NULL) {
//        printf("Error: Head A is NULL\n");
//        exit(1);
//    }
//    // Traverse to the Nth node
//    struct Node* current = *headA;
//    int count = 1;
//    while (count < N && current != NULL) {
//        current = current->next;
//        count++;
//    }
//    // Check if N is a valid index
//    if (current == NULL) {
//        printf("Error: Index N is out of range\n");
//        exit(1);
//    }
//    // Extract M elements into linked list B
//    struct Node* currentB = NULL;
//    for (int i = 0; i < M && current != NULL; i++) {
//        if (i == 0) {
//            *headB = current;
//        }
//        else {
//            currentB->next = current;
//        }
//        currentB = current;
//        current = current->next;
//    }
//    // Check if M is valid
//    if (currentB == NULL) {
//        printf("Error: Size M is zero\n");
//        exit(1);
//    }
//    // Set the next pointer of the last node in linked list B to NULL
//    currentB->next = NULL;
//}
//
//// Function to print the linked list
//void printList(struct Node* head) {
//    struct Node* current = head;
//    while (current != NULL) {
//        printf("%d ", current->data);
//        current = current->next;
//    }
//    printf("\n");
//}
//
//// Main function
//int main() {
//    // Initialize linked list A
//    struct Node* headA = NULL;
//    insertAtEnd(&headA, 1);
//    insertAtEnd(&headA, 2);
//    insertAtEnd(&headA, 3);
//    insertAtEnd(&headA, 4);
//    insertAtEnd(&headA, 5);
//    insertAtEnd(&headA, 6);
//    insertAtEnd(&headA, 7);
//    // Print linked list A
//    printf("Linked List A: ");
//    printList(headA);
//    // Extract M elements from linked list A
//    int N = 3, M = 4;
//    struct Node* headB = NULL;
//    extractElements(&headA, N, M, &headB);
//    // Print linked list B
//    printf("Linked List B: ");
//    printList(headB);
//    // Print updated linked list A
//    printf("Updated Linked List A: ");
//    printList(headA);
//    return 0;
//}



//CPP

//#include <iostream>
//
//using namespace std;
//
//// Define a node for the linked list
//struct Node {
//    int data;
//    Node* next;
//};
//
//// Function to insert a node at the end of the list
//void insertAtEnd(Node** head, int data) {
//    Node* newNode = new Node;
//    newNode->data = data;
//    newNode->next = nullptr;
//    if (*head == nullptr) {
//        *head = newNode;
//        return;
//    }
//    Node* current = *head;
//    while (current->next != nullptr) {
//        current = current->next;
//    }
//    current->next = newNode;
//}
//
//// Function to extract M elements from linked list A
//void extractElements(Node** headA, int N, int M, Node** headB) {
//    // Check if headA is nullptr
//    if (*headA == nullptr) {
//        cout << "Error: Head A is nullptr\n";
//        exit(1);
//    }
//    // Traverse to the Nth node
//    Node* current = *headA;
//    int count = 1;
//    while (count < N && current != nullptr) {
//        current = current->next;
//        count++;
//    }
//    // Check if N is a valid index
//    if (current == nullptr) {
//        cout << "Error: Index N is out of range\n";
//        exit(1);
//    }
//    // Extract M elements into linked list B
//    Node* currentB = nullptr;
//    for (int i = 0; i < M && current != nullptr; i++) {
//        if (i == 0) {
//            *headB = current;
//        }
//        else {
//            currentB->next = current;
//        }
//        currentB = current;
//        current = current->next;
//    }
//    // Check if M is valid
//    if (currentB == nullptr) {
//        cout << "Error: Size M is zero\n";
//        exit(1);
//    }
//    // Set the next pointer of the last node in linked list B to nullptr
//    currentB->next = nullptr;
//}
//
//// Function to print the linked list
//void printList(Node* head) {
//    Node* current = head;
//    while (current != nullptr) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//// Main function
//int main() {
//    // Initialize linked list A
//    Node* headA = nullptr;
//    insertAtEnd(&headA, 1);
//    insertAtEnd(&headA, 2);
//    insertAtEnd(&headA, 3);
//    insertAtEnd(&headA, 4);
//    insertAtEnd(&headA, 5);
//    insertAtEnd(&headA, 6);
//    insertAtEnd(&headA, 7);
//    // Print linked list A
//    cout << "Linked List A: ";
//    printList(headA);
//    // Extract M elements from linked list A
//    int N = 3, M = 4;
//    Node* headB = nullptr;
//    extractElements(&headA, N, M, &headB);
//    // Print linked list B
//    cout << "Linked List B: ";
//    printList(headB);
//    // Print updated linked list A
//    cout << "Updated Linked List A: ";
//    printList(headA);
//    return 0;
//}