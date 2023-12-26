/*
 * @Author: JorD
 * @LastEditTime: 2023-10-10 23:39:04
 * n用质数来表示，但是d(n)可以直接算出来。只要d(n)需要的质数n都有就行。 
 * how to Get
 */
#pragma GCC optimize(2)
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
void Solve(){
    int n, m; cin >> n >> m;
    map<int,int> st;
    for(int i = 2;i <= n / i;i ++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt ++;
                n /= i;
            }
            st[i] += cnt;
        }
    }
    if(n > 1){
        st[n] += 1;
    }
    auto ls = st;
    while(m --){
        int op; cin >> op;
        if(op == 2){
            st = ls;
            continue;
        }
        int x; cin >> x;
        for(int i = 2;i <= x / i;i ++){
            if(x % i == 0){
                int cnt = 0;
                while(x % i == 0){
                    cnt ++;
                    x /= i;
                }
                st[i] += cnt;
            }
        }
        if(x > 1){
            st[x] ++;
        }
        ll res = 1;
        for(auto [d, y] : st){
            res *= y + 1;
        }
        for(int i = 2;i <= res / i;i ++){
            if(res % i == 0){
                int cnt = 0;
                while(res % i == 0){
                    cnt ++;
                    res /= i;
                }
                if(st.count(i) && st[i] >= cnt) continue;
                res = -1;
                break;
            }
        }
        if(res > 1){
            if(st.count(res) && st[res] >= 1){res = 1;}
            else res = 0;
        }
        if(res == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}