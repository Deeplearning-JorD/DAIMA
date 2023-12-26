/*
 * @Author: JorD
 * @LastEditTime: 2022-08-12 15:55:42
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
void out(){
    cout<<"0 0 0\n";
    return;
}
void Solve(){
    int n; cin>>n;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<int> b;
    int js=0,last=-1;
    for(auto x:a){
        if(last>x){
            b.push_back(js);
            js=0;
        }
        js++;
        last=x;
    }
    b.push_back(js);
    ll idx=0,num=0;
    for(int i=0;i<b.size();i++){
        num+=b[i];
        if(num>n/2) break;
        idx=i;
    }
    if(idx<2){
        out();
        return;
    }   
    vector<ll> pre(idx+1,0);
    rep(i,0,idx){
        if(!i) pre[i]=b[i];
        else pre[i]=pre[i-1]+b[i];
    } 
    ll Au=b[0],Ag=b[1],Cu=b[2];
    for(int i=1;i<=idx;i++){
        ll left=pre[i]-pre[0];
        ll right=pre[idx]-pre[i];
        if(left>pre[0]&&right>pre[0]){
            Ag=left,Cu=right;
            break;
        }
    }
    if(Au>=Ag||Au>=Cu) out();
    else cout<<Au<<' '<<Ag<<' '<<Cu<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}