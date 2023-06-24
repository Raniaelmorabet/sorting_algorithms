CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -I.

all: 0

0:
	$(CC) $(FLAGS) 0-bubble_sort.c tests/0-main.c tests/print_array.c -o bubble

1:
	$(CC) $(FLAGS) 1-insertion_sort_list.c tests/1-main.c tests/print_list.c -o insertion

clean:
	rm -f bubble insertion

re: clean all
