#include <stdio.h>
#include <stdlib.h>


struct Perfect_Array {
	int length;
	int* arr;
};


//initialize
void init_perfect_array(struct Perfect_Array* a, int size){
	(*a).length = size;
	(*a).arr = (int*)malloc(sizeof(int)*size);
	int* curr = (*a).arr;
	//initialize array elements to 0
	for(int i = 0; i < size; i++){
		curr = curr + sizeof(int)*i;
		*curr = 0;
	}
}


//verify number passed in is a perfect number
bool check_perfect_number(int x){
	int divisors[(x/2)+1];
}


//convert perfect number passed into an index
int perfect_number_to_index(int x){

}


//put integer at specific index
void put(struct Perfect_Array* a, int index, int content){
	if(index <= (*a).length-1 && index >= 0){
		int* address = (*a).arr + (sizeof(int)*index);
		*address = content;
	}else{
		printf("%d is not a valid index \n", index);
	}
}


//retrieve integer at specific index
int get(struct Perfect_Array* a, int index){
	if(index <= (*a).length - 1 && index >= 0){
		int* address = (*a).arr + sizeof(int)*index;
		return *address;	
	}else{
		printf("%d is not a valid index \n", index);
		exit(0);
	}	
}


//add element to end of array
void append(struct Perfect_Array* a, content){

}


//returns length of the array
int length(struct Perfect_Array* a){
	return (*a).length;
}


//free malloc
void terminate(struct Perfect_Array* a){
	free((*a).arr);
}


int main(){
	struct Perfect_Array array;
	int size = 10;
	init_perfect_array(&array, size);
	terminate(&array);
	return 0;
}