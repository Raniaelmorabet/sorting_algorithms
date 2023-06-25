CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -I.

all: 0

0:
	$(CC) $(FLAGS) 0-bubble_sort.c tests/0-main.c tests/print_array.c -o bubble

1:
	$(CC) $(FLAGS) 1-insertion_sort_list.c tests/1-main.c tests/print_list.c -o insertion

2:
	$(CC) $(FLAGS) 2-selection_sort.c tests/2-main.c tests/print_array.c -o selection

3:
	$(CC) $(FLAGS) 3-quick_sort.c tests/3-main.c tests/print_array.c -o quick

100:
	$(CC) $(FLAGS) 100-shell_sort.c tests/100-main.c tests/print_array.c -o shell

101:
	$(CC) $(FLAGS) 101-cocktail_sort_list.c tests/101-main.c tests/print_list.c -o cocktail

102:
	$(CC) $(FLAGS) 102-counting_sort.c tests/102-main.c tests/print_array.c -o counting

103:
	$(CC) $(FLAGS) 103-merge_sort.c tests/103-main.c tests/print_array.c -o merge

104:
	$(CC) $(FLAGS) 104-heap_sort.c tests/104-main.c tests/print_array.c -o heap

105:
	$(CC) $(FLAGS) 105-radix_sort.c tests/105-main.c tests/print_array.c -o radix

106:
	$(CC) $(FLAGS) 106-bitonic_sort.c tests/106-main.c tests/print_array.c -o bitonic

107:
	$(CC) $(FLAGS) 107-quick_sort.c tests/107-main.c tests/print_array.c -o quick_2

1000:
	$(CC) $(FLAGS) 1000-sort_deck.c tests/1000-main.c -o deck

clean:
	rm -f bubble insertion selection quick shell cocktail counting merge heap radix bitonic quick_2 deck

re: clean all
