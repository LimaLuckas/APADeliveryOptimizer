#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap{

    private:
        std::vector<std::pair<double, int>> heapStructure; // heap na qual teremos o par custo-pai a ser implementada
    public:
        MinHeap(int V);
        void buildMinHeap(const std::vector<int>& array);
        void minHeapify(int index);
        std::pair<int,int> extractMin();
        bool isEmpty();
};

#endif