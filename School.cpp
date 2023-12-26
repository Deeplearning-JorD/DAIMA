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
    ll n, m, h, t;
    cin >> n >> h >> m >> t;
    map<ll,int> q;
    ll INF = h*m;
    q[INF] = 0;
    rep(i, 1, n){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a = a*m + b;
        c = c*m + d;
        if(a>c){
            q[a] ++;
            q[0] ++;
            q[c+1] --;  
        }else{
            q[a] ++;
            q[c+1] --;
        }
    }
    vector<pair<ll,int>> a;
    rep(i,1,t){
        ll x ,y;
        cin >> x >> y;
        x = x*m + y;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    int len = t, idx = 0;
    vector<bool> st(t+1);
    int now=0;
    ll last=0,wz=0;
    for(auto x:q){
        now += x.second;
        int l=0,r=-1;
        if(last > 0){
            l = wz;
            if(now >= 0) r = x.first-1;
            while(a[idx].first<l&&idx<t) idx++;
            while(a[idx].first>=l&&a[idx].first<=r&&idx<t){
                st[a[idx].second]= true;
                idx++;
            }
        }
        wz=x.first,last=now;
    }
    for(int i=1;i<=t;i++){
        if(!st[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}