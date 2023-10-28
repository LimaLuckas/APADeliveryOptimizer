#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    int V;
    std::vector<vector<double>> adjacencyMatrix;
public:
    Graph(int V);
    void addEdge(int from, int to, double weight);
    int getEdge(int VertexToFind, int linkedTo);
    void printGraph();
    int getV();
    std::vector<std::vector<double>> getAdjacencyMatrix();
};

#endif