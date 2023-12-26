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
const int N = 5e5 + 5;
int a[N], b[N];
void Solve(){
    int n; cin >> n;
    vector<int> ne(n + 1);
    a[n + 1] = n + 1;
    rep(i, 1, n) cin >> a[i];
    int i = 1, j = 1;
    while(i <= n){
        while(a[j] <= a[i]) j ++;
        ne[i] = j;
        i = j;
    }
    
    int al = 0;
    i = 1;
    while(i <= n){
        a[al ++]=ne[i] - i;
        i = ne[i];
    }
    sort(a,a+al);
    b[0]=0;
    for(i=0,j=0;j<al;j++){
        if(a[i]!=a[j]){
            a[++i]=a[j];
            b[i]=0;
        }
        b[i]++;
    }

    al=i+1;
    vector<bool> st(n + 1);
    st[0]=1;
    for(i=0;i<al;i++){
        j=1;
        int p=b[i];
        while(j<=p){
            p-=j;
            int x=a[i]*j;
            for(int k=n / 2;k>=x;k--){
                if(st[k-x])st[k]=1;
            }
            j<<=1;
        }
        if(p){
            int x=a[i]*p;
            for(int k=n / 2;k>=x;k--){
                if(st[k-x])st[k]=1;
            }
        }
    }
    if(st[n / 2]) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}