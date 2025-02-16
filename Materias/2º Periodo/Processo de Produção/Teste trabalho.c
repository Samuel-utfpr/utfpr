#include <stdio.h>
#include <string.h>

char cliente[50][100];
char data[50][100];
char horario[50][100];
int agendamentos = 1;

void cadastra() {
    printf("\nNome do Cliente: ");
    scanf(" %[^\n]s", cliente[agendamentos]);
    printf("Data do Agendamento: ");
    scanf(" %[^\n]s", data[agendamentos]);
    printf("Horario do Agendamento: ");
    scanf(" %[^\n]s", horario[agendamentos]);
    printf("________________________\n");
    printf("\nAgendamento numero %d cadastrado com sucesso! :)\n", agendamentos);
    printf("________________________\n");
    agendamentos++;
}

int validacao() {
    int num_agenda;
    printf("\nDigite o numero do agendamento: ");
    scanf("%d", &num_agenda);
    printf("________________________\n");

    if (num_agenda < 1 || num_agenda >= agendamentos) {
        printf("\nAgendamento nao encontrado!\n");
        printf("________________________\n");
        return -1;
    } else if (strcmp(cliente[num_agenda], "excluido") == 0) {
        printf("\nEsse agendamento foi excluido!\n");
        printf("________________________\n");
        return -1;
    }

    return num_agenda;
}

void consulta() {
    int num_agenda = validacao();
    if (num_agenda == -1) return;  // Exit if validation failed

    printf("\nAgendamento numero: %d\n", num_agenda);
    printf("Cliente: %s\n", cliente[num_agenda]);
    printf("Data: %s\n", data[num_agenda]);
    printf("Horario: %s\n", horario[num_agenda]);
    printf("________________________\n");
}

void atualiza() {
    int num_agenda = validacao();
    if (num_agenda == -1) return;  // Exit if validation failed

    int funcao = 0;
    printf("\nO que voce deseja alterar? \n");
    printf("[1] Nome do cliente\n");
    printf("[2] Data do Agendamento\n");
    printf("[3] Horario do Agendamento\n");
    printf("[4] Atualizar tudo\n");
    printf("Informe uma opcao: ");
    scanf("%d", &funcao);

    switch (funcao) {
        case 1:
            printf("Novo nome do Cliente: ");
            scanf(" %[^\n]s", cliente[num_agenda]);
            printf("\nNome atualizado com sucesso :)\n");
            break;
        case 2:
            printf("Nova data do Agendamento: ");
            scanf(" %[^\n]s", data[num_agenda]);
            printf("\nData atualizada com sucesso :)\n");
            break;
        case 3:
            printf("Novo horario do Agendamento: ");
            scanf(" %[^\n]s", horario[num_agenda]);
            printf("\nHorario atualizado com sucesso :)\n");
            break;
        case 4:
            printf("Novo nome do Cliente: ");
            scanf(" %[^\n]s", cliente[num_agenda]);
            printf("Nova data do Agendamento: ");
            scanf(" %[^\n]s", data[num_agenda]);
            printf("Novo horario do Agendamento: ");
            scanf(" %[^\n]s", horario[num_agenda]);
            printf("Dados atualizados com sucesso :)\n");
            break;
        default:
            printf("\nEscolha invalida.\n");
            break;
    }
    printf("________________________\n");
}

void exclui() {
    int num_agenda = validacao();
    if (num_agenda == -1) return;  // Exit if validation failed

    strcpy(cliente[num_agenda], "excluido");
    strcpy(data[num_agenda], "excluido");
    strcpy(horario[num_agenda], "excluido");
    printf("\nAgendamento excluido com sucesso!\n");
    printf("________________________\n");
}

int main() {
    while (1) {
        int menu = 0;
        printf("\n____- AGENDAMENTO -____\n");
        printf("\n[1] Cadastrar\n");
        printf("[2] Consultar\n");
        printf("[3] Atualizar\n");
        printf("[4] Excluir\n\n");
        printf("Funcao: ");
        scanf("%d", &menu);
        printf("________________________\n");

        switch (menu) {
            case 1:
                cadastra();
                break;
            case 2:
                if (agendamentos == 1) {
                    printf("\nNao ha agendamentos ativos!\n");
                    printf("________________________\n");
                } else {
                    consulta();
                }
                break;
            case 3:
                if (agendamentos == 1) {
                    printf("\nNao ha agendamentos ativos!\n");
                    printf("________________________\n");
                } else {
                    atualiza();
                }
                break;
            case 4:
                if (agendamentos == 1) {
                    printf("\nNao ha agendamentos ativos!\n");
                    printf("________________________\n");
                } else {
                    exclui();
                }
                break;
            default:
                printf("\nEscolha invalida.\n");
                printf("________________________\n");
                break;
        }
    }
}
