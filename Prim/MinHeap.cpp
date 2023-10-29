#include <iostream>
#include <vector>
#include <pair>
#include "minheap.h"

using namespace std;


MinHeap::MinHeap(int V){

    heapStructure = heapStructure(V,HeapElement(-1,__DBL_MAX__,-1));
    heapStructure[0].key = 0.0;
    heapStructure[0].num = 0;
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
    this.heapStructure[leftChildIndex].key < this.heapStructure[menor].key){
        
        menor = leftChildIndex;
    }
    if (rightChildIndex <= this.heapStructure.size() &&
    this.heapStructure[rightChildIndex].key < this.heapStructure[menor].key){
        
        menor = rightChildIndex;
    }
    
    if (menor != index){
        
        int temp = this.heapStructure[index];
        this.heapStructure[index] = this.heapStructure[menor];
        this.heapStructure[menor] = temp;
        minHeapify(menor);
    }

}

HeapElement MinHeap::extractMin(){
    
    if (!isEmpty())
    {
        HeapElement u = heapStructure[0];
        heapStructure.erase(heapStructure.begin()); //exluimos o primeiro elemento da heap
        minHeapify(0); // aplicamos o minheapify para reordenar a heap
        return u;
    }
    
    cout << "Fila de prioridade vazia" << endl;
}

void MinHeap::buildMinHeap(vector<HeapElement>& array){

    for(int i = int(array.size()/2) - 1; i >= 0; i--){
        minHeapify(i);
    }
}

bool MinHeap::isEmpty(){

    return this.heapStructure.empty();
}

double MinHeap::getKey(int index){

    return heapStructure[index].key;
}

std::vector<HeapElement> MinHeap::getHeap()
{
    return heapStructure;
}

