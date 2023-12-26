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
const int N = 5e5 + 10, mod = 1e9 + 7;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
struct node{
    int l, r, id;
}a[N], b[N], c[N * 2];
int js[N];
int pre[N];
vector<int> son[N];
map<pair<int,int>,int> er;
void Solve(){
    int n; cin >> n;
    rep(i, 1, n){
        cin >> a[i].l >> a[i].r;
        cin >> b[i].l >> b[i].r;
        c[2 * i - 1] = a[i];
        c[2 * i] = b[i];
        c[2 * i - 1].id = i;
        c[2 * i].id = i;
        if(a[i].l > b[i].l) swap(a[i], b[i]);
    }
    sort(c + 1, c + 1 + 2 * n, [](node a, node b){
        if(a.l == b.l) return a.r < b.r;
        return a.l < b.l;
    });
    ll cnt = 0;
    set<int> s;
    ll res = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> ls;
    for(int i = 1;i <= 2 * n + 1;i ++){
        son[c[i].l].push_back(c[i].id);
        if(c[i].l == c[i - 1].l){
            cnt ++;
            js[c[i].id] ++;
            // if(js[c[i].id] == 2 && a[c[i].id].l < b[c[i].id].l){
            //     cnt --;
            //     js[c[i].id] --;
            //     er[{a[c[i].id].r,c[i].id}] = 1;
            //     // ls.push_back(c[i].id);
                
            //     // cout << "erase: ";
            //     // cout << ' ' << c[i].id << endl;
            // } 
            s.insert(c[i].id);
            q.push({c[i].r, c[i].id});
            continue;
        }  
        pre[c[i].l] = c[i - 1].l;
        int now = c[i - 1].l;
        // cout << now << ' ' << pre[now] << endl;
        // for(auto x:son[now]){
        //     cnt ++; js[x] ++;
        //     q.push({a[x].r, x});
        //     // cout << x << endl;
        // }
        ls.clear();
        while(q.size()){
            auto [h, id] = q.top();
            // if(er.count({h,id})){
            //     q.pop();
            //     er.erase({h,id});
            //     continue;
            // }
            if(h >= now) break;
            js[id] --; cnt --;
            if(js[id] == 0) s.erase(id);
            q.pop();
        }
        if(s.size() == n){
            ll need = cnt - s.size();
            ll sum = 0;
            for(auto j : son[now]){
                // cout << now << ' ' << need << endl;
                if(js[j] == 2 && a[j].l < a[j].r) sum += fpow(2, need - 1, mod);
                // res = (res + fpow(2, need - 1, mod)) % mod;
                else sum += fpow(2, need, mod);
                // res = (res + fpow(2, need, mod)) % mod;
            }
            cout << now << ' ' << sum << endl;
        }

        cnt ++;
        js[c[i].id] ++;
        // if(js[c[i].id] == 2 && a[c[i].id].l < b[c[i].id].l){
        //     cnt --;
        //     js[c[i].id] --;
        //     er[{a[c[i].id].r,c[i].id}] = 1;
        //     // son[c[i].l].push_back(c[i].id);
        //         // cout << "erase: ";
        //         // cout << ' ' << c[i].id << endl;
        // } 
        s.insert(c[i].id);
        q.push({c[i].r, c[i].id});
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}