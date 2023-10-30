#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    int V; //numero de vertices
    std::vector<std::vector<double>> adjacencyMatrix; // matriz de adjacencia representando o grafo
public:
    Graph(int V);
    void addEdge(int from, int to, double weight); //adicionar uma aresta na matriz
    int getEdge(int from, int to); // retornar a aresta
    int getV(); // retornar o numero de vertices
    std::vector<std::vector<double>> getAdjacencyMatrix(); // acessar a matriz de adjacencia
};

#endif