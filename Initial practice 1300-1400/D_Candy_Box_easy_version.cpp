#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(omll& map)
{
    vecll freq;
    for(auto it: map){
        freq.pb(it.second);
    }
    sort(freq.begin(),freq.end(),greater<int>());
    ll ans=0;
    int n=freq.size();
    ll prev=freq[0]+2;
    for(int i=0;i<n;i++){
        if(prev>freq[i]){
            prev=freq[i];
            ans+=(freq[i]*1LL);
        }
        else if(prev<=freq[i] && (prev-1)>0){
            ans+=((prev-1)*1LL);
            prev-=1;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        omll map;
        forLoop
        {
            int k;
            cin>>k;
            map[k]++;
        }
        helper(map);
    }
    return 0;
}
//2,3,4
//4,3,2
//4+3+2 = 9