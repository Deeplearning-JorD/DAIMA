/*
 * @Author: JorD
 * @Date: 2022-05-06 15:42:23
 * @LastEditTime: 2022-08-10 09:07:25
 * @Description: 
 * 解释权归JorD所有
 */
#include<bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
const int N=5e5+10;
char s[N];
ll n,c,q;
ll l[N],r[N];
ll pre[N];
char dfs(ll now){
    if(now<=n)
        return s[now];
    ll p=lower_bound(pre,pre+c+1,now)-pre;
    return dfs(r[p-1]-(pre[p]-now));
}
void solve(){
    cin>>n>>c>>q;
    for(ll i=1;i<=n;i++) cin>>s[i];
    pre[0]=n;
    for(int i=0;i<c;i++){
        cin>>l[i]>>r[i];
        pre[i+1]=pre[i]+r[i]-l[i]+1;
    }
    while(q--){
        ll k;
        cin>>k;
        cout<<dfs(k)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}