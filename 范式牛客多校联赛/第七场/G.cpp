/*
 * @Author: JorD
 * @LastEditTime: 2023-08-09 15:12:21
 * 注意连边，有孤立点
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> son;
    vector<int> a(n + 1), st(n + 1);
    rep(i, 1, n) cin >> a[i];
    for(int i = 1;i <= n;i ++)if(!st[i]){
        int j = i;
        vector<int> ls;
        while(1){
            if(st[j]) break;
            st[j] = 1;
            ls.push_back(a[j]);
            int m = j + k;
            if(m > n) m -= n;
            if(j < m){if(n + j - m < k) break;}
            else if(j - m < k) break;
            j = m;
        }
        son.push_back(ls);
    }
    for(auto &u : son){
        int len = u.size();
        if(len == 1){
            if(u[0]){
                cout << "NO\n";
                return;
            } 
            continue;
        }
        int down = 0, up = u[0];
        int a = 0, b = -1;
        for(int i = 1;i < len;i ++){
            a = u[i] - a;
            if(b == -1){
                up = min(up, a);
                down = max(down, a - u[i]);
            }else{
                up = min(up, u[i] - a);
                down = max(down, -a);
            }
            b *= -1;
        }
        if(down > up){
            cout << "NO\n";
            return;
        }
        if(len & 1){
            a = u[0] - a;
            if(a & 1){
                cout << "NO\n";
                return;
            }
            ll x = a / 2;
            if(down <= x && x <= up) continue;
            cout << "NO\n";
            return;
        }else{
            if(u[0] != a){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}