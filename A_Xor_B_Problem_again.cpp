#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int tr[N][2], cnt[N], idx;
void insert(int x){
    int p = 0;
    for(int i = 20;i >= 0;i --){
        int c = x >> i & 1;
        if(!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    } 
    cnt[p] ++;
}
ll find(int x, int i, int p){
    if(i < 0) return cnt[p];
    if(x >> i & 1){
        if(tr[p][1])
        return find(x, i - 1, tr[p][1]);
    }
    ll res = 0;
    if(tr[p][0])
    res += find(x , i - 1, tr[p][0]);
    if(tr[p][1]) 
    res += find(x, i - 1, tr[p][1]);
    return res;
} 
void Solve(){
    int n;
    cin >> n;
    ll res = 0, js = 0;
    rep(i, 1, n){
        int x; cin >> x;
        res += i - find(x, 20, 0) - 1;
        insert(x);
        js += x == 0;
    }
    cout << res * 2 + js;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}