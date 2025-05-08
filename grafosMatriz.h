#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int numVertices; 
    int peso;  
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int pesoMatrix[MAX_VERTICES][MAX_VERTICES];
} Grafo;

// Matriz sem nenhuma aresta conectando os vértices
// Inicializa o grafo com número de vértices e zera matrizes de adjacência e peso
void inicializarGrafo(Grafo* g, int numVertices);

// Adiciona uma aresta entre dois vértices
// Utilizar função quando o grafo for não orientado
void adicionarAresta(Grafo* g, int origem, int destino);

// Adiciona uma aresta entre dois vértices
// Utilizar função quando o grafo for não orientado
void adicionarPesoAresta(Grafo* g, int origem, int destino, int peso);

// Remove uma aresta entre dois vértices zerando sua posição na matriz de adjacência e matriz de peso
// Utilizar função quando o grafo for não orientado
void removeAresta(Grafo *g, int origem, int destino);

// Adiciona uma aresta entre dois vértices
// Utilizar função quando o grafo for orientado
void adicionarArestaOrientado(Grafo* g, int origem, int destino);

// Adiciona uma aresta entre dois vértices
// Utilizar função quando o grafo for orientado
void adicionarPesoArestaOrientado(Grafo* g, int origem, int destino, int peso);

// Remove uma aresta entre dois vértices zerando sua posição na matriz de adjacência e matriz de peso
// Utilizar função quando o grafo for orientado
void removeArestaOrientado(Grafo *g, int origem, int destino);

// Exibe a matriz de adjacência
void imprimirMatriz(Grafo* g);

// Exibe a matriz de peso
void imprimirMatrizPeso(Grafo* g);

// Imprime os resultados de distância
void imprimeDistancia(int dist[], int V);

// O arquivo deve conter o número de vértices na primeira linha e as arestas nas linhas seguintes
// Cada aresta deve ser representada por três números: origem, destino e peso
void carregarGrafo(const char* nomeArquivo, int* num_vertices, Grafo* g);

// Dois vértices são adjacentes se existe uma aresta entre eles
int verificaVerticesAdjacentes (Grafo *g, int origem1, int destino1);

// Duas arestas são adjacentes se compartilham um vértice
int verificaArestasAdjacentes (Grafo *g, int origem1, int destino1, int origem2, int destino2);

// Duas arestas são paralelas se existem duas arestas entre os mesmos vértices
int verificaArestasParalelasOrientado (Grafo *g, int origem1, int destino1);

// Laços são arestas que ligam um vértice a ele mesmo
int verificaLacos (Grafo *g);

// O grau de um vértice é o número de arestas que incidem sobre ele
void grauVertices (Grafo *g, int grauVertices[]);

// O grau de entrada é o número de arestas que chegam ao vértice
// O grau de saída é o número de arestas que saem do vértice
void grauVerticesOrientado (Grafo *g, int grauVerticesEntrada[], int grauVerticesSaida[]);

// Um grafo é completo se existe uma aresta entre todos os pares de vértices
int verificaGrafoCompleto (Grafo *g);

// Um subgrafo é induzido se contém todos os vértices do grafo original e todas as arestas que ligam esses vértices
void verificarSubgraficoInduzido ();

// dfs (Depth First Search)
// Percorre o grafo a partir de um vértice, marcando os vértices visitados
void dfs (Grafo *g, int vertice, int verticesVisitados[]);

// O fecho transitivo direto de um vértice é o conjunto de vértices que podem ser alcançados a partir dele
// através de um caminho de arestas orientadas
void fechoTransitivoDireto ();

// O fecho transitivo inverso de um vértice é o conjunto de vértices que podem alcançar o vértice
// através de um caminho de arestas orientadas
void fechoTransitivoInverso ();

