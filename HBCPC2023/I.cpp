/*
 * @Author: JorD
 * @LastEditTime: 2023-05-21 19:47:52
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
ll p[1229];
bool isp[10004];
ll pl=0;
map<ll,ll>mp;
ll a[100],b[100];
ll al;
ll lc;
ll ans;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll x1,y1;
    ll gcd = exgcd(b,a%b,x1,y1);
    x = y1, y = x1 - a/b*y1;
    return gcd;
}
void cal(ll a,ll b){
    if(a==1||b==1)return;
    ll k;
    ll m = b, x, y;
    ll d = exgcd(a,m,x,y);
    k = x/d%m;
    k += m;
    k %= m;
    ans=min(ans,k*a-1);
}
int idxx = 0;
void dfs(int i,ll x,ll y){
    cal(x,y);
    if(i==al)return;
    dfs(i+1,x*a[i],y/a[i]);
    dfs(i+1,x,y);
}
void Solve(){
    int n; cin >> n;
    ll x;
    ll cnt;
    rep(i, 1, n){
        cin >> x;
        for(int j=0;p[j]*p[j]<=x;j++){
            if(x%p[j]==0){
                cnt=0;
                while(x%p[j]==0){
                    x/=p[j];
                    cnt++;
                }
                mp[p[j]]=max(mp[p[j]],cnt);
            }
        }
        if(x!=1){
            mp[x]=max(1ll,mp[x]);
        }
    }
    mp[2]++;
    al=0;
    lc=1;
    for(auto [x,y]:mp){
        a[al]=1;
        for(int j=0;j<y;j++)a[al]*=x;
        lc*=a[al];
        al++;
    }
    ans=lc-1;
    dfs(0,1,lc);
    ll res = 1;
    cout<<ans<<endl;
    return;
}
int main(){
    for(int i=2;i<10004;i++){
        if(!isp[i])p[pl++]=i;
        for(int j=0;p[j]*i<10004;j++){
            isp[p[j]*i]=1;
            if(i%p[j]==0)break;
        }
    }
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}