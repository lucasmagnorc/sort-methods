#include "functions.h"

/*******************************************************************************
* SELECTION SORT METHOD
*******************************************************************************/
void selection_sort_method(float *values_to_ordenate, int n_file_rows){
  int i, min, j;
  float aux;
  for(i = 1; i <= n_file_rows - 1; i++){
    min = i;
    for(j = i + 1; j <= n_file_rows; j++){
      if(values_to_ordenate[j] < values_to_ordenate[min]){
        min = j;
      }
    }
    aux = values_to_ordenate[min];
    values_to_ordenate[min] = values_to_ordenate[i];
    values_to_ordenate[i] = aux;
  }
}

/*******************************************************************************
* INSERTION SORT METHOD
*******************************************************************************/
void insertion_sort_method(float *values_to_ordenate, int n_file_rows){
  int i, j;
  float aux;
  for(i = 2; i <= n_file_rows; i++){
    aux = values_to_ordenate[i];
    j = i - 1;
    values_to_ordenate[0] = aux;
    while(aux < values_to_ordenate[j]){
      values_to_ordenate[j + 1] = values_to_ordenate[j];
      j--;
    }
    values_to_ordenate[j + 1] = aux;
  }
}

/*******************************************************************************
* SHELL SORT METHOD
*******************************************************************************/
void shell_sort_method(float *values_to_ordenate, int n_file_rows){
  int i, j, h = 1;
  float aux;
  do{
    h = h*3 + 1;
  }while(h < n_file_rows);
  do{
    h /= 3;
    for(i = h + 1; i <= n_file_rows; i++){
      aux = values_to_ordenate[i];
      j = i;
      while(values_to_ordenate[j - h] > aux){
        values_to_ordenate[j] = values_to_ordenate[j - h];
        j -= h;
        if(j <= h){
          goto L999;
        }
      }
      L999: values_to_ordenate[j] = aux;
    }
  }while(h!=1);
}

/*******************************************************************************
* QUICK SORT METHOD
*******************************************************************************/
void quick_sort_method(float *values_to_ordenate, int left, int right){
  int i, j;
  float pivo, aux;
  if(right > left){
    pivo = values_to_ordenate[right];
    i = left - 1;
    j = right;
    for(;;){
      while(values_to_ordenate[++i] < pivo){
      }
      while(values_to_ordenate[--j] > pivo){
      }
      if(i >= j){
        break;
      }
      aux = values_to_ordenate[i];
      values_to_ordenate[i] = values_to_ordenate[j];
      values_to_ordenate[j] = aux;
    }
    values_to_ordenate[right] = values_to_ordenate[i];
    values_to_ordenate[i] = pivo;
    quick_sort_method(values_to_ordenate, left, i-1);
    quick_sort_method(values_to_ordenate, i+1, right);
  } 
}

/*******************************************************************************
* MERGE SORT METHOD
*******************************************************************************/
void merge_sort_method(float *values_to_ordenate, int array_start, int array_end, int size_file){
  int middle;
  if(array_start < array_end){
    middle = (array_start + array_end) / 2;
    merge_sort_method(values_to_ordenate, array_start, middle, size_file);
    merge_sort_method(values_to_ordenate, middle+1, array_end, size_file);
    merge_method(values_to_ordenate, array_start, array_end, middle, size_file);
  }
}

void merge_method(float *values_to_ordenate, int array_start, int array_end, int middle, int size_file){
  int position_free, array_start_vet1, array_start_vet2, i;
  float aux[size_file+1];
  array_start_vet1 = array_start;
  array_start_vet2 = middle + 1;
  position_free = array_start;
  while(array_start_vet1 <= middle && array_start_vet2 <= array_end){
    if(values_to_ordenate[array_start_vet1] <= values_to_ordenate[array_start_vet2]){
      aux[position_free] = values_to_ordenate[array_start_vet1];
      array_start_vet1++;
    }else{
      aux[position_free] = values_to_ordenate[array_start_vet2];
      array_start_vet2++;
    }
    position_free++;
  }
  
  for(i = array_start_vet1; i <= middle; i++){
    aux[position_free] = values_to_ordenate[i];
    position_free++;
  }
  
  for(i = array_start_vet2; i <= array_end; i++){
    aux[position_free] = values_to_ordenate[i];
    position_free++;
  }
  
  for(i =  array_start; i <= array_end; i ++){
    values_to_ordenate[i] = aux[i];
  }
}
