#include<stdio.h>
#include<time.h>
int fib ( int n )
{
    int f [ n + 1 ] ;
    int i = 2 ;
    f [ 0 ] = 0 ;
    f [ 1 ] = 1 ;
    while ( i <= n )
    {
        f [ i ] = f [ i - 1 ] + f [ i - 2 ] ;
        i = i + 1 ;
    }
    return f [ n ] ;
}
void main()
{
    double time_spent = 0.0 ;
    int i = 0 , n ;
    printf ( " Enter terms of fibonacci series \n " ) ;
    scanf ( "%d" , &n ) ;
    clock_t begin = clock() ;
    printf ( " Fibonacci series is : \n " ) ;
    while ( i < n )
    {
        printf ( " %d " , fib ( i ) ) ;
        i = i + 1 ;
    }
    clock_t end = clock() ;
    time_spent = time_spent + ( double ) ( end - begin ) / CLOCKS_PER_SEC ;
    printf ( " \n %f secs " , time_spent ) ;
}
