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


void costHeuristic(const int& n, const vector<int>& d, const vector<vector<int>>& c, Graph& adjMatrix){

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {   
            if (adjMatrix.getAdjacencyMatrix()[i][j] == 0)
            {
                continue;
            }
            
            double efficiency = d[i]/c[i][j];
            adjMatrix.addEdge(i,j,efficiency);
        }
    }
}


int prim(const Graph& grafo, minHeap& priorityQueue, const vector<vector<int>>& c, int& L, int& r) {

    int n = grafo.getV(); // numero de iteracoes: mesmo numero de vertices
    vector<bool> inQ(n,true); // vetor para saber se um elemento esta em Q
    HeapElement u; //elemento de Q a ser obtido
    int solucao;
    double menor

    int adjTo; // Coluna a se procurar arestas adjacentes

    while (!priorityQueue.isEmpty())
    {
        u = priorityQueue.extractMin(); //pop no primeiro elemento da fila de prioridade
        menor = u.key;
        adjTo = u.num;

        if(u.parent == -1){
            solucao += c[0][u.num];
        }
        else
        {
            solucao += c[u.parent][u.num];
        }
        
        inQ[adjTo] = false;

        for (int i = 0; i < n; i++)
        {

            double currentValue = grafo.getAdjacencyMatrix[adjTo][i]; //custo da aresta do vertice i adjacente ao vertice representado por adjTo

            if (currentValue == 0.0)
            {
                continue;
            }

            if ()
            {
                
            }
            

            if (inQ[i] == true && currentValue < priorityQueue.getKey(i)); 
            {
                priorityQueue.getHeap()[i]->parent = adjTo;
                priorityQueue.getHeap()[i]->key = currentValue;
                priorityQueue.getHeap()[i]->num = i;
                priorityQueue.minHeapify(0);
            }
            
        }
        
    }
    
}
