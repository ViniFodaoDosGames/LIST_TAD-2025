#include "List_Header.h"
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    List* list_ptr = Create_list();

    if(Its_empty(list_ptr))
        printf("\t\nEmpty\n");
    else
        printf("\t\nNot empty\n");

    Insert_first(list_ptr, 9);
    Insert_first(list_ptr, 10);
    Insert_last(list_ptr, -2);

    if(Its_empty(list_ptr))
        printf("\t\nEmpty\n");
    else
        printf("\t\nNot empty\n");

    printf("\n----\n");

    printf("\nFirst value of the list: %d\n", Remove_first(list_ptr));

    Destroy_list(list_ptr);

    printf("\nFirst value of the list: %d\n", Remove_first(list_ptr));

    printf("\nFirst value of the list: %d\n", Remove_first(list_ptr));

    printf("\nFirst value of the list: %d\n", Remove_first(list_ptr));

    /**Correção do problema: estava retornando -1 porque a função de destruir não apagava totalmente os nós da lista*/
    list_ptr=NULL;
    return 0;
}
