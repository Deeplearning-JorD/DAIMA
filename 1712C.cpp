/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 23:22:52
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
    int n;
    cin>>n;
    vector<int> c(n+2,2e9);
    vector<vector<int>> a(n+1);
    int sum=0;
    rep(i,1,n){
        cin>>c[i];
        a[c[i]].push_back(i);
    }
    c[0]=0;
    int res=0;
    vector<bool> st(n+1);
    rep(i,1,n){
        if(c[i-1]>c[i]){
            int now = c[i-1] == 0?c[i]:c[i-1];
            if(st[now]) continue;
            st[now]=true;
            queue<int> q;
            q.push(now);
            while(q.size()){
                auto t = q.front(); q.pop();
                res++;
                for(auto x:a[t]){
                    c[x]=0;
                    if(c[x-1]>c[x]){
                        if(!st[c[x-1]]){
                            st[c[x-1]] = true;
                            q.push(c[x-1]);
                        }
                    }
                }
            }
        }
    }
    cout<<res<<endl;
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