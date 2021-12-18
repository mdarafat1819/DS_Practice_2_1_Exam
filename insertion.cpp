#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {

    for(int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;

       while(j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j--;
       }
       arr[j + 1] = key;
    }

    return;
}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    insertionSort(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}