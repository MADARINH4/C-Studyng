#include "mergesort.h"
#define size(list) (sizeof(list) / sizeof(*(list))) // Macro que retorna tamanho de qualquer array inicializado
using namespace std;

void merge(int*, int, int, int);

void mergeSort(int *list, int inicio, int fim){
    if(inicio < fim){
        int meio = floor((inicio + fim)/2);
        mergeSort(list, inicio, meio);
        mergeSort(list, meio+1, fim);
        merge(list, inicio, meio, fim);
    }
}

void merge(int *list, int inicio, int meio, int fim){
    int left[meio-inicio+1], right[fim-meio];
    int top_left = 0, top_right = 0;
    int i = inicio;

    copy(list + (inicio), list + (inicio+size(left)), left);
    copy(list + (meio+1), list + (meio+1+size(right)), right);

    while(top_left < size(left) && top_right < size(right)){
        if(left[top_left] <= right[top_right]){
            list[i++] = left[top_left++];
        }else{
            list[i++] = right[top_right++];
        }
    }
    while(top_left < size(left)){
        list[i++] = left[top_left++];
    }
    while(top_right < size(right)){
        list[i++] = right[top_right++];
    }
}