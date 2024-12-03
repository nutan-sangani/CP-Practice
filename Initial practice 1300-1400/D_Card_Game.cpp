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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct suit{
    char val;
    vector<ll> data;
};

void helper(suit t,suit a,suit b,suit c)
{
    int toMatch=0;
    if(a.data.size()%2!=0){
        toMatch++;
    }
    if(b.data.size()%2!=0){
        toMatch++;
    }
    if(c.data.size()%2!=0){
        toMatch++;
    }
    if(t.data.size()<toMatch){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    sort(t.data.begin(),t.data.end(),greater<ll>());
    sort(a.data.begin(),a.data.end(),greater<ll>());
    sort(b.data.begin(),b.data.end(),greater<ll>());
    sort(c.data.begin(),c.data.end(),greater<ll>());
    int size=a.data.size();
    int tVar=0;
    for(int i=0;i<size;){
        int left=size-i;
        if(left>=2){
            cout<<a.data[i+1]<<a.val<<" "<<a.data[i]<<a.val<<endl;
            i+=2;
        }
        else{
            cout<<a.data[i]<<a.val<<" "<<t.data[tVar++]<<t.val<<endl;
            i+=2;
        }
    }
    size=b.data.size();
    for(int i=0;i<size;){
        int left=size-i;
        if(left>=2){
            cout<<b.data[i+1]<<b.val<<" "<<b.data[i]<<b.val<<endl;
            i+=2;
        }
        else{
            cout<<b.data[i]<<b.val<<" "<<t.data[tVar++]<<t.val<<endl;
            i+=2;
        }
    }
    size=c.data.size();
    for(int i=0;i<size;){
        int left=size-i;
        if(left>=2){
            cout<<c.data[i+1]<<c.val<<" "<<c.data[i]<<c.val<<endl;
            i+=2;
        }
        else{
            cout<<c.data[i]<<c.val<<" "<<t.data[tVar++]<<t.val<<endl;
            i+=2;
        }
    }
    size=t.data.size();
    if(size>toMatch){
        for(int i=tVar;i<size;){
            int left=size-i;
            if(left>=2){
                cout<<t.data[i+1]<<t.val<<" "<<t.data[i]<<t.val<<endl;
                i+=2;
            }
        }
    }
    else{
        return;
    }
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
        vector<ll> s;
        vector<ll> h;
        vector<ll> d;
        vector<ll> c;
        char trump;
        cin>>trump;
        for(int i=0;i<2*n;i++){
            string k;
            cin>>k;
            if(k[1]=='S')
            {
                s.push_back(k[0]-'0');
            }
            else if(k[1]=='C'){
                c.push_back(k[0]-'0');
            }
            else if(k[1]=='H'){
                h.push_back(k[0]-'0');
            }
            else{
                d.push_back(k[0]-'0');
            }
        }
        suit h1;
        h1.val='H';
        h1.data=h;
        suit d1;
        d1.val='D';
        d1.data=d;
        suit c1;
        c1.val='C';
        c1.data=c;
        suit s1;
        s1.val='S';
        s1.data=s;
        if(trump=='S'){
            helper(s1,d1,h1,c1);
        }
        else if(trump=='C'){
            helper(c1,d1,h1,s1);
        }
        else if(trump=='D'){
            helper(d1,h1,c1,s1);
        }
        else{
            helper(h1,d1,c1,s1);
        }
    }
    return 0;
}