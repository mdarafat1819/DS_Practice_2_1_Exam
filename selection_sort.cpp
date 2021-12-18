#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }

    return;
}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    selectionSort(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}