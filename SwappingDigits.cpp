#include<vector>
#include<stack>
#include<map>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
using namespace std;
#define FOR(i,a,b)              for(long long i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
class SwappingDigits
{
      public:
            string minNumber(string num) 
            {
                  REP(i,num.size())
                  {
                        if(i==0)
                        {
                              int min = 10;int minind = -1;
                              FOR(j,i+1,num.size())
                              {
                                    if(num[j]-'0'<=min && num[j]-'0'<num[i]-'0' && num[j]-'0'!=0)
                                          min = num[j]-'0',minind = j;
                              }
                              if(minind!=-1)
                              {     
                                    char temp = num[0];
                                    num[0] = num[minind];
                                    num[minind] = temp;
                                    return num;      
                              }
                        }
                        else
                        {
                              int min = 10;int minind = -1;
                              FOR(j,i+1,num.size())
                              {
                                    if(num[j]-'0'<=min && num[j]-'0'<num[i]-'0')
                                          min = num[j]-'0',minind = j;
                              }
                              if(minind!=-1)
                              {     
                                    char temp = num[i];
                                    num[i] = num[minind];
                                    num[minind] = temp;
                                    return num;      
                              }
                              
                        }      
                  }
                  
                  
                        return num;
            }         
};
