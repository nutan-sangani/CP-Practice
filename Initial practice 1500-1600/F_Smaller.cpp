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

void printAnswer(int smallestA,int biggestB,ll aFreq,ll bFreq,bool anyOneElseA,bool anyOneElseB){
    if(biggestB>smallestA){
        cout<<"YES"<<endl;
        return;
    }
    //else unki value same hai
    if(aFreq==bFreq){
        cout<<"NO"<<endl;
        return;
    }
    else if(aFreq<bFreq){
        if(anyOneElseA){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}

void helper(ll n)
{
    int i=0;
    int smallestA='a';
    int biggestB='a';
    ll aFreq=1;
    ll bFreq=1;
    bool anyOneElseA = false;
    bool anyOneElseB = false;
    bool doesBiggerExist = false;
    while(i<n){
        i++;
        int choice;
        cin>>choice;
        if(choice==1){
            int freq;
            cin>>freq;
            string x;
            cin>>x;
            if(doesBiggerExist){
                cout<<"YES"<<endl;
                continue;
            }
            for(int j=0;j<x.length();j++){
                if(x[j]==smallestA){
                    aFreq+=freq;
                }
                else{
                    anyOneElseA=true;
                }
            }
            printAnswer(smallestA,biggestB,aFreq,bFreq,anyOneElseA,anyOneElseB);
        }
        else{
            int freq;
            cin>>freq;
            string x;
            cin>>x;
            if(doesBiggerExist){
                cout<<"YES"<<endl;
                continue;
            }
            for(int j=0;j<x.length();j++){
                if(x[j]!='a'){
                    anyOneElseB=true;
                }
                if(x[j]>biggestB){
                    doesBiggerExist=true;
                    biggestB=x[j];
                    bFreq = freq;
                }
                else if(x[j]==biggestB){
                    bFreq+=freq;
                }
            }
            printAnswer(smallestA,biggestB,aFreq,bFreq,anyOneElseA,anyOneElseB);
        }
    }
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        helper(n);
    }
    return 0;
}