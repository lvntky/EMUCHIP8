INCLUDES = -I ./includes
FLAGS = -g
all:
	gcc $(FLAGS) $(INCLUDES) ./src/main.c -o ./bin/main