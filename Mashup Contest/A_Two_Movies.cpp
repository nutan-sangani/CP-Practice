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
    int n;
    cin>>n;
    vecll a(n,0),b(n,0);
    forn(0,n){
        cin>>a[i];
    }
    forn(0,n){
        cin>>b[i];
    }
    int negCount=0;
    int posCount=0;
    int firstCount=0,secondCount=0;
    forn(0,n){
        if(a[i]==-1 && b[i]==-1) ++negCount;
        else{
            if(a[i]>b[i]){
                firstCount+=a[i];
            }
            else if(a[i]<b[i]){
                secondCount+=b[i];
            }
            else if(a[i]==1 && b[i]==1){
                ++posCount;
            }
        }
    }
    int diff = abs(firstCount - secondCount);
    if(diff<=posCount){
        int maxi = max(firstCount,secondCount);
        posCount-=diff;
        int half = posCount/2;
        maxi+=half;
        firstCount = secondCount = maxi;
        if(posCount%2!=0) firstCount+=1;
    }
    else{
        if(firstCount<secondCount){
            firstCount+=posCount;
        }
        else secondCount+=posCount;
    }
    diff = abs(firstCount-secondCount);
    if(negCount>diff){
        negCount-=diff;
        int half = negCount/2;
        int mini = min(firstCount,secondCount);
        mini-=half;
        if(negCount%2!=0) mini-=1;
        cout<<mini<<endl;
    }
    else cout<<min(firstCount,secondCount)<<endl;
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