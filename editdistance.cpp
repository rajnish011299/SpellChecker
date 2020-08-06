#include "editdistance.h"

int editdistance(std::string a, std::string b)
{
    int m = a.size(),n = b.size();
    int dp[m+1][n+1];
    int cost;
    for(int i=0; i<=m; i++)
    {
    	for(int j=0; j<=n; j++)
    	{
    		dp[i][j]=0;
    	}
    }
    for(int i=0; i<=m; i++)
    {
        dp[i][0]= i;
    }
    for(int j=0; j<=n; j++)
    {
        dp[0][j]= j;
    }

    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=m; i++)
        {
           if(a[i-1]==b[j-1])
            {
                cost=0;
            }
            else
            {
                cost=1;
            }

            int del, rep, ins;

            del = dp[i-1][j]+1;
            ins = dp[i][j-1]+1;
            rep = dp[i-1][j-1]+cost;

            dp[i][j] = std::min(del,std::min(ins,rep));



            if((i>1 and j>1))
            {
                        if((a[i-1]==b[j-2]) and (a[i-2]==b[j-1]))
                    {
                        int swp= dp[i-2][j-2]+cost;
                        dp[i][j]= std::min(swp,dp[i][j]);
                    }
            }
        }
    }
   return dp[m][n];

}