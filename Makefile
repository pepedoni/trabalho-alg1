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


#$(EXEC): main.cpp nave.o tipoitem.o tipocelula.o pilha.o fila.o lista.o pilhaencadeada.o listaencadeada.o filaencadeada.o  
#	$(CC) $(CFLAGS) main.cpp tipoitem.o tipocelula.o nave.o pilha.o fila.o lista.o pilhaencadeada.o listaencadeada.o filaencadeada.o -o $(EXEC)

$(EXEC): ${SRC_DIR}/main.cpp posto.o pessoa.o
	$(CC) $(CFLAGS) ${SRC_DIR}/main.cpp posto.o pessoa.o -o $(EXEC)

pessoa.o: ${HEADERS_DIR}/Pessoa.hpp  ${SRC_DIR}/Pessoa.cpp 
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Pessoa.cpp -o pessoa.o

posto.o: ${HEADERS_DIR}/Posto.hpp  ${SRC_DIR}/Posto.cpp 
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Posto.cpp -o posto.o
 
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf posto.o pessoa.o

clean_windows:
	del posto.o pessoa.o
# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
