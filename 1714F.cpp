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
void out(vector<int> a){
    cout << "YES" <<endl;
    rep(i,1,siz(a)-1) cout << a[i-1] << ' ' << a[i] << endl;
    return ;
}
void Solve(){
    int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    if(d12 == d23 + d13){
        if(d12 == 2) swap(p[1],p[2]);
        else{
            swap(p[1], p[d12]);
            swap(p[2], p[d13]);
        }
        out(p);
        return;
    }
    if(d13 == d12 + d23){
        swap(p[d13],p[2]);
        swap(p[d12],p[1]);
        out(p);
        return;
    }
    if(d23 == d12 + d13){
        swap(p[0], p[1]);
        swap(p[2], p[d23]);
        swap(p[1], p[d12]);
        out(p);
        return;
    }
    int sum = d12 - d23 + d13;
    int k = sum/2, x = d12 - k, y = d13 - k;
    if((sum&1)||k <= 0||x <= 0||y <= 0||x + y + k>n - 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" <<endl;
    swap(p[2], p[d12 + y]);
    swap(p[1], p[d12]);
    rep(i, 1, d12) cout << p[i-1] << ' ' << p[i] << endl;
    swap(p[d12], p[k]);
    rep(i, d12+1, n-1) cout << p[i-1] << ' ' << p[i] <<endl;

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