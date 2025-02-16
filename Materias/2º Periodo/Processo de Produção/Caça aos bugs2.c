#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGENDAMENTOS 100

typedef struct {
    int id;
    char nome[50];
    char data[11];
    char horario[6];
} Agendamento;

Agendamento agendamentos[MAX_AGENDAMENTOS];
int contador_agendamentos = 99;
int proximo_id = 100;

void cadastrarAgendamento() {
    if (contador_agendamentos >= MAX_AGENDAMENTOS) { //adicionado 
        printf("Limite de agendamentos atingido!\n");
        return;
    }
    
    Agendamento novo_agendamento;
    novo_agendamento.id = proximo_id++;
    
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", novo_agendamento.nome);
    printf("Data do Agendamento (DD/MM/AAAA): ");
    scanf("%s", novo_agendamento.data);
    printf("Horário do Agendamento (HH:MM): ");
    scanf("%s", novo_agendamento.horario);
    
    agendamentos[contador_agendamentos] = novo_agendamento;
    contador_agendamentos++; // incremento
    printf("Agendamento cadastrado com sucesso! ID: %d\n", novo_agendamento.id);
}

void consultarAgendamento() {
    int id;
    printf("Informe o ID do agendamento: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_agendamentos; i++) {
        if (agendamentos[i].id == id) {
            printf("Agendamento encontrado:\n");
            printf("Nome: %s\n", agendamentos[i].nome);
            printf("Data: %s\n", agendamentos[i].data);
            printf("Horário: %s\n", agendamentos[i].horario);
            return;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void atualizarAgendamento() {
    int id;
    printf("Informe o ID do agendamento a ser atualizado: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_agendamentos; i++) { // retirado igual
        if (agendamentos[i].id == id) {
            printf("Atualizando agendamento ID %d:\n", id);
            printf("Novo nome do Cliente: ");
            scanf(" %[^\n]", agendamentos[i].nome);
            printf("Nova data do Agendamento (DD/MM/AAAA): ");
            scanf("%s", agendamentos[i].data);
            printf("Novo horário do Agendamento (HH:MM): ");
            scanf("%s", agendamentos[i].horario);
            printf("Agendamento atualizado com sucesso!\n");
            return;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void excluirAgendamento() {
    int id;
    printf("Informe o ID do agendamento a ser excluído: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_agendamentos; i++) {
        if (agendamentos[i].id == id) {
            for (int j = i; j < contador_agendamentos-1; j++) { //adicionado -1
                agendamentos[j] = agendamentos[j + 1];
            }
            contador_agendamentos--;
            printf("Agendamento excluído com sucesso!\n");
            return;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void exibirMenu() {
    printf("\nMenu Principal:\n");
    printf("1. Cadastrar Agendamento\n");
    printf("2. Consultar Agendamento\n");
    printf("3. Atualizar Agendamento\n");
    printf("4. Excluir Agendamento\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarAgendamento();
                break;
            case 2:
                consultarAgendamento();
                break;
            case 3:
                atualizarAgendamento();
                break;
            case 4:
                excluirAgendamento();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
    return 0;
}