#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int partiton(int list[], int left, int right,int* move_count, int* compare_count, int print) {
	int pivot;
	int temp = 0;
	int low, high;

	low = left;
	high = right + 1;

	pivot = list[left];

	do {
		do {
			low++;
			(*compare_count)++;
		} while (low <= right && list[low] < pivot);
		do {
			high--;
			(*compare_count)++;
		} while (high > left && list[high] > pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp);
			(*move_count)++;
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	(*move_count)++;

	if (print == 1) {
		for (int i = 0; i < MAX_SIZE; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	}

	return high;
}

void quick_sort(int list[], int left, int right,int* move_count, int* compare_count, int print) {
	if (left < right) {
		int q = partiton(list, left, right, move_count, compare_count, print);
		quick_sort(list, left, q - 1,move_count, compare_count,print);
		quick_sort(list, q + 1, right,move_count,compare_count,print);
	}
}

int main()
{
	int list[MAX_SIZE] = { 0 };
	int move[MAX_SIZE] = { 0 };
	int compare[MAX_SIZE] = { 0 };

	int n = MAX_SIZE;
	int move_count = 0;
	int compare_count = 0;
	double move_average = 0;
	double compare_average = 0;

	// 난수 리스트 생성
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100;
	}

	printf("Original List\n");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("Quick Sort\n");

	quick_sort(list, 0, n - 1, &move_count,&compare_count,1);
	move[0] = move_count;
	compare[0] = compare_count;

	for (int i = 1; i < MAX_SIZE; i++) {
		move_count = 0;
		compare_count = 0;
		
		// 난수 리스트 생성
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = rand() % 100;
		}

		quick_sort(list, 0, n - 1, &move_count, &compare_count, 0);
		move[i] = move_count;
		compare[i] = compare_count;
	}
	printf("Move Average : %f\n", move_average);
	printf("Compare Average : %f\n", compare_average);

}