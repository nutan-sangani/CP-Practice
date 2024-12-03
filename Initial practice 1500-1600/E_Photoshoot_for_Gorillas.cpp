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
        int n,m,k;
        cin>>n>>m>>k;
        int w;
        cin>>w;
        vecll weights(w,0);
        forn(0,w) cin>>weights[i];
        vecll hori(n,1);
        vecll verti(m,1);
        int counter=1;
        forn(0,n){
            int end = i+k;
            if(end>n){
                if(counter>1)
                    --counter;
                hori[i]=counter;
            }
            else{
                hori[i]=counter;
                if(counter<k) ++counter;
            }
        }
        counter=1;
        forn(0,m){
            int end = i+k;
            if(end>m){
                if(counter>1)
                    --counter;
                verti[i]=counter;
            }
            else{
                verti[i]=counter;
                if(counter<k) ++counter;
            }
        }
        priority_queue<ll,vecll> pq;
        forn(0,n){
            for(int j=0;j<m;j++){
                pq.push(1LL*hori[i]*verti[j]);
            }
        }
        sort(itr(weights));
        ll sum = 0;
        for(int i=w-1;i>=0;i--){
            ll top = pq.top();
            ll temp = (1LL*weights[i]*top);
            pq.pop();
            sum+=temp;
        }
        cout<<sum<<endl;
    }
    return 0;
}