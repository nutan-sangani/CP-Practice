#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void helper()
{
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> a(2,0);
        vector<int> b(2,0);
        vector<int> c(2,0);
        vector<int> d(2,0);
        cin>>a[0];
        cin>>a[1];
        cin>>b[0];
        cin>>b[1];
        cin>>c[0];
        cin>>c[1];
        cin>>d[0];
        cin>>d[1];
        if(a[0]==b[0])
        {
            int bigger;
            int smaller;
            if(a[1]>b[1])
            {
                bigger=a[1];
                smaller=b[1];
            }
            else
            {
                bigger=b[1];
                smaller=a[1];
            }
            int length = bigger-smaller;
            cout<<length*length<<endl;
            continue;
        }
        else if(a[0]==c[0])
        {
            int bigger;
            int smaller;
            if(a[1]>c[1])
            {
                bigger=a[1];
                smaller=c[1];
            }
            else
            {
                bigger=c[1];
                smaller=a[1];
            }
            int length = bigger-smaller;
            cout<<length*length<<endl;
            continue;
        }
        else
        {
            int bigger;
            int smaller;
            if(a[1]>d[1])
            {
                bigger=a[1];
                smaller=d[1];
            }
            else
            {
                bigger=d[1];
                smaller=a[1];
            }
            int length = bigger-smaller;
            cout<<length*length<<endl;
            continue;
        }
    }
    return 0;
}