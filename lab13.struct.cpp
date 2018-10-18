#include <iostream>
using namespace std;

#define TOTAL_CITIES 7 //Total of 7 cities
#define MAX_CITY_LEN 50 //The max length allowed of a city name

struct City{
	char* name = new char[MAX_CITY_LEN];
	int costIndex;
} sampleCity;

/*
Swap the values found at the source and target indices
*/
void swap(City structure[TOTAL_CITIES], int source, int target){
	char* tmp_name = structure[source].name;
	int tmp_costIndex = structure[source].costIndex;
	structure[source].name = structure[target].name;
	structure[source].costIndex = structure[target].costIndex;
	structure[target].name = tmp_name;
	structure[target].costIndex = tmp_costIndex;
}

/*
Sort the cities by their cost indices using the selection sort algorithm
*/
void selectionSort(City structure[TOTAL_CITIES]){
	for(int selection = 0; selection < TOTAL_CITIES; selection++){
		for(int candidate = selection + 1; candidate < TOTAL_CITIES; candidate++){
			if(structure[selection].costIndex > structure[candidate].costIndex){
				swap(structure, selection, candidate);
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
	City cities[TOTAL_CITIES];
	City *pCity;
	
	//Read in the city and cost index from the user input
	for(int index = 0; index < TOTAL_CITIES; index++){

		cout << "Please enter a city and its cost index:" << endl;
		cin >> cities[index].name >> cities[index].costIndex;
		cities[index] = sampleCity;

		cout << endl;
	}

	//Sort the cities by their cost indices
	selectionSort(cities);

	//Output the sorted result
	cout << "Here is the result in sorted order by cost index:" << endl;
	for(int index = 0; index < TOTAL_CITIES; index++){
		cout << cities[index].name << " " << cities[index].costIndex << endl;
	}

	return(0);
}