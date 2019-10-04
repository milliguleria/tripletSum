//Created by Brandon Barnes

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

int partition(int* array, int low, int high){
	int pivot = array[high];
	int temp = (low-1);
	int t;
	
	for(int i = low; i<= high-1; i++){
		if(array[i]<=pivot){
			temp++;
	        	t= array[i];
    			array[i]=pivot;
   		        pivot=t;
		}
	}
	t=array[temp+1]; 
    	array[temp+1]=array[high]; 
    	array[high]=t; 
	return(temp+1);
}

void quickSort(int* array, int low, int high){
	if(low<high){
		int part = partition(array, low, high);
		
		quickSort(array, low, part-1);
		quickSort(array, part+1, high);
	}
}

void tripletSum(){
	int sizeArray = 1;
	int inputSum = 1;
	
	while(sizeArray){
		cout << "Provide size of array as an int" << endl;
		cout << "Input 0 as value to exit" << endl;
		cin >> sizeArray;
		cout << "Your input: " << sizeArray << endl;
		
		
		if(sizeArray !=0 && sizeArray < 3){ //in a proper end user program, would include max int/min int checks 
			cout << "invalid input, please have non-negative values for inputs" << endl;
			continue;
		}
		if(sizeArray == 0){
			cout << "Input of 0 given, now exiting" << endl;
		}
		else{
			int* testArray = (int*) malloc(sizeArray);
			string arrayInput;
			stringstream ss;
			
			getline(cin, arrayInput); //this is used to clear out cin for array input
			
			cout << "please enter array data as space seperated integers" << endl;
			getline(cin, arrayInput);
			ss << arrayInput;
			cout<<endl;
			int temp = 0;
			int tripletAccumulator = 0;
			int first;
			int second;
			
			int iterator = 0;
			
			while(ss>>temp && iterator < sizeArray){
				testArray[iterator] = temp;
				iterator++;
			}
			
			quickSort(testArray, 0,sizeArray-1);
			
			for(int i = sizeArray-1; i>1;i--){
				first = 0;
				second = i-1;
				while(first<second){
					if(testArray[first]+testArray[second]==testArray[i]){
						tripletAccumulator++;
						first++;
					}
					else if(testArray[first]+testArray[second]<testArray[i]){
						second--;
					}
					else{
						first++;
					}
				}
			}
			
			cout << "number of valid triplets: "<< tripletAccumulator << endl;
			delete testArray;
			
		}
		
	}
}

int main(){
	tripletSum();
	
	return 0;
}
