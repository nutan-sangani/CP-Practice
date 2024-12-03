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

void helper(string& a,int n,int k)
{
    int sameChalega = 1;
    forn(0,n){
        if(a[i]>a[i%k]){
            sameChalega = -1;
            break;
        }
        else if(a[i]<a[i%k]){
            sameChalega = 1;
            break;
        }
    }
    if(sameChalega==1){
        std::cout<<n<<endl;
        forn(0,n) std::cout<<a[i%k];
        return;
    }
    vector<char> window(k,'0');
    forn(0,k){
        window[i]=a[i];
    }
    int i=k-1;
    do{
        if(a[i]=='9'){
            window[i]='0';
            i-=1;
            continue;
        }
        int num = a[i]-'0';
        num+=1;
        window[i] = '0'+num;
        break;
    }while(i>=0);
    std::cout<<n<<endl;
    forn(0,n){
        std::cout<<window[i%k];
    }
    return;
}

int main()
{
    FASTIO
    
    {
        int n,k;
        cin>>n>>k;
        string nums;
        cin>>nums;
        helper(nums,n,k);
    }
    return 0;
}