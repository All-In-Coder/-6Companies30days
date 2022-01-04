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