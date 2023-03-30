#include <iostream>

using namespace std;

struct entrega
{
    int tempo;
    int quantPizzas;
};

int main() {

    int quantMaxPizzas; // quantidade de pedidos
    int quantPedidos; // vetor de entregas

    int pd[100][100]; // valor máximo de pizzas sendo 100
	// olhando do item 'i'-> final
	// olhando uma mochila de capacidade 'j'
	
    int caminho[100][100]; // utilizado para recuperar quais itens foram escolhidos
	// 0 nao pegar o item
	// 1 pegar o item
	
    entrega v[100]; 


    cin >> quantMaxPizzas; // quantidade de pizzas
    cin >> quantPedidos; 

    for (int i = 0; i < quantPedidos; i++) {
        cin >> v[i].tempo >> v[i].quantPizzas;
    }

    // inicializacao:
    // casos base

    for(int i = 0; i <= quantMaxPizzas; i++)
        pd[quantPedidos][i] = 0;

    for(int i = 0; i <= quantPedidos; i++)
        pd[i][0] = 0;

    // programacao dinamica:
    // caso geral

    for(int i = quantPedidos - 1; i >= 0; i--)
		for(int j = 1; j <= quantMaxPizzas; j++)
		{
			int pega, npega; 
			
			npega = pd[i + 1][j];

			if(j >= v[i].quantPizzas) 
				pega = pd[i + 1][j - v[i].quantPizzas] + v[i].tempo;
		
			else
				pega = 0; 

			
			if(pega > npega) 
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}
			
			else 
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
		}
     // recuperando o tempo
    int i, j;
	i = 0;
	j = quantMaxPizzas;
    int tempoFinal = 0;
	
	while(i != quantPedidos){ 
		if(caminho[i][j] == 0) 
			i++;
		
		else 
		{
			tempoFinal += v[i].tempo;
			j-= v[i].quantPizzas; 
		}
	}

    cout << "Tempo: " << tempoFinal << " min." << endl;

    return 0;
}
