/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 14:11:45
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
void Solve(){
    int n, x;
    cin >> n >> x;
    if(n % x){
        cout << -1 << endl;
        return;
    }
    vector<int> st(n + 1, -1);
    vector<int> use(n + 1, 1);
    st[1] = x;
    st[n] = 1;
    use[1] = use[x] = 0;
    int now = x;
    while(st[now] == -1){   
        int bei = now;
        for(bei = now;bei <= n;bei += now){
            if(n % bei == 0&&use[bei]){
                break;                
            }
        }
        use[bei] = 0;
        st[now] = bei;
        now = bei;
    }
    rep(i, 1, n){
        if(st[i] == -1){
            int now = i;
            while(st[now] == -1){
                int bei = now;
                while(bei <= n&&!use[bei]) bei += now;
                if(bei > n){
                    cout << -1 << endl;
                    return;
                }
                use[bei] = 0;
                st[now] = bei;
                now = bei;
            }
        }
    }
    rep(i, 1, n) cout << st[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}