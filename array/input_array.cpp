#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[10];
    cout<<"Enter value of n :";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Your elements are"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    return 0;
}