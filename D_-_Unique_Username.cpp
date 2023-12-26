/*
 * @Author: JorD
 * @LastEditTime: 2022-09-11 19:41:10
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
    cin >> n >> m;
    vector<string> s(n + 1);
    int sum = n - 1;
    rep(i, 1, n){
        cin >> s[i];
        sum += s[i].size();
    }
    unordered_map<string, int> q;
    bool res = false;
    vector<bool> st(n + 1);
    rep(i, 1, m){
        string a;
        cin >> a;
        q[a] = true;
    }
    vector<string> ls;
    vector<int> w(20);
    function<void(int,int)> dfs1 = [&](int dist,int now){
        if(now < 0) return;
        if(dist == n){
            if(now != 0) return;
            string lis = "";
            int idx = 0;
            rep(i, 1, n - 1){
                lis += ls[idx] + '_';
                rep(j, 1, w[i]) lis += '_';
                idx ++;
            }
            lis += ls[idx];
            if(!q[lis]){
                res = true;
                cout << lis << endl;
                exit(0);
            }
            return;
        }
        rep(i, 0, now){
            w[dist] = i;
            dfs1(dist + 1,now - i);
            w[dist] = 0;
        }
    };
    function<void(int)> dfs = [&](int dist){
        if(dist == n){
            rep(i, 0, 16){
                if(sum + i <= 16&&sum + i >= 3){
                    dfs1(1, i);
                }
            }
            return;
        }
        rep(i, 1, n){
            if(st[i]) continue;
            st[i] = true;
            ls.push_back(s[i]);
            dfs(dist + 1);
            ls.pop_back();
            st[i] = false;
        }
    };
    dfs(0);
    cout << -1 << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}