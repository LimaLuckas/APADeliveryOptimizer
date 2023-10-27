#include <iostream>
#include <vector>

// Função para realizar a operação 2-opt em uma solução inicial
std::vector<int> Opt2(const std::vector<int>& solucao, const std::vector<std::vector<int>>& custos, int custoAtual) {
    std::vector<int> novaSolucao = solucao;
    int aux = 0;
    int novoCusto = 0;
    int best_Value = custoAtual;
    int best_i = 0;
    int best_j = 0;

    //Cálculo do melhor custo e intervalo para a nova solução
    for (int i = 1 ; i < solucao.size()-3; i++){  // i só percorre até o (tamanho do vetor) - 3, para evitar movimentos de Swap
        for (int j = i + 3; j < solucao.size(); j++){  // j começa em i+3 para evitar que vire um movimento de Swap

            novoCusto = custoAtual;
            
            //Subtração dos arcos originais que serão retirados
            for (int k = i; k <= j + 1; k++)
            {
                novoCusto = novoCusto - custos[novaSolucao[k-1]][novaSolucao[k]];
            }

            //Soma dos extremos i e j já invertidos
            novoCusto = novoCusto + custos[novaSolucao[i]][novaSolucao[j+1]] + custos[novaSolucao[i-1]][novaSolucao[j]];

            //Soma dos arcos invertidos
            for (int k = j; k > i; k--)
            {
                novoCusto = novoCusto + custos[novaSolucao[k]][novaSolucao[k-1]];
            }
            
            if(novoCusto < custoAtual){
              best_Value = novoCusto;
              best_i = i;
              best_j = j;
            }          
        }
    }

    // Inverte os elementos entre i e j
    while (best_i < best_j)
    {
        aux = novaSolucao[best_j];
        novaSolucao[best_j] = novaSolucao[best_i];
        novaSolucao[best_i] = aux;
        best_i++;
        best_j--;
    }
    
    
    return novaSolucao;
}