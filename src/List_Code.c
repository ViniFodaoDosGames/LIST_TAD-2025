#include "List_Header.h"
#include <stdio.h>
#include <stdlib.h>

/**Até então, tá td show ness bagaça*/
List* Create_list()
{
    List* p_list = (List*) malloc(sizeof(List));
    if(!p_list)
    {
        //printf("\nERROR: list not alocate...\n");
        return NULL;
    }
    else
    {
        //printf("nCertin (:^D)\n");
        p_list->first = NULL;
        p_list->last = NULL;
        if((p_list->first==NULL) &&(p_list->last==NULL))
        {
            //printf("\nCertin tbm (X^D)\n");
            //printf("\n\tendereço da p_list->first: %d\n", p_list->first);
            return p_list;
        }
        else
        {
            //printf("\nERROR: list attributes not alocate...\n");
            return NULL;
        }
    }
}

int Its_empty(List* l)
{
    return l->first==NULL;
}

void Insert_first(List* l, int value)
{
    Node* p_node = (Node*) malloc(sizeof(Node));
    if(!p_node)
    {
        printf("\nERROR: node not alocate...\n");
        return;
    }
    p_node->data=value;
    p_node->next=NULL;
    p_node->before=NULL;
    if(Its_empty(l))
    {
        l->first=p_node;
        l->last=p_node;
    }
    else
    {
        l->first->before=p_node;
        p_node->next=l->first;
        p_node->before=NULL;
    }

    l->first=p_node;
}


/**Essa função está alterando o valor next do first, preciso corrigir isso depois*/
/**Eu acho q já corrigir...em 5 sec... bruh*/
/**Sim, mestre dos magos fodásticos, está certin agr*/
void Insert_last(List* l, int value)
{
    Node* p_node = (Node*) malloc(sizeof(Node));
    if(!p_node)
    {
        printf("\nERROR: node not alocate...\n");
        return;
    }
    p_node->data=value;
    p_node->next=NULL;
    p_node->before=NULL;
    if(Its_empty(l))
    {
        l->first=p_node;
        l->last=p_node;
    }
    else
    {
        l->last->next=p_node;
        p_node->next=NULL;
        p_node->before=l->last;

    }
    l->last=p_node;
}

int Remove_first(List* l)
{

    if(!Its_empty(l))
    {
        int return_value = l->first->data;

        if(l->first==l->last){
            free(l->first);
            l->first=NULL;
            l->last=NULL;
            return return_value;
        }

        Node* aux_first = l->first;
        l->first=l->first->next;
        l->first->before=NULL;
        free(aux_first);
        aux_first=NULL;

        return return_value;
    }
    else
    {
        printf("\n\tERROR: list alredy empty...\n");
        return 0;
    }
}

/**Até então, tá td show ness bagaça aqui tbm, joia - 14/11/25 */
void Destroy_list(List* l)
{
    if(Its_empty(l))  // se a lista já estiver vazia
    {
        free(l); // remove cada nó da lista
        return;
    }
    else
    {
        while(!Its_empty(l)) // enquanto a lista estiver cheia
        {
            int temp_result = Remove_first(l); // remove cada nó da lista
        }
        free(l);//libera a lista
    }
    /**PROBLEMA: Não libera os nós entre a lista - 15/11/25 */
}
/**Seria bom eu verificar em todas as funções se a lista existe ou não?*/

void print_first_to_last(List *l)
{
    Node *fir_lst = l->first;

    printf("\n=======Print Screen First to Last=======\n");
    while (fir_lst != NULL)
    {
        printf("|%d| ", fir_lst->data);
        fir_lst = fir_lst->next;
    }
    printf("\n---------------------------------------\n");

    printf("\n");
}
void print_last_to_first(List *l)
{
    Node *lst_fir = l->last;

    printf("\n=======Print Screen Last to First=======\n");
    while (lst_fir != NULL)
    {
        printf("|%d| ", lst_fir->data);
        lst_fir = lst_fir->before;
    }
    printf("\n---------------------------------------\n");

    printf("\n");
}

int Remove_itens(List* l, int value)
{
    if(Its_empty(l) || l->first==NULL) return 0;

    Node* temp_node_actual = l->first;

    while(temp_node_actual && (temp_node_actual->data!=value))
    {
        /*
        printf("\t\ttemp_node_actual: %d\n", temp_node_actual);
        printf("\t\ttemp_node_actual->data: %d\n", temp_node_actual->data);
        printf("\t\ttemp_node_actual->next: %d\n", temp_node_actual->next);
        printf("\t\ttemp_node_actual->before: %d\n\t++++++++++++\n\n", temp_node_actual->before);
        */
        temp_node_actual=temp_node_actual->next;
    }

    if (!temp_node_actual) return 0;

    /*
    printf("\tACHOU\n");
    printf("\t\ttemp_node_actual: %d\n", temp_node_actual);
    printf("\t\ttemp_node_actual->data: %d\n", temp_node_actual->data);
    printf("\t\ttemp_node_actual->next: %d\n", temp_node_actual->next);
    printf("\t\ttemp_node_actual->before: %d\n\t++++++++++++\n\n", temp_node_actual->before);
    */

    if(!temp_node_actual->before)
    {
        int aux_value = Remove_first(l);
        temp_node_actual = NULL;
    }
    else
    {
        if(temp_node_actual->next) // 1 <- 2 ->NULL
        {
            temp_node_actual->next->before = temp_node_actual->before;
            temp_node_actual->before->next = temp_node_actual->next;
        }
        else
        {
            l->last=l->last->before;
            l->last->next=NULL;
        }
        free(temp_node_actual);
        temp_node_actual=NULL;
    }
/*
    printf("\tLista\n");
    printf("\t\tl->fist: %d\n", l->first);
    printf("\t\tl->last: %d\n", l->last);
*/
    return 1;
}
