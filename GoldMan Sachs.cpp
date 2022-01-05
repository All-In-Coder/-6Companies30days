1. Given an array of strings, return all groups of strings that are anagrams.
	// First Approach

	vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        map<string,vector<string>>store;
        for(int i=0;i<s.size();i++)
        {
            string t = s[i];
            sort(t.begin(), t.end());
            store[t].push_back(s[i]);
        }
        
        vector<vector<string>>ans;
        for(auto x:store)
            ans.push_back(x.second);
            
        return ans;
    }

    //Second Approach
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        map<string,vector<string>>store;
        for(int i=0;i<s.size();i++)
        {
            string t = s[i];
            int bit[26]={0};
            
            for(int j=0;j<t.length();j++)
                bit[t[j]-'a']++;
                
            string temp="";
            for(int i=0;i<26;i++)
                temp+=to_string(bit[i]);
                
            store[temp].push_back(t);
        }
        
        
            
        vector<vector<string>>ans;
        for(auto x:store)
            ans.push_back(x.second);
            
        return ans;
    }


// <=====================================================================================>



2.Overlapping rectangles
	int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        if(L2[0]>R1[0] or L1[0]>R2[0])
            return false;
            
        if(L1[1]<R2[1] or L2[1]<R1[1])
            return false;
            
        return true;
    }

// <==========================================================================================>

3. Count the subarrays having product less than k 
	int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0;
        int i = 0, j=0;
        long long prod = 1;
        
        while(j<n)
        {
            prod = prod*a[j];
            while(i<j and prod>=k)
            {
                prod/=a[i];
                i++;
            }
            
            if(prod<k)
            {
                int N = j-i+1;
                ans = ans + N;
            }
            j++;
           
        }
        return ans;
    }


// <======================================================================>

4. Run Length Encoding
	string encode(string src)
	{     
	  //Your code here 
	  string ans = "";
	  int i = 0;
	  while(i<src.length())
	  {
	      int j = i;
	      int count = 0;
	      while(j<src.length() and src[i]==src[j])
	      {
	          count++;
	          j++;
	      }
	      ans = ans + src[i] + to_string(count);
	      i = j;
	  }
	  return ans;
	}   

// <=========================================================================>

5.Ugly Number
	ull getNthUglyNo(int n) {
	    // code here
	    int two_i = 1, three_i=1, five_i = 1;
	    ull arr[n+1];
	    arr[1] = 1;
	    if(n==1)
	        return 1;
	        
	    ull ans  =1;
	    for(int i=2;i<=n;i++)
	    {
	        ull p1 = 2*arr[two_i];
	        ull p2 = 3*arr[three_i];
	        ull p3 = 5*arr[five_i];
	        
	        ans = min({p1,p2,p3});
	        if(ans==p1)
	            two_i++;
	            
	        if(ans==p2)
	            three_i++;
	            
	        if(ans==p3)
	            five_i++;
	            
	        arr[i] = ans;
	    }

	    return arr[n];
	}

// <================================================================>

6.  GCD of String
	bool check(string temp, string s)
    {
        int n = temp.size();
        int m = s.size();
        int i=0,j=0;
        while(j<m)
        {
            if(s[j]!=temp[i])
                return false;
            j++;
            i = (i+1)%n;
        }
        
        return true;
    }
    string gcdOfStrings(string s, string t) {
        
        string ans = "";
        int n = s.length();
        int m = t.length();
        
        int k = __gcd(n,m);
        
        if(n<m)
            swap(s,t);
        string sub = t.substr(0,k);
        
        if(check(sub,s) and check(sub,t))
            ans = sub;
        return ans;
    } 
// <====================================================================>

7.  Find the kid which gets tha damaged toy
	int findPosition(int n , int m , int k) {
        // code here
        if (m <= n - k + 1)
            return m + k - 1;

    
        m = m - (n - k + 1);
        return (m % n == 0) ? n : (m % n);
    }

// <==========================================================================>

8.  Count Number of ways to decode a string
	int CountWays(string s){
		    // Code here
	    int n = s.size();
	    long dp[n+1] = {0};
	    
	    dp[0] = 1;
	    int MOD = 1e9+7;
	    if(s[0]>'0')
	        dp[1] = 1;
	    for(int i=1;i<n;i++)
	    {
	        if(s[i]>'0')
	            dp[i+1] = dp[i];
	            
	        string temp="";
	        temp+=s[i-1];
	        temp+=s[i];
	        
	        if(temp>="10" and temp<="26")
	        {
	            dp[i+1] = (dp[i+1]%MOD + dp[i-1]%MOD)%MOD;
	        }
	        
	    }
	    return dp[n]%MOD;
	}

// <====================================================================================>

9.Given a pattern containing only I's and D's. I for increasing and D
	string findMinNumberPattern(string str)
{
    string ans = ""; // Minimum number following pattern
 
    int i = 0;
    int cur = 1; // cur val following pattern
    int dCount = 0; // Count of char 'D'
    while (i < str.length()) {
 
        char ch = str[i];
 
        // If 1st ch == 'I', incr and add to ans
        if (i == 0 && ch == 'I') {
            ans += to_string(cur);
            cur++;
        }
 
        // If cur char == 'D',
        // incr dCount as well, since we always
        // start counting for dCount from i+1
        if (ch == 'D') {
            dCount++;
        }
 
        int j = i + 1; // Count 'D' from i+1 index
        while (j < str.length()
               && str[j] == 'D') {
            dCount++;
            j++;
        }
 
        int k = dCount;  // Store dCount
        while (dCount >= 0) {
            ans += to_string(cur + dCount);
            dCount--;
        }
 
        cur += (k + 1); // Manages next cur val
        dCount = 0;
        i = j;
    }
 
    return ans;
} 

// <============================================================================>

10. Find max 10 numbers in a list having 10M entries
	We can use priority queue and the time complexity will be NlogK

// <==========================================================================>

11. Find the Missing and Repeated Number in the unsorted array.
	int *findTwoElement(int *arr, int n) {
        // code here
        int Xor = arr[0];
        for(int i=1;i<n;i++)
            Xor^=arr[i];
        
        for(int i=1;i<=n;i++)
            Xor^=i;
        
        int bit = Xor & ~(Xor-1);
        int x = 0,y=0;
        
        for(int i=0;i<n;i++)
        {
            if(bit&arr[i])
                x^=arr[i];
            else
                y^=arr[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            if(i&bit)
                x^=i;
            else
                y^=i;
        }
        
          int *ans = new int[2];
        
        for(int i=0;i<n;i++)
        {
            if(x==arr[i])
            {
                ans[0]=x;
                ans[1]=y;
                break;
            }
            if(y==arr[i])
            {
                ans[0]=y;
                ans[1]=x;
                break;
            }
        }
      
        
        
        return ans;
    }

// <====================================================================================>

12. Find total number of Squares in a N*N chessboard
	long long squaresInChessBoard(long long N) {
        // code here
        if(N==1)
            return 1;
        long long a = N*N;
        N = N-1;
        long long b = (N*(N+1)*(2*N+1))/6;
        
        long long ans = a+b;
        return ans;
    }
// <===================================================================================>

13. Decode String
	string decodedString(string s){
        // code here
        stack<string>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=']')
            {
                string temp = "";
                temp+=s[i];
                st.push(temp);
            }
            
            else
            {
                
                stack<string>rev;
                while(!st.empty() and st.top()!="[")
                {
                    rev.push(st.top());
                    st.pop();
                }
                
                string temp = "";
                while(!rev.empty())
                {
                    temp+=rev.top();
                    rev.pop();
                }
                
                if(!st.empty() and st.top()=="[")
                    st.pop();
                
                
                int times = 0;
                stack<int>store;
                if(!st.empty())
                {
                    while(!st.empty() and st.top()>="0" and st.top()<="9")
                    {
                        store.push(stoi(st.top()));
                        st.pop();
                    }
                    while(!store.empty())
                    {
                        times = times*10 + store.top();
                        store.pop();
                    }
                }
                string cur = "";
                for(int j=0;j<times;j++)
                    cur+=temp;
                st.push(cur);
                
            }
        }
       
        return st.top();
    } 

// <========================================================================================>

14. Minimum Size Subarray Sum
	int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        
        int n = nums.size();
        
        long sum = 0;
        int i=0,j=0;
        while(i<n)
        {
            
            if(sum+nums[i]<target){
                sum+=nums[i];
                i++;
            }
            else
            {
                ans = min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        
        return ans==INT_MAX?0:ans;
        
        
    }

// <===========================================================================>

15. Array Pair Sum Divisibility Problem
	bool canPair(vector<int> nums, int k) {
        // Code here.

        unordered_map<int,int>store;
        for(int x:nums)
        {
            store[x%k]++;
        }
        
        for(auto x:store)
        {
            int freq = x.second;
            int ele = x.first;
            
            if(ele==0)
            {
                if(freq%2)
                    return false;
                store[ele] = 0;
            }
            else if(store[k-ele]==freq)
            {
                store[k-ele] = 0;
                store[ele] = 0;
            }
            else
                return false;
        }
        for(auto x:store)
        {
            if(x.second!=0)
                return false;
        }
        return true;
    }