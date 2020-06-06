#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define MAX 5000

int main(){
     
    /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int t;
    cin>>t;
    while(t--){
        int n,x=0,w[10]={0};
        cin>>n;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<10;j++){
                if(s[j]=='1'){
                    w[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<10;i++){
            if(w[i]%2!=0)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
