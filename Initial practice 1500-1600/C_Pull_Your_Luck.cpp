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

ll binarySearch(ll target){
    ll l,h,mid;
    l=0LL;
    h=target;
    while(l<=h){
        mid=(l+h)/2LL;
        ll val = (mid*(mid+1LL))/2LL;
        if(val==target) return mid;
        else if(val<target){
            l=mid+1;
        }
        else h=mid-1;
    }
    return mid*-1;
}

void helper(ll n,ll x,ll p)
{
    ll y = n-1LL-x+1LL;
    ll multiple=0;
    while(multiple<=3*n){
        ll toMake = y+(multiple*n*1LL);
        ll needed = binarySearch(toMake);
        if(needed<0){
            // needed*=-1;
            // if(needed>p){
            //     cout<<"NO"<<endl;
            //     return;
            // }
        }
        else{
            if(needed>p){
                cout<<"NO"<<endl;
                return;
            }
            else{
                // cout<<toMake<<endl;
                // cout<<needed<<endl;
                // cout<<multiple<<endl;
                cout<<"YES"<<endl;
                return;
            }
        }
        multiple++;
    }
    cout<<"NO"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,p;
        cin>>n>>x>>p;
        helper(n,x,p);
    }
    return 0;
}
//n,x,p
//16,12,36
//y=4, 16, 36, 52, 84, 100, 116, 132, 148, 164,180,196,212,228,244,260

//yes chahiye and no mila.