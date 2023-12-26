/*
 * @Author: JorD
 * @LastEditTime: 2023-02-02 00:47:58
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
void Solve(){
    int n, k;
    cin >> n >> k;
    string a, b; cin >> a >> b;
    map<char, int> mp;
    vector<char> son;
    for(auto x:a){
        if(!mp[x]){
            mp[x] ++;
            son.push_back(x);
        }
    }
    vector<char> ls;
    int up = son.size();
    map<char, int> st;
    ll res = 0, idx = 0;
    function<void(int,int)> dfs = [&](int i, int depth){
        if(depth > k ||i > up) return;
        if(i == up){
            idx ++;
            bool flag = true;
            ll len = 0;
            ll now = 0;
            for(int i = 0;i < b.size();i ++){
                auto x = a[i];
                if(st[x] || b[i] == a[i]){
                    len ++;
                }else{
                    now += len * (len + 1) / 2;
                    len = 0;
                }
            }
            now += len * (len + 1) / 2;
            res = max(now, res);
            return;
        }
        st[son[i]] = 1;
        dfs(i + 1, depth + 1);
        st[son[i]] = 0;
        dfs(i + 1, depth); 
    };
    dfs(0, 0);
    cout << res << endl;
    cout << idx << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}