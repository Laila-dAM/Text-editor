#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LEN 256

typedef struct Node {
    char line[MAX_LINE_LEN];
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void insertLine(const char *text) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->line, text);
    newNode->next = NULL;
    

if (head == NULL) {
    head = newNode;
    current = newNode;
} else {
    current->next = newNode;
    current = newNode;
}
}

void deleteLine() {
    if (head == NULL)
    return;

    Node *temp = head;
    Node *prev = NULL;

    while (temp->next !=NULL){
        prev = temp;
        temp = temp->next;
    }

    if(prev !=NULL)
    prev->next = NULL;
    else
    head = NULL;

    free(temp);
}

void displayText(){
    Node *temp = head;

    while (temp !=NULL){
        printf("%s\n", temp->line);
        temp = temp->next;
    }
}

void saveToFile(const char *filename){
    FILE *file = fopen(filename, "w");
   
   if (file == NULL) {
    printf("Failed to open file for writing.\n");
    return;
   }

   Node *temp = head;
   while (temp != NULL) {
    fprintf(file, "%s\n", temp->line);
    temp = temp->next;
   }

   fclose(file);
}