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

void solve(){
    ll n,m;
    cin>>n>>m;
    multiset<ll> set;
    ll sum = 0;
    forn(0,n){
        ll a;
        cin>>a;
        set.insert(a);
        sum+=a;
    }
    ll count = n;
    while(!set.empty() && !(set.size()==1)){
        auto largest = set.end();
        --largest;
        ll target = m - *largest;
        ll iterVal,largestVal;
        largestVal = *largest;
        set.erase(largest);
        auto iter = set.lower_bound(target);
        iterVal = *iter;
        if(iter!=set.end()){
            if(iterVal==target){ //largest val ke equal hua toh iter ko piche jana hi padega
                count-=2;
                if(set.size()==1){
                    count+=1;
                }
                set.erase(iter);
            }
            else if(iter!=set.begin()){
                --iter;
                count-=2;
                if(set.size()==1){
                    count+=1;
                }
                set.erase(iter);
            }
        }
        else{ //means last wala is still chota than target.
            largest = set.end();
            --largest;
            count-=2;
            if(set.size()==1){
                count+=1;
            }
            set.erase(largest);
        }
    }
    cout<<(sum+count)<<endl;
}

int main()
{
    FASTIO
    
    {
        solve();
    }
    return 0;
}
//3,3,6,11
//100-11 = 