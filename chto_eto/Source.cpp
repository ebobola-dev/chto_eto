#include <stdio.h>
#include <locale.h>

int number_len(int number);
void print_line(char symbol, int len);

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, h, max, max_size, kol, cont = 1;

	do {
		do {
			int ch;
			printf("Введите границы и шаг(a b h): ");
			kol = scanf("%d%d%d", &a, &b, &h);
			while (ch = getchar() != '\n');
		} while (kol < 3);

		while (1) {
			max = a > b ? a : b;
			if (h != 0 && (max == a && h < 0 || max == b && h > 0)) break;
			if (h == 0) {
				printf("Шаг не может быть равен 0!\n");
				do {
					int ch;
					
					printf("Введите шаг заново: ");
					kol = scanf("%d", &h);
					while (ch = getchar() != '\n');
				} while (kol < 1);
			}
			if (max == a && h > 0) {
				printf("Нельзя двигаться назад с положительным шагом!\nВведите данные заново\n");
				do {
					int ch;
					printf("Введите границы и шаг(a b h): ");
					kol = scanf("%d%d%d", &a, &b, &h);
					while (ch = getchar() != '\n');
				} while (kol < 3);
			}
			if (max == b && h < 0) {
				printf("Нельзя двигаться вперед с отрицательным шагом!\nВведите данные заново\n");
				do {
					int ch;
					printf("Введите границы и шаг(a b h): ");
					kol = scanf("%d%d%d", &a, &b, &h);
					while (ch = getchar() != '\n');
				} while (kol < 3);
			}
		}
		max = a > b ? a : b;
		printf("\n");
		max_size = number_len(max * max);
		max_size = max_size > 2 ? max_size : 3;
		print_line('-', max_size * 2 + 3);
		printf("\n");
		printf("|%*c|%*c|\n", max_size, 'x', max_size, 'y');
		print_line('-', max_size * 2 + 3);
		printf("\n");
		for (a; h > 0 ? a <= b : a >= b; a += h) {
			printf("|%*d|%*d|\n", max_size, a, max_size, a * a);
			print_line('-', max_size * 2 + 3);
			printf("\n");
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
	return len;
}

void print_line(char symbol, int len) {
	for (int i = 0; i < len; i++) printf("%c", symbol);
}