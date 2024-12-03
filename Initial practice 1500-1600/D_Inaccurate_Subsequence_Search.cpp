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

void helper(vecll& a,vecll& b,ll k,ll n,ll m)
{
    ll countSimilar=0;
    ll ans=0;
    map<ll,ll> freqB;
    map<ll,ll> freqWindow;
    for(int i=0;i<m;i++){
        freqB[b[i]]++;
    }
    for(int i=0;i<m;i++){
        freqWindow[a[i]]++;
    }
    for(auto it : freqWindow){
        if(freqB[it.first]!=0){
            countSimilar+=(min<ll>(freqB[it.first],it.second));
        }
    }
    if(countSimilar>=k)
        ans++;

    for(int i=0;i<=n-m;i++){ //1,
        ll end = i+m;
        ll removed = a[i];
        if(end>=n){
            break;
        }
        ll added = a[end];
        freqWindow[removed]--;
        freqWindow[added]++;
        ll diff = freqB[removed]-freqWindow[removed];
        if(diff>0 && added!=removed){
            countSimilar--;
        }
        diff = freqB[added] - freqWindow[added];
        if(diff>=0 && added!=removed){
            countSimilar++;
        }
        if(countSimilar>=k)
            ans++;
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vecll a(n);
        vecll b(m);
        forLoop
            cin>>a[i];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        helper(a,b,k,n,m);
    }
    return 0;
}
