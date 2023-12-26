/*
 * @Author: JorD
 * @LastEditTime: 2022-08-26 20:00:48
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
int res;
bool st[100004];
int p[1000004];
int a[1000004];
int ans[1000004];
int nex[1000004];
set<int> s;
void is_prime(int x){
    for(int i=2;i<=x;i++){
        if(!st[i]) {p[res++]=i;s.insert(i);}
        for(int j=0;p[j]<=x/i;j++){
            st[p[j]*i]=true;
            if(i%p[j]==0) break;
        }
    }
}
void Solve(){
    int n, t;
    scanf("%d%d",&n,&t);
    is_prime(4e6);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n){
        if(s.count(a[i])){
            s.erase(a[i]);
        }ans[i] = *s.begin();
    }
    while(t --){
        int x; scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return;
}
int main(){
    //int t; cin>>t;

    
    Solve();
    return 0;
}