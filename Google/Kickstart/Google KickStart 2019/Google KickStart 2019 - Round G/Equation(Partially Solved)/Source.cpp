#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,result;
    cin>>t;
    int n,m;
    int var=0;
    while(t--){
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(m==0){
            int  cnt = count(a,a+n,a[0]);
            if(n!=cnt){
                result = -1;
            }
            else{
                result = a[0]-1;
            }
        }
        else{
        int x = (int)log2(m)+1;
        int s = pow(2,x+1) - 1;
        int r = m+1;
        while(r>m){
            int sol = 0;
            for(int i=0;i<n;i++){
                sol = sol + (a[i]^s);
            }
            r=sol;
            s--;
        }
        result = s;
        }
        cout<<"Case #"<<++var<<": "<<result+1<<endl;
    }
}
