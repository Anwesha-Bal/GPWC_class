#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ;i<n-1;i++){
       if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    cout<<"Largest: "<<arr[n-1]<<" "<<endl;
    for(int i = 0 ;i<n-1;i++){
       if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
     cout<<"Second Largest: "<<arr[n-2]<<" "<<endl;
    
    return 0;
}