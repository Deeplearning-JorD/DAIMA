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
    int mb = 0;
    for(int i = 1;i <= 9;i ++){
        int x; cin >> x;
        mb |= x << i;
    }
    int d[9] = {22,76,400,832,46,178,928,616,372};
    vector<int> st(1 << 10, 1e9);
    queue<int> q;
    st[0] = 0;
    q.push(0);
    while(q.size()){
        auto t = q.front(); q.pop();
        if(t == mb){
            cout << st[mb] << endl;
            return;
        }
        for(int i = 0;i < 9;i ++){
            if(st[t ^ d[i]] != 1e9) continue;
            st[t ^ d[i]] = st[t] + 1;
            q.push({t ^ d[i]});
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}