#include <stdio.h>
#include <string.h>

char nomes[50][100], datas[10][100], horarios[5][100];
int agendamentos=0;

void cadastrar(){
    printf("Cliente: ");
    scanf(" %[^\n]s", nomes[agendamentos]);
    printf("Data (DD/MM/AAAA): ");
    scanf(" %[^\n]s", datas[agendamentos]);
    printf("Horario (HH:MM): ");
    scanf(" %[^\n]s", horarios[agendamentos]);
    printf("\nAgendamento cadastrado com sucesso! ID: %d\n", agendamentos);
    agendamentos++;
}

void consultar(){
    int codigo;
    printf("Codigo do agendamento: ");
    scanf("%d", &codigo);
    printf("=-=-=-=-=-=-=-=-=-=-=\n");
    if(codigo > agendamentos-1 || strcmp(nomes[codigo], "excluido") == 0){
        printf("Agendamento nao encontrado.\n");
    }
    else{
        printf("Cliente: %s\n", nomes[codigo]);
        printf("Data: %s as %s\n", datas[codigo], horarios[codigo]);
    }
}

void atualizar(){
    int codigo;
    printf("Codigo do agendamento: ");
    scanf("%d", &codigo);
    printf("=-=-=-=-=-=-=-=-=-=-=\n");
    if(codigo > agendamentos-1){
        printf("Agendamento nao encontrado.\n");
    }
    else{
        printf("Cliente: ");
        scanf(" %[^\n]s", nomes[codigo]);
        printf("Data (DD/MM/AAAA): ");
        scanf(" %[^\n]s", datas[codigo]);
        printf("Horario (HH:MM): ");
        scanf(" %[^\n]s", horarios[codigo]);
        printf("\nAgendamento atualizado com sucesso!\n");
    }
}

void excluir(){
    int codigo;
    printf("Codigo do agendamento: ");
    scanf("%d", &codigo);
    printf("=-=-=-=-=-=-=-=-=-=-=\n");
    if(codigo > agendamentos-1){
        printf("Agendamento nao encontrado.\n");
    }

    else{
        strcpy(nomes[codigo], "excluido");
        strcpy(datas[codigo], "excluido");
        strcpy(horarios[codigo], "excluido");
        printf("\nAgendamento excluido com sucesso!\n");
    }

}

int main(){
    while(1){
        int menu=0;

        printf("=-=- AGENDAMENTO -=-=\n");
        printf("[1] Cadastrar\n");
        printf("[2] Consultar\n");
        printf("[3] Atualizar\n");
        printf("[4] Excluir\n\n");
        printf("Acao: ");
        scanf("%d", &menu);
        printf("=-=-=-=-=-=-=-=-=-=-=\n");

        switch (menu)
        {
            
        case 1:
            cadastrar();
            break;

        case 2:
            if (agendamentos == 0){
                printf("\n Nao ha agendamentos ativos!");
            }
            else{
                consultar();
            }
            break;

        case 3:
            if (agendamentos == 0){
                printf("\n Nao ha agendamentos ativos!");
            }
            else{
                atualizar();
            }
            break;

        case 4:
            if (agendamentos == 0){
                printf("\n Nao ha agendamentos ativos!");
            }
            else{
                excluir();
            }
            break;
        
        default:
            printf("Escolha invalida.\n");
            break;
        }
    }
}