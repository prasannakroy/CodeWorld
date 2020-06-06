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
     
    int a[128];
    a[0]=0;
    a[1]=0;
    for(int i=2;i<128;i++){
        int k=128;
        for(int j=i-2;j>=0;j--){
            if(a[i-1]==a[j]){
                k=j;
                break;
            }
        }
        if(k==128)
            a[i]=0;
        else{
            a[i]=i-1-k;
        }
    }
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int x = count(a,a+n,a[n-1]);
        cout<<x<<endl;
    }
    return 0;
}
