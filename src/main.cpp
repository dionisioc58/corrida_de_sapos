/**
 * @file	main.cpp
 * @brief	Codigo fonte principal do programa
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	22/04/2017
 * @date	22/04/2017
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "../include/sapo.h"
#include "../include/corrida.h"

int Sapo::contador = 0;   /**< Contador para o numero de objetos instanciados */
int Sapo::maxjump  = 10;  /**< Distância máxima que pode ser percorrida em cada salto */
int Sapo::runsize  = 200; /**< Tamanho da corrida */
int numAtletas = 5;		  /**< Quantidade de atletas */
int velocidade = 0;		  /**< Velocidade da corrida (em ms). Valor 0 não exibe a corrida */

/** @brief Funcao principal */
int main(int argc, char *argv[]) {
	
	//Seta opções passadas por parâmetros
	verificaOpcoes(argc, argv, &velocidade, &numAtletas);
	if((numAtletas == 0) || (Sapo::getMaxJump() <= 0) || (Sapo::getRunSize() <= 0)) {
		cout << "Configurações inválidas!" << endl;
		return 0;
	}

	//Inicializa a função rand()
	srand (time(NULL));
    
	//Cria o vetor de Sapos
	Sapo *s = new Sapo[numAtletas];
	
	//Exibe dados da corrida
	showDadosCorrida(s, numAtletas, velocidade);

	int menu = -1;
	while((menu != 1) && (menu != 0)) {
		cout << "Tecle 1 para iniciar a corrida" << endl;
		cout << "Tecle 0 para sair do programa" << endl;
		cin >> menu;
	}
	
	switch(menu) {	
		case 0: //Encerrar o programa
			cout << endl;
			delete[] s;
			return 0;
		case 1:	//Executa a corrida
			corrida(s, Sapo::getNumeroObjetos(), velocidade);
			break;
	}

	//Imprime o resultado da corrida
	imprimeResultado(s);

	delete[] s;
	return 0;
}
