//print mathematical table of positive integer n, till 10th multiple. Use Recursion 
#include <iostream> 
using namespace std; 
//tail recursive 
void print_first_i_multiples(const unsigned int n, unsigned int i) 
{ 
    if(i < 1) 
        return; 
    print_first_i_multiples(n, i - 1); 
    cout << n << " * " << i << " = " << n * i << endl; 
} 
//iterative 
void print_first_i_multiples_iterative(const unsigned int n, unsigned int i) 
{ 
    if(i < 1) 
        return; 
    cout << "\n"; 
    for(unsigned int j = 1; j <= i; j++) 
    { 
        cout << n << " * " << j << " = " << n * j << endl; 
    } 
} 
//using previous value to use addition instead of multiplicative calculations 
//tail recursive function 
void print_first_i_multiples_using_add(const unsigned int n, unsigned int i) 
{ 
    if(i < 1) 
        return; 
    static unsigned int last_value = 0; 
    //print_first_i_multiples_using_add_helper(n, i, last_value); 
    print_first_i_multiples_using_add(n, i - 1); 
    unsigned int this_value = n + last_value; 
    cout << n << " * " << i << " = " << this_value << endl; 
    last_value = this_value; 
} 
//iterative 
void print_first_i_multiples_using_add_iterative(const unsigned int n, unsigned int i) 
{ 
    if(i < 1) 
        return; 
    cout << "\n"; 
    unsigned int last_value = n; 
    for(unsigned int j = 2; j <= i; j++) 
    { 
        unsigned int this_value = n+last_value; 
        cout << n << " * " << j << " = " << this_value << endl; 
        last_value = this_value; 
    } 
} 
int main(int argc, char const *argv[]) 
{ 
    print_first_i_multiples(10, 10); 
    cout << "\n"; 
    print_first_i_multiples_iterative(7, 10); 
    cout << "\n"; 
    print_first_i_multiples_using_add(15, 10); 
    cout << "\n"; 
    print_first_i_multiples_using_add_iterative(20, 10); 
    return 0; 
} 