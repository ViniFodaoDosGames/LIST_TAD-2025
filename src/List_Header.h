#pragma once

typedef struct node
{
    int data;
    struct node* before;
    struct node* next;
}Node;


typedef struct
{
    Node* first;
    Node* last;
}List;


/**Function's prototype*/

List* Create_list();
void Destroy_list(List* l);
int Its_empty(List* l);
void Insert_first(List* l, int value);
void Insert_last(List* l, int value);
int Remove_first(List* l);
void print_first_to_last(List *l);
void print_last_to_first(List *l);
int Remove_itens(List* l, int value);
