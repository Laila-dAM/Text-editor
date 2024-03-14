#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LEN 256

typedef struct Node {
    char line[MAX_LINE_LEN];
    struct Node *next;
} Node;
