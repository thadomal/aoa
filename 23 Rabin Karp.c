#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("\t\tRABIN KARP ALGORITHM\n");
    char a[50];
    printf("ENTER THE STRING : ");
    gets(a);
    char b[50];
    printf("ENTER THE PATTERN TO BE SEARCHED : ");
    gets(b);
    int n = strlen(a);
    int m = strlen(b);
    int d = 10,p=0,t=0,h=1,i,j,mod = 11;
    for(i=0;i<m-1;i++)
        h=(d*h)%mod;
    for(i=0;i<m;i++)
       {
         p = (d*p + b[i])%mod;
         t = (d*t + a[i])%mod;
       }
    for(i=0;i<=n-m;i++)
    {  if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==m)
                printf("PATTERN FOUND AT : %d \n",i+1);
        }
        if(i<n-m)
        {
          t = (d*(t - a[i]*h) + a[i+m])%mod;
            if(t < 0)
              t = (t + mod);
        }
    }
    return 0;
}
