#include <iostream>
#include <vector>

// Função para realizar a operação 2-opt em uma solução
std::vector<int> Opt2(const std::vector<int>& solucao, int i, int j) {
    std::vector<int> novaSolucao = solucao;
    int aux = 0;

    // Inverte os elementos entre i e j
    while (i < j) {
        aux = novaSolucao[j];
        novaSolucao[j] = novaSolucao[i];
        novaSolucao[i] = aux;
        i++;
        j--;
    }

    return novaSolucao;
}