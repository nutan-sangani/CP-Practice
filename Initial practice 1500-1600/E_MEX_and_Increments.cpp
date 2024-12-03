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

void solve()
{
    int n;
    cin>>n;
    vecll a(n,0);
    multiset<ll> sortedElements;
    vecll ans(n+1,-1);
    forn(0,n){
        cin>>a[i];
        sortedElements.insert(a[i]);
    }
    sort(itr(a));
    int last = -1;
    forn(0,n){
        ll diff = i - a[i];
        if(diff<0){
            last = i+1;
            break;
        }
    }
    if(last==-1) last=n+1;
    int i=0;
    ll cost=0;
    // cout<<last<<endl;
    while(i<last){
        ll equalRemovalCost = sortedElements.count(i);
        ans[i]=cost+equalRemovalCost;
        if(i<last-1 && !sortedElements.empty()){
            //i ko banane ke liye minimum cost kya hoga.
            if(sortedElements.find(i)!=sortedElements.end()){
                sortedElements.erase(sortedElements.find(i));
                cost+=0;
                ++i;
                continue;
            }
            auto it = sortedElements.lower_bound(i); //equal ya greater dega, equal chalega par greater nhi.
            --it;
            cost += (i - (*it));
            sortedElements.erase(it);
        }
        ++i;
    }
    forn(0,n+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
//0 2 3 4 5 5 6
//0 1 2 3 4 5 6

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
//we want to remove all the numbers that are equal to i.
//if i se chote element bache h, then usee farq nhi pdta, cuz MEX doesn't work that way
//also ye sare i ke equal elem ko hume 1 se hi badhana padega