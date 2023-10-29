#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct {

    int num;
    double key;
    int parent;

} heapElement;

class MinHeap{

    private:
        std::vector<std::pair<double, int>> heapStructure; // heap na qual teremos o par custo-pai a ser implementada
    public:
        MinHeap(int V);
        void buildMinHeap(const std::vector<pair<double,int>>& array); //iniciar a heap
        void minHeapify(int index); //ordenar a heap minima
        std::pair<double,int> extractMin(); //extrair o valor com o minimo custo
        bool isEmpty(); //checar se esta vazia
        double getKey(int index); //retornar a chave(custo) de um vertice na heap
        std::vector<std::pair<double,int>> getHeap(); // acessar a heap
};

#endif