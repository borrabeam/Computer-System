
FLAGS = -Wall -pthread
INCLUDES = ../include

all: t0 t1 final

clean:
	rm -f t0 t1 last

	
t0: t0.c
	gcc -I $(INCLUDES) -o t0 t0.c $(FLAGS)

t1: t1.c
	gcc -I $(INCLUDES) -o t1 t1.c $(FLAGS)

final: final.c
	gcc -I $(INCLUDES) -o final final.c $(FLAGS)
