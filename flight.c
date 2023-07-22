#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int seatNumber;
    char passengerName[50];
    int isReserved;
    struct Node* prev;
    struct Node* next;
} Node;

void initializeList(Node** head) {
    *head = NULL;
}

void insertNode(Node** head, int seatNumber, char* passengerName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->seatNumber = seatNumber;
    strcpy(newNode->passengerName, passengerName);
    newNode->isReserved = 1; // Assuming the seat is initially reserved
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;

        while (current->next != NULL && current->next->seatNumber < seatNumber) {
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void cancelReservation(Node** head, int seatNumber) {
    Node* current = *head;

    while (current != NULL && current->seatNumber != seatNumber) {
        current = current->next;
    }

    if (current != NULL) {
        current->isReserved = 0;
    }
}

void modifyReservation(Node** head, int seatNumber, char* newPassengerName) {
    Node* current = *head;

    while (current != NULL && current->seatNumber != seatNumber) {
        current = current->next;
    }

    if (current != NULL) {
        strcpy(current->passengerName, newPassengerName);
    }
}

void displayList(Node* head, FILE* file) {
    Node* current = head;

    fprintf(file, "Seat Number\tPassenger Name\tReserved\n");
    fprintf(file, "------------------------------------------\n");

    while (current != NULL) {
        fprintf(file, "%d\t\t%s\t\t%s\n", current->seatNumber, current->passengerName,
               current->isReserved ? "Yes" : "No");
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head;
    initializeList(&head);

    int choice;
    int seatNumber;
    char passengerName[50];

    printf("Flight Reservation System\n");

    FILE* inputFile = fopen("flight_reservation_input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen("flight_reservation_output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &choice) == 1) {
        switch (choice) {
            case 0:
                printf("Exiting program...\n");
                fclose(inputFile);
                fclose(outputFile);
                freeList(head);
                return 0;
            case 1:
                fscanf(inputFile, "%d", &seatNumber);
                fscanf(inputFile, "%s", passengerName);
                insertNode(&head, seatNumber, passengerName);
                fprintf(outputFile, "Seat booked successfully.\n");
                break;
            case 2:
                fscanf(inputFile, "%d", &seatNumber);
                cancelReservation(&head, seatNumber);
                fprintf(outputFile, "Reservation canceled successfully.\n");
                break;
            case 3:
                fscanf(inputFile, "%d", &seatNumber);
                fscanf(inputFile, "%s", passengerName);
                modifyReservation(&head, seatNumber, passengerName);
                fprintf(outputFile, "Reservation modified successfully.\n");
                break;
            case 4:
                displayList(head, outputFile);
                fprintf(outputFile, "Reservation list saved to file.\n");
                break;
            default:
                fprintf(outputFile, "Invalid choice. Please try again.\n");
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    freeList(head);

    return 0;
}



