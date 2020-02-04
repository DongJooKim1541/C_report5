#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int temp_numbers[MAX + 1];
int Random_result(int number, int count);
void Temp_save(int temp, int number);
void Result(int count, int number);

int main() {

	int number;
	int count = 0;
	printf("25�̻��� ������ �� �Է�: ");
	scanf_s("%d", &number);
	if (number >= 25) {
		Random_result(number, count);
	}
	return 0;
}

int Random_result(int number, int count) {
	int temp;
	int i = 0;
	srand(time(NULL));
	while (i < 100) {
		temp = rand() % (number + 1);
		Temp_save(temp, number);

		if (temp == number) {
			i++;
		}
		count++;
	}
	Result(count, number);
	return 0;
}

void Temp_save(int temp, int number) {
	int i;

	for (i = 0; i < number + 1; i++) {
		if (temp == i) {
			temp_numbers[i]++;
		}
	}
}

void Result(int count, int number) {
	int i;
	for (i = 0; i < number + 1; i++) {
		printf("%2d:%10dȸ\n", i, temp_numbers[i]);
	}
	printf("%d��(��) 100ȸ �߻��ϱ� ���� ���ڸ� �߻���Ų Ƚ���� %dȸ �Դϴ�.\n", number, count);
}

