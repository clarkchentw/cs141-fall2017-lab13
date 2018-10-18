#include <iostream>
using namespace std;

#define TOTAL_CITIES 7 //Total of 4 cities
#define MAX_CITY_LEN 50 //The max length allowed of a city name

/*
Swap the values found at the source and target indices of the integer array 
*/
void swap(int *arr, int source, int target){
	int tmp = arr[source];
	arr[source] = arr[target];
	arr[target] = tmp;
}

/*
Swap the values found at the source and target indices of the array of strings
*/
void swap(char **arr, int source, int target){
	char *tmp = arr[source];
	arr[source] = arr[target];
	arr[target] = tmp;
}

/*
Sort the cities by their cost indices using the selection sort algorithm
*/
void selectionSort(char **cities, int* cost_indices){
	for(int selection = 0; selection < TOTAL_CITIES; selection++){
		for(int candidate = selection + 1; candidate < TOTAL_CITIES; candidate++){
			if(cost_indices[selection] > cost_indices[candidate]){
				swap(cost_indices, selection, candidate);
				swap(cities, selection, candidate);
			}
		}
	}
}

/*
The program will take seven cities and their associated cost index and then sort 
in ascending order by cost index.

Ex:
1. Please enter a city and its cost index:
chicago 4

2. Please enter a city and its cost index:
nyc 8

3. Please enter a city and its cost index:
sanfran 7

4. Please enter a city and its cost index:
seattle 5

5. Please enter a city and its cost index:
bloomington 1

6. Please enter a city and its cost index:
dallas 2

7. Please enter a city and its cost index:
boston 3

Here is the result in sorted order by cost index:
1. bloomington 1
2. dallas 2
3. boston 3
4. chicago 4
5. seattle 5
6. sanfran 7
7. nyc 8
*/
int main(){
	char* cities[TOTAL_CITIES];
	int cost_indices[TOTAL_CITIES];
	
	//Read in the city and cost index from the user input
	for(int index = 0; index < TOTAL_CITIES; index++){
		char* city = new char[MAX_CITY_LEN];
		int cost_index = 0;

		cout << "Please enter a city and its cost index:" << endl;
		cin >> city >> cost_index;

		cout << endl;

		cities[index] = city;
		cost_indices[index] = cost_index;
	}

	//Sort the cities by their cost indices
	selectionSort(cities, cost_indices);

	//Output the sorted result
	cout << "Here is the result in sorted order by cost index:" << endl;
	for(int index = 0; index < TOTAL_CITIES; index++){
		cout << index+1 << ". " << cities[index] << " " << cost_indices[index] << endl;
	}

	return(0);
}