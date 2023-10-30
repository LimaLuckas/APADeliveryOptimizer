#include<iostream>
#include "minheap.h"
#include "graph.h"
#include <vector>
#include "fileReader.h"
#include <chrono>


using namespace std;

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

int prim(Graph& grafo, const vector<vector<int>>& c, vector<bool>& inQueue) {

    int n = grafo.getV(); // numero de iteracoes: mesmo numero de vertices
    MinHeap priorityQueue(n);// vetor para saber se um elemento esta em Q
    HeapElement u; //elemento de Q a ser obtido
    int solucao;

    int adjTo = 0; // Coluna a se procurar arestas adjacentes

    while (!priorityQueue.isEmpty())
    {
        u = priorityQueue.extractMin(); //pop no primeiro elemento da fila de prioridade
        adjTo = u.num;

        if(u.parent != -1){
            solucao += c[u.parent][u.num]; //c[i][j]
        }
        
        inQueue[adjTo] = false;

        for (int i = 0; i < n; i++)
        {

            double currentValue = grafo.getAdjacencyMatrix()[adjTo][i]; //custo da aresta do vertice i adjacente ao vertice representado por adjTo

            if (currentValue == 0.0)
            {
                continue;
            }       

            if (inQueue[i] == true && currentValue < priorityQueue.getKey(i)); 
            {
                priorityQueue.getHeap()[i].parent = adjTo;
                priorityQueue.getHeap()[i].key = currentValue;
                priorityQueue.getHeap()[i].num = i;
                priorityQueue.minHeapify(0);
            }
            
        }
        return solucao;  
    }
    
}

int main(){

    // Calcule a diferença de tempo
    FileReader parser("instancias/n9k5_A.txt");
    parser.readfileData();

    int n = parser.getN();
    int k = parser.getK();
    int Q = parser.getQ();
    int L = parser.getL();
    int r = parser.getR();
    vector<int> p = parser.getP();
    vector<int> d = parser.getD();
    vector<vector<int>> c = parser.getC();

    Graph AdjMatrix(n);

    costHeuristic(n,d,c,AdjMatrix);
    
    vector<bool> inQueue(n,true);

    auto start_time = std::chrono::high_resolution_clock::now();
    int solucao = prim(AdjMatrix,c,inQueue);
    auto end_time = std::chrono::high_resolution_clock::now();
    
    cout << solucao;

    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << duration.count();

    return 0;
}