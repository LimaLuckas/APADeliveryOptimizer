#include <iostream>
#include <vector>
// Feito considerando o vetor contendo o vertice inicial na primeira e na ultima posição do vetor

std::vector<int> swap(const std::vector<int>& solucao, const std::vector<std::vector<int>>& custos, int custoAtual) {
  
    std::vector<int> ns = solucao; // Cria uma cópia da solução original, ns = novaSolucao   ***analisar se vale a pena deixar essa linha***
    
    int n = solucao.size();
    int novocusto = 0;
    int best_Value = custoAtual;
    int best_i = 0;
    int best_j = 0;
  
  for(int i = 0; i < n - 1; i++){
       for(int j = i + 1; j < n-1; j++){
          novocusto = custoAtual - (custos[ns[i]][ns[i+1]] - custos[ns[i+1]][ns[i+2]] - 
            custos[ns[j]][ns[j+1]] - custos[ns[j+1]][ns[j+2]]) + (custos[ns[i]][ns[j+1]] + 
            custos[ns[j+1]][ns[i+2]] + custos[ns[j]][ns[i+1]] + custos[ns[i+1]][ns[j+2]]); 
          if(best_Value > novocusto){
              best_Value = novocusto;
              best_i = i;
              best_j = j;
          }          
       } 
    }
  
  int aux = ns[best_i];
  ns[best_i] = ns[best_j];
  ns[best_j] = aux;
  
    return ns;
}
