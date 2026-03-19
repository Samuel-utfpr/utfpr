#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct pessoa {
    char nome[50];
    unsigned long long int cpf;
} Pessoa;

Pessoa tabela[TAM];

void inicializaTabela(){
    for (int i = 0; i < TAM; i++)
        tabela[i].cpf = 0;
}

int hash(Pessoa p);
void inserir(Pessoa p);
Pessoa* buscar(Pessoa p);
void mostrar_tabela();

int hash(Pessoa p){
    return p.cpf % TAM;
}

void inserir(Pessoa p){
    int id = hash(p);
    int tentativas = 0;
    while(tabela[id].cpf != 0 && tentativas < TAM){
        id = (id + 1) % TAM;
        tentativas++;
    }
    if (tentativas < TAM){
        tabela[id] = p;
    } else {
        printf("Tabela cheia, nao foi possivel inserir a pessoa!\n");
    }
}

Pessoa* buscar(Pessoa p){
    int id = hash(p);
    int inicio = id;
    while(tabela[id].cpf != 0){
        if(tabela[id].cpf == p.cpf) return &tabela[id];
        id = (id + 1) % TAM;
        if(id == inicio) break; 
    }
    return NULL; 
}

void mostrar_tabela(){
    for(int i = 0; i < TAM; i++){
        if(tabela[i].cpf != 0){
            printf("Posicao %d: Nome: %s, CPF: %011llu\n", i, tabela[i].nome, tabela[i].cpf);
        } else {
            printf("Posicao %d: Vazia\n", i);
        }
    }
}

int main(){
    inicializaTabela();
    while(1){
        int opcao;
        printf("1. Inserir Pessoa\n");
        printf("2. Buscar Pessoa\n");
        printf("3. Mostrar Tabela\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: {
                Pessoa p;
                printf("Informe o nome: ");
                scanf(" %[^\n]", p.nome);
                printf("Informe o CPF (somente numeros): ");
                scanf("%llu", &p.cpf);
                inserir(p);
                printf("Pessoa inserida com sucesso!\n");
                break;
            }
            case 2: {
                Pessoa p;
                printf("Informe o CPF da pessoa a buscar: ");
                scanf("%llu", &p.cpf);
                Pessoa* resultado = buscar(p);
                if(resultado){
                    printf("Pessoa encontrada: Nome: %s, CPF: %011llu\n", resultado->nome, resultado->cpf);
                } else {
                    printf("Pessoa nao encontrada!\n");
                }
                break;
            }
            case 3: {
                mostrar_tabela();
                break;
            }
            case 4: {
                printf("Saindo...\n");
                return 0;
            }
            default:
                printf("Opcao invalida!\n");
        }
    }
}