#include <iostream>
#include <vector>
#include "Swap.cpp"
#include "Opt2.cpp"
#include "ReInsertion.cpp"


// Função para calcular o custo total de uma solução
int calcCusto(std::vector<int> solucao, const std::vector<std::vector<int>>& custos){
  int n = solucao.size();
  int custoSolucao = 0;
  for(int i = 0; i < n; i++){
    custoSolucao += custos[solucao[i]][solucao[i+1]];
  }
  return custoSolucao;
}

// Função VND
std::vector<int> VND(std::vector<int> solucao, const std::vector<std::vector<int>>& custos){
  std::vector<int> novaSolucao;
  int k = 1;
  int custoAtual = 0;
  custoAtual = calcCusto(solucao, custos);
  int novoCusto = 0;
  
  while(k<=3){
      switch (k) {
          case 1:
              novaSolucao = swap(solucao, custos, custoAtual);
              break;
          case 2:
              novaSolucao = Opt2(solucao, int i, int j); // Colocar o outros parametros i e j opt2
              break;
          case 3:
              novaSolucao = ReInsertion(solucao, custoAtual, int i, int j); // Colocar o parametros i e j do ReInsertion
              break;
      }
    
    novoCusto = calcCusto(novaSolucao, custos);
    
    if(novoCusto < custoAtual){
      solucao = novaSolucao;
      custoAtual = novoCusto;
      k = 1;
    }else{
      k++;
    }
  }
  return solucao;
}
