#include <stdio.h>

int & f() {
    int i = 1;
    return i;
}

int g() {
    int j = 2;
    return j;
}

int main() {
    int &ri = f();
    g();
    printf( "%d\n", ri);
    // The code above outputs 2 because f() specifically returns an address in stack memory above the function call.
    // This will be any local variables that are initialized
    // &ri is an alias that references this particular address.
    // When g is called, g initializes a variable in stack memory above the function call, which is what ri is an alias for.
    // When g finishes, the address in stack memory is still 2. So when printed, the value of ri is 2.
}