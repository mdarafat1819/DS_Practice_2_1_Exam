#include <bits/stdc++.h>

using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] > mx) mx = arr[i];
    }

    return mx;
}

void countingSort(int arr[], int n, int pos) {

    int output[n], count[10] = {0};

    for(int i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }
    //prefix sum
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    //Find the actual position
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }
    //copy output[] to arr[]
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {

    int mx = getMax(arr, n);

    for(int pos = 1; mx / pos > 0; pos *= 10) {
        countingSort(arr, n, pos);
    }

}

int main() {

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    radixSort(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}