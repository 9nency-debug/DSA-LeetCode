#include<iostream>
using namespace std;

int main() {

    int stalls[] = {1,2,4,8,9};
    int size = sizeof(stalls) / sizeof(stalls[0]);
    int c = 3;
    int n = 5;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(stalls[i] > stalls[j]) {
                swap(stalls[j], stalls[i]);
            }
        }
    }
    
    int low = stalls[0];
    int high = stalls[size - 1] - stalls[0];
    
    return 0;
}