#include <iostream>
#include <vector>
#include <pair>
#include "minheap.h"

using namespace std;


MinHeap::MinHeap(int V){

    this.heapStructure = heapStructure(V*V, make_pair(__DBL_MAX__, -1));
    this.heapStructure[0].first = 0.0;
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

pair<int,int> MinHeap::extractMin(){
    
    if (!isEmpty())
    {
        pair<int,int> u = heapStructure[0];
        heapStructure.erase(heapStructure.begin());
        minHeapify(0);
        return u;
    }
    
    cout << "Fila de prioridade vazia" << endl;
}

void MinHeap::buildMinHeap(){

    for(int i = int(array.size()/2) - 1; i >= 0; i--){
        minHeapify(i);
    }
}

bool MinHeap::isEmpty(){

    return this.heapStructure.empty();
}

