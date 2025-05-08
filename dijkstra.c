#include "grafosMatriz.h"

// Encontra o vértice com a menor distância ainda não incluído no conjunto de visitados
int menorDistancia(int dist[], int visitado[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visitado[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Implementação do algoritmo de Dijkstra
int* dijkstra(Grafo *g, int origem) {
    // dist[i] será a menor distância da origem até o vértice i
    int *dist = (int*) malloc (g->numVertices*sizeof(int)); 
    // visitado[i] será verdadeiro (1) se o vértice i já foi incluído no caminho mínimo
    int *visitado = (int*) malloc (g->numVertices*sizeof(int));

    // Inicializa todas as distâncias como infinito e os visitados como falso
    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < g->numVertices - 1; count++) {
        int u = menorDistancia(dist, visitado, g->numVertices);

        visitado[u] = 1;

        // Atualiza os valores de distância dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < g->numVertices; v++)
            if (!visitado[v] && g->pesoMatrix[u][v] && dist[u] != INT_MAX 
                && dist[u] + g->pesoMatrix[u][v] < dist[v])
                dist[v] = dist[u] + g->pesoMatrix[u][v];
    } 
    return dist;  
}