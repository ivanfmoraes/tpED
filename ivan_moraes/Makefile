CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult
BUILD = ./build

$(EXEC): src/main.cc list.o
	$(CC) $(CFLAGS) src/main.cc list.o -o $(EXEC)
	mv *.o $(BUILD)

list.o: src/list.cc
	$(CC) $(CFLAGS) -c src/list.cc -o list.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf $(BUILD)/*
	rm -rf tp1