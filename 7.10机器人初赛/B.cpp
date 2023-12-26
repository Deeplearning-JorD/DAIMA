/*
 * @Author: JorD
 * @LastEditTime: 2023-07-14 21:26:38
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef pair<int, int> PII;
typedef pair<string,int> PSI;
#define f first
#define s second
const int N = 2e5+10;
int a[N],b[N];
int n,s,l;
int check(int mid)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+b[i]*mid>=l) sum+=a[i]+b[i]*mid;
    }
    if(sum>=s) return 1;
    return 0;
}
signed main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>s>>l;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    //for(int i=1;i<=n;i++) cout<<b[i]<<endl;
    int l=1,r=1e18;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<r<<endl;
    return 0;
}
