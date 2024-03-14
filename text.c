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