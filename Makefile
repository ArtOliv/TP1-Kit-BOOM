PC = gcc
EXECUTAVEL = kitBoom
OBJ = main.o in_out.o kit.o
INTERFACE = Interface_kit/kit.h
CAMINHO = ./Entrada_saida/Arquivos_entrada/

all: $(OBJ)
	$(PC) $(OBJ) -o $(EXECUTAVEL)

main.o: Main/main.c $(INTERFACE)
	$(PC) -c Main/main.c

in_out.o: Entrada_saida/in_out.c $(INTERFACE)
	$(PC) -c Entrada_saida/in_out.c

kit.o: Configuracao_kit/kit.c $(INTERFACE)
	$(PC) -c Configuracao_kit/kit.c

clean:
	rm *.o
	rm $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL) -a $(CAMINHO)composicao.txt -b $(CAMINHO)configuracao.txt