#include <iostream>
#include <vector>

// Função para realizar a operação 2-opt em uma solução inicial
std::vector<int> Opt2(const std::vector<int>& solucao, int i, int j) {
    std::vector<int> novaSolucao = solucao;
    int aux = 0;


    // Inverte os elementos entre i e j
    for (i ; i < j; i++)
    {
        for (j ; j > i; j--)
        {            
            aux = novaSolucao[j];
            novaSolucao[j] = novaSolucao[i];
            novaSolucao[i] = aux;
        }
    }
    
    return novaSolucao;
}