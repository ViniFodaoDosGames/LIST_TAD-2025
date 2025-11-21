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
        //printf("\nCertin (:^D)\n");
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
/**/

/**Até então, tá td show ness bagaça aqui tbm, joia*/
int Its_empty(List* l)
{
    if(l->first==NULL)
        return 1;
    else
        return 0;
}
/**/

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
        /**
        printf("\n\tPRIMEIRO ADICIONADO\n");
        printf("\n\tendereço da l->first: %d\n", l->first);
        printf("\n\tendereço gurdado em l->last->before: %d\n", l->last->before);
        printf("\n\tendereço gurdado em l->last->next: %d\n", l->last->next);
        printf("\n\t------------------------------------------------");
        */
    }
    else
    {
        l->first->before=p_node;
        p_node->next=l->first;
        p_node->before=NULL;
        /**
        printf("\n\tNOVO ADICIONADO\n");
        printf("\n\tendereço gurdado em p_node: %d\n", p_node);
        printf("\n\tendereço gurdado em p_node->next: %d\n", p_node->next);
        printf("\n\tendereço gurdado em p_node->before: %d\n", p_node->before);
        printf("\n\t------------------------------------------------");

        printf("\n\tVALORES DO PRIMEIRO, SEM QUE A LISTA TENHA SIDO ATUALIZADA\n");
        printf("\n\tendereço da l->first: %d\n", l->first);
        printf("\n\tendereço gurdado em l->first->before: %d\n", l->first->before);
        printf("\n\tendereço gurdado em l->first->next: %d\n", l->first->next);
        printf("\n\t------------------------------------------------");
        */

    }

    l->first=p_node;
    /**
    printf("\n\t------------------------------------------------");
    printf("\n\tLISTA\n");
    printf("\n\tendereço da l->first: %d\n", l->first);
    printf("\n\tendereço gurdado em l->last: %d\n", l->last);
    printf("\n\t------------------------------------------------");
    printf("\n");
    */
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
        /**
        printf("\n\tFIRST value add\n");
        printf("\n\tAddress l->first: %d\n", l->first);
        printf("\n\tAddress storage in l->last->before: %d\n", l->last->before);
        printf("\n\tAddress storage in l->last->next: %d\n", l->last->next);
        printf("\n\t------------------------------------------------");
        */
    }
    else
    {
        l->last->next=p_node;
        p_node->next=NULL;
        p_node->before=l->last;
        /**
        printf("\n\tNEWEST value\n");
        printf("\n\tAddress storage in p_node: %d\n", p_node);
        printf("\n\tAddress storage in p_node->next: %d\n", p_node->next);
        printf("\n\tAddress storage in p_node->before: %d\n", p_node->before);
        printf("\n\t------------------------------------------------");

        printf("\n\tVALORES DO ÚLTIMO, SEM QUE A LISTA TENHA SIDO ATUALIZADA\n");
        printf("\n\tAddress l->last: %d\n", l->last); // node
        printf("\n\tAddress storage in l->last->before: %d\n", l->last->before);
        printf("\n\tAddress storage in l->last->next: %d\n", l->last->next);
        printf("\n\t------------------------------------------------");
        */

    }

    l->last=p_node;
    /**
    printf("\n\t------------------------------------------------");
    printf("\n\tLIST DATA\n");
    printf("\n\tAddress l->first: %d\n", l->first);
    printf("\n\tAddress storage in l->last: %d\n", l->last);
    printf("\n\t------------------------------------------------");
    printf("\n");
    */
}

int Remove_first(List* l)
{

    if(!Its_empty(l))
    {
        //printf("\n\tendereço da l->first: %d\n", l->first);
        //printf("\n\tendereço da l->first->next: %d\n", l->first->next);
        int return_value = l->first->data;
        Node* aux_first = l->first;

        l->first=l->first->next;

        free(aux_first);
        aux_first=NULL;

        //printf("\n\tendereço da l->first ATUALIZADO: %d\n", l->first);
        return return_value;
    }
    else
    {
        printf("\n\tERROR: list alredy empty...\n");
        return -1;
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
            Remove_first(l); // remove cada nó da lista
        }
        free(l);//libera a lista
    }
    /**PROBLEMA: Não libera os nós entre a lista - 15/11/25 */
    /**
    Posso, al invés de remover o primeiro e o último, fazer uma validação que, enquato n estiver vazia, remover o primeiro. Só depois remover a lista - 15/11/25
    Entretanto sua complexidade será O(n).
    */
}
/**/
/**Seria bom eu verificar em todas as funções se a lista existe ou não?*/
