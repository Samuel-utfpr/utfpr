#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

// Estrutura do Grafo
typedef struct adjacencia {
    int vertice;
    struct adjacencia* prox;
} Adjacencia;

typedef struct vertice {
    int id;
    Adjacencia* listaAdj;
} Vertice;

typedef struct grafo {
    int vertices;
    int arestas;
    Vertice* listaVert;
} Grafo;

// Funções do Grafo
Grafo* criarGrafo(int numVertices) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->vertices = numVertices;
    g->arestas = 0;
    g->listaVert = (Vertice*)malloc(numVertices * sizeof(Vertice));
    for (int i = 0; i < numVertices; i++) {
        g->listaVert[i].id = i;
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
    if (origem == destino) return 0;
    if (g->listaVert[origem].listaAdj != NULL) {
        Adjacencia* adj = g->listaVert[origem].listaAdj;
        while (adj) {
            if (adj->vertice == destino) {
                return 0; 
            }
            adj = adj->prox;
        }
    }
    Adjacencia* novaAdjDest = criarAdjacencia(destino);
    Adjacencia* novaAdjOrig = criarAdjacencia(origem);
    novaAdjDest->prox = g->listaVert[origem].listaAdj;
    novaAdjOrig->prox = g->listaVert[destino].listaAdj;
    g->listaVert[origem].listaAdj = novaAdjDest;
    g->listaVert[destino].listaAdj = novaAdjOrig;
    g->arestas++;
    return 1;
}

void imprimeGrafo(Grafo* g) {
    printf("Verrtices: %d, Arestas: %d\n", g->vertices, g->arestas);
    int i;
    for(i = 0; i < g->vertices; i++) {
        printf("V%d: ", i+1);
        Adjacencia* adj = g->listaVert[i].listaAdj;
        while (adj) {
            printf("V%d ", adj->vertice+1);
            adj = adj->prox;
        }
        printf("\n");
    }
}


//Mecanismos de Busca
void visitaP(Grafo *g, int u, int *cor);
void visitaL(Grafo *g, int s, int *expl);
void profundidade(Grafo *g, int v);
void largura(Grafo *g, int v);


//DFS
void profundidade(Grafo *g, int v) {
    int cor[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++) {
        cor[u] = BRANCO;
    }
    for (u = v; u < g->vertices; u++) {
        if (cor[u] == BRANCO) {
            visitaP(g, u, cor);
        }
    }
}
void visitaP(Grafo *g, int u, int *cor) {
    cor[u] = AMARELO;
    Adjacencia* adj = g->listaVert[u].listaAdj;
    while (adj) {
        if (cor[adj->vertice] == BRANCO) {
            visitaP(g, adj->vertice, cor);
        }
        adj = adj->prox;
    }
    cor[u] = VERMELHO;
    printf("Visitado: %d\n", u+1);
}

// BFS
void largura(Grafo *g, int v) {
    int expl[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++) {
        expl[u] = 0;
    }
    for (u = v; u < g->vertices; u++) {
        if (!expl[u]) {
            visitaL(g, u, expl);
        }
    }
}
void visitaL(Grafo *g, int s, int *expl) {
    int fila[g->vertices];
    int inicio = 0, fim = 0;

    fila[fim++] = s;
    expl[s] = 1;

    while (inicio < fim) {
        int u = fila[inicio++];
        Adjacencia* adj = g->listaVert[u].listaAdj;
        while (adj) {
            if (!expl[adj->vertice]) {
                fila[fim++] = adj->vertice;
                expl[adj->vertice] = 1;
            }
            adj = adj->prox;
        }
        printf("Visitado: %d\n", u+1);
    }
}


// main do programa
int main() {
    Grafo* g = NULL;

    while(1) {
        int opcao;
        printf("Escolha uma opcao:\n");
        printf("1. Criar grafo\n");
        printf("2. Criar aresta\n");
        printf("3. Imprimir grafo\n");
        printf("4. Busca em profundidade(DFS)\n");
        printf("5. Busca em largura(BFS)\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao){
            case 1: {
                int numVertices;
                printf("Numero de vertices: ");
                scanf("%d", &numVertices);
                g = criarGrafo(numVertices);
                if(g) {
                    printf("Grafo criado com sucesso!\n");
                } else {
                    printf("Erro ao criar grafo!\n");
                }
                break;
            }
            case 2: {
                if(!g) {
                    printf("Grafo nao criado ainda!\n");
                    break;
                }
                int origem, destino;
                printf("Informe a vertice de Origem: ");
                scanf("%d", &origem);
                printf("Informe a vertice de Destino: ");
                scanf("%d", &destino);
                origem --;
                destino --;
                if (criaAresta(g, origem, destino)) {
                    printf("Aresta criada com sucesso!\n");
                } else {
                    printf("Erro ao criar aresta!\n");
                }
                break;
            }
            case 3: {
                if(!g) {
                    printf("Grafo não criado ainda!\n");
                    break;
                }
                imprimeGrafo(g);
                printf("\n");
                break;
            }
            case 4: {
                if(!g) {
                    printf("Grafo nao criado ainda!\n");
                    break;
                }
                int vertice_inicial;
                printf("Informe o vertice inicial para DFS: ");
                scanf("%d", &vertice_inicial);
                vertice_inicial --;
                profundidade(g, vertice_inicial);
                printf("\n");
                break;
            }
            case 5: {
                if(!g) {
                    printf("Grafo nao criado ainda!\n");
                    break;
                }
                int vertice_inicial;
                printf("Informe o vertice inicial para BFS: ");
                scanf("%d", &vertice_inicial);
                vertice_inicial --;
                largura(g, vertice_inicial);
                printf("\n");
                break;
            }
            case 6: {
                printf("Saindo...\n");
                return 0;
            }
            default:
                printf("Opcao invalida!\n");
        }
    }
    

}