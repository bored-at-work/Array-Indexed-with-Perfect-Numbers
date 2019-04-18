#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct Perfect_Array {
	int length;
	int* arr;
};


//initialize
void init_perfect_array(struct Perfect_Array* a, int size){
	(*a).length = size;
	(*a).arr = (int*)calloc(size, sizeof(int));
}


//verify number passed in is a perfect number
bool check_perfect_number(int x){
	int sum = 1;
	for(int i = 2; i <= floor(sqrt(x)); i++){
		if(x % i == 0){
			sum += i;
			sum += x/i;
		}
	}
	if(sum == x){
		return true;
	}
	return false;
}


//convert perfect number passed into an index
int perfect_number_to_index(int x){
	int count = -1;
	for(int i = 1; i <= x; i++){
		if(i % 2 == 0){
			if(check_perfect_number(i)){
				count++;
			}
		}
	}
	return count;
}


//put integer at specific index
void put(struct Perfect_Array* a, int index, int content){
	if(check_perfect_number(index)){
		index = perfect_number_to_index(index);
	}else{
		printf("%d is not a perfect number \n", index);
		return;
	}

	if(index <= (*a).length-1 && index >= 0){
		int* address = (*a).arr + (sizeof(int)*index);
		*address = content;
	}else{
		printf("%d is not a valid index \n", index);
	}
}


//retrieve integer at specific index
int get(struct Perfect_Array* a, int index){
	if(check_perfect_number(index)){
		index = perfect_number_to_index(index);
	}else{
		printf("%d is not a perfect number \n", index);
		exit(0);
	}

	if(index <= (*a).length - 1 && index >= 0){
		int* address = (*a).arr + sizeof(int)*index;
		return *address;	
	}else{
		printf("%d is not a valid index \n", index);
		exit(0);
	}	
}


//add element to end of array
void append(struct Perfect_Array* a, int content){
	if((*a).length % 10 == 0){
		(*a).arr = realloc((*a).arr, ((*a).length + 10)*sizeof(int));
	}
	int* curr = (*a).arr + (((*a).length)*sizeof(int));
	*curr = content;
	(*a).length = (*a).length + 1;
}


//returns length of the array
int length(struct Perfect_Array* a){
	return (*a).length;
}


//free malloc
void terminate(struct Perfect_Array* a){
	free((*a).arr);
}


/*int main(){
	struct Perfect_Array array;
	int size = 3;
	init_perfect_array(&array, size);
	put(&array, 6, 4);
	put(&array, 496, 1);
	printf("length is %d \n", length(&array));
	append(&array, 12);
	printf("index 0 is %d \n", get(&array, 6));
	printf("index 2 is %d \n", get(&array, 496));
	printf("index 3 is %d \n", get(&array, 8128));
	printf("length is %d \n", length(&array));
	append(&array, 11);
	printf("length is %d \n", length(&array));
	//get(&array, 33550336);
	//get(&array, 14);
	//put(&array, 7, 1);
	terminate(&array);
	return 0;
}*/