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
const int N = 2e5 + 10;
int st[22][N];
int a[N];
int find(int l, int r){
    if(l > r) return 0;
    int mid = log2(r - l + 1);
    return min(st[mid][l], st[mid][r - (1 << mid) + 1]);
}
void Solve(){
    int n, k;
    cin >> n >> k;
    rep(i, 1, n){
        cin >> a[i];
        st[0][i] = a[i];
    }
    for(int j = 1;j <= 20;j ++){
        for(int i = 1;i + (1 << j) - 1 <= n;i ++){
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        if(a[i] > a[i - 1]){
            cnt ++;
            if(cnt >= k){
                rep(j, 1, n) cout << a[j] << ' ';
                cout << endl;
                return;
            }
            continue;
        }
        cnt = 1;
    }
    int last = n - k + 1;
    for(int j = n - k;j >= 1;j --){
        if(a[j] > a[j + 1]) break;
        if(a[j] < find(j + 1, j + k - 1)) last = j;
    }
    sort(a + last, a + last + k);
    rep(i, 1, n) cout << a[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}