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

class MyComp{
    public:
    bool operator()(const pll& a,const pll& b){
        return a.second<b.second;
    }
};

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,d,k;
        cin>>n>>d>>k;
        vecll a(n+1,0);
        um<ll,vecll> map;
        forn(0,k){
            ll l,r;
            cin>>l>>r;
            a[l]+=1;
            map[l].pb(r);
        }
        ll sum=0;
        forn(1,n+1){
            sum+=a[i];
            a[i]=sum;
        }
        priority_queue<ll,vecll,greater<ll>> pq;
        int maxi,mini,minIdx,maxIdx;
        maxi=INT_MIN;
        mini = INT_MAX;
        forn(1,n+1){
            int start = i;
            int end = i+d-1;
            if(end>n){
                break;
            }
            while(!pq.empty() && pq.top()<start) pq.pop();
            int endWale = pq.size();
            int prev = start-1>=0 ? a[start-1] : 0;
            int startWale = a[end]-prev;
            int temp = startWale+endWale;
            if(temp>maxi){
                maxi=temp;
                maxIdx=i;
            }
            if(temp<mini){
                mini=temp;
                minIdx=i;
            }
            vecll tempi = map[start];
            for(auto x : tempi){
                pq.push(x);
            }
        }
        cout<<maxIdx<<" "<<minIdx<<endl;
    }
    return 0;
}