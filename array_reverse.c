/*
 * Write a program in C to read n number of values in an array and display it in reverse order.
 *
 * */
#include<stdio.h>
#include<stdlib.h>

void print_int_array(int *array, int length);
void print_reverse_int_array(int *array, int length);

int main(){

	int *numbers;
	int length, i;

	printf("Please enter array size(1-100) : ");
	scanf("%d", &length);

	if (length < 0 || length > 100){
		printf("Length is out of bound\n");
		return 0;
	}

	// allocate memory for array
	numbers = (int *)malloc(length * sizeof(int));

	for (i = 0; i < length; i++){
		scanf("%d", &numbers[i]);
	}
	
	print_int_array(numbers, length);
	print_reverse_int_array(numbers, length);
	print_int_array(0, 0);

	return 0;
}

void print_int_array(int *array, int length){

	int i;
	if (length <= 0 || array == 0){
		return;
	}
	printf("[");
	for (i = 0; i < length - 1; i++){
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[i]);
}
void print_reverse_int_array(int *array, int length){

        int i;
        if (length <= 0 || array == 0){
                return;
        }
        printf("[");
        for (i = length - 1; i > 0; i--){
                printf("%d, ", array[i]);
        }
        printf("%d]\n", array[i]);
}
