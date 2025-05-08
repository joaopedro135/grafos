#include "grafosMatriz.h"

void inicializarGrafo(Grafo* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adjMatrix[i][j] = 0;
            g->pesoMatrix[i][j] = 0;
        }
    }
}

void adicionarAresta(Grafo* g, int origem, int destino) {
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices) {
        g->adjMatrix[origem][destino] += 1;
        g->adjMatrix[destino][origem] += 1;     
    } else {
        printf("Erro: vértices fora do intervalo.\n");
    }
}

void adicionarPesoAresta(Grafo* g, int origem, int destino, int peso) {
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices && 
         g->adjMatrix[origem][destino]>=1 ) {
        g->pesoMatrix[origem][destino] = peso;
        g->pesoMatrix[destino][origem] = peso;

    } else {
        printf("Erro: vértices fora do intervalo ou não existe aresta.\n");
    }
}

void removeAresta(Grafo *g, int origem, int destino){
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices) {
        if (g->adjMatrix[origem][destino] >= 1) {
            g->adjMatrix[origem][destino] = 0;
            g->adjMatrix[destino][origem] = 0;
            g->pesoMatrix[origem][destino] = 0;
            g->pesoMatrix[destino][origem] = 0;
        }
        else{
            printf("Erro: vértices não pertence ao grafo.\n");    
        }    
    } else {
        printf("Erro: vértices fora do intervalo.\n");
    }
}

void adicionarArestaOrientado(Grafo* g, int origem, int destino) {
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices) {
        g->adjMatrix[origem][destino] += 1;    
    } else {
        printf("Erro: vértices fora do intervalo.\n");
    }
}

void adicionarPesoArestaOrientado(Grafo* g, int origem, int destino, int peso) {
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices && g->adjMatrix[origem][destino]>=1 ) {
        g->pesoMatrix[origem][destino] = peso;
    } else {
        printf("Erro: vértices fora do intervalo ou não existe aresta.\n");
    }
}

void removeArestaOrientado(Grafo *g, int origem, int destino) {
    if (origem >= 0 && destino >= 0 && origem < g->numVertices && destino < g->numVertices) {
        if (g->adjMatrix[origem][destino] >= 1){
            g->adjMatrix[origem][destino] = 0;
            g->pesoMatrix[origem][destino] = 0;
        }
        else{
            printf("Erro: vértices não pertence ao grafo.\n");    
        }    
    } else {
        printf("Erro: vértices fora do intervalo.\n");
    }
}

void imprimirMatriz(Grafo* g) {
    printf("Matriz de Adjacencia:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d  ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatrizPeso(Grafo* g) {
    printf("Matriz de Adjacencia:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d  ", g->pesoMatrix[i][j]);
        }
        printf("\n");
    }
}

void imprimeDistancia(int dist[], int V) { 
    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < V; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
    }
}

void carregarGrafo(const char* nomeArquivo, int* num_vertices, Grafo* g) {
    FILE* f = fopen(nomeArquivo, "r");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fscanf(f, "%d", num_vertices);
    inicializarGrafo(g, *num_vertices);
    int u, v, peso;
    while (fscanf(f, "%d %d %d", &u, &v, &peso) != EOF) {
        adicionarAresta (g, u, v);
        adicionarPesoAresta(g, u, v, peso);
    }
    fclose(f);
}

int verificaVerticesAdjacentes (Grafo *g, int origem1, int destino1) {
    if (g->adjMatrix[origem1][destino1] == 1) {
        return 1;
    }
    return 0;
}

int verificaArestasAdjacentes (Grafo *g, int origem1, int destino1, int origem2, int destino2) {
    if (origem1 == origem2 || origem1 == destino2 || destino1 == origem2 || destino1 == destino2) {
        return 1;
    } else {
        return 0;
    }
}

int verificaArestasParalelasOrientado (Grafo *g, int origem1, int destino1) {
    if (g->adjMatrix[origem1][destino1] == 1 && g->adjMatrix[destino1][origem1] == 1) { //Verificação para grafos orientados, nos quais não são inicializados os dois sentidos
        return 1;
    }
    return 0;
}

int verificaLacos (Grafo *g) {
    int quantidadeLacos = 0;
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[i][i]) {
            quantidadeLacos++;
        }
    }
    return quantidadeLacos;
}

void grauVertices (Grafo *g, int grauVertices[]) {
    grauVertices[g->numVertices];
    for (int i = 0; i < g->numVertices; i++) {
        grauVertices[i] = 0;
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                grauVertices[i]++;
            }
        }
    }
}

void grauVerticesOrientado (Grafo *g, int grauVerticesEntrada[], int grauVerticesSaida[]) {
    grauVerticesEntrada[g->numVertices];
    grauVerticesSaida[g->numVertices];
    for (int i = 0 ; i < g->numVertices; i++) {
        grauVerticesEntrada[i] = 0;
        grauVerticesSaida[i] = 0;
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                grauVerticesSaida[i]++;
                grauVerticesEntrada[j]++;
            }
        }
    }
}

int verificaGrafoCompleto (Grafo *g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (i != j && g->adjMatrix[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void verificarSubgraficoInduzido () {
    Grafo g;
    scanf ("%d", &g.numVertices);
    inicializarGrafo(&g, g.numVertices);
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            scanf ("%d", &g.adjMatrix[i][j]);
            adicionarAresta(&g, i, j);
        }
    }
    int numVerticesSubgrafico;
    scanf ("%d", &numVerticesSubgrafico);
    int verticesSubgrafico[numVerticesSubgrafico];
    for (int i = 0; i < numVerticesSubgrafico; i++) {
        scanf ("%d", &verticesSubgrafico[i]);
    }
    for (int i = 0; i < numVerticesSubgrafico; i++) {
        for (int j = 0; j < numVerticesSubgrafico; j++) {
            if (g.adjMatrix[verticesSubgrafico[i]][verticesSubgrafico[j]] == 1) {
                adicionarAresta(&g, verticesSubgrafico[i], verticesSubgrafico[j]);
            }
        }
    }
}

void dfs (Grafo *g, int vertice, int verticesVisitados[]) {
    verticesVisitados[vertice] = 1;
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertice][i] == 1 && !verticesVisitados[i]) {
            dfs(g, i, verticesVisitados);
        }
    }
}

void fechoTransitivoDireto () {
    Grafo g;
    scanf ("%", &g.numVertices);
    inicializarGrafo(&g, g.numVertices);
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            scanf ("%d", &g.adjMatrix[i][j]);
            adicionarArestaOrientado(&g, i, j);
        }
    }
    int vertice;
    scanf ("%d", &vertice);
    int verticesVisitados[g.numVertices];
    for (int i = 0; i < g.numVertices; i++) {
        verticesVisitados[i] = 0;
    }
    dfs(&g, vertice, verticesVisitados); 
}

void fechoTransitivoInverso () {
    Grafo g;
    scanf ("%", &g.numVertices);
    inicializarGrafo(&g, g.numVertices);
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            scanf ("%d", &g.adjMatrix[i][j]);
            adicionarArestaOrientado(&g, j, i);
        }
    }
    int vertice;
    scanf ("%d", &vertice);
    int verticesVisitados[g.numVertices];
    for (int i = 0; i < g.numVertices; i++) {
        verticesVisitados[i] = 0;
    }
    dfs(&g, vertice, verticesVisitados);
}