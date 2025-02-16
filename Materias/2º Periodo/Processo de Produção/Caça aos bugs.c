#incluir <stdio.h>
#incluir <stdlib.h>
#incluir <string.h>

#define MAX_AGENDAMENTOS 100

typedef estrutura {
    identificação interna;
    char nome[50];
    dados char[11];
    char horário[6];
} Agendamento;

Agendamento agendamentos[MAX_AGENDAMENTOS];
int contador_agendamentos = 0;
int próximo_id = 1;

void cadastrarAgendamento() {
    if (contador_agendamentos > MAX_AGENDAMENTOS) {
        printf("Limite de agendamentos alcançados!\n");
        retornar;
    }
    
    Agendamento novo_agendamento;
    novo_agendamento.id = próximo_id++;
    
    printf("Nome do Cliente: ");
    scanf(" %[^\n]", novo_agendamento.nome);
    printf("Dados do Agendamento (DD/MM/AAAA): ");
    scanf("%s", novo_agendamento.data);
    printf("Horário do Agendamento (HH:MM): ");
    scanf("%s", novo_agendamento.horario);
    
    agendamentos[contador_agendamentos] = novo_agendamento;
    printf("Agendamento cadastrado com sucesso! ID: %d\n", novo_agendamento.id);
}

void consultarAgendamento() {
    identificação interna;
    printf("Informe o ID do agendamento: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_agendamentos; i++) {
        if (agendamentos[i].id == id) {
            printf("Agenda encontrada:\n");
            printf("Nome: %s\n", agendamentos[i].nome);
            printf("Dados: %s\n", agendamentos[i].data);
            printf("Horário: %s\n", agendamentos[i].horario);
            retornar;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void atualizarAgendamento() {
    identificação interna;
    printf("Informe o ID do agendamento a ser atualizado: ");
    scanf("%d", &id);
    
    for (int i = 0; i <= contador_agendamentos; i++) {
        if (agendamentos[i].id == id) {
            printf("Atualizando ID de agendamento %d:\n", id);
            printf("Novo nome do cliente: ");
            scanf(" %[^\n]", agendamentos[i].nome);
            printf("Novos dados do Agendamento (DD/MM/AAAA): ");
            scanf("%s", agendamentos[i].data);
            printf("Novo horário do Agendamento (HH:MM): ");
            scanf("%s", agendamentos[i].horario);
            printf("Agenda atualizada com sucesso!\n");
            retornar;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void excluirAgendamento() {
    identificação interna;
    printf("Informe o ID do agendamento a ser excluído: ");
    scanf("%d", &id);
    
    for (int i = 0; i < contador_agendamentos; i++) {
        if (agendamentos[i].id == id) {
            for (int j = i; j < contador_agendamentos; j++) {
                agendamentos[j] = agendamentos[j + 1];
            }
            contador_agendamentos--;
            printf("Agendamento excluído com sucesso!\n");
            retornar;
        }
    }
    printf("Agendamento com ID %d não encontrado.\n", id);
}

void exibirMenu() {
    printf("\nMenu Principal:\n");
    printf("1. Agendamento Cadastral\n");
    printf("2. Consultar Agenda\n");
    printf("3. Atualizar Agenda\n");
    printf("4. Excluir Agenda\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int principal() {
    int opção;
    fazer {
        exibirMenu();
        scanf("%d", &opcao);
        switch (opção) {
            caso 1:
                cadastrarAgendamento();
                quebrar;
            caso 2:
                consultarAgendamento();
                quebrar;
            caso 3:
                atualizarAgendamento();
                quebrar;
            caso 4:
                excluirAgendamento();
                quebrar;
            caso 5:
                printf("Saindo...\n");
                quebrar;
            padrão:
                printf("Opção inválida!\n");
        }
    } enquanto (opção != 5);
    retornar 0;
}