#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Estrutura do Grafo
typedef struct adjacencia {
    int vertice;
    struct adjacencia* prox;
} Adjacencia;

typedef struct vertice {
    int id;
    char disciplina[100];
    Adjacencia* listaAdj;
} Vertice;

typedef struct grafo {
    int vertices;
    int arestas;
    Vertice* listaVert;
} Grafo;

// Funções do Grafo
Grafo* criarGrafo(int numVertices, char disciplinas[76][100]) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = numVertices;
    g->arestas = 0;
    g->listaVert = (Vertice*)malloc(numVertices * sizeof(Vertice));
    for (int i = 0; i < numVertices; i++) {
        g->listaVert[i].id = i;
        strcpy(g->listaVert[i].disciplina, disciplinas[i]);
        g->listaVert[i].listaAdj = NULL;
    }
    return g;
}

Adjacencia* criarAdjacencia(int v) {
    Adjacencia* novaAdj = (Adjacencia*)malloc(sizeof(Adjacencia));
    novaAdj->vertice = v;
    novaAdj->prox = NULL;
    return novaAdj;
}

int criaAresta(Grafo* g, int origem, int destino) {
    if(!g) return 0;
    if (origem < 0 || origem >= g->vertices || destino < 0 || destino >= g->vertices) return 0;
    Adjacencia* novaAdj = criarAdjacencia(destino);
    novaAdj->prox = g->listaVert[origem].listaAdj;
    g->listaVert[origem].listaAdj = novaAdj;
    g->arestas++;
    return 1;
}

// Utilitários do Grafo
void imprimeGrafo(Grafo* g) {
    printf("Total de Diciplinas: %d, Total pré requisitos(arestas): %d\n", g->vertices, g->arestas);
    int i;
    for(i = 0; i < g->vertices; i++) {
        printf("D.:%d - %s: ", i, g->listaVert[i].disciplina);
        Adjacencia* adj = g->listaVert[i].listaAdj;
        while (adj) {
            printf("%d - %s; ", g->listaVert[adj->vertice].id, g->listaVert[adj->vertice].disciplina);
            adj = adj->prox;
        }
        printf("\n");
    }
}

int verificaPreRequisito(Grafo* g, int disciplina, int preRequisito) {
    Adjacencia* adj = g->listaVert[disciplina].listaAdj;
    while (adj) {
        if (adj->vertice == preRequisito) {
            return 1; 
        }
        adj = adj->prox;
    }
    return 0; 
}


// main do programa
int main() {
    //Disciplinas da UTFPR - Eng. de Software
    char disciplinas[76][100] = {
        "Algoritmos 1",
        "ENADE I",
        "Fundamentos de Engenharia de Software",
        "Letramento Academico",
        "Logica para Computacao",
        "Matematica Discreta",
        "Atividades Complementares",
        "Algoritmos 2",
        "Algebra Linear",
        "Banco de Dados 1",
        "Organizacao de Computadores",
        "Processo de Producao de Software",
        "Requisitos de Software",
        "Algoritmos e Estrutura de Dados 1",
        "Banco de Dados 2",
        "Gerencia de Configuracao de Software",
        "Gestao de Pessoas",
        "Modelagem de Software",
        "Programacao Orientada a Objetos",
        "Algoritmos e Estrutura de Dados 2",
        "Arquitetura de Software",
        "Etica, Normas e Postura Profissional",
        "Programacao para Web 1",
        "Redes de Computadores",
        "Sistemas Operacionais",
        "Bancos de Dados nao Relacionais",
        "Engenharia de Software Baseada em Busca",
        "Computacao Grafica",
        "Desenvolvimento de Software Educativo",
        "Direitos Humanos",
        "Desenvolvimento de Jogos",
        "Programacao para Dispositivos Moveis",
        "Design de Processos",
        "Design de Produtos e Servicos",
        "Estudos Culturais e Relacoes Etnico-Raciais",
        "Empreendedorismo e Inovacao",
        "Experiencia do Usuario",
        "Experimentacao em Engenharia de Software",
        "Fundamentos de Robotica e Sistemas Autonomos Inteligentes",
        "Fabrica de Software 1",
        "Frameworks Web",
        "Gerencia e Administracao de Redes de Computadores",
        "Game Design",
        "Governanca de TI Verde",
        "Interacao Humano-Computador",
        "Historia e Cultura Afro-Brasileira",
        "Ingles Instrumental",
        "Integracao de Sistemas",
        "Introducao a Teoria da Computacao",
        "Libras 2",
        "Libras 1",
        "Modelagem de Processos",
        "Projeto e Analise de Algoritmos",
        "Praticas de Desenvolvimento Enxuto de Software",
        "Gestao de Projeto de Software",
        "Programacao para Web 2",
        "Qualidade de Vida",
        "Redes Neurais Artificiais",
        "Resolucao de Problemas",
        "Sociedade e Meio Ambiente",
        "Saude e Seguranca no Trabalho",
        "Topicos Especiais em Ciencia da Computacao",
        "Topicos Especiais em Desenvolvimento de Software",
        "Topicos Especiais em Engenharia de Software",
        "Visao Computacional",
        "Fabrica de Software 2",
        "Manutencao de Software",
        "Metodologia de Pesquisa",
        "Probabilidade e Estatistica",
        "Fundamentos de Sistemas Inteligentes",
        "Teste de Software",
        "Design de Software",
        "Programacao Concorrente",
        "Paradigmas de Programacao",
        "Qualidade de Software",
        "Sistemas Inteligentes Aplicados a Engenharia de Software",
        "Trabalho de Conclusao de Curso 1",
        "ENADE C",
        "Estagio Curricular Obrigatorio",
        "Integracao Continua",
        "Mercado Produtor de Software",
        "Seguranca e Auditoria em Sistemas",
        "Trabalho de Conclusao de Curso 2"
    };

    //Criacao do grafo
    Grafo* g = criarGrafo (76, disciplinas);

    //Dependencias entre as disciplinas
    // Período 2
    criaAresta(g, 0, 7);
    // Período 3
    criaAresta(g, 7, 13);
    criaAresta(g, 9, 14);
    criaAresta(g, 11, 15);
    criaAresta(g, 12, 17);
    criaAresta(g, 7, 18);
    // Período 4
    criaAresta(g, 13, 19);
    criaAresta(g, 17, 20);
    criaAresta(g, 7, 22);
    criaAresta(g, 10, 24);
    // Período 5
    criaAresta(g, 14, 25);
    criaAresta(g, 19, 52);
    criaAresta(g, 13, 28);
    // 6º Período
    criaAresta(g, 25, 40);
    criaAresta(g, 19, 41);
    criaAresta(g, 19, 49);
    criaAresta(g, 24, 41);
    criaAresta(g, 53, 49);
    // 7º Período
    criaAresta(g, 40, 53);
    criaAresta(g, 41, 55);
    criaAresta(g, 20, 66);
    criaAresta(g, 52, 66);
    // 8º Período
    criaAresta(g, 53, 70);
    criaAresta(g, 66, 79);
    criaAresta(g, 70, 79);

    while(1) {
        printf("Grafo de Disciplinas - UTFPR Eng. de Software\n");
        printf("1. Imprimir grafo\n");
        printf("2. Verificar pre-requisito\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        int opcao;
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao){
            case 1: {
                imprimeGrafo(g);
                printf("\n");
                break;
            }
            case 2: {
                int disciplina, preRequisito;
                printf("Informe o codigo do pre-requisito (0-75): ");
                scanf("%d", &preRequisito);
                printf("Informe o codigo da disciplina (0-75): ");
                scanf("%d", &disciplina);
                if (verificaPreRequisito(g, preRequisito, disciplina)) {
                    printf("A disciplina %s e pre-requisito de %s\n", g->listaVert[preRequisito].disciplina, g->listaVert[disciplina].disciplina);
                } else {
                    printf("A disciplina %s nao e pre-requisito de %s\n", g->listaVert[preRequisito].disciplina, g->listaVert[disciplina].disciplina);
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("Saindo...\n");
                exit(0);
            }
            default: {
                printf("Opcao invalida!\n\n");
                break;
            }
        }
    }


    return 0;
}
