#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    	
    	string ans = "aaaa";
    	int l1 = str1.size();
    	int l2 = str2.size();
		    	
    	// gcd
    	int r = 0;
		while(l2){
			r = l1 % l2 ;
			l1 = l2;
			l2 = r;
		}
		int strgcd_len = l1;
    	
    	if(str1 + str2 != str2 + str1){
            return "";    
    	}
		return str1.substr(0, strgcd_len);
	}
};

int main(){
	string str1 = "ABABAB";
	string str2 = "ABAB";
	string ans = Solution().gcdOfStrings(str1, str2);
	cout << ans << "\n";
	
	return 0;
}


