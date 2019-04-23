#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}
void lcs1(char *str1,char *str2,int len1,int len2)
{
	int L[len1+1][len2+1];
	int i,j;
	for (i=0;i<=len1;i++)
	{
		for (j=0;j<=len2;j++)
		{
			if (i==0 || j==0)
				L[i][j]=0;
			else if (str1[i-1] == str2[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	int index = L[len1][len2];
	char lcs[index+1];
	lcs[index] = '\0';

	int m = len1, n = len2;
	while (m > 0 && n > 0)
	{
		if (str1[m-1] == str2[n-1])
		{
			lcs[index-1] = str1[m-1];
			m--;
			n--;
			index--;
		}
		else if (L[m-1][n] > L[m][n-1])
			m--;
		else
			n--;
	}
	printf("Longest common subsequence is: %s",lcs);
	printf("\nLength of longest common subsequence is: %d",L[len1][len2]);
}

int main()
{
	char s1[15],s2[15];
	int len1,len2;
	printf("Enter string 1: ");
	scanf("%s",s1);
	printf("Enter string 2: ");
	scanf("%s",s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	lcs1(s1,s2,len1,len2);
	return 0;
}
