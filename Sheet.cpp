#include<iostream>
using namespace std;

int main()
{
    int arr[] ={1,2,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 6;
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] > m) {
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans;
}