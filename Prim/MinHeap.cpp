#include <iostream>
#include <vector>
#include <pair>
#include "minheap.h"

using namespace std;


MinHeap::MinHeap(int V){

    this.heapStructure = heapStructure(V*V, make_pair(__DBL_MAX__, -1));
    this.heapStructure[0].first = 0.0;
    buildMinHeap(heapStructure);
}


void MinHeap::minHeapify(int index){

    if (isEmpty())
    {
        cout << "Heap vazia" << endl;
        return;
    }
    
    int leftChildIndex =  2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    int menor = index;

    if (leftChildIndex <= this.heapStructure.size() &&
    this.heapStructure[leftChildIndex].first < this.heapStructure[menor].first){
        
        menor = leftChildIndex;
    }
    if (rightChildIndex <= this.heapStructure.size() &&
    this.heapStructure[rightChildIndex].first < this.heapStructure[menor].first){
        
        menor = rightChildIndex;
    }
    
    if (menor != index){
        
        int temp = this.heapStructure[index];
        this.heapStructure[index] = this.heapStructure[menor];
        this.heapStructure[menor] = temp;
        minHeapify(menor);
    }

}

pair<double,int> MinHeap::extractMin(){
    
    if (!isEmpty())
    {
        pair<double,int> u = heapStructure[0];
        heapStructure.erase(heapStructure.begin()); //exluimos o primeiro elemento da heap
        minHeapify(0); // aplicamos o minheapify para reordenar a heap
        return u;
    }
    
    cout << "Fila de prioridade vazia" << endl;
}

void MinHeap::buildMinHeap(vector<pair<double,int>>& array){

    for(int i = int(array.size()/2) - 1; i >= 0; i--){
        minHeapify(i);
    }
}

bool MinHeap::isEmpty(){

    return this.heapStructure.empty();
}

double MinHeap::getKey(int index){

    return heapStructure[index].first;
}

std::vector<std::pair<double, int>> MinHeap::getHeap()
{
    return heapStructure;
}

