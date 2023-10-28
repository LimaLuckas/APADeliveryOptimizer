#include <iostream>
#include <vector>

//Função para realizar a operação Reinsertion em uma solução inicial
std::vector<int> ReInsertion(const std::vector<int>& solucao, const std::vector<std::vector<int>>& custos, int custoAtual){

    std::vector<int> novaSolucao = solucao;
    int best_Value = custoAtual;
    int best_i;
    int best_j;
    int novoCusto;
    
    //cálculo do custos de reinserção
    for (int i = 1; i < novaSolucao.size(); i++){
        for (int j = 1; j < novaSolucao.size(); j++){
            novoCusto = custoAtual - custos[novaSolucao[i-1]][novaSolucao[i]] - custos[novaSolucao[i]][novaSolucao[i+1]]
                - custos[novaSolucao[j]][novaSolucao[j+1]] + custos[novaSolucao[i-1]][novaSolucao[i+1]]
                    + custos[novaSolucao[j]][novaSolucao[i]] + custos[novaSolucao[i]][novaSolucao[j+1]];
            
            if(novoCusto < custoAtual){
              best_Value = novoCusto;
              best_i = i;
              best_j = j;
            }
        }
    }
    
    //Efetuando a operação de reinserção na melhor posição
    int aux = novaSolucao[best_i];

    for (int i = best_i ; i < best_j; i++){
        
        novaSolucao[i] = novaSolucao[i+1];
    }

    novaSolucao[best_j] = aux;

    return novaSolucao;
}