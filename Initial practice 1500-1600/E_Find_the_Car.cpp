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

void helper(ll q,umll& map,vecll& time,vecll& dist,vector<double>& speed)
{
    while(q--){
        ll d;
        cin>>d;
        if(map[d]!=0){
            cout<<map[d]<<" ";
            continue;
        }
        if(d==0){
            cout<<0<<" ";
            continue;
        }
        ll total = 0;
        int index = (lower_bound(dist.begin(),dist.end(),d)-dist.begin());
        int prevDist = index>0 ? dist[index-1] : 0;
        ll diffDist;
        diffDist = d-prevDist;
        total = index>0 ? time[index-1] : 0;
        // cout<<diffDist<<endl;
        double speedi = speed[index];
        total += ((diffDist)/(speedi));
        // cout<<((diffDist)/(speedi))<<" "<<total<<endl;
        cout<<total<<" ";
        continue;
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,q;
        cin>>n>>k>>q;
        vecll dist,time;
        vector<double> speed;
        umll map;
        for(int i=0;i<k;i++){
            ll a;
            cin>>a;
            dist.pb(a);
        }
        for(int i=0;i<k;i++){
            ll a;
            cin>>a;
            time.pb(a);
            map[dist[i]]=a;
        }
        for(int i=0;i<k;i++){
            ll prevT,prevD;
            prevT = i>0 ? time[i-1]:0;
            prevD = i>0 ? dist[i-1]:0;
            double speedi = ((double)(dist[i]-prevD)*1.f)/((double)(time[i]-prevT)*1.f);
            speed.pb(speedi);
            // cout<<speedi<<" ";
        }
        helper(q,map,time,dist,speed);
    }
    return 0;
}