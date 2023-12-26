/*
 * @Author: JorD
 * @Date: 2023-11-29 13:17:18
 * @LastEditTime: 2023-11-29 13:24:32
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
bool st[10004];
int p[10003], idx;
vector<int> resl, resr;
void Solve(){
    int x; cin >> x;
    int l = -1, r = -1;
    for(int i = 0;i < idx && p[i] <= x / p[i];i ++)if(x % p[i] == 0){
        if(l == -1){
            l = 1;
            while(x % p[i] == 0){
                x /= p[i];
                l *= p[i];
            }
        }else{
            if(r == -1) r = 1;
            while(x % p[i] == 0){
                x /= p[i];
                r *= p[i];
            }
        }
    }
    if(x > 1){
        if(l != -1){
            if(r == -1) r = 1;
            r *= x;
        }
    }
    if(r != -1){resl.push_back(l);resr.push_back(r);}
    else{resl.push_back(-1);resr.push_back(-1);}
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i = 2;i <= 1e4;i ++){
        if(!st[i]) p[idx ++] = i;
        for(int j = 0;p[j] <= 1e4 / i;j ++){
            st[p[j] * i] = true;
            if(i % p[j] == 0) break;
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    for(auto x:resl) cout << x << ' ';
    cout << endl;
    for(auto x:resr) cout << x << ' ';
    return 0;
}