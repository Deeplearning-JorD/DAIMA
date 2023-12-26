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
    int n;
    cin >> n;
    vector<int> res(1000);
    auto dfs = [&](auto dfs, int now, int ji){
        if(now == 0){
            cout << "nunhehhe";
            int sum = 0;
            for(int i = 30;i >= 1;i --){
                for(int j = 1;j <= res[i];j ++)
                    cout << "h";
                sum += res[i];
                if(sum) cout << 'a'; 
            }
            cout << endl;
            return;
        }
        for(int i = ji;i >= 1;i --){
            int kun = 1 << i;
            kun --;
            if(kun <= now){
                res[i] ++; 
                dfs(dfs, now - kun, i);
                return;
            }
        }
    };
    dfs(dfs, n, 30);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}