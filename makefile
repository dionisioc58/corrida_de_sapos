#Makefile for "Laboratorio 01" C++ aplication
#Created by Dionísio Carvalho & Daniel Oliveira

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: sapo doxy
debug: CFLAGS += -g -O0
debug: sapo

# Alvo (target) para a construcao do executavel sapo.exe
# Define os arquivos sapo.o, corrida.o e main.o como dependencias
sapo: $(OBJ_DIR)/sapo.o $(OBJ_DIR)/corrida.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@.exe $^
	@echo "+++ [Executavel sapos.exe criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto sapo.o
# Define os arquivos sapo.cpp e sapo.h como dependencias.
$(OBJ_DIR)/sapo.o: $(SRC_DIR)/sapo.cpp $(INC_DIR)/sapo.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto corrida.o
# Define os arquivos corrida.cpp e corrida.h como dependencias.
$(OBJ_DIR)/corrida.o: $(SRC_DIR)/corrida.cpp $(INC_DIR)/corrida.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*.exe
	$(RM) $(OBJ_DIR)/*.o
