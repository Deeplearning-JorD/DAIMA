/*
 * @Author: JorD
 * @LastEditTime: 2022-09-12 14:14:04
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
    cin >> n;
    m = n >> 1;
    vector<int> a(n), b(n);
    rep(i, 0, n - 1){
        cin >> a[i];
        b[a[i]] = i;
    }
    set<int> s;
    auto f = [&](int x,int i){
        if(x < i){
            return i - x;
        }else return n - (x - i);
    };
    vector<ll> c(3 * n + 2);
    auto ji = [&](int x){
        if(x < 0) return;
        if(x > 3 * n) return;
        c[x] ++;
        if(x + m <= 3 * n)
        c[x + m] -= 2; 
        if(x + 2 * m <= 3 * n)
        c[x + 2 * m] ++;
    };
    auto ou = [&](int x){
        if(x < 0) return;
        if(x <= 3 * n)
        c[x] ++;
        if(x + m <= 3 * n)
        c[x + m] --;
        if(x + m + 1 <= 3 * n)
        c[x + m + 1] --;
        if(x + 2 * m + 1 <= 3 * n)
        c[x + 2 * m + 1] ++;
    };
    rep(i, 0, n - 1){
        int x = f(b[i], i) + 1;
        if(n & 1){
            rep(j, 0, 6){
                ou(x);
                x += 2 * m + 1;
            }
        }else{
            rep(j, 0, 5){
                ji(x);
                x += 2 * m;
            }
        }
    }
    rep(i, 1, 3 * n) c[i] += c[i - 1];
    rep(i, 1, 3 * n) c[i] += c[i - 1];
    ll res = 1e18;
    rep(i, 2 * n + 1, 3 * n) res = min(res, c[i]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}