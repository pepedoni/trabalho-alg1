# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp01.exe # nome do executavel que sera gerado, nao troque
TMPOUT=./tp01.testresult
HEADERS_DIR = ./headers
SRC_DIR = ./src


$(EXEC): ${SRC_DIR}/main.cpp loja.o cliente.o
	$(CC) $(CFLAGS) ${SRC_DIR}/main.cpp loja.o cliente.o -o $(EXEC)

cliente.o: ${HEADERS_DIR}/Cliente.hpp  ${SRC_DIR}/Cliente.cpp 
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Cliente.cpp -o cliente.o

loja.o: ${HEADERS_DIR}/Loja.hpp  ${SRC_DIR}/Loja.cpp 
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Loja.cpp -o loja.o
 
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf loja.o cliente.o

clean_windows:
	del loja.o cliente.o
# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
