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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<char> a(n,'.');
        um<char,int> odd;
        um<char,int> even;
        um<char,int> oddR;
        um<char,int> evenR;
        forn(0,n){
            char c;
            cin>>c;
            if(i%2==0){
                ++even[c];
            }
            else ++odd[c];
            a[i]=c;
        }
        if(n==2){
            cout<<0<<endl;
            continue;
        }
        else if(n==1){
            cout<<1<<endl;
            continue;
        }
        ll mini = LLONG_MAX;
        if(n%2==0){
            int length = n;
            int places = ceil(float(length)/2.f);
            int min1=INT_MAX;
            int min2=INT_MAX;
            for(int j=0;j<26;j++){
                int cost = places - even[j+'a'];
                min1=min<ll>(cost,min1);
            }
            for(int j=0;j<26;j++){
                int cost = places - odd[j+'a'];
                min2=min<ll>(cost,min2);
            }
            mini = min1+min2;
        }
        else{
            forn(0,n){
                int cost1,cost2;
                cost1=cost2=INT_MAX;
                int places = (n-1)/2;
                if(i%2==0){
                    --even[a[i]];
                }
                else --odd[a[i]];
                for(int j=0;j<26;j++){
                    int count;
                    int count2;
                    if(i%2==0){
                        count = odd[j+'a']+evenR[j+'a'];
                        count2 = even[j+'a']+oddR[j+'a'];
                    }
                    else{
                        count = even[j+'a']+oddR[j+'a'];
                        count2 = odd[j+'a']+evenR[j+'a'];
                    } 
                    int wrong = places - count;
                    int wrong2 = places - count2;
                    cost1 = min<ll>(cost1,wrong);
                    cost2=min<ll>(cost2,wrong2);
                }
                mini=min<ll>(mini,cost1+cost2+1);
                if(i%2==0){
                    ++evenR[a[i]];
                }
                else ++oddR[a[i]];
            }
        }        
        cout<<mini<<endl;
    }
    return 0;
}