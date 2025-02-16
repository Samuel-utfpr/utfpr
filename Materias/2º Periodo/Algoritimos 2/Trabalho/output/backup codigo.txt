#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PALAVRAS 50
#define MIN_PALAVRAS 10  // Mínimo de palavras necessárias para iniciar o jogo
#define MIN_LETRAS 20
#define MAX_TENTA 6

void menu();
void novoJogo();
void cadastrarPalavra();
void atualizarPalavra();
void apagarPalavra();
void mostrarPalavras();
void desenharForca();
void jogar(char *palavra);
void menuPosJogo();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;
    do {
        printf("\nMenu Inicial:\n");
        printf("1. Novo Jogo\n");
        printf("2. Cadastrar Palavra\n");
        printf("3. Atualizar Palavra\n");
        printf("4. Apagar Palavra\n");
        printf("5. Mostrar Palavras\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
        }
        else{
            getchar();

            switch (opcao) {
                case 1: novoJogo(); break;
                case 2: cadastrarPalavra(); break;
                case 3: atualizarPalavra(); break;
                case 4: apagarPalavra(); break;
                case 5: mostrarPalavras(); break;
                case 6: printf("Saindo...\n"); break;
                default: printf("Opcao invalida!\n");
            }
        }
    } while (opcao != 6);
}

void novoJogo() {
    FILE *file = fopen("palavras.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    char palavras[MAX_PALAVRAS][MIN_LETRAS];
    int cont = 0;
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MIN_LETRAS, file)) {
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); // <--- Adicione este loop
        }
        cont++;
    }
    fclose(file);
    
    if (cont < MIN_PALAVRAS) {  // Verifica se há pelo menos 10 palavras
        printf("Voce precisa cadastrar pelo menos %d palavras para iniciar o jogo!\n", MIN_PALAVRAS);
        printf("Palavras cadastradas atualmente: %d\n", cont);
        return;
    }
    
    srand(time(NULL));
    int index = rand() % cont;
    jogar(palavras[index]);
}

void desenharForca(int tentativas) {
    switch(tentativas) {
        case 5:
            printf("          ____\n");
            printf("         /. . \\\n");
            printf("        |  L   |\n");
            printf("        |  __  |\n");
            printf("         \\____/\n");
            break;
        case 4:
            printf("          ____\n");
            printf("         /. . \\\n");
            printf("        |  L   |\n");
            printf("        |  __  |\n");
            printf("         \\____/\n");
            printf("          _||_\n");
            printf("         /    \\\n");
            printf("     ___/      \\___\n");
            printf("    -___        ___-\n");
            printf("        |      |\n");
            printf("        |  __  |\n");
            break;
        case 3:
            printf("          ____\n");
            printf("         /. . \\\n");
            printf("        |  L   |\n");
            printf("        |  __  |\n");
            printf("         \\____/\n");
            printf("          _||_\n");
            printf("         /    \\\n");
            printf("     ___/      \\___\n");
            printf("    -___        ___-\n");
            printf("        |      |\n");
            printf("        |  __  |\n");
            printf("         ||  ||\n");
            printf("         ||  ||\n");
            break;
        case 2:
            printf("          ____\n");
            printf("         /. . \\\n");
            printf("        |  L   |\n");
            printf("        |  __  |\n");
            printf("         \\____/\n");
            printf("          _||_\n");
            printf("         /    \\\n");
            printf("     ___/      \\___\n");
            printf("    -___        ___-\n");
            printf("        |      |\n");
            printf("        |  __  |\n");
            printf("         ||  ||\n");
            printf("         ||  ||\n");
            printf("       __||  ||__\n");
            printf("      |___|  |___|\n");
            break;
        case 1:
            printf("          ____\n");
            printf("         /. . \\\n");
            printf("        |  L   |\n");
            printf("        |  __  |\n");
            printf("         \\____/\n");
            printf("    -------||--------\n");
            printf("         /    \\\n");
            printf("     ___/      \\___\n");
            printf("    -___        ___-\n");
            printf("        |      |\n");
            printf("        |  __  |\n");
            printf("         ||  ||\n");
            printf("         ||  ||\n");
            printf("       __||  ||__\n");
            printf("      |___|  |___|\n");
            break;

        default:
            // Não mostra nada se tiver 6 tentativas
            break;
    }
}

void jogar(char *palavra) {
    int len = strlen(palavra);
    char display[MIN_LETRAS];
    char usadas[26] = "";
    int tentativas = MAX_TENTA;
    int acertos = 0;
    int pontuacao = 0;

    for (int i = 0; i < len; i++) {
        display[i] = '_';
    }
    display[len] = '\0';

    while (tentativas > 0 && acertos < len) {
        system("cls||clear");
        printf("\n");
        desenharForca(tentativas); // <----- ADICIONE ESTA LINHA
        printf("\nPalavra: %s\n", display);
        printf("Letras usadas: %s\n", usadas);
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Pontuacao: %d\n", pontuacao);

        // Resto do código permanece igual...
        printf("Digite uma letra: ");
        char tentativa;
        scanf(" %c", &tentativa);
        getchar();
        tentativa = tolower(tentativa); // <--- Adicione esta linha

        if (strchr(usadas, tentativa)) {
            printf("Voce ja usou essa letra!\n");
        } 
        else { // Só processa se a letra for nova
            strncat(usadas, &tentativa, 1);
            int encontrou = 0;
            for (int i = 0; i < len; i++) {
                if (tolower(palavra[i]) == tentativa) { // <--- Modifique esta linha
                    display[i] = tentativa;
                    encontrou = 1;
                    acertos++;
                    pontuacao += 10;
                }
            }
            if (!encontrou) {
                tentativas--;
                pontuacao -= 5;
                printf("Letra errada! Voce perdeu 5 pontos.\n");
            }
        }
    }

    if (acertos == len) {
        pontuacao += 50;  // Bônus por acertar a palavra completa
        printf("\nParabens! Voce acertou a palavra: %s\n", palavra);
    } else {
        printf("          ____\n");
        printf("         /_ _ \\\n");
        printf("        |  L   |\n");
        printf("        |  -¬ |\n");
        printf("         \\____/\n");
        printf("    -------||--------\n");
        printf("         /    \\\n");
        printf("     ___/      \\___\n");
        printf("    -___        ___-\n");
        printf("        |      |\n");
        printf("        |  __  |\n");
        printf("         ||  ||\n");
        printf("         ||  ||\n");
        printf("       __||  ||__\n");
        printf("      |___|  |___|\n");
        printf("\nFim de jogo! A palavra era: %s\n", palavra);
    }
    printf("Pontuacao final: %d\n", pontuacao);  // Mostrar a pontuação final

    // Exibir o menu pós-jogo
    menuPosJogo();
}

void menuPosJogo() {
    int opcao;
    do {
        printf("\nMenu Pos-Jogo:\n");
        printf("1. Novo Jogo\n");
        printf("2. Menu Inicial\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
        }
        else{
        getchar();

            switch (opcao) {
                case 1: novoJogo(); break;
                case 2: menu(); break;
                case 3: printf("Saindo...\n"); exit(0);
                default: printf("Opcao invalida!\n");
            
            }
        }
    } while (opcao < 1 || opcao > 3);
}

void atualizarPalavra() {

    FILE *file = fopen("palavras.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char palavras[MAX_PALAVRAS][MIN_LETRAS];
    int cont = 0;

    // Ler todas as palavras do arquivo
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MIN_LETRAS, file)) {
        cont++;
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); // <--- Adicione este loop
        }
    }
    fclose(file);

    if (cont == 0) {
        printf("Nenhuma palavra cadastrada!\n");
        return;
    }

    // Mostrar as palavras cadastradas
    printf("\n");
    printf("Palavras cadastradas:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d. %s\n", i + 1, palavras[i]);
    }

    // Solicitar ao usuário qual palavra deseja excluir
    int escolha;
    printf("\n");
    printf("Escolha o numero da palavra que deseja atualizar: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > cont) {
        printf("Escolha invalida!\n");
        return;
    }
    getchar(); // Limpar o buffer do teclado


    char nova_palavra[MIN_LETRAS];
    printf("\n");
    printf("Digite a nova palavra: ");
    fgets(nova_palavra, MIN_LETRAS, stdin);
    nova_palavra[strcspn(nova_palavra, "\n")] = 0;
    for (int i = 0; nova_palavra[i]; i++) {
        nova_palavra[i] = tolower(nova_palavra[i]); // <--- Adicione este loop
    }
    file = fopen("palavras.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Verificar se a palavra já existe
    char palavra_existente[MIN_LETRAS];
    int palavra_ja_existe = 0;
    while (fread(palavra_existente, sizeof(char), MIN_LETRAS, file)) {
        if (strcmp(palavra_existente, nova_palavra) == 0) {
            palavra_ja_existe = 1;
            break;
        }
    }

    if (palavra_ja_existe) {
        printf("Essa palavra ja foi cadastrada!\n");
        fclose(file);
        return;
    }
    fclose(file);

    strcpy(palavras[escolha - 1], nova_palavra);

    // Reescrever o arquivo com as palavras restantes
    file = fopen("palavras.dat", "wb");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fwrite(palavras[i], sizeof(char), MIN_LETRAS, file);
    }
    fclose(file);

    printf("Palavra atualizada com sucesso!\n");
}

void mostrarPalavras() {
    FILE *file = fopen("palavras.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    char palavra[MIN_LETRAS];
    printf("Palavras cadastradas:\n");
    while (fread(palavra, sizeof(char), MIN_LETRAS, file)) {
        printf("%s\n", palavra);
    }
    fclose(file);
}

void apagarPalavra() {
    FILE *file = fopen("palavras.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char palavras[MAX_PALAVRAS][MIN_LETRAS];
    int cont = 0;

    // Ler todas as palavras do arquivo
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MIN_LETRAS, file)) {
        cont++;
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); // <--- Adicione este loop
        }
    }
    fclose(file);

    if (cont == 0) {
        printf("Nenhuma palavra cadastrada!\n");
        return;
    }

    // Mostrar as palavras cadastradas
    printf("Palavras cadastradas:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d. %s\n", i + 1, palavras[i]);
    }

    // Solicitar ao usuário qual palavra deseja excluir
    int escolha;
    printf("Escolha o numero da palavra que deseja excluir: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > cont) {
        printf("Escolha invalida!\n");
        return;
    }
    getchar(); // Limpar o buffer do teclado

    // Remover a palavra escolhida
    for (int i = escolha - 1; i < cont - 1; i++) {
        strcpy(palavras[i], palavras[i + 1]);
    }
    cont--;

    // Reescrever o arquivo com as palavras restantes
    file = fopen("palavras.dat", "wb");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fwrite(palavras[i], sizeof(char), MIN_LETRAS, file);
    }
    fclose(file);

    printf("Palavra excluida com sucesso!\n");
}

void cadastrarPalavra() {

    FILE *file = fopen("palavras.dat", "a+b");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nova_palavra[MIN_LETRAS];
    printf("Digite a nova palavra: ");
    fgets(nova_palavra, MIN_LETRAS, stdin);
    nova_palavra[strcspn(nova_palavra, "\n")] = 0;  // Remove o '\n' do final

    for (int i = 0; nova_palavra[i]; i++) {
        nova_palavra[i] = tolower(nova_palavra[i]); // <--- Adicione este loop
    }

    if (strlen(nova_palavra) < 5) {
        printf("A palavra deve ter no minimo 5 letras!\n");
        fclose(file);
        return;
    }

    // Verificar se a palavra já existe
    char palavra_existente[MIN_LETRAS];
    int palavra_ja_existe = 0;
    while (fread(palavra_existente, sizeof(char), MIN_LETRAS, file)) {
        if (strcmp(palavra_existente, nova_palavra) == 0) {
            palavra_ja_existe = 1;
            break;
        }
    }

    if (palavra_ja_existe) {
        printf("Essa palavra ja foi cadastrada!\n");
        fclose(file);
        return;
    }

    // Se a palavra não existe, cadastrá-la
    fseek(file, 0, SEEK_END);  // Posiciona o cursor no final do arquivo
    fwrite(nova_palavra, sizeof(char), MIN_LETRAS, file);
    printf("Palavra cadastrada com sucesso!\n");
    fclose(file);
}