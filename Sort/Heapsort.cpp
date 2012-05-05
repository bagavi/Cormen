#include <malloc.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Heapsort {
int size ;
private:
	//All private members here
protected:
	//All protected members here
public:
	Heapsort() {
        //constructor
    }

    void sort( int arr[] , int size1){
    	size = size1 ;
    	int i, temp ;
    	int size_2 = size ;
    	printf("Intial Array\n") ;
    	print_array(arr);
    	build_heap(arr ,size) ;
    	printf("Heaped Array\n") ;
    	print_array(arr);
    	for( i = 0 ; i < size ; i++){
    		temp = arr[size - 1 -i] ;
    		arr[size - 1 -i] = arr[0] ;
    		arr[0] = temp ;
    		size_2 -- ;
    		build_heap(arr , size_2);
    	}
    	printf("Final Array\n") ;
    	print_array(arr);
    }

    /*
     * Heapifies Arr[i] ie, it swaps the numbers to heapify the Arr[i] and below section
     */
    void max_heapify( int arr[] , int i , int size){
    	int l = 2*(i+1) - 1 ;
    	int r = 2*(i+1) ;
    	int largest = i ;
    	if(l<size && arr[l] > arr[largest]){
    		largest = l ;
    	}
    	if(r<size && arr[r] > arr[largest]){
    		largest = r ;
    	}

    	if(largest!=i){
    		int temp	= arr[i] ;
    		arr[i]		= arr[largest] ;
    		arr[largest]= temp ;
    		max_heapify(arr , largest, size) ;
    	}
    }

    /*
     * Builds the heap - All the elements satisfy the heap property
     */
    void build_heap(int arr[] , int size){
    	int i ;
    	for ( i = size/2 ; i >=0 ; i--){
    		max_heapify(arr,i,size);
    	}
    }

    int heap_extract_max(int arr[]){
    	int max = arr[0];
    	size--;
    	arr[0] = arr[size] ;
    	arr[size] = max ;
    	printf("The current max is %d" ,max) ;
    	max_heapify(arr,0,size) ;
    	return max ;
    }
    /*
     * Prints out the array in a single line and adds "\n"
     */
    void print_array(int arr[] ){
    	int i;
    	for( i=0 ; i<size ; i++){
    		printf(" %d",arr[i]);
    	}
    	printf("\n");
    }

};

int main()
{
	Heapsort obj;
	int arr[] = {1,2,3,4,65,8,23,79,-34} ;
	int size = sizeof(arr)/sizeof(arr[0]); //
	obj.sort(arr, size);
}
