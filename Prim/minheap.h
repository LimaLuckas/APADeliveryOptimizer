#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct HeapElement{

    int num; // numero do vertice
    double key; // valor de custo
    int parent; // numero do vertice pai

    HeapElement(int n, double k, int p): num(n), key(k), parent(p){}    

} HeapElement;

class MinHeap{

    private:
        std::vector<HeapElement> heapStructure; // vetor de elementos heap que será nossa min heap
    public:
        MinHeap(int V);
        void buildMinHeap(const std::vector<HeapElement>& array); //iniciar a heap
        void minHeapify(int index); //ordenar a heap minima
        HeapElement extractMin(); //extrair o valor com o minimo custo
        bool isEmpty(); //checar se esta vazia
        double getKey(int index); //retornar a chave(custo) de um vertice na heap
        std::vector<HeapElement> getHeap(); // acessar a heap
};

#endif