
Corrida de Sapos                         {#mainpage}
============

OBJETIVO

Este programa tem o intuito de realizar uma corrida de sapos utilizando a classe criada.

COMPILAÇÃO

Para gerar o binários basta executar o comando "make" no diretório raiz do projeto.

Automaticamente será gerado o arquivo: sapo.exe dentro da pasta bin.

EXECUÇÃO

A execução do aplicativo deve ser, por exemplo: ./bin/sapo.exe

Para alterar alguns parâmetros pode-se fazer uso dos argumentos de linha de comando.

Os argumentos possíveis são: 
-v -> para informar a velocidade da corrida (valor 0 não exibe o andamento da corrida). O valor padrão é 0.
-a -> para informar o número de atletas. O valor padrão é 5.
-d -> para o tamanho do percurso. O valor padrão é 200.
-p -> para a máxima distância percorrida com um único pulo. O valor padrão é 10.

Exemplo:
	./bin/sapo.exe -v=100 -a=5 (para 100ms de velocidade e 5 atletas)

REGRAS

O programa escolhe cores aleatórias para cada competidor e exibe-os na cor selecionada.

O programa também escolhe aleatoriamente qual atleta dá o primeiro pulo. Após o primeiro pulo, todos saltam um após o outro.

Cada atleta executa um salto que percorre uma distância aleatória entre 1m e o máximo selecionado.

O atleta que primeiro alcançar a linha de chegada é declarado vencedor. O resultado com os 3 primeiros lugares, aparecerá em seguida.

