#include <iostream> 
#include <cassert> 
using namespace std; 
size_t fact(size_t n) 
{ 
    if (n > 1u) 
    { 
        return n * fact(n - 1); 
    } 
    return 1; //if (n == 1 || n == 0) 
} 
size_t fact_iterative(size_t n) 
{ 
    if (n == 1 || n == 0) 
        return 1;
    size_t previous = 1; 
    for (size_t i = 2; i <= n; ++i) 
    { 
        previous *= i; 
    } 
    return previous; 
} 
size_t n_sqaure_fact(size_t n) 
{ 
    n = fact(n); 
    return n * n; 
} 
size_t n_sqaure_fact_iterative(size_t n) 
{ 
    n = fact_iterative(n); 
    return n * n; 
} 
int main(int argc, char const *argv[]) 
{ 
    assert(fact(0) == 1ull); 
    assert(fact_iterative(0) == 1ull); 
    assert(fact(1) == 1ull); 
    assert(fact_iterative(1) == 1ull); 
    assert(fact(5) == 120ull); 
    assert(fact_iterative(5) == 120ull); 
    assert(fact(30) == 9682165104862298112ull); 
    assert(fact_iterative(30) == 9682165104862298112ull); 
    cout << n_sqaure_fact(30) << endl; 
    cout << n_sqaure_fact_iterative(30) << endl; 
    return 0; 
} 
