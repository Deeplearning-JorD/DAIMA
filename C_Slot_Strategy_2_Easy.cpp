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
void Solve(){
    int n; cin >> n;
    vector<vector<int>> cnt(3, vector<int> (10));
    vector<string> s(3);
    for(auto &x:s) cin >> x;
    for(int i = 0;i < 3;i ++){
        for(int j = 0;j < n;j ++){
            cnt[i][s[i][j] - '0'] = 1;
        }
    }
    int res = 1e9;
    vector<int> id;
    id.push_back(0);
    id.push_back(1);
    id.push_back(2);
    do{
        for(int i = 0;i < 10;i ++)if(cnt[0][i] & cnt[1][i] & cnt[2][i]){
            int i1 = 0, i2 = 0, i3 = 0;
            int now = 0, j = 0;
            while(cnt[0][i] | cnt[1][i] | cnt[2][i]){
                if(i1 == n) i1 = 0;
                if(i2 == n) i2 = 0;
                if(i3 == n) i3 = 0;
                if(cnt[id[0]][i] && s[id[0]][i1] - '0' == i ) cnt[id[0]][i] = 0;
                else if(cnt[id[1]][i] && s[id[1]][i2] - '0' == i) cnt[id[1]][i] = 0;
                else if(cnt[id[2]][i] && s[id[2]][i3] - '0' == i) cnt[id[2]][i] = 0;
                i1 ++;
                i2 ++;
                i3 ++;
                if(cnt[0][i] & cnt[1][i] & cnt[2][i]) j = now + 1;
                now ++;
            }
            res = min(res, now - j);
        }
    }while(next_permutation(id.begin(), id.end()));
    if(res == 1e9) cout << -1;
    else cout << res - 1;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}