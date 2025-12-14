#include "List_Header.h"
#include <stdio.h>
#include <locale.h>

void menu()
{
     printf("\n============================================\n");
    printf("                    MENU              \n");
    printf("============================================\n");
    printf("\n\t1 - Adicionar música no início;");
    printf("\n\t2 - Adicionar música no fim;");
    printf("\n\t3 - Exibir playlist;"); // Ordem normal
    printf("\n\t4 - Exibir histórico;"); // Ordem inversa
    printf("\n\t5 - Remover música;"); // A musica tocando no momento seria a primeira da lista
    printf("\n\t0 - Apagar e Sair;");

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int op;
    int id;

    printf("\n\t------ CRIANDO PLAYLIST ------\n");
    List* list_ptr = Create_list();
    printf("\nPlaylist criada com sucesso!\n");

    printf("\nAdicionado faixas: 101, 102, 103, 104...\n");
    Insert_last(list_ptr,101);
    Insert_last(list_ptr,102);
    Insert_last(list_ptr,103);
    Insert_last(list_ptr,104);

    printf("\nPlaylist atual:");
    print_first_to_last(list_ptr);

    do{

        menu();
        printf("\nDigite sua opção: ");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            printf("\n\tFinalizando programa. Apagando playlist...\n");
            Destroy_list(list_ptr);
            printf("\n\tPlaylist apagada!");
            break;

        case 1:
            printf("\n\t---  ADICIONAR NO INÍCIO  ---\n");
            printf("\nDigite o ID da música a ser adicionada: ");
            scanf("%d", &id);
            Insert_first(list_ptr, id);
            break;

        case 2:
            printf("\n\t---  ADICIONAR NO FIM  ---\n");
            printf("\nDigite o ID da música a ser adicionada: ");
            scanf("%d", &id);
            Insert_last(list_ptr, id);
            break;

        case 3:
            printf("\n\t---  TOCANDO AGORA  ---\n"); // Ordem normal
            print_first_to_last(list_ptr);
            break;

        case 4:
            printf("\n\t---  HISTÓRICO  ---\n"); // Ordem inversa
            print_last_to_first(list_ptr);
            break;

        case 5:
            printf("\n\t---  REMOVER MÚSICA  ---\n");
            printf("Digite o id da música a ser removida: ");
            scanf("%d", &id);
            Remove_itens(list_ptr, id);
            break;

        default:
            printf("!! ERROR: Opção inválida !!");
            printf("Tente novamente");
        }

    }while(op != 0);

    printf("\n\n\t---   SAINDO...  ---\n");

    return 0;
}

/*void __debug(List **l);
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
 /*   list_ptr=NULL;
    return 0;
}

void __debug(List **l)
{
    printf("ponteiro de ponteiro: %d\n", l);
    printf("ponteiro de ponteiro (valor armazenado): %d\n", *l);
    printf("ponteiro de ponteiro (valor armazenado do valor armazenado): %d\n", (*l)->first);

}
*/
