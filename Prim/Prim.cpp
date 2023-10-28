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
            if (c[i][j] == 0)
            {
                continue;
            }
            
            double efficiency = d[i]/c[i][j];
            adjMatrix.addEdge(i,j,efficiency);
        }
    }
}


int prim(const Graph& grafo) {

    vector<bool> inQ(grafo.getV()**2,true);

    MinHeap priorityQueue(grafo.getV());

    while (!priorityQueue.isEmpty())
    {
        pair<double,int> u = priorityQueue.extractMin();
        
        for (const auto& neighbor: grafo.getAdjacencyMatrix()[])
        {
            if (neighbor)
            {
                /* code */
            }
            
        }
        
    }
    
}
