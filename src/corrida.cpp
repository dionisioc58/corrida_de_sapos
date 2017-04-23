/**
* @file	    corrida.cpp
* @brief	Definicao do corpo das funções para implementar uma corrida de sapos
* @author	Dionísio Carvalho (dionisio@naracosta.com.br))
* @since	22/04/2017
* @date	    22/04/2017
*/

#include "../include/corrida.h"
#include "../include/sapo.h"

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
void verificaOpcoes(int argc, char *argv[], int *v, int *a) {
    for(int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
		string arg;
		string val;
		getline(ss, arg, '=');
		getline(ss, val);
		
		if(val != "") {
			if(arg == "-v")		//Velocidade
				*v = atoi(val.c_str());
			if(arg == "-a")		//Número de atletas
				*a = atoi(val.c_str());
			if(arg == "-d") 	//Tamanho do percurso
				Sapo::runsize = atoi(val.c_str());
			if(arg == "-p")		//Salto máximo
				Sapo::maxjump = atoi(val.c_str());
		}
	}
}

/**
* @brief     	Função que exibe os dados gerais de uma corrida
* @param[in] 	*s Vetor de Sapos (atletas)
* @param[in]    atletas Quantidade de atletas
* @param[in]    velocidade Velocidade da corrida
*/
void showDadosCorrida(Sapo *s, int atletas, int velocidade) {
    cout << string(50, '\n'); //Limpa a tela
	cout << endl << "==========Corrida de Sapos==========" << endl;
	cout << "Tamanho do percurso: " << Sapo::runsize << " m" << endl;
	if(velocidade > 0)
        cout <<  "Velocidade da corrida: " << velocidade << " ms" << endl;
    else
        cout << "Não exibir a corrida" << endl;
    cout << "Salto máximo para cada atleta: " << Sapo::getMaxJump() << " m" << endl;
	cout << "Quantidade de atletas inscritos: " << Sapo::getNumeroObjetos() << endl;
    cout << "----------------------------" << endl;
	
	for(int i = 0; i <atletas; i++) {
		cout << "---- " << (i + 1) << "º competidor: " << s[i].getCor() << s[i].getNome() << "\x1b[0m" << endl;
	}
	cout << "----------------------------" << endl;
}

/**
* @brief     	Função que executa uma corrida
* @param[in] 	*s Vetor de Sapos (atletas)
* @param[in]    qtde Quantidade de atletas
* @param[in]    velocidade Velocidade da corrida (igual à 0 não exibe a corrida)
*/
void corrida(Sapo *s, int qtde, int velocidade) {
	bool i = true;
    int ini = rand()%qtde;//Escolhe um número aleatório para ser o primeiro sapo à saltar
	while(i) {
		if(velocidade <= 0) { //Não exibe a corrida
			for(int j = ini; j < qtde; j++) {
				if(s[j].pular() >= Sapo::getRunSize()) {
					i = false;
					break;
				}
			}
		} else { //Exibe a corrida
			cout << string(50, '\n'); //Limpa a tela

			for(int j = ini; j < qtde; j++) { //A primeira rodada é iniciada por um competidor aleatório
				
                if(i) s[j].pular(); //Só pular se ainda estiver competindo. Caso contrário, só preencher o grid.
				
                cout << s[j].getCor() << s[j].getNome() << ": ";
				for(int k = 0; k < (s[j].getDistancia()*40/Sapo::getRunSize()); k++) //40 é uma medida razoável para não preencher a tela horizontalmente
					cout << "=";
				cout << " " << s[j].getDistancia() << "m";
				cout << "\x1b[0m" << endl;//Cor reset

				if(s[j].getDistancia() >= Sapo::getRunSize())
					i = false;  //Alguém ganhou. Encerrar a corrida após a rodada completar
			}
        
			cout << "------------------------------------" << endl;
			
            //Aguardar um tempo em milissegundos
            std::chrono::milliseconds dura(velocidade);
    		std::this_thread::sleep_for(dura);
		}
		ini = 0; //Zera ini para que todas as próximas rodadas sejam iniciadas pelo primeiro
	}
}

/**
* @brief     	Função que imprime o resultado da corrida
* @param[in] 	*s Vetor de Sapos (atletas)
*/
void imprimeResultado(Sapo *s) {
	int qtde = Sapo::getNumeroObjetos();
	qsort(s, qtde , sizeof(Sapo), Sapo::sapo_sorter_distancia); //Ordena o vetor de sapos em ordem decrescente da distância percorrida

    cout << endl << "Resultado:" << endl << endl;
	
    for(int i = 0; (i < qtde && i < 3); i++) { //Imprime apenas os 3 primeiros lugares
		cout << (i + 1) << "º lugar: " << s[i].getCor() << "'";
		cout << s[i].getNome() << "'" << "\x1b[0m" << " com " << s[i].getPulos() << " pulos " << "e " << s[i].getDistancia() << " metros percorridos.";
		cout << "\x1b[0m" << endl;//Cor reset
	}
	cout << endl;
}