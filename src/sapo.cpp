/**
 * @file	sapo.cpp
 * @brief	Implementacao dos métodos da classe Sapo
 * @author	Dionísio Carvalho (dionisio@naracosta.com.br)
 * @since	22/04/2017
 * @date	22/04/2017
 * @sa      sapo.h
 */

#include <iostream>
using std::cerr;
using std::endl;

#include "../include/sapo.h"

static const char * cores[] = {
    "\x1b[31m",
    "\x1b[32m",
    "\x1b[33m",
    "\x1b[34m",
    "\x1b[35m",
    "\x1b[36m"
};

/**
 * @details Os valores de distancia e pulo sao inicializados com zero 
 *			e o contador de objetos incrementado em uma unidade.
 *          O identificador recebe o contador de objetos.
 */
Sapo::Sapo() {
    id        = ++contador;
    stringstream ss;
    ss.clear();
    ss << nome;
    ss << id;
    ss >> nome;
    nome      = "Sapo " + nome;
    cor       = cores[rand() % 6];//Quantidade de cores
    distancia = 0;
	pulos     = 0;
}

/**
 * @details Os valores de distância e pulos sao recebidos por parâmetro
 *			e o contador de objetos incrementado em uma unidade. 
 *          O identificador recebe o contador de objetos.
 *			O construtor também impede a instanciação de objetos com
 *			valores negativos.
 * @param[in]   n Nome do sapo
 * @param[in]   c Cor do sapo
 * @param[in]   d Valor para a distância
 * @param[in]   p Valor para a quantidade de pulos
 */
Sapo::Sapo(string n, string c, int d, int p) {
    if (d >= 0 && p >= 0) {
        nome = n;
        cor = c;
        distancia = d;
        pulos = p;
    } else {
        cerr << "Valores inválidos" << endl;
    }
    id = ++contador;
}

/**
 * @details Os valores de distância e pulos sao provenientes do objeto
 *			passado por referência e o contador de objetos incrementado
 *			em uma unidade.
 *          O identificador recebe o contador de objetos.
 * @param   s Objeto da classe Sapo do qual os atributos 
 *			serão copiados
 */
Sapo::Sapo(Sapo &s) {
    nome = s.nome;
    cor = s.cor;
    distancia = s.distancia;
    pulos = s.pulos;
    id = ++contador;
}

// Destrutor
Sapo::~Sapo() {
    // Destrutor vazio
}

/**
 * @return Identificador do sapo
 */
int Sapo::getID() {
	return id;
}

/**
 * @return Nome do sapo
 */
string Sapo::getNome() {
	return nome;
}

/**
 * @details O método modifica o nome do sapo para o parâmetro passado
 * @param   n Nome do sapo
 */
void Sapo::setNome(string n) {
    nome = n;
}

/**
 * @return Cor do sapo
 */
string Sapo::getCor() {
	return cor;
}

/**
 * @details O método modifica a cor do sapo para o parâmetro passado
 * @param   c Cor do sapo
 */
void Sapo::setCor(string c) {
    cor = c;
}

/**
 * @return Distância percorrida
 */
int Sapo::getDistancia() {
	return distancia;
}

/**
 * @details O método verifica se o valor passado por parâmetro e válido
 * @param   d Valor para a distância
 */
void Sapo::setDistancia(int d) {
    if (d >= 0) {
    	distancia = d;
    } else {
        cerr << "Valor inválido" << endl;
    }
}

/**
 * @return Quantidade de pulos
 */
int Sapo::getPulos() {
	return pulos;
}

/**
 * @details O método verifica se o valor passado por parâmetro e válido
 * @param   p Valor para a quantidade de pulos
 */
void Sapo::setPulos(int p) {
    if (p >= 0) {
    	pulos = p;
    } else {
        cerr << "Valor inválido" << endl;
    }
}

/**
 * @details Efetua um salto com o sapo. Incrementa distância 
            percorrida de forma randômica entre 1 e o máximo 
            que o sapo pode saltar.
 * @return Distância percorrida
 */
int Sapo::pular() {
    distancia += (rand()%Sapo::maxjump) + 1;
    pulos++;
	return distancia;
}

/**
 * @details Este método e estático e portanto pode ser invocado 
 *			diretamente, sem requerer a instanciação de um objeto 
 *			da classe Sapo
 * @return Numero total de objetos da classe Sapo instanciados
 */
int Sapo::getNumeroObjetos() {
    return contador;
}

/**
 * @details Este método e estático e portanto pode ser invocado 
 *			diretamente, sem requerer a instanciação de um objeto 
 *			da classe Sapo
 * @return Tamanho da corrida
 */
int Sapo::getRunSize() {
    return runsize;
}

/**
 * @details Este método e estático e portanto pode ser invocado 
 *			diretamente, sem requerer a instanciação de um objeto 
 *			da classe Sapo
 * @return Distância máxima que um sapo pode percorrer em um salto
 */
int Sapo::getMaxJump() {
    return maxjump;
}

/**
 * @details Ordena um vetor de Sapo pela distância percorrida decrescente
 * @param[in] *first_arg Primeiro argumento para comparação
 * @param[in] *second_arg Segundo argumento para comparação
 * @return Positivo se second é maior que first. Negativo, caso contrário
 */
int Sapo::sapo_sorter_distancia(const void *first_arg, const void *second_arg) {
    Sapo first = *(Sapo*)first_arg;
    Sapo second = *(Sapo*)second_arg;
    return second.getDistancia() - first.getDistancia();
}