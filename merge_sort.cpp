#include <bits/stdc++.h>

using namespace std;

void mergeSort(int arr[], int low, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, high);
    int temp[high - low + 1], i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];
    i = low;
    for(k = 0; k <= (high - low); k++) {
        arr[i++] = temp[k];
    }
}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    mergeSort(arr, 0, 6);

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}