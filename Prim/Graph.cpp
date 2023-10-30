#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

Graph::Graph(int V){
    this->V = V;
    vector<vector<double>> adjacencyMatrix(V, vector<double>(V,0.0));
}

void Graph::addEdge(int from, int to, double weight){

    adjacencyMatrix[from][to] = weight;

}

int Graph::getEdge(int from, int to){

    return adjacencyMatrix[from][to];

}

int Graph::getV(){
    return V;
}

std::vector<std::vector<double>> Graph::getAdjacencyMatrix()
{
    return adjacencyMatrix;
}