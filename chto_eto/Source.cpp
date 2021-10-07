#include <stdio.h>
#include <locale.h>

#define ROUND_COUNT 2

#define VER				2995 // │
#define HOR				2500 //  ─
#define TOP_LEFT		2522 // ┌
#define TOP_CENTER		2754 //  ┬
#define TOP_RIGHT		3263 // ┐
#define BOTTOM_LEFT		3264 //  └
#define BOTTOM_CENTER	2753 // ┴
#define BOTTOM_RIGHT	2521 //  ┘
#define LEFT_SIDE		3267 // ├
#define CENTER			2501 //  ┼
#define RIGHT_SIDE		2484 // ┤

int number_len(int number);
void print_line(char symbol, int len);

int main() {
	float a, b, h, max;
	int max_size, kol, cont = 1;
	
	do {
		setlocale(LC_ALL, "Rus");
		do {
			int ch;
			printf("Введите границы и шаг (a b h): ");
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
		max_size++;

		setlocale(LC_ALL, "C");

		// Верхняя линия шапки
		printf("\n");
		printf("%c", TOP_LEFT);
		print_line(HOR, max_size);
		printf("%c", TOP_CENTER);
		print_line(HOR, max_size);
		printf("%c", TOP_RIGHT);
		printf("\n");

		// Центр шапки
		printf("%c", 2483);
		printf("%*c%c%*c", max_size, 'x', 2483, max_size, 'y');
		printf("%c\n", 2483);

		// Нижняя линия шапки
		printf("%c", LEFT_SIDE);
		print_line(HOR, max_size);
		printf("%c", CENTER);
		print_line(HOR, max_size);
		printf("%c", RIGHT_SIDE);
		printf("\n");
		
		if (max == b){
			for (a; a <= b; a += h) {
					printf("%c", 2483);
					printf("%*.*f%c%*.*f", max_size, ROUND_COUNT, a, VER, max_size, ROUND_COUNT, a * a);
					printf("%c\n", 2483);

				// Линия под числами
				if (a != b && a + h <= b) {
					printf("%c", LEFT_SIDE);
					print_line(HOR, max_size);
					printf("%c", CENTER);
					print_line(HOR, max_size);
					printf("%c", RIGHT_SIDE);
				}
				else {
					printf("%c", BOTTOM_LEFT);
					print_line(HOR, max_size);
					printf("%c", BOTTOM_CENTER);
					print_line(HOR, max_size);
					printf("%c", BOTTOM_RIGHT);
				}
				printf("\n");
			}
		}
		else {
			for (a; a >= b; a -= h) {
				printf("%c", 2483);
				printf("%*.*f%c%*.*f", max_size, ROUND_COUNT, a, VER, max_size, ROUND_COUNT, a * a);
				printf("%c\n", 2483);

				// Линия под числами
				if (a != b && a - h >= b) {
					printf("%c", LEFT_SIDE);
					print_line(HOR, max_size);
					printf("%c", CENTER);
					print_line(HOR, max_size);
					printf("%c", RIGHT_SIDE);
				}
				else {
					printf("%c", BOTTOM_LEFT);
					print_line(HOR, max_size);
					printf("%c", BOTTOM_CENTER);
					print_line(HOR, max_size);
					printf("%c", BOTTOM_RIGHT);
				}
				printf("\n");
			}
		}

		setlocale(LC_ALL, "Rus");
		cont = 0;
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