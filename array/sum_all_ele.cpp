#include<iostream>
using namespace std;

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = sum + arr[i];
    }
    cout<<"Sum are all elements present in the array is : "<<sum;
    return 0;
}

/*
OUTPUT
Sum are all elements present in the array is : 550
*/