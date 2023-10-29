#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

Graph::Graph(int V){
    this->V = V;

}

void Graph::addEdge(int from, int to, double weight){

    adjacencyMatrix[from][to] = weight;

}

int Graph::getEdge(int from, int to){

    return adjacencyMatrix[from][to];

}

void Graph::printGraph(){

    for (int i = 0; i < V; ++i) {
        std::cout << "Edges from vertex " << i << ": ";
        for (const auto& neighbor : adj[i]) {
            std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

int Graph::getV(){
    return this->V;
}


std::vector<std::vector<double>> Graph::getAdjacencyMatrix()
{
    return this->adjacencyMatrix;
}