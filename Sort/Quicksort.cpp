/*
 * Quicksort.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Vivek Kumar Bagaria
 */

#include <malloc.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


class Quicksort {
	int size ;

public:
	void sort( int arr[] , int a){
		size  = a ;
		printf("Intial Array \n") ;
		print_array(arr) ;
		quicksort( arr , 0 ,size-1) ;
		printf("Final Array \n") ;
		print_array(arr) ;
	}

	void quicksort( int arr[] , int start , int end){
		if(start<end){
			int mid = partition(arr , start ,end);
			quicksort(arr , start ,mid -1 ) ;
			quicksort(arr , mid+1 , end) ;
		}

	}

	void swap_number(int arr[] , int i , int j){
		int temp	= arr[i] ;
		arr[i]		= arr[j] ;
		arr[j]	= temp ;
	}

	int partition( int arr[] , int start , int end){
		int mid_element = arr[end] ;
		int i = start ;
		int j = end -1 ;
		for( ; i<j ; ){
			if(arr[i] <= mid_element){
				i++ ;
				continue ;
			}
			else if(arr[j] > mid_element){
				j-- ;
				continue ;
			}
			else{
				swap_number(arr , i ,j) ;
				i++ ;
				j-- ;
			}
		}
		swap_number(arr , i ,end) ;
		return i ;
	}

	void print_array(int arr[] , int start = 0 , int end =-1 ){
		if(end == -1){
			end = size -1 ;
		}
		int i ;
		for( i=start ; i<=end ; i++){
			printf(" %d",arr[i]) ;
		}
		printf("\n") ;
	}

};

int main()
{
	Quicksort obj ;
	int arr[] = {1,2,1,2,1,2,2,2,2,1,1,1} ;
	int size = sizeof(arr)/sizeof(arr[0]) ;
	obj.sort(arr, size) ;
}
