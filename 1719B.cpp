/*
 * @Author: JorD
 * @LastEditTime: 2022-08-16 23:02:17
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
void Solve(){
    int n, m;
    cin >> n >> m;
    if(m%4==0){
        cout<<"NO"<<endl;
        return;
    }
    if(m&1){
        cout<<"YES"<<endl;
        for(int i=1,j=2;j<=n;j+=2,i+=2)
            cout<<i<<' '<<j<<endl;
    }
    else {
        cout<<"YES"<<endl;
        vector<bool> st(n+1);
        for(int i=4;i<=n;i+=4){
            cout<<i-1<<' '<<i<<endl;
            st[i-1]=st[i]=true;
        }
        for(int i=1;i<=n;i+=2){
            if(st[i]||st[i+1]) continue;
            cout<<i+1<<' '<<i<<endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;

    while(t--)
    Solve();
    return 0;
}