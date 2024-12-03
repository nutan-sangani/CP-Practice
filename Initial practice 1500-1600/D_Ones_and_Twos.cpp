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
    int n,q;
    cin>>n>>q;
    umll map;
    priority_queue<ll,vecll,greater<ll>> firstOne;
    priority_queue<ll,vecll> lastOne;
    ll sum=0;
    forn(0,n){
        ll a;
        cin>>a;
        sum+=a;
        map[i+1]=a;
        if(a==1){
            firstOne.push(i+1);
            lastOne.push(i+1);
        }
    }
    forn(0,q){
        int choice;
        cin>>choice;
        if(choice==1){
            ll find;
            cin>>find;
            while(!firstOne.empty() && map[firstOne.top()]==2){
                firstOne.pop();
            }
            int idx = n+1;
            if(!firstOne.empty()){
                idx = firstOne.top();
            }
            int length = idx-1;
            ll rangeHigh = sum - (2LL*length);
            if(find>=0 && find<=rangeHigh && !firstOne.empty()){
                cout<<"YES"<<endl;
                continue;
            }
            ll diff = find - rangeHigh;
            ll available = length*2LL;
            if(diff%2==0){
                if(diff<=available){
                    cout<<"YES"<<endl;
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    continue;
                }
            }
            else{
                while(!lastOne.empty() && map[lastOne.top()]==2){
                    lastOne.pop();
                }
                if(lastOne.empty()){
                    cout<<"NO"<<endl;
                    continue;
                }
                int idx2 = lastOne.top();
                ll removed = (n - idx2)*2LL;
                removed+=1;
                diff+=removed;
                if(available>=diff){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
        else{
            int idx,to;
            cin>>idx>>to;
            if(to==1){
                firstOne.push(idx);
                lastOne.push(idx);
            }
            sum-=map[idx];
            sum+=to;
            map[idx]=to;
        }
    }
}
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