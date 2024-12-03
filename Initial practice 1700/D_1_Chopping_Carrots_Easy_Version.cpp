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
    bool operator()(const pair<short,short>& a,const pair<short,short>& b){
        if(a.first!=b.first)
            return a.first<b.first;
        else return a.second<b.second;
    }
};

void solve(){
    short n,k;
    cin>>n>>k;
    vector<pair<short,short>> ranges;
    short maxi = -1;
    forn(0,n){
        short a;
        cin>>a;
        maxi = max<short>(maxi,a);
        for(short j=1;j<=k;j++){
            short val = a/j;
            ranges.pb(mp(val,i));
            if(val==1) break;
        }
    }
    if(maxi<k){
        cout<<0<<endl;
        return;
    }
    sort(itr(ranges),MyComp());
    int size = ranges.size();
    um<short,short> map;
    int left,right;
    left = right = 0;
    right=-1;
    short ans = abs(ranges[0].first - ranges[size-1].first);
    short count = 0;
    while(right<(size-1)){
        if(count<n){ //means right ko badha
            right+=1;
            pair<short,short> temp = ranges[right];
            if(map[temp.second]==0){
                ++count;
            }
            map[temp.second]+=1;
            if(count==n){
                ans = min<short>(ans,abs(ranges[left].first-ranges[right].first));
            }
        }
        else{
            ans = min<short>(ans,abs(ranges[left].first - ranges[right].first));
            pair<short,short> temp = ranges[left];
            if(map[temp.second]==1){
                --count;
            }
            map[temp.second]-=1;
            left+=1;
            if(count==n){
                ans = min<short>(ans,abs(ranges[left].first-ranges[right].first));
            }
        }
    }
    cout<<ans<<endl;
}
//isse better bhi solution hosakta tha, with almost same time complexity.
//0 to a0 can be considered as the minimum (atmost 3000 val hongi), than baki sare no.s ko 
//ya toh x (ai/v=x, ie x is aisa no. jisko ai se divide kiya toh v ie minimum no milega) ya fhir k se
//divide krke max nikal and range nikal.

//dono methods ko same time atmost 10^6 lagega. but 2nd wale ki sc is less, 1st wali ki sc mene short use krke
//decr ki h.

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}