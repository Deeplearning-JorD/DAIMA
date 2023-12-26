#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int res=0,sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        if(sum>m){
            sum=x;
            res++;
        }
    }cout<<res;
}