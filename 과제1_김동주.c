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
	printf("25이상의 임의의 수 입력: ");
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
		printf("%2d:%10d회\n", i, temp_numbers[i]);
	}
	printf("%d이(가) 100회 발생하기 위해 숫자를 발생시킨 횟수는 %d회 입니다.\n", number, count);
}

