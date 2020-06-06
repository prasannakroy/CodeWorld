#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define MAX 5000
   
int main(){
     
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    
    int t;
    cin>>t;
    ll n,m;
    while(t--){
        cin>>n>>m;
        vector<pair<ll,ll>> v;
        vector<ll> help(m,1e10);
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.push_back(make_pair(x,i%m));
            if(v[i].first<help[i%m]){
                help[i%m]=v[i].first;
            }
        }
        sort(v.begin(),v.end());
        ll mx=*max_element(help.begin(),help.end());
        int q=0;
        while(help[q]!=mx)q++;
        /*for(int i=0;i<n;i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        for(int i=0;i<m;i++){
            cout<<help[i]<<endl;
        }*/

        int i=0;
        vector<ll> cnt(m,0);
        while(v[i].second!=q){
            cnt[v[i].second]+=1;
            i++;
        }
        cnt[v[i].second]+=1;
        ll r = i;
        ll s,min=1e10,res;
        int flag=1;
        //cout<<r<<endl;
        ll j=0;
        while(r<n){
            if(flag==1){
                s = v[r].first - v[j].first;
                if(s<min)
                    min=s;
                if(cnt[v[j].second]==1){
                    flag=0;
                    r++;
                }
                cnt[v[j].second]-=1;
                i=j;
                j++;
            }
            else{
                cnt[v[r].second]+=1;
                if(cnt[v[i].second]==1)
                    flag=1;
                else {
                    flag=0;
                    r++;
                }
            }
            res=min;
        }
        cout<<res<<endl;
    }
    return 0;
}
