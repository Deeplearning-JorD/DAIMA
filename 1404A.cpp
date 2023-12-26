/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 03:18:46
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
    string s; cin >> s;
    s = ' ' + s;
    vector<int> f(n + 1);
    rep(i, 1, n) f[i] = i;
    function<int(int)> find = [&](int x){
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    };
    rep(i, 1, n - k){
        if(s[i] == '1' && s[i + k] == '0'){
            cout << "NO\n";
            return;
        }
        if(s[i] == '0' && s[i + k] == '1'){
            cout << "NO\n";
            return;
        }
        f[find(i)] = find(i + k);
    }
    vector<vector<int>> son(n + 1);
    vector<set<char>> son1(n + 1);
    set<int> ss;
    rep(i, 1, n){
        son[find(i)].push_back(i);
        son1[find(i)].insert(s[i]);
        ss.insert(find(i));
        if(son1[find(i)].size() == 3){
            cout << "NO\n";
            return;
        }
    }
    for(auto x:ss){
        char c = '?';
        for(auto u:son[x]){
            if(s[u] != '?'){
                c = s[u];
                break;
            }
        }
        for(auto u:son[x]){
            s[u] = c;
        }
    }
    int sum = 0, cnt = 0;
    auto cc = [&](char c){
        if(c == '1') return 1;
        if(c == '0') return -1;
        return 0;
    };
    ss.clear();
    rep(i, 1, k){
        int now = cc(s[i]);
        if(!now) cnt ++;
        else sum += now;
    }
    if(abs(sum) >= cnt){
        sum = abs(sum) - cnt;
    }else{
        cnt -= abs(sum);
        sum = cnt & 1;
    }
    if(sum != 0){
        cout << "NO\n";
        return;
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