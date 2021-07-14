#include<iostream>
using namespace std;

// 寫一個“標準”巨集MIN ，這個巨集輸入兩個參數並返回較小的一個
#define min(a,b) ((a)<(b)?(a):(b))

//Write a MARCO to calculate the square of integer a.
#define sqare(x) ((x)*(x))

//用預處理指令#define 聲明一個常數，用以表明1年中有多少秒（忽略閏年問題）
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL

// Set/Clear/Inverse Bit
# define SET_BIT(x,n) ((x)|=(1<<(n))
# define CLEAR_BIT(x,n) ((x)&=~(1<<(n))
# define INVERSE_BIT(x,n) ((x)^=(1<<(n))
