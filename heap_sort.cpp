#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int root) {
   int left = 2 * root + 1, right = 2 * root + 2, largest = root;

   if(left < n && arr[largest] < arr[left]) largest = left;
   if(right < n && arr[largest] < arr[right]) largest = right;

   if(largest != root) {
       swap(arr[largest], arr[root]);
       heapify(arr, n, largest);
   }
}

void heapSort(int arr[], int n) {
    //build heap
    for(int i = n / 2; i >= 0; i--) heapify(arr, n, i);

    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    heapSort(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }


    return 0;
}