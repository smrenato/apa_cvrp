#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib.h" //



int main(int argc, char * argv[])
{
    FILE *arq; //Variável que receberá o endereço do arquivo caso esse seja aberto sem dificuldades
    int count, dimensao = 0, veiculos, capacidade, temp = 0;//Contador para pegar os dados de dimensão, veículos e capacidade do arquivo
    char Linha[100], *strDimensao, *strVeiculos, *strCapacidade, *result;//Buffer que terá a linha do arquivo a cada vez no loop, e ponteiros que receberão os dados do arquivo que serão em string.
    int linha = 0, coluna = 0, num_linha=0;
    int **matriz;

    //abrindo o arquivo
    arq = fopen("P-n16-k8.txt", "r"); 
    if(arq == NULL) //verificando se tudo ocorreu corretamente
    {
       puts("Problemas em abrir o arquivo\n");
        return 0;
    }
    //leitura do arquivo e imprimi-lo todo na tela
    count = 0;
    while (!feof(arq))
    {
        fgets(Linha, 100, arq);//ler linha a linha
        Linha[strlen(Linha) - 1] = '\0';
       
        //guardar as variáveis de dimensão. veículos e capacidade
        count++;
        if(count == 2)//Caso esteja na segunda linha
        {
            strDimensao = strchr(Linha, ' '); //
            strDimensao++; 
            dimensao = atoi(strDimensao); //transforme essa string em inteiro
            matriz = (int**)malloc(sizeof(int*)*dimensao);
        
        }
        if(count == 3)//Caso esteja na terceira linha
        {
            strVeiculos = strchr(Linha, ' ');
            strVeiculos++;
            veiculos = atoi(strVeiculos);
        }
        if (count == 4)//Caso esteja na quarta linha
        {
            strCapacidade = strchr(Linha, ' ');
            strCapacidade++;
            capacidade =  atoi(strCapacidade);
        }
        

        if(count > 5){
            //tratando os espaços
            
            char *token;
            token = strtok(Linha, " ");
            matriz[num_linha++] = (int*)malloc(sizeof(int)*dimensao);

            while(token != NULL)
            {
                //percorre a linha pesquisando cada número
                
                matriz[linha][coluna] = atoi(token); //guarda os números como inteiros na matriz
              
                token = strtok(NULL, " ");
         
                coluna++;
            }
            linha++; //pulando pra próxima linha da matriz a ser preenchida
        }
        coluna = 0;//voltando para 1º coluna quando começar a atribuição na matriz da nova linha

    }

    fclose(arq);
    return 0;
}
