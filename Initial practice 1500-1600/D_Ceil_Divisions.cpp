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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pll> ans;
        forn(3,n){
            if(i==64) continue;
            ans.pb(mp(i,n));
        }
        // cout<<ceil(float(65)/64.f);
        //thus now, 64 and n bacha h khali.
        if(n>64){
            int nCopy = n;
            while(nCopy>1){
                ans.pb(mp(n,64));
                nCopy = ceil(float(nCopy)/64.f);
            }
            int i=0;
            while(i<6){
                ans.pb(mp(64,2));
                i++;
            }
        }
        else{
            int nCopy = n;
            while(nCopy>1){
                ans.pb(mp(n,2));
                nCopy = ceil(float(nCopy)/2.f);
            }
        }
        int size = ans.size();
        cout<<size<<endl;
        forn(0,size){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
    return 0;
}