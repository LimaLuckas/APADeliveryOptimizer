#include<iostream>
#include "minheap.h"
#include "graph.h"
#include <vector>
#include "fileReader.h"

using namespace std;

int main(){

    FileReader parser();
    parser.readfileData("entrada.txt");

    int n = parser.getN();
    int k = parser.getK();
    int Q = parser.getQ();
    int L = parser.getL();
    int r = parser.getR();
    vector<int> p = parser.getP();
    vector<int> d = parser.getD();
    vector<vector<int>> c = parser.getC();

}


void efficienyHeuristic(const int& n, const vector<int>& d, const vector<vector<int>>& c, Graph& adjMatrix){

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {   
            if (adjMatrix.getAdjacencyMatrix()[i][j] == 0)
            {
                continue;
            }
            
            double efficiency = c[i][j]/d[i];
            adjMatrix.addEdge(i,j,efficiency);
        }
    }
}


int prim(const Graph& grafo, minHeap& priorityQueue, int& begin = 0) {

    int n = grafo.getV(); // numero de iteracoes: mesmo numero de vertices
    vector<bool> inQ(n,true); // vetor para saber se um elemento esta em Q
    pair<double,int> u; //elemento de Q a ser obtido

    int adjTo = 0; // Coluna a se procurar arestas adjacentes

    while (!priorityQueue.isEmpty())
    {
        u = priorityQueue.extractMin();
        inQ[adjTo] = false;

        for (int i = 0; i < n; i++)
        {

            double currentValue = grafo.getAdjacencyMatrix[adjTo][i];

            if (currentValue == 0.0)
            {
                continue;
            }

            if (inQ[i] == true && currentValue < priorityQueue.getKey(i)); 
            {
                priorityQueue.getHeap()[i].second = int(i/2);
                priorityQueue.getHeap()[i].first = currentValue;
            }
            
        }
        
    }
    
}
