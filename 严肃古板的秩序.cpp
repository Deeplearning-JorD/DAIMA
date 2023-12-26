/*
 * @Author: JorD
 * @LastEditTime: 2023-01-20 16:37:05
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
ll qmi(ll a,ll p){
    ll k = a;
    ll res=1;
    while(k){
        if(k&1) res=res*a%p;
        a=a*(ll)a%p;
        k>>=1;
    }
    return res;
}
struct node{
    int x;
    char c;
    ll val;
};
vector<node> ji;
int n;
ll now;
vector<char> op;
void dfs(int d, __int128 w){
    if(d == n){
        if(w == now){
            int idx = 1;
            for(auto [x, c, val]:ji){
                if(x) cout << val;
                else cout << op[idx ++];
            }
            cout << '=' << now;
            exit(0);
        }
        return;
    }
    auto [x, c, val] = ji[d];
    if(x){
        if(op.back() == '+'){
            dfs(d + 1, w + val);
        }else if(op.back() == '-'){
            dfs(d + 1, w - val);
        }else if(op.back() == '#'){
            if(w <= 0||val <= 0) return;
            dfs(d + 1, qmi(w, val));
        }
    }else{
        if(c == '?'){

            op.push_back('-');
            dfs(d + 1, w);
            op.pop_back();

            op.push_back('+');
            dfs(d + 1, w);
            op.pop_back();
            
            op.push_back('#');
            dfs(d + 1, w);
            op.pop_back();
        }
        else{
            op.push_back(c);
            dfs(d + 1, w);
            op.pop_back();
        }
    }
}
void Solve(){
    string s;
    cin >> s;
    op.push_back('+');
    for(auto x:s){
        // cout << x << ' ' << now << endl; 
        if(x == '='){
            ji.push_back({1, x, now});
            now = 0;
            continue;
        }
        if(x == '?' || x == '+' || x == '-' || x == '#'){
            ji.push_back({1, x, now});
            ji.push_back({0, x, 0});
            now = 0;
        }else now = now * 10 + x - '0';
    }
    n = siz(ji);
    dfs(0, 0);
    cout << -1<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}