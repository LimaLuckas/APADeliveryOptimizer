#include <vector>
#ifndef MINHEAP_H
#define MINHEAP_H

struct HeapElement{

    int num; // numero do vertice
    double key; // valor de custo
    int parent; // numero do vertice pai

    HeapElement(): num(-1), key(__DBL_MAX__), parent(-1){}    

};

class MinHeap{

    private:
        std::vector<HeapElement> heapStructure; // vetor de elementos heap que será nossa min heap
    public:
        MinHeap(int V);
        void buildMinHeap(); //iniciar a heap
        void minHeapify(int index); //ordenar a heap minima
        HeapElement extractMin(); //extrair o valor com o minimo custo
        bool isEmpty(); //checar se esta vazia
        double getKey(int index); //retornar a chave(custo) de um vertice na heap
        std::vector<HeapElement> getHeap(); // acessar a heap
};

#endif