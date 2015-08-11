#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool funct(string s){
    int arr[26] = {0};
    int a = int('a');
    int len = s.length();
    for(int i=0; i<len; i++){
        arr[int(s[i])-a]++;
    }
    bool flag = false;
    for(int i=0; i<26; i++){
        if(arr[i]%2 != 0){
            if(!flag){
                flag = true;
            }
            else
                return false;
        }
    }
    return true;
}

int main() {
   
    string s;
    cin>>s;
     
    int flag = funct(s);
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
