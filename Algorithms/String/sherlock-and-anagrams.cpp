#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int funct(string str){
    int len = str.length();
    map<string, int> M;
    for(int i=1; i<len; i++){
        for(int j=0; j<=len-i; j++){
            string s = str.substr(j, i);
            sort(s.begin(), s.end());
            M[s]++;
            //cout<<s<<" "<<M[s]<<'\n';
        }
    }
    map<string, int>::iterator it;
    int count = 0;
    for(it = M.begin(); it != M.end(); it++){
        if(it->second > 1){
            count += ((it->second) * (it->second-1))/2;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        string str;
        cin>>str;
        cout<<funct(str)<<'\n';
    }
    return 0;
}
