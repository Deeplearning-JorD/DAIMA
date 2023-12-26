/*
 * @Author: JorD
 * @LastEditTime: 2023-04-24 23:23:30
 */
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
vector<int> a;
int st[100];
int n;
void dfs(int now){
    if(now == 0){
        ll sum = 0;
        set<int> s;
        for(auto x:a){
            sum += x;
            sum %= n;
            s.insert(sum);
        }
        if(s.size() == n){
            for(auto x:a){
                cout << x << ' ';
            }
            cout << endl;
        }
        return;
    }
    for(int i = 1;i <= n;i ++){
        if(st[i]) continue;
        st[i] = true;
        a.push_back(i);
        dfs(now - 1);
        a.pop_back();
        st[i] = false;
    }
}
void Solve(){
    cin >> n;
    if(n & 1){
        if(n == 1){
            cout << 1 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    vector<int> res(n + 1);
    res[1] = n;
    int l = 1, r = n - 1, now = n;
    for(int i = 2;i <= n;i ++){
        if(i & 1){
            if(r > now) res[i] = r - now;
            else res[i] = n + r - now;
            now = r --;
        }else{
            if(l > now) res[i] = l - now;
            else res[i] = n + l - now;
            now = l ++;
        }
    }
    rep(i, 1, n){
        cout << res[i] << " \n"[i == n];
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}