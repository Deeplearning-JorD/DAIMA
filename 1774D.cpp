/*
 * @Author: JorD
 * @LastEditTime: 2022-12-18 02:49:30
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
struct node{
    int l, r, p;
};
void Solve(){
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> sonz(n + 1);
    vector<vector<int>> sony(n + 1);
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    vector<set<int>> lim(m + 1);
    rep(i, 1, n) rep(j, 1, m){
        cin >> f[i][j];
        sum += f[i][j];
        if(f[i][j]){
            sony[i].push_back(j);
        }else sonz[i].push_back(j);
    }
    if(sum % n){
        cout << -1 << endl;
        return;
    }
    sum /= n;
    vector<int> js(n + 1);
    vector<int> v;
    rep(i, 1, n) js[i] = siz(sony[i]);
    for(int i = 1;i <= n;i ++){
        if(siz(sony[i]) <= sum) v.push_back(i);
        else{
            for(auto x:sony[i]) lim[x].insert(i);
        }
    }
    vector<node> res;
    for(auto x:v){
        int need = sum - siz(sony[x]);
        int flag;
        for(auto now:sonz[x]){
            if(need == 0) break;
            flag = -1;
            vector<int> ls;
            for(auto y:lim[now]){
                if(js[y] == sum){
                    ls.push_back(y);
                    continue;
                }
                flag = y;
                res.push_back({y, x, now});
                break;
            }
            if(flag != -1){
                lim[now].erase(lim[now].find(flag));
                js[flag]--;
                need --;
            }
            for(auto x:ls) lim[now].erase(lim[now].find(x));
            if(need == 0) break;
        }
    }
    cout << siz(res) << endl;
    for(auto [x, y, z]:res) cout << x << ' ' << y << ' ' << z << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}