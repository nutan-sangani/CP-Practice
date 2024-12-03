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

bool inRange(pll& p,int a){
    return (p.first<=a && p.second>=a);
}

void helper(int a,int b,int c,ll z)
{
    pll aRange,bRange,cRange;
    cRange.first = pow(10,c-1);
    cRange.second = pow(10,c)-1;
    aRange.first = pow(10,a-1);
    aRange.second = pow(10,a)-1;
    bRange.first = pow(10,b-1);
    bRange.second = pow(10,b)-1;
    ll mini = aRange.first+bRange.first;
    int i,j,k;
    i=aRange.first; //10
    j=bRange.first; //10
    k=cRange.first; //100
    if(mini < cRange.first){
        while(mini<cRange.first){
            int target = cRange.first;
            if(i<=aRange.second){
                target-=i;
                if(inRange(bRange,target)){
                    j=target;
                    break;
                }
            }
            else{
                cout<<-1<<endl;
                return;
            }
            i++;
        }
    }
    else{
        if(inRange(cRange,mini)){
            k=mini;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    ll rem = z;
    while(rem>0 && aRange.second>=i){
        int incrementalB = (bRange.second - j); //8
        int incrementalC = (cRange.second - k); //7
        int minInc = min(incrementalB,incrementalC)+1;
        if(minInc>=rem){
            int A = i;
            int B = j + (rem - 1);
            int C = k + (rem-1);
            cout<<A<<" + "<<B<<" = "<<C<<endl;
            return;
        }
        else{
            rem-=minInc;
            ++i;
            if(bRange.first<j){
                --j;
            }
            else {
                ++k;
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        ll k;
        cin>>a>>b>>c>>k;
        helper(a,b,c,k);
    }
    return 0;
}