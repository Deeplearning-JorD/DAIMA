/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 21:58:22
 */
#include<bits/stdc++.h>
using namespace std;
long long a[200100];
int main(){
    long long n,m;
    cin >> n >> m;
    long long all=0;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
        all+=a[i];
    }
    a[0]=a[1]-1;
    sort(a+1,a+n+1);
    long long ma=0;
    long long p=0;
    long long r=n;
    long long first=0;
    for(long long i=1;i<=n;i++){
        if(a[i]-a[i-1]<=1){        //-1 0 0 1 2  4 5
            first+=a[i];
        }else{
            p=a[i];
            r=i;
            break;
        }
    }
    long long bj=max(p, first);
    a[0]=-1;
    for(long long i=r+1;i<=n;i++){
        if(a[i]-a[i-1]<=1){
            p+=a[i];
        }else{
            p=a[i];
        }
        if(i==n&&a[i]==m-1&&a[1] == 0){
            bj=max(p+first,bj);
        }else{ 
            bj=max(p,bj);
        }
    }
    cout << all-bj << endl;
    return 0;
}