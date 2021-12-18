#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) {

    int pivot = arr[high], i = low;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {

     if(low < high) {
         int pi = partition(arr, low, high);

         quickSort(arr, low, pi - 1);
         quickSort(arr, pi + 1, high);
     }
    return;
}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    quickSort(arr, 0, 6);

    for(int i = 0; i < 6; i++) cout<<arr[i]<<" ";

    return 0;
}