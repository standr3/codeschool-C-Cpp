#include <stdio.h>
#include <stdlib.h>
// POINTERS AS FUNCTION RETURNS
int Add(int a, int b) // Called function
{
    printf("Address of a in Add = %d\n",&a);
    int c = a+b;
    return c;
}



int main() // Calling function
{
    int a=2, b=4;
    printf("Address of a in main = %d\n");
    int c = Add(a,b);
    // Call by value
    printf("Sum = %d\n",c);
    // value in a of main is copied to a of Add
    return 0;
}
