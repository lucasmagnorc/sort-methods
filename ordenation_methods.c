#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "src/functions.h"

int main(){

	// Variables declaration
	int count_rows_file = 0;
	float values_to_ordenate[150];
	time_t time_start, time_end;

	// Start execution time
  time_start = time(NULL);
	
	// Opening file and put into array
	FILE *file;
	if((file = fopen("values_to_ordenate.txt", "r")) == NULL) {
		printf("It's no possible to open the file\n");
		exit(1);
	} else {
		while(!feof(file)) {
	  	fscanf(file, "%f", &values_to_ordenate[count_rows_file]);
			count_rows_file++;
		}
		fclose(file);		
	} 

	// Menu to select sort method
	printf("\n Sort Methods\n 1 - Seletion sort\n 2 - Insertion sort\n 3 - Shell sort\n 4 - Quick sort\n 5 - Merge sort\n Choose the option (only write the number and press enter): ");
	int menu;
	scanf("%d", &menu);
	switch(menu){
		case 1:
			selection_sort_method(values_to_ordenate, count_rows_file);
			break;
		case 2:
			insertion_sort_method(values_to_ordenate, count_rows_file);
			break;
		case 3: 
			shell_sort_method(values_to_ordenate, count_rows_file);
			break;
		case 4:
			quick_sort_method(values_to_ordenate, 1, count_rows_file);
			break;
		case 5:
			merge_sort_method(values_to_ordenate, 1, count_rows_file, count_rows_file);
			break;
		default:
			printf("Invalid option. Choose again: ");
			scanf("%d", &menu);		
	}
	time_end = time(NULL);
	
	// Wrinting a output file
	file=fopen("output_file.txt", "w");
	if(file == NULL){
		printf("It's no possible to open the file\n");
		exit(1);
	}

	for(int i = 1; i < count_rows_file; i++){
		if(values_to_ordenate[i] > 0.00){
			fprintf(file, "%.2f\n", values_to_ordenate[i]);	
		}
	}
	fclose(file);

	printf("\n File was gerated with success\n");
	exit(1);
}
