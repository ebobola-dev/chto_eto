#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b, h, cont = 1;
	do {
		printf("������� ������� � ���(a b h): ");
		scanf("%d%d%d", &a, &b, &h);

		printf(" x y\n");
		for (a; a <= b; a+=h) {
			printf(" %d %d\n", a, a * a);
		}
		printf("������� 1, ����� ����������: ");
		scanf("%d", &cont);
		printf("\n");
	} while (cont == 1);
	return 0;
}