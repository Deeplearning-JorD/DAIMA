/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 01:44:03
 * how to Get
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
    int n, k;
    cin >> n >> k;
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    set<char> s;
    rep(i, 1, n) rep(j, 1, n){
        cin >> f[i][j];
        s.insert(f[i][j]);
    }
    if((n * k) % 100){
        cout << "error\n";
        return;
    }
    if(s.size() == 1){
        rep(i, 1, n * k / 100){
            rep(j, 1, n * k / 100){
                cout << f[1][1]; 
            }
            cout << endl;
        }
        return;
    }
    if(k == 100){
        rep(i, 1, n){
            rep(j, 1, n){
                cout << f[i][j];
            }
            cout << endl;
        }
        return;
    }
    if(k == 125 || k == 175){
        for(int i = 1;i <= n;i += 4){
            for(int j = 1;j <= n;j += 4){
                int x = i + 3, y = j + 3;
                if(x > n || y > n) continue;
                set<char> c;
                for(int ii = i;ii <= x;ii ++){
                    for(int jj = j;jj <= y;jj ++){
                        c.insert(f[ii][jj]);
                    }
                }
                if(c.size() > 1){
                    cout << "error\n";
                    return;
                }
            }
        }
        if(k == 125){
            rep(i, 1, n){
                rep(j, 1, n){
                    cout << f[i][j];
                    if(j % 4 == 0){
                        cout << f[i][j];
                    }
                }
                cout << endl;
                if(i % 4 == 0){
                    rep(j, 1, n){
                        cout << f[i][j];
                        if(j % 4 == 0)
                            cout << f[i][j];
                    }
                    cout << endl;
                }
            }
        }else{
            rep(i, 1, n){
                rep(j, 1, n){
                    cout << f[i][j];
                    if(j % 4 == 0){
                        cout << f[i][j] << f[i][j] << f[i][j];
                    }
                }
                cout << endl;
                if(i % 4 == 0){
                    rep(o,1,3){
                        rep(j, 1, n){
                            cout << f[i][j];
                            if(j % 4 == 0){
                                cout << f[i][j] << f[i][j] << f[i][j];
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
    if(k == 150){
        for(int i = 1;i <= n;i += 2){
            for(int j = 1;j <= n;j += 2){
                int x = i + 1, y = j + 1;
                if(x > n || y > n) continue;
                set<char> c;
                for(int ii = i;ii <= x;ii ++){
                    for(int jj = j;jj <= y;jj ++){
                        c.insert(f[ii][jj]);
                    }
                }
                if(c.size() > 1){
                    cout << "error\n";
                    return;
                }
            }
        }
        rep(i, 1, n){
            rep(j, 1, n){
                cout << f[i][j];
                if(j % 2 == 0)
                    cout << f[i][j];
            }
            cout << endl;
            if(i % 2 == 0){
                rep(j, 1, n){
                    cout << f[i][j];
                    if(j % 2 == 0)
                        cout << f[i][j];
                }
                cout << endl;
            }
        }
    }
    if(k == 200){
        rep(i, 1, n){
            rep(j, 1, n){
                cout << f[i][j] << f[i][j];
            }
            cout << endl;
            rep(j, 1, n){
                cout << f[i][j] << f[i][j];
            }
            cout << endl;
        }
        return;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}