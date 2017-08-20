//Source - www.geeksforgeeks.org
//https://www.youtube.com/watch?v=GTJr8OvyEVQ
#include<bits/stdc++.h>
using namespace std;
string pat ,text ;
int n , m ;
int lps[1002]; // longest proper prefix that is also a suffix.

int vivek =0 ; // just check comment to test github
void fun()
{
    int i = 1;
    int len = 0;  lps[0] =0 ;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i] = len ;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i] =0  ;
                i++;
            }
        }
    }
}
int main()
{
    cin>>text>>pat;
    m = pat.size();
    n = text.size(); 
    fun(); 
    int i =0 , j =0 ;
    while(i<n)
    {
        if(pat[j]==text[i]) 
        {
            i++;j++;
        }
        if(j==m)
        {
            cout<<"found at position "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<n && pat[j]!=text[i])
        {
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return 0;
}
