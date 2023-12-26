/*
 * @Author: JorD
 * @LastEditTime: 2022-12-01 23:45:11
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
    vector<int> cnt(11);
    rep(i, 0, 9) cin >> cnt[i];
    int sum = accumulate(all(cnt), 0);
    int num = 0, mx = 0;
    rep(i, 0, 9){
        if(cnt[i] > mx){
            num = i;
            mx = cnt[i];
        }  
    }
    if(sum == 1 && cnt[0] == 1){
        cout << 0 << endl;
        return;
    }
    if(num == 0 && mx > (sum - mx)){
        cout << "-1\n";
        return;
    }
    if(num&&mx > (sum - mx + 1)){
        cout << "-1\n";
        return;
    }
    if(cnt[0] > (sum - cnt[0])){
        cout << "-1\n";
        return;
    }
    if(num == 0&&mx == (sum - mx)){
        vector<int> res;
        rep(i, 1, 9){
            rep(j, 1, cnt[i]) res.push_back(i);
        }
        int idx = 0;
        rep(i, 1, mx){
            cout << res[idx ++];
            cout << 0;
        }
        if(sum & 1) cout << res[idx ++];
        cout << endl;
        return;
    }
    if(num && mx == (sum - mx + 1)){
        vector<int> res;
        rep(i, 0, 9){
            if(i == num) continue;
            rep(j, 1, cnt[i]) res.push_back(i);
        }
        int idx = 0;
        rep(i, 1, mx){
            cout << num;
            if(idx < siz(res))cout << res[idx ++];
        }
        cout << endl;
        return;
    }
    vector<int> res(sum + 1);
    int idx = 1;
    int use = -1;
    res[0] = -1;
    while(idx <= sum){
        int uuse = use;
        bool flag = false;
        rep(now, 1, 9){
            if(!cnt[now]||use == now) continue;
            res[idx ++] = now;
            flag = true;
            cnt[now] --;
            if(idx > sum) break;
            bool st = false;
            rep(jiji, 0, 9){
                if(!cnt[jiji]||jiji == now) continue;
                res[idx ++] = jiji;
                cnt[jiji] --; 
                st = true;
                use = jiji;
                break;
            }
            vector<int> last;
            if(!st){
                per(i, idx - 1, 1){
                    if(cnt[now] && res[i] != now && res[i - 1] != now){
                        last.push_back(res[i]);
                        last.push_back(now);
                        cnt[now] --;
                    }else last.push_back(res[i]);
                }
                reverse(last.begin(), last.end());
                int cc = 0;
                vector<int> v, vv;
                rep(i, 0, sum - 1){
                    if(last[i] == now){
                        cout << now;
                        rep(j, i + 1, sum - 1){
                            if(last[j] == now) vv.push_back(now);
                            else v.push_back(last[j]);
                        }
                        sort(all(v));
                        int l = 0;
                        while(l < siz(v)){
                            cout << v[l] << vv[l];
                            l ++;
                        }
                        cout << endl;
                        return;
                    }
                    cout << last[i];
                }
                cout << endl;
                return;
            }
            break;
        }
        if(!flag){
            vector<int> last;
            int now = use;
            per(i, idx - 1, 1){
                if(cnt[now] && res[i] != now && res[i - 1] != now){
                    last.push_back(res[i]);
                    last.push_back(now);
                    cnt[now] --;
                }else last.push_back(res[i]);
            }
            int cc = 0;
            vector<int> v, vv;
            reverse(last.begin(), last.end());
            rep(i, 0, sum - 1){
                if(last[i] == now){
                    cout << now;
                    rep(j, i + 1, sum - 1){
                        if(last[j] == now) vv.push_back(now);
                        else v.push_back(last[j]);
                    }
                    sort(all(v));
                    int l = 0;
                    while(l < siz(v)){
                        cout << v[l] << vv[l];
                        l ++;
                    }
                    cout << endl;
                    return;
                }
                cout << last[i];
            }
            cout << endl;
            return;
        }
    }
    rep(i, 1, sum) cout << res[i];
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