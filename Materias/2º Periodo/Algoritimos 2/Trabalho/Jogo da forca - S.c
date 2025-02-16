#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TAM_PALAVRA 50
#define MAX_PALAVRAS 100

// Estrutura para representar uma palavra (slide 6 - Estruturas)
typedef struct {
    char palavra[TAM_PALAVRA];
    int tamanho;
} Palavra;

// Variáveis globais (slide 2 - Funções)
Palavra *lista_palavras = NULL;
int total_palavras = 0;
int pontuacao = 0;

// Protótipos de funções (slide 16 - Funções)
void carregar_arquivo();
void salvar_arquivo();
void cadastrar_palavra();
void listar_palavras();
void menu_principal();
void iniciar_jogo();
void exibir_forca(const char *letras_descobertas, const char *letras_usadas, int chances);

// Função recursiva para menu (slide 30 - Recursão)
void menu_pos_jogo(int recursao) {
    int opcao;
    printf("\n1. Novo Jogo\n2. Menu Principal\n3. Sair\nOpcao: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1: iniciar_jogo(); break;
        case 2: menu_principal(); break;
        case 3: exit(0);
        default:
            printf("Opcao invalida!\n");
            if(recursao < 3) menu_pos_jogo(recursao + 1);
            else exit(1);
    }
}

// Função para alocação dinâmica de palavras (slide 40 - Alocação Dinâmica)
void carregar_arquivo() {
    FILE *arquivo = fopen("palavras.bin", "rb");
    if(!arquivo) return;

    fseek(arquivo, 0, SEEK_END);
    total_palavras = ftell(arquivo) / sizeof(Palavra);
    rewind(arquivo);

    lista_palavras = (Palavra*)malloc(total_palavras * sizeof(Palavra));
    fread(lista_palavras, sizeof(Palavra), total_palavras, arquivo);
    fclose(arquivo);
}

void salvar_arquivo() {
    FILE *arquivo = fopen("palavras.bin", "wb");
    if(!arquivo) return;

    fwrite(lista_palavras, sizeof(Palavra), total_palavras, arquivo);
    fclose(arquivo);
}

// Função com passagem de parâmetros (slide 25 - Ponteiros)
void cadastrar_palavra() {
    if(total_palavras >= MAX_PALAVRAS) {
        printf("Limite de palavras atingido!\n");
        return;
    }

    Palavra nova;
    printf("Digite a palavra (min 5 letras): ");
    scanf("%s", nova.palavra);
    nova.tamanho = strlen(nova.palavra);

    if(nova.tamanho < 5) {
        printf("Palavra muito curta!\n");
        return;
    }

    // Verifica duplicatas usando ponteiros (slide 28 - Ponteiros e Vetores)
    for(int i = 0; i < total_palavras; i++) {
        if(strcmp(lista_palavras[i].palavra, nova.palavra) == 0) {
            printf("Palavra ja existe!\n");
            return;
        }
    }

    lista_palavras = realloc(lista_palavras, (total_palavras + 1) * sizeof(Palavra));
    lista_palavras[total_palavras++] = nova;
    salvar_arquivo();
    printf("Palavra cadastrada!\n");
}

// Função com vetor como parâmetro (slide 14 - Ponteiros e Vetores)
void listar_palavras() {
    printf("\n=== PALAVRAS CADASTRADAS ===\n");
    for(int i = 0; i < total_palavras; i++) {
        printf("%d. %s (%d letras)\n", i+1, lista_palavras[i].palavra, lista_palavras[i].tamanho);
    }
}

// Função principal do jogo usando vários conceitos
void iniciar_jogo() {
    if(total_palavras < 10) {
        printf("Cadastre pelo menos 10 palavras primeiro!\n");
        return;
    }

    srand(time(NULL));
    int indice = rand() % total_palavras;
    char *palavra = lista_palavras[indice].palavra;
    int tamanho = lista_palavras[indice].tamanho;

    char letras_descobertas[TAM_PALAVRA] = {0};
    char letras_usadas[26] = {0};
    int chances = 6;
    int letras_restantes = tamanho;

    // Inicializa letras descobertas
    memset(letras_descobertas, '_', tamanho);
    letras_descobertas[tamanho] = '\0';

    while(chances > 0 && letras_restantes > 0) {
        exibir_forca(letras_descobertas, letras_usadas, chances);
        
        char letra;
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);

        if(!isalpha(letra)) {
            printf("Caractere invalido!\n");
            continue;
        }

        // Verifica se a letra já foi usada
        if(strchr(letras_usadas, letra)) {
            printf("Letra ja utilizada!\n");
            continue;
        }

        letras_usadas[strlen(letras_usadas)] = letra;
        int acertou = 0;

        // Verifica ocorrências da letra
        for(int i = 0; i < tamanho; i++) {
            if(tolower(palavra[i]) == letra) {
                letras_descobertas[i] = palavra[i];
                letras_restantes--;
                acertou = 1;
                pontuacao += 10;
            }
        }

        if(!acertou) {
            chances--;
            pontuacao -= 5;
        }
    }

    exibir_forca(letras_descobertas, letras_usadas, chances);
    printf("\nPalavra: %s\n", palavra);
    printf("Pontuacao final: %d\n", pontuacao);
    menu_pos_jogo(0);
}

void exibir_forca(const char *letras_descobertas, const char *letras_usadas, int chances) {
    system("cls||clear");
    printf("\n=== JOGO DA FORCA ===\n");
    printf("Palavra: %s\n", letras_descobertas);
    printf("Letras usadas: %s\n", letras_usadas);
    printf("Chances restantes: %d\n", chances);
    printf("Pontuacao: %d\n", pontuacao);
}

void menu_principal() {
    carregar_arquivo();
    int opcao;
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Novo Jogo\n2. Cadastrar Palavra\n3. Listar Palavras\n4. Sair\nOpcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: iniciar_jogo(); break;
            case 2: cadastrar_palavra(); break;
            case 3: listar_palavras(); break;
            case 4: exit(0);
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 4);
}

int main() {
    lista_palavras = malloc(MAX_PALAVRAS * sizeof(Palavra));
    menu_principal();
    free(lista_palavras);
    return 0;
}