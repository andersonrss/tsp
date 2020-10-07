# variável que representa o 'gcc', compilador responsável;
CC = g++

# conjunto de parâmetros de compilação;
CFLAGS = -lm 

# conjunto de arquivos .h que os arquivos .c dependem;
DEPS = util.h    	  	  \
	   types.h   	  	  \
	   heuristics.h   	  \
	   local_search.h	  \
	   route_functions.h  \

# conjunto de arquivos objetos;
OBJ = tsp.o          	 \
	  util.o         	 \
	  heuristics.o   	 \
	  local_search.o 	 \
	  route_functions.o  \

# essa primeira regra diz que arquivos .c dependem de certos arquivos .h;
# aplicada para todos os arquivos que terminam com .c;
# o arquivo .o depende da sua versão .c e dos arquivos .h inclusos na macro DEPS;
# '-c' fala para gerar o arquivo objeto;
# '$<' é o primeiro item da lista de dependências;
# '-o $@' fala para gerar a saída do programa com o nome à esquerda de ':';

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

# essa segunda regra é responsável pela compilação dos arquivos .c;
# colocando os arquivos main.o e operacoes.o na lista de dependências da regra, o makefile saberá que é necessário compilar os arquivos .c individualmente pra depois construir o executável chamado 'main';
# colocando a lista de arquivos que o comando depende depois do ':', o makefile saberá que a regra 'main' precisa ser executada se algum desses arquivos sofrer mudanças; 

tsp: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	@echo 'Cleaning the things...'
	@rm *.o 2> /dev/null
	@rm tsp 2> /dev/null

