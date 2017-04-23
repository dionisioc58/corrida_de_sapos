/**
 * @file	sapo.h
 * @brief	Definicao da classe Sapo, que representa um sapo
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br))
 * @since	22/04/2017
 * @date	22/04/2017
 */

#ifndef SAPO_H
#define SAPO_H

#include <iostream>
using std::stringstream;
#include <sstream>

#include <string>
using std::string;

/**
 * @class   Sapo sapo.h
 * @brief   Classe que representa um sapo
 * @details Os atributos de um sapo são o identificador, a distância percorrida e a quantidade de pulos
 */  
class Sapo {
	private:
		int id;		   /**< ID do sapo */
		string nome;   /**< Nome do sapo */
		string cor;	   /**< Cor do sapo */
		int distancia; /**< Distância que percorre em cada pulo */
		int pulos;     /**< Quantidade de pulos */
	
	public:
        static int contador;            		/**< Contador para o numero de objetos instanciados */
		static int maxjump;						/**< Distância máxima que um sapo pode percorrer em um salto */
		static int runsize;						/**< Tamanho da corrida */

		Sapo();                    				/**< Construtor padrao */
        Sapo(string n, string c, int d, int p);	/**< Construtor parametrizado */
        Sapo(Sapo& r);        					/**< Construtor copia */
        ~Sapo();	                    		/**< Destrutor */

		int getID();               				/**< Retorna o identificador */ 
		string getNome();          				/**< Retorna o nome */ 
		void setNome(string n);    				/**< Modifica o nome */
		string getCor();          				/**< Retorna a cor */ 
		void setCor(string c);    				/**< Modifica a cor */
		int getDistancia();             		/**< Retorna o valor da distância percorrida */
		void setDistancia(int d);       		/**< Modifica o valor da distância percorrida */
		int getPulos();         	    		/**< Retorna o valor da quantidade de pulos */
		void setPulos(int p);	        		/**< Modifica o valor da quantidade de pulos */
		int pular();							/**< Efetua um salto e retorna a distância percorrida*/
		
		static int getNumeroObjetos();  		/**< Retorna o numero de objetos instanciados */
		static int getRunSize();				/**< Retorna o tamanho da corrida */
		static int getMaxJump();				/**< Retorna a distância máxima que um sapo pode percorrer em um salto */
		static int sapo_sorter_distancia(const void *first_arg, const void *second_arg); /**< Ordena um vetor de Sapo pela distancia percorrida decrescente */
};

#endif
