#include<iostream>
using namespace std;

int main() {

    int arr[] = {100,5,4,9,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int c = 3;
    int n = 5;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[j], arr[i]);
            }
        }
    }
    for(int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    
    return 0;
}