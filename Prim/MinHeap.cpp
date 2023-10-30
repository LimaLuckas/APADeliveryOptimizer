#include <iostream>
#include <vector>
#include "minheap.h"

using namespace std;


MinHeap::MinHeap(int V){

    vector<HeapElement> heapStructure(V);
    heapStructure[0].key = 0.0;
    heapStructure[0].num = 0;
    buildMinHeap();
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

    if (leftChildIndex < heapStructure.size() &&
    heapStructure[leftChildIndex].key < heapStructure[menor].key){
        
        menor = leftChildIndex;
    }
    if (rightChildIndex < heapStructure.size() &&
    heapStructure[rightChildIndex].key < heapStructure[menor].key){
        
        menor = rightChildIndex;
    }
    
    if (menor != index){
        
        HeapElement temp = heapStructure[index];
        heapStructure[index] = heapStructure[menor];
        heapStructure[menor] = temp;
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

void MinHeap::buildMinHeap(){

    for(int i = int(heapStructure.size()/2) - 1; i >= 0; i--){
        minHeapify(i);
    }
}

bool MinHeap::isEmpty(){

    return heapStructure.empty();
}

double MinHeap::getKey(int index){

    return heapStructure[index].key;
}

std::vector<HeapElement> MinHeap::getHeap()
{
    return heapStructure;
}

