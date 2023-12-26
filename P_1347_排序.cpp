/*
 * @Author: JorD
 * @LastEditTime: 2023-05-02 16:35:47
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
const int N = 110;
vector<int> son[N];
int st[N][N];
int instak[N];
void dfs(int i, int now){
    if(instak[now]){
        cout << "Inconsistency found after " << i << " relations.";
        exit(0);
    }
    instak[now] = 1;
    for(auto x:son[now]){
        dfs(i, x);
    }
    instak[now] = 0;
}
int f[N];
int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 0, n - 1) f[i] = i;
    vector<int> in(n + 1, -1);
    rep(i, 1, m){
        string s;
        cin >> s;
        int a = s[0] - 'A', b = s[2] - 'A';
        in[a] = max(0, in[a]);
        in[b] = max(0, in[b]);
        if(a == b){
            cout << "Inconsistency found after " << i << " relations.";
            return;
        }
        if(st[a][b]) continue;
        st[a][b] = 1;
        son[a].push_back(b);
        f[find(a)] = find(b);
        in[b] ++;
        dfs(i, a);
        set<int> ss;
        rep(j, 0, n - 1) ss.insert(find(j));
        if(ss.size() != 1) continue;
        queue<int> q;
        auto inn = in;
        rep(j, 0, n - 1)if(!inn[j])q.push(j);
        vector<char> res;
        while(q.size()){
            auto now = q.front(); q.pop();
            res.push_back('A' + now);
            int cnt = 0;
            for(auto x:son[now]){
                if(-- inn[x] == 0){
                    cnt ++;
                    q.push(x);
                }
            }
            if(cnt > 1) break;
        }
        if(res.size() == n){
            cout << "Sorted sequence determined after " << i << " relations: ";
            for(auto x:res) cout << x;
            cout << ".";
            return;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}