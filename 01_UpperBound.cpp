#include<iostream>
using namespace std;
int main()

{
    int arr[] = {2,3,6,7,8,8,11,11,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = n - 1;
    int x = 11;
    int ans;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        
         else {
            low = mid + 1;   
        } 
    }
    cout << "Ans is: "<< ans <<endl;
    return 0;
}