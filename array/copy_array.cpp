#include<iostream>
using namespace std;

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int brr[10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        brr[i] = arr[i];
    }
    
    cout<<"copied array is:"<<endl;

    for (int i = 0; i < 10; i++)
    {
        cout<<brr[i]<<" ";
    }
    
    
    return 0;
}

/*
OUTPUT
copied array is:
10 20 30 40 50 60 70 80 90 100 
*/