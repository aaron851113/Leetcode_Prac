// write a code that check the input is a multiple of 3 or not without using division or mod

#include<iostream>
using namespace std;

int divide3(int a){
    int ans = 0 ;
    while(a){
        ans += a & 1 ;
        ans >>= 1;
        ans -= a & 1 ;
        ans >>= 1;
    }
    return !(ans);
}

///通用算法版(This can use for any number)
int isMult3(unsigned int n)
{
    if ( n == 0 )    
        return 1;
    if ( n < 3 ) 
        return 0;
    
  	n = (n >> 2) + (n & 3);
    
    /* Recursive call till you get n
        or a special terminate condition */
    return(isMultN(n));
}