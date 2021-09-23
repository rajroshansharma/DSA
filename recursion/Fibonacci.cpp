#include<iostream>
using namespace std;

int fibonacci(int n){
    if (n == 1)
    {
        return 1;
    }
    if(n==0){
        return 0;
    }
    return fibonacci(n-2) + fibonacci(n-1);
    
}

int main(){
    int num = 100;
    //calculates fibonacci of a single number
    //cout<<fibonacci(num);
    for (int i = 0; i <= num; i++)
    {
        cout<<" "<<fibonacci(i);
    }
    
    return 0;
}


// Expalnation
/*
fibonacci function calculates the number at one time only so we use the for loop iteration in the main function.
for example if we are calculating for f(3) then    f(3)   
                                                    |
                                                f(2)+f(1)
                                                 /     
                                            f(1)+f(0)  

stack represntation

f(1) -> returns 1 and poped and wait so that f(2) can bring some value to be added.
f(2)
f(3)
main()

f(1) -> returns 1 and poped and wait so that f(0) can bring some value to be added.
f(2)
f(3)
main()

f(0) -> returns 0 and poped . here 0+1 = 1 will be retured to f(2)
f(2)
f(3)
main()

f(2) -> returns 1. here 1+1 = 2 & f(2) will poped out.
f(3)
main()

f(3) -> returns 2. & f(3) will poped out.
main()

main() -> returns 2;

you can check 3rd index will be 2.
indexes 0 1 2 3 4 5 6 ...
values  0 1 1 2 3 5 8 ..

*/
