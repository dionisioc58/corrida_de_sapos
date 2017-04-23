/**
* @file	corrida.h
* @brief	Definicao do cabeçalho das funções para implementar uma corrida de sapos
* @author	Dionísio Carvalho (dionisio@naracosta.com.br))
* @since	22/04/2017
* @date	    22/04/2017
*/

#ifndef CORRIDA_H
    #define CORRIDA_H

    #include <iostream>
    using std::cout;
    using std::endl;

    #include <chrono>
    #include <thread>

    #include "sapo.h"

    /**
    * @brief Função que verifica os argumentos passados na chamada do programa.
    *		 Parâmetros devem ser passados com "=". Ex.: -v=100 para alterar a
    *		 velocidade da corrida para 100ms.
    *		 Os possíveis parâmetros são: -v (velocidade); -a (número de atletas);
    *		 -d (tamanho do percurso); -p (salto máximo)
    * @param[in] argc Quantidade de argumentos
    * @param[in] *argv Vetor com os argumentos
    * @param[inout] *v Velocidade da corrida
    * @param[inout] *a Quantidade de atletas
    */
    void verificaOpcoes(int argc, char *argv[], int *v, int *a);

    /**
    * @brief     	Função que exibe os dados gerais de uma corrida
    * @param[in] 	*s Vetor de Sapos (atletas)
    * @param[in]    atletas Quantidade de atletas
    * @param[in]    velocidade Velocidade da corrida
    */
    void showDadosCorrida(Sapo *s, int atletas, int velocidade);

    /**
    * @brief     	Função que executa uma corrida
    * @param[in] 	*s Vetor de Sapos (atletas)
    * @param[in]    qtde Quantidade de atletas
    * @param[in]    velocidade Velocidade da corrida (igual à 0 não exibe a corrida)
    */
    void corrida(Sapo *s, int qtde, int velocidade = 0);

    /**
    * @brief     	Função que imprime o resultado da corrida
    * @param[in] 	*s Vetor de Sapos (atletas)
    */
    void imprimeResultado(Sapo *s);

#endif