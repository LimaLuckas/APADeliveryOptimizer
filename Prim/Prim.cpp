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
            if (i == j)
            {
                continue;
            }
            
            double efficiency = d[i]/c[i][j];
            adjMatrix.addEdge(i,j,efficiency);
        }
    }
}


int prim(const Graph& grafo, minHeap& priorityQueue, int& begin = 0) {

    int n = grafo.getV();
    vector<bool> inQ(n**2,true);
    vector<pair<double,int>> solution;

    int adjTo = 0;

    while (!priorityQueue.isEmpty())
    {
        solution.emplace_back(priorityQueue.extractMin());
        inQ[adjTo] = false;

        for (int i = 0; i < n; i++)
        {

            if (adjTo == i)
            {
                continue;
            }

            double currentValue = grafo.getAdjacencyMatrix[adjTo][i];

            if (inQ[i] == true && currentValue < priorityQueue.getKey(i)); 
            {
                priorityQueue.getHeap()[i].second = adjTo;
                priorityQueue.getHeap()[i].first = currentValue;
            }
            
        }
        
    }
    
}
