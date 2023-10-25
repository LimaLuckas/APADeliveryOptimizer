#include <iostream>
#include <vector>

//Função para realizar a operação Reinsertion em uma solução inicial
std::vector<int> ReInsertion(std::vector<int> &solucao, int custoAtual, int i, int j){

    std::vector<int> novaSolucao = solucao;
    int aux = novaSolucao[i];

    for ( i ; i < j; i++)
    {
        novaSolucao[i] = novaSolucao[i+1];
    }

    novaSolucao[j] = aux;

    return novaSolucao;
}