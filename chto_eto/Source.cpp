#include <stdio.h>
//#include <locale.h>

#define ROUND_COUNT 2
#define HOR_SYMBOL '─'
#define VER_SYMBOL '│'

int number_len(int number);
void print_line(char symbol, int len);

int main() {
	//setlocale(LC_ALL, "Rus");
	float a, b, h, max;
	int max_size, kol, cont = 1;
	
	do {
		do {
			int ch;
			printf("Введите границы и шаг(a b h): ");
			kol = scanf("%f%f%f", &a, &b, &h);
			while (ch = getchar() != '\n');
		} while (kol < 3);

		max = a > b ? a : b;

		while (1) {
			if (h > 0) break;
			printf("Шаг должен быть положительным!\n");
			do {
				int ch;
				printf("Введите шаг заново: ");
				kol = scanf("%f", &h);
				while (ch = getchar() != '\n');
			} while (kol < 1);
		}

		max_size = number_len(max * max);
		max_size = max_size > 2 ? max_size : 3;

		printf("\n");
		print_line(HOR_SYMBOL, max_size * 2 + 3);
		printf("\n");
		printf("|%*c|%*c|\n", max_size, 'x', max_size, 'y');
		print_line(HOR_SYMBOL, max_size * 2 + 3);
		printf("\n");
		
		if (max == b){
			for (a; a <= b; a += h) {
				printf("|%*.*f|%*.*f|\n", max_size, ROUND_COUNT, a, max_size, ROUND_COUNT, a * a);
				print_line(HOR_SYMBOL, max_size * 2 + 3);
				printf("\n");
			}
		}
		else {
			for (a; a >= b; a -= h) {
				printf("|%*.*f|%*.*f|\n", max_size, ROUND_COUNT, a, max_size, ROUND_COUNT, a * a);
				print_line(HOR_SYMBOL, max_size * 2 + 3);
				printf("\n");
			}
		}

		printf("\nВведите 1, чтобы продолжить: ");
		scanf("%d", &cont);
		printf("\n");
	} while (cont == 1);
	return 0;
}

int number_len(int number) {
	if (number < 0) number *= -1;
	int len = 0;
	while (number > 0) {
		len++;
		number /= 10;
	}
	return len + ROUND_COUNT + 2;
}

void print_line(char symbol, int len) {
	for (int i = 0; i < len; i++) printf("%c", symbol);
}