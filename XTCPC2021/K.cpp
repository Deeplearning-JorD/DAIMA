/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 19:14:02
 */
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define int long long 
signed main(){
    int k;
    while(cin>>k){
        string s;
        cin>>s;
        map<char,int>mp;
        int l=0;
        int r=0;
        int ma=-2e8;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>k){
                mp[s[l]]--;
                l++;
            }
            ma=max(ma,r-l+1);
            r++;
        }
        cout<<ma<<endl;
    }
    return 0;
}