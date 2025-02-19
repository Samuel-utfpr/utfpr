#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PALAVRAS 50
#define MIN_PALAVRAS 10  
#define MAX_LETRAS 20
#define MAX_TENTA 6

void menu();
void novo_jogo();
void cadastrar_palavra();
void atualizar_palavra();
void apagar_palavra();
void mostrar_palavras();
void desenhar_forca();
void jogar(char *palavra);
void menu_pos_jogo();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;
    do {
        printf(" \n");
        printf("\n===== Menu Inicial: =====\n");
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
                case 1: novo_jogo(); break;
                case 2: cadastrar_palavra(); break;
                case 3: atualizar_palavra(); break;
                case 4: apagar_palavra(); break;
                case 5: mostrar_palavras(); break;
                case 6: printf("Saindo...\n"); exit(0);
                default: printf("Opcao invalida!\n");
            }
        }
    } while (opcao != 6);
}

void novo_jogo() {
    FILE *file = fopen("palavras.bin", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Dica: Tente Cadastrar uma nova palvra!\n");
        return;
    }
    
    
    // Carrega palavras para uma matriz
    char palavras[MAX_PALAVRAS][MAX_LETRAS];
    int cont = 0;
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MAX_LETRAS, file)) {
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); 
            
        }
        cont++;
    }
    fclose(file);
    
    if (cont < MIN_PALAVRAS) {  // Verifica se há pelo menos 10 palavras
        printf(" \n");
        printf("Voce precisa cadastrar pelo menos %d palavras para iniciar o jogo!\n", MIN_PALAVRAS);
        printf("Palavras cadastradas atualmente: %d\n", cont);
        return;
    }
    
    // Sortea a palavra
    srand(time(NULL));
    int index = rand() % cont;
    jogar(palavras[index]);
}

void desenhar_forca(int tentativas) {
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
        case 0: 
            printf("          ____\n");
            printf("         /x x \\\n");
            printf("        |  L   |\n");
            printf("        |  -¬  |\n");
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
            break;
    }
}

void jogar(char *palavra) {
    int tam_pala = strlen(palavra);
    char display[MAX_LETRAS];
    char usadas[26] = "";
    int tentativas = MAX_TENTA;
    int acertos = 0;
    int pontuacao = 0;

    // Display recebe "_" na mesma quantidade de letras sorteadas
    for (int i = 0; i < tam_pala; i++) {
        display[i] = '_';
    }
    display[tam_pala] = '\0';

    //Processamento do jogo
    while (tentativas > 0 && acertos < tam_pala) {
        printf(" \n");
        desenhar_forca(tentativas); 
        printf("\nPalavra: %s\n", display);
        printf("Letras usadas: %s\n", usadas);
        printf("Tentativas restantes: %d\n", tentativas);
        printf("Pontuacao: %d\n", pontuacao);
        printf("Digite uma letra: ");
        char tentativa;
        scanf(" %c", &tentativa);
        while(getchar() != '\n');  // Limpa o buffer
        tentativa = tolower(tentativa);

        if (strchr(usadas, tentativa)) {
            printf("Voce ja usou essa letra!\n");
        } 
        else { // Só processa se a letra for nova
            strncat(usadas, &tentativa, 1);
            int encontrou = 0;
            for (int i = 0; i < tam_pala; i++) {
                if (tolower(palavra[i]) == tentativa) {
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

    //Encerramento do jogo
    if (acertos == tam_pala) {
        pontuacao += 50;  // Bônus por acertar a palavra completa
        printf(" \n");
        printf("\nParabens! Voce acertou a palavra: %s\n", palavra);
    } else {
        desenhar_forca(0); 
        printf("\nFim de jogo! A palavra era: %s\n", palavra);
    }
    printf("\n");
    printf("Pontuacao final: %d\n", pontuacao);  // Mostrar a pontuação final

    // Exibir o menu pós-jogo
    menu_pos_jogo();
}

void menu_pos_jogo() {
    int opcao;
    do {
        printf(" \n");
        printf("\n===== Menu Pos-Jogo: =====\n");
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
                case 1: novo_jogo(); break;
                case 2: menu(); break;
                case 3: printf("Saindo...\n"); exit(0);
                default: printf("Opcao invalida!\n");
            
            }
        }
    } while (opcao < 1 || opcao > 3);
}

void atualizar_palavra() {

    FILE *file = fopen("palavras.bin", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Dica: Tente Cadastrar uma nova palvra!\n");
        return;
    }

    char palavras[MAX_PALAVRAS][MAX_LETRAS];
    int cont = 0;

    // Ler todas as palavras do arquivo
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MAX_LETRAS, file)) {
        cont++;
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); 
        }
    }
    fclose(file);

    //Valida se possui palavras cadastradas
    if (cont == 0) {
        printf(" \n");
        printf("Nenhuma palavra cadastrada!\n");
        return;
    }

    // Mostra as palavras cadastradas
    printf("\n");
    printf("Palavras cadastradas:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d. %s\n", i + 1, palavras[i]);
    }

    // Solicita ao usuário qual palavra deseja Atualizar
    int escolha;
    printf("\n");
    printf("Escolha o numero da palavra que deseja atualizar: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > cont) {
        printf("Escolha invalida!\n");
        return;
    }
    getchar();

    //Solicita para o usuario a nova palavra
    char nova_palavra[MAX_LETRAS];
    printf("\n");
    printf("Digite a nova palavra: ");
    fgets(nova_palavra, MAX_LETRAS, stdin);
    nova_palavra[strcspn(nova_palavra, "\n")] = 0;
    for (int i = 0; nova_palavra[i]; i++) {
        nova_palavra[i] = tolower(nova_palavra[i]); 
    }
    for(int i=0; nova_palavra[i] != '\0'; i++){
        if(!isalpha(nova_palavra[i])){
            printf("A palavra deve conter apenas letras de A-Z\n");
            fclose(file);
            return;
        }

    }

    file = fopen("palavras.bin", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Dica: Tente Cadastrar uma nova palvra!\n");
        return;
    }

    // Verifica se a palavra já existe
    char palavra_existente[MAX_LETRAS];
    int palavra_ja_existe = 0;
    while (fread(palavra_existente, sizeof(char), MAX_LETRAS, file)) {
        if (strcmp(palavra_existente, nova_palavra) == 0) {
            palavra_ja_existe = 1;
            break;
        }
    }

    if (palavra_ja_existe) {
        printf(" \n");
        printf("Essa palavra ja foi cadastrada!\n");
        fclose(file);
        return;
    }
    fclose(file);

    strcpy(palavras[escolha - 1], nova_palavra);

    // Reescreve o arquivo com a nova palavra
    file = fopen("palavras.bin", "wb");
    if (!file) {
        printf(" \n");
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fwrite(palavras[i], sizeof(char), MAX_LETRAS, file);
    }
    fclose(file);

    printf("\n");
    printf("Palavra atualizada com sucesso!\n");
}

void mostrar_palavras() {
    FILE *file = fopen("palavras.bin", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Dica: Tente Cadastrar uma nova palvra!\n");
        return;
    }
    
    char palavra[MAX_LETRAS];
    printf("\n");
    printf("Palavras cadastradas:\n");
    while (fread(palavra, sizeof(char), MAX_LETRAS, file)) {
        printf("%s\n", palavra);
    }
    fclose(file);
}

void apagar_palavra() {
    FILE *file = fopen("palavras.bin", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        printf("Dica: Tente Cadastrar uma nova palvra!\n");
        return;
    }

    char palavras[MAX_PALAVRAS][MAX_LETRAS];
    int cont = 0;

    // Ler todas as palavras do arquivo
    while (cont < MAX_PALAVRAS && fread(palavras[cont], sizeof(char), MAX_LETRAS, file)) {
        cont++;
        for (int i = 0; palavras[cont][i]; i++) {
            palavras[cont][i] = tolower(palavras[cont][i]); 
        }
    }
    fclose(file);

    if (cont == 0) {
        printf("Nenhuma palavra cadastrada!\n");
        return;
    }

    // Mostra as palavras cadastradas
    printf("Palavras cadastradas:\n");
    for (int i = 0; i < cont; i++) {
        printf("%d. %s\n", i + 1, palavras[i]);
    }

    // Solicitar ao usuário qual palavra deseja excluir
    int escolha;
    printf("\n");
    printf("Escolha o numero da palavra que deseja excluir: ");
    if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > cont) {
        printf(" \n");
        printf("Escolha invalida!\n");
        return;
    }
    getchar(); 

    // Remove a palavra escolhida
    for (int i = escolha - 1; i < cont - 1; i++) {
        strcpy(palavras[i], palavras[i + 1]);
    }
    cont--;

    // Reescreve o arquivo com as palavras restantes
    file = fopen("palavras.bin", "wb");
    if (!file) {
        printf(" \n");
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < cont; i++) {
        fwrite(palavras[i], sizeof(char), MAX_LETRAS, file);
    }
    fclose(file);
    printf(" \n");
    printf("Palavra excluida com sucesso!\n");
}

void cadastrar_palavra() {

    FILE *file = fopen("palavras.bin", "a+b");
    if (!file) {
        printf(" \n");
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nova_palavra[MAX_LETRAS];
    printf(" \n");
    printf("Digite a nova palavra: ");
    fgets(nova_palavra, MAX_LETRAS, stdin);
    nova_palavra[strcspn(nova_palavra, "\n")] = 0;  // Remove o '\n' do final
    
    // Valida se o usuario não informou numeros junto
    for(int i=0; nova_palavra[i] != '\0'; i++){
        if(!isalpha(nova_palavra[i])){
            printf("A palavra deve conter apenas letras de A-Z\n");
            fclose(file);
            return;
        }
    }

    // Normaliza palvras
    for (int i = 0; nova_palavra[i]; i++) {
        nova_palavra[i] = tolower(nova_palavra[i]); 
    }

    if (strlen(nova_palavra) < 5) {
        printf(" \n");
        printf("A palavra deve ter no minimo 5 letras!\n");
        fclose(file);
        return;
    }

    // Verificar se a palavra já existe
    char palavra_existente[MAX_LETRAS];
    int palavra_ja_existe = 0;
    while (fread(palavra_existente, sizeof(char), MAX_LETRAS, file)) {
        if (strcmp(palavra_existente, nova_palavra) == 0) {
            palavra_ja_existe = 1;
            break;
        }
    }

    if (palavra_ja_existe) {
        printf(" \n");
        printf("Essa palavra ja foi cadastrada!\n");
        fclose(file);
        return;
    }

    // Se a palavra não existe, cadastrá-la
    fseek(file, 0, SEEK_END);  
    fwrite(nova_palavra, sizeof(char), MAX_LETRAS, file);
    printf("\n");
    printf("Palavra cadastrada com sucesso!\n");
    fclose(file);
}