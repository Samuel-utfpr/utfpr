#include <stdio.h>
#include <string.h>

char cliente[50][100];
char data[10][100];
char horario[5][100];
int agendamentos=1;

void cadastra(){
    printf("\nNome do Cliente: ");
    scanf(" %[^\n]s", cliente[agendamentos]);
    printf("Data do Agendamento: ");
    scanf(" %[^\n]s", data[agendamentos]);
    printf("Horario do Agendamento: ");
    scanf(" %[^\n]s", horario[agendamentos]);
    printf("________________________\n");
    printf("\nAgedamento numero %d cadastrado com sucesso! :) \n", agendamentos);
    printf("________________________\n");
    agendamentos++;
}

void consulta(){
    int num_agenda;
    printf("\nDigite o numero  do agendamento: ");
    scanf("%d", &num_agenda);
    printf("________________________\n");
    if(num_agenda > agendamentos-1){
        printf("\nAgendamento nao encontrado!\n");
        printf("________________________\n");
    }else if(strcmp(cliente[num_agenda], "excluido") == 0){
        printf("\nAgendamento Excluido!\n");
        printf("________________________\n");
    }else{
        printf("\nAgendamento numero: %d\n", num_agenda);
        printf("Cliente: %s\n", cliente[num_agenda]);
        printf("Data: %s\n", data[num_agenda]);
        printf("Horario: %s\n", horario[num_agenda]);
        printf("________________________\n");
    }
}

void atualiza(){
    int num_agenda, funcao=0; 
    printf("\nDigite o numero do agendamento: ");
    scanf("%d", &num_agenda);
    printf("________________________\n");
    if(num_agenda > agendamentos-1){
        printf("\nAgendamento nao encontrado!\n");
        printf("________________________\n");
    }else if(strcmp(cliente[num_agenda], "excluido") == 0){
        printf("\nAgendamento Excluido!\n");
        printf("________________________\n");
    }else{
        printf("\nO que voce deseja alterar? \n");
        printf("\n");
        printf("[1] Nome do cliente \n");
        printf("[2] Data do Agendamento \n");
        printf("[3] Horario do Agendamento \n");
        printf("[4] Atualizar tudo \n");
        printf("\n");
        printf("Informe uma opcao: ");
        scanf("%d", &funcao);
        switch (funcao){
            case 1:
                printf("________________________\n");
                printf("\nNovo nome do Cliente: ");
                scanf(" %[^\n]s", cliente[num_agenda]);
                printf("\nNome atualizado com sucesso :)\n");
                printf("________________________\n");
                break;
            case 2:
                printf("________________________\n");
                printf("\nNova data do Agendamento: ");
                scanf(" %[^\n]s", data[num_agenda]);
                printf("\nData atualizada com sucesso :)\n");
                printf("________________________\n");
                break;
            case 3:
                printf("________________________\n");
                printf("\nNovo horario do Agendamento: ");
                scanf(" %[^\n]s", horario[num_agenda]);
                printf("\nHorario atualizado com sucesso :)\n");
                printf("________________________\n");
                break;
            case 4:
                printf("________________________\n");
                printf("\nNovo nome do Cliente: ");
                scanf(" %[^\n]s", cliente[num_agenda]);
                printf("Nova data do Agendamento: ");
                scanf(" %[^\n]s", data[num_agenda]);
                printf("Novo horario do Agendamento: ");
                scanf(" %[^\n]s", horario[agendamentos]);
                printf("\n");
                printf("Dados atualizados com sucesso :)\n");
                printf("________________________\n");
                break;
            default:
                printf("\n");
                printf("Escolha invalida.\n");
                printf("________________________\n");
                break;
        }
    }
}

void exclui(){
    int num_agenda;
    printf("\nDigite o numero  do agendamento: ");
    scanf("%d", &num_agenda);
    printf("________________________\n");
    if(num_agenda > agendamentos-1){
        printf("\nAgendamento nao encontrado!\n");
        printf("________________________\n");
    }else if(strcmp(cliente[num_agenda], "excluido") == 0){
        printf("\nAgendamento Excluido!\n");
        printf("________________________\n");
    }else{
        strcpy(cliente[num_agenda], "excluido");
        strcpy(data[num_agenda], "excluido");
        strcpy(horario[num_agenda], "excluido");
        printf("\nAgendamento excluido com sucesso!\n");
        printf("________________________\n");
    }
}

int main(){
    while(1){
        int menu=0;

        printf("\n____- AGENDAMENTO -____\n");
        printf("\n[1] Cadastrar\n");
        printf("[2] Consultar\n");
        printf("[3] Atualizar\n");
        printf("[4] Excluir\n\n");
        printf("Funcao: ");
        scanf("%d", &menu);
        printf("________________________\n");

        switch (menu)
        {
            
        case 1:
            cadastra();
            break;

        case 2:
            if (agendamentos == 1){
                printf("\nNao ha agendamentos ativos!");
                printf("\n");
                printf("________________________\n");
            }
            else{
                consulta();
            }
            break;

        case 3:
            if (agendamentos == 1){
                printf("\nNao ha agendamentos ativos!");
                printf("\n");
                printf("________________________\n");
            }
            else{
                atualiza();
            }
            break;

        case 4:
            if (agendamentos == 1){
                printf("\nNao ha agendamentos ativos!");
                printf("\n");
                printf("________________________\n");
            }
            else{
                exclui();
            }
            break;
        
        default:
            printf("\nEscolha invalida.");
            printf("\n");
            printf("________________________\n");
            break;
        }
    }
}