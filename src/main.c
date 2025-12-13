#include "List_Header.h"
#include <stdio.h>
#include <locale.h>

void __debug(List **l);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    List* list_ptr = Create_list();

    if(Its_empty(list_ptr))
        printf("\t\nEmpty\n");
    else
        printf("\t\nNot empty\n");

    print_first_to_last(list_ptr);

    if(Remove_itens(list_ptr, 0)==0) // validação para ver se não está removendo se a lista está vazia (deve retornar 0)
    {
        printf("Não existe\n");// deve imprimir esse valor
    }

    Insert_first(list_ptr,2);
    Insert_first(list_ptr,1);
    Insert_first(list_ptr,0);
    Insert_first(list_ptr,0);
    Insert_first(list_ptr,10);



    print_first_to_last(list_ptr);
    Remove_itens(list_ptr, 10);

    print_first_to_last(list_ptr);
    Remove_itens(list_ptr, 2);

    print_first_to_last(list_ptr);// deve imprimir legal, esm ter valor alterado
    Remove_itens(list_ptr, 0);

    print_first_to_last(list_ptr);
    Remove_itens(list_ptr, 1);


    print_first_to_last(list_ptr);
    Remove_itens(list_ptr, 0);

    print_first_to_last(list_ptr);

    Destroy_list(list_ptr);
    /**Correção do problema: estava retornando -1 porque a função de destruir não apagava totalmente os nós da lista*/
    list_ptr=NULL;
    return 0;
}

void __debug(List **l)
{
    printf("ponteiro de ponteiro: %d\n", l);
    printf("ponteiro de ponteiro (valor armazenado): %d\n", *l);
    printf("ponteiro de ponteiro (valor armazenado do valor armazenado): %d\n", (*l)->first);

}

