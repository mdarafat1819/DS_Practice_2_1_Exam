#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int low, int high, int value) {
    if(low > high) return -1;
    int mid = low + (high - low) / 2;

    if(arr[mid] == value) return mid;
    if(arr[mid] < value) return binarySearch(arr, mid + 1, high, value);
    else return binarySearch(arr, low, mid - 1, value);
}

int main() {

    int arr[] = {10, 30, 40, 50, 80, 90};

   cout<<binarySearch(arr, 0, 6, 91)<<endl;

    return 0;
}