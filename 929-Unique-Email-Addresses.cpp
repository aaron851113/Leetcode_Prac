// % g++ -std=c++11 -o x x.cpp
// % ./x
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;
        vector<string> v_list ;
        for(int i = 0 ; i < emails.size() ; i++){
            int pos = emails[i].find('@');
            //cout<<pos<<' '<<emails[i][pos]<<endl;
            string local, domain;
            local = emails[i].substr(0, pos);
            domain = emails[i].substr(pos);
            string newLocal;
            for(int j = 0 ; j < local.size() ; j++){
                if(local[j]=='+')break;
                if(local[j]!='.'){
                    newLocal += local[j];
                }
                
            }
            newLocal += domain;
            //cout<<newLocal<<endl;
            if (v_list.empty() || find(v_list.begin(),v_list.end(),newLocal) == v_list.end()){
                v_list.push_back(newLocal);
            }
        }
        //for(int i = 0; i < v_list.size(); i++)cout << v_list[i] << endl;
        return v_list.size() ;
    }
};

int main(){
    vector<string> v = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    int ans = Solution().numUniqueEmails(v);

    cout<<"ans = "<<ans<<endl;
    return 0;
}