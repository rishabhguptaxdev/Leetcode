// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int LongestRepeatingSubsequence(string str){
		    // Code here
		string X = str;
		string Y = str;
		int m=X.length();
        int n=Y.length();
        int dp[m+1][n+1];
        
        // initialization
        for(int i=0;i<=m;i++)
            dp[i][0]=0;   // Eg LCS of "abc" & "" = 0
        for(int j=0;j<=n;j++)
            dp[0][j]=0;   // Eg LCS of "" & "abc" = 0
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1] && i!=j)     // this is the only extra condition
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends