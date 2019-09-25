#ifndef __CONSTRUCAO_H_
#define __CONSTRUCAO_H_

#include "auxiliar.h"
#include <vector>
using namespace std;

vector<rota_veiculo> Gulosa(double **grafo)
{
    //printf("grafo[0][2]: %f, grafo[3][7]: %f, grafo[11][15]: %f\n", grafo[0][2], grafo[3][7], grafo[11][15]);
    qtdveiculos = 0;
    int count = 0, c, numcliente;
    vector<rota_veiculo> rotas;
    //rotas.push_back(rota_veiculo());
    int countcliente = 1;
    bool *clientes = (bool*)malloc(sizeof(bool)*dimensao);
    //double *chaves = (double*)malloc(sizeof(double)*dimensao);
    //int *pais = (int*)malloc(sizeof(int)*dimensao);
    
    //pais[0] = -1;
    
    for (int i = 0; i < dimensao; i++)
    {
        //chaves[i] = INT_MAX;
        clientes[i] = false;
    }
    //chaves[0] = demanda[0];

    clientes[0] = 1;

    while (countcliente < dimensao)
    {
        rotas.push_back(rota_veiculo());
        //printf("#Rotas: %d\n", rotas.size());
        count = 0;
        //rota_veiculo[count] rotas[qtdveiculos] = (rota_veiculo[count])malloc(sizeof(rota_veiculo[count]));
        //printf("Demanda[0]: %d --- Demanda[3]: %d --- Demanda[7]: %d\n", demanda[0], demanda[3], demanda[7]);
        rotas[qtdveiculos].carga = demanda[0];
        rotas[qtdveiculos].distancia = 0;
        rotas[qtdveiculos].tamanho_percurso = 1;
        rotas[qtdveiculos].percurso.push_back(int());
        //rotas[qtdveiculos].percurso = (int*)realloc(rotas[qtdveiculos].percurso, sizeof(int)*dimensao);

        //int *percorridos = (int*)malloc(sizeof(int)*dimensao);

        rotas[qtdveiculos].percurso[0] = 0;
        //printf("percurso[0] = %d\n", rotas[qtdveiculos].percurso[0]);

        while (rotas[qtdveiculos].carga < capacidade)        
        {
            if (countcliente == dimensao)
            {
                rotas[qtdveiculos].percurso.push_back(int());
                /*printf("grafo[3][5]: %d --- grafo[6][2]: %d --- grafo[11][11]: %d\n",
                grafo[3][5], grafo[6][2], grafo[11][11]);*/
                rotas[qtdveiculos].distancia += grafo[rotas[qtdveiculos].percurso[count]][0];
                count++;
                rotas[qtdveiculos].tamanho_percurso++;
                rotas[qtdveiculos].percurso[count] = 0;
                rotas[qtdveiculos].carga += demanda[0];
                //printf("percurso[%d] = %d\n", count, rotas[qtdveiculos].percurso[count]);
                //Print_Percurso(rotas[qtdveiculos].percurso, rotas[qtdveiculos].tamanho_percurso);
                //printf("Carga: %d --- Distancia: %d\n", rotas[qtdveiculos].carga, rotas[qtdveiculos].distancia);
                return rotas;
            }
            /*printf("grafo[3][5]: %d --- grafo[6][2]: %d --- grafo[11][11]: %d\n",
            grafo[3][5], grafo[6][2], grafo[11][11]);*/
            numcliente = rotas[qtdveiculos].percurso[count];
            count++;
            //printf("numcliente = %d --- count: %d --- rotas[qtdveiculos].percurso[count]: %d --- qtdveiculos: %d --- countcliente: %d\n", numcliente, count, rotas[qtdveiculos].percurso[0], qtdveiculos, countcliente);
            c = BuscaMenor(grafo, numcliente, clientes);
            //printf("c: %d\n", c);
            clientes[c] = true;
            
            /*for (int o = 0; o < dimensao; o++)
                printf("Cliente %d: %d\n", o, clientes[o]);*/
            
            rotas[qtdveiculos].percurso.push_back(int());
            int aux = rotas[qtdveiculos].percurso[count];
            rotas[qtdveiculos].percurso[count] = c;
            //printf("percurso[%d] = %d\n", count, rotas[qtdveiculos].percurso[count]);
            rotas[qtdveiculos].distancia += grafo[c][aux];
            rotas[qtdveiculos].tamanho_percurso++;
            rotas[qtdveiculos].carga += demanda[c];
            //printf("demanda[%d] = %d --- rotas[%d].carga = %d\n", c, demanda[c], qtdveiculos, rotas[qtdveiculos].carga);
            countcliente++;
        }

        rotas[qtdveiculos].percurso.push_back(int());
        rotas[qtdveiculos].distancia += grafo[rotas[qtdveiculos].percurso[count]][0];
        count++;
        rotas[qtdveiculos].tamanho_percurso++;
        rotas[qtdveiculos].percurso[count] = 0;
        rotas[qtdveiculos].carga += demanda[0];
        //rotas.push_back(rota_veiculo());
        //Print_Percurso(rotas[qtdveiculos].percurso, rotas[qtdveiculos].tamanho_percurso);
        qtdveiculos++;
    }

    //return rotas;
}

#endif