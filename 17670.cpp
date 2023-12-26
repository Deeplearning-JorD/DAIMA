/*
 * @Author: JorD
 * @LastEditTime: 2022-12-17 13:55:48
 */
#include<iostream>
using namespace std;
int main(){
    long long t;
    cin  >> t;
    while(t--){
        char c;
        cin >> c;
        double a[3][2];
        for(int y=0;y<3;y++){
            for(int x=0;x<2;x++){
                cin >> a[y][x];
            }
        }
            int p=0;
            if(a[0][0]==a[1][0])p++;
            if(a[0][0]==a[2][0])p++;
            if(a[1][0]==a[2][0])p++;
            if(a[0][1]==a[1][1])p++;
            if(a[0][1]==a[2][1])p++;
            if(a[1][1]==a[2][1])p++;
            if(p>=2){
                cout << "NO"<<endl;
            }else{
                cout << "YES"<<endl;
            }
        }else{
            cout << "NO"<<endl;
        }
    }
    return 0;
}
