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

void loadFromFile(const char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Failed to open file for reading.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file) !=NULL){
        insertLine(line);
    }
    fclose(file);
}

int main(){
    setlocale(LC_ALL,"en_US");

    char choice;
    char input[MAX_LINE_LEN];

    printf("Simple Text Editor\n");


    while(1){
        printf("\n=== Menu ===\n");
        printf("1. Insert line\n");
        printf("2. Delete line\n");
        printf("3. Display text\n");
        printf("4. Save to file\n");
        printf("5. Load from file\n");
        printf("6. Exit\n");
        printf("Enter your choice:");
        scanf(" %c", &choice);
    }
}