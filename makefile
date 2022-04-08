CFLAGS= -Wall -Werror

all: cliente

cliente: cliente.c lista_com_cabeca.o pilha.o 
	gcc $^ -o $@

%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o cliente