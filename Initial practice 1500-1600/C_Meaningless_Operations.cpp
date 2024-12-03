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

bool checkAllOnes(ll a,int power){
    if(pow(2,power)-1==a) return true;
    return false;
}

ll findSmallestFactor(ll a){
    for(int i=2;i<=(sqrt(a));i++){
        if(a%i==0){
            return i;
        }
    }
    return a;
}

ll getCompliment(ll a){
    ll ans=0;
    int flag=0;
    for(int i=35;i>=0;i--){
        bool isOne = (a & 1LL<<i) > 0 ? true : false;
        if(!isOne && flag==1){
            ans = ans | 1LL<<i;
            continue;
        }
        else if(isOne && flag){
            continue;
        }
        else if(isOne && flag==0){
            flag=1;
        }
    }
    return ans;
}

void helper(ll a)
{
    for(int i=0;i<32;i++){
        if(checkAllOnes(a,i)){
            ll smallestFactor = findSmallestFactor(a);
            cout<<a/smallestFactor<<endl;
            return;
        }
    }
    ll b = getCompliment(a);
    cout<<a+b<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll a;
        cin>>a;
        helper(a);
    }
    return 0;
}