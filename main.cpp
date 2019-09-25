#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <vector>


#include "auxiliar.h"
#include "leitura_normal.h"
#include "leitura_cvrp.h"
#include "gulosa.h"
#include "refinamento.h"
#include "VND.h"
#include "ILS.h"

using namespace std;

int main()
{
    qtdveiculos = 0;
    FILE *arq, *teste; //Variável que receberá o endereço do arquivo caso esse seja aberto sem dificuldades
    int tamanho = INT_MAX/3;
    
    Leitura_Normal(arq, "P-n50-k10.txt");
    //Leitura_CVRP(arq, "cvrp1.txt");
    //printf("Debug\n");
    /*teste = fopen("teste.txt" , "w+");

    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
        {
            if (j < dimensao - 1)
                fprintf(teste, "%.0f  ", matriz[i][j]);
            else
            {
                fprintf(teste, "%.0f\n", matriz[i][j]);
            }
            
        }
    }
    fclose(teste);*/
    vector<rota_veiculo> solucao_incial = Gulosa(matriz);


    /*for (int i = 0; i <= qtdveiculos; i++)
    {
        printf("Veiculo (Gulosa):%d\nDistancia percorrida pelo veiculo: %.0f --- Carga do veiculo: %d\n",
         i, solucao_incial[i].distancia, solucao_incial[i].carga);
        Print_Percurso(solucao_incial[i].percurso, solucao_incial[i].tamanho_percurso);
    }*/

    printf("------------------------\nGulosa terminada\n------------------------\n");

    /*vector<rota_veiculo> solucao_VND = VND(solucao_incial, matriz);

    for (int i = 0; i <= qtdveiculos; i++)
    {
        printf("Veiculo (VND):%d\nDistancia percorrida pelo veiculo: %.0f --- Carga do veiculo: %d\n",
         i, solucao_VND[i].distancia, solucao_VND[i].carga);

        Print_Percurso(solucao_VND[i].percurso, solucao_VND[i].tamanho_percurso);
    }*/

    vector<rota_veiculo> solucao_final = IlsMetaheuristica(matriz, solucao_incial, 10000);
    
    for (int i = 0; i <= qtdveiculos; i++)
    {
        printf("Veiculo (ILS):%d\nDistancia percorrida pelo veiculo: %.0f --- Carga do veiculo: %d\n",
         i, solucao_final[i].distancia, solucao_final[i].carga);

        Print_Percurso(solucao_final[i].percurso, solucao_final[i].tamanho_percurso);
    }


    printf("Deu certo!\n");
    //abrindo o arquivo


    //fclose(arq);
    return 0;
}
