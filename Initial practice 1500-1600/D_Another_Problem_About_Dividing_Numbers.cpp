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

int findCountOfPrimeFactors(int a){
    int x=2;
    int cnt=0;
    int rootA = sqrt(a);
    while(a>1 && x<=rootA){
        if(a%x==0) {
            a/=x; 
            ++cnt;
        }
        else ++x;
    }
    if(a!=1) ++cnt;
    return cnt;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int cnt1=findCountOfPrimeFactors(a);
        int cnt2=findCountOfPrimeFactors(b);
        int cntSum = cnt1+cnt2;
        //there is a case, that if k=1, than a can be made to b with one ops or vice versa.
        if(k==1){
            if((a%b==0 || b%a==0) && (a!=b)){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else if(k<=cntSum){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}