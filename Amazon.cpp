1. Calculating Maximum Profit
	int maxProfit(int k, int n, int A[]) {
        int dp[k+1][n];
        memset(dp,0,sizeof dp);
        
        for(int i=1;i<=k;i++)
        {
            int val = -A[0]+dp[i-1][0];
            for(int j=1;j<n;j++)
            {
                dp[i][j] = max(dp[i][j-1], A[j]+val);
                val = max(val,-A[j]+ dp[i-1][j]);
            }
        }
        return dp[k][n-1];
    }
// <==============================================================================>

2. Longest Mountain in Array
	int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int i=0;
        int j;
        for(int i=0;i<n;i=j+1)
        {
            j=i;
            bool up = false, down = false;
            
            while(j<n-1 and arr[j]<arr[j+1])
            {
                up = true;
                j++;
            }
            
            if(up)
            {
                while(j<n-1 and arr[j]>arr[j+1])
                {
                    down = true;
                    j++;
                }
            }
            
            if(up and down)
            {
                ans = max(ans, j-i+1);
                j--;
            }
        }
        return ans;
    }


// <=====================================================================>

3. Maximum of Subarray
	vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and arr[dq.back()]<arr[i])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        vector<int>ans;
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);
            
            while(!dq.empty() and dq.front()<=i-k)
                dq.pop_front();
                
            while(!dq.empty() and arr[dq.back()]<arr[i])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        ans.push_back(arr[dq.front()]);
        return ans;
    }

// <=================================================================>

4. Print bracket in Matrix chain multiplication
	vector<vector<int>>dp;
    vector<vector<int>>bracket;
    int solve(int p[], int n,int i, int j)
    {
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int res = solve(p,n,i,k) + solve(p,n,k+1,j) + p[i-1]*p[k]*p[j];
            
            if(res<ans)
            {
                ans = res;
                bracket[i][j] = k;
            }
        }
        return dp[i][j] = ans;
    }
    
    void print(char& ch,string& ans, int i, int j)
    {
        if(i==j)
        {
            ans+=ch;
            ch++;
            return;
        }
        
        ans+='(';
        
        print(ch,ans,i,bracket[i][j]);
        print(ch,ans,bracket[i][j]+1,j);
        
        ans+=')';
    }
    string matrixChainOrder(int p[], int n){
        // code here
        dp.resize(n+1, vector<int>(n+1,-1));
        bracket.resize(n+1, vector<int>(n+1,-1));
        
        string temp = "";
        char ch = 'A';
        string ans = "";
        
        solve(p,n,1,n-1);
        print(ch,ans,1,n-1);
        return ans;
        
    }

// <====================================================================>

5. Phone Number Directory
	struct Node{
    bool end;
    Node* ch[256];
    
};

Node* root;
    Node* getNode()
    {
        Node* temp = new Node;
        
        for(int i=0;i<256;i++)
            temp->ch[i]=NULL;
            
        temp->end = false;
        
        return temp;
        
    }
    void insert(string temp)
    {
        struct Node* cur = root;
        for(int i=0;i<temp.length();i++)
        {
            if(cur->ch[temp[i]-'a']==NULL)
            {
                cur->ch[temp[i]-'a'] = getNode();
            }
            cur = cur->ch[temp[i]-'a'];
        }
        cur->end = true;
    }
    
    void search(Node* pre,vector<string>& temp,string prefix)
    {
        if(pre->end)
        {
            temp.push_back(prefix);
        }
        
        for(int i=0;i<26;i++)
        {
            Node* cur = pre->ch[i];
            if(cur!=NULL)
            {
                char ch = i+'a';
                search(cur,temp,prefix+ch);
            }
        }
    }
    
    bool solve(Node*& prev,string prefix, vector<string>&res, int n)
    {
        char last = prefix[n];
            
        Node* curNode = prev->ch[last-'a'];
        if(curNode==NULL)
        {
            return false;
        }
        else
        {
            search(curNode,res,prefix);
            prev = curNode;
            return true;
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans;
        root = getNode();
        for(int i=0;i<n;i++)
        {
            string temp = contact[i];
            insert(temp);
            
        }
        string prefix = "";
        Node* prev = root;
        
        bool temp = false;
        for(int i=0;i<s.length();i++)
        {
            
            prefix+=s[i];
            vector<string>store;
            if(i>0 and temp==false)
            {
                ans.push_back({"0"});
                continue;
            }
            temp = solve(prev,prefix,store,i);
            if(!temp)
                ans.push_back({"0"});
            else
            {
                ans.push_back(store);
            }
        }
        return ans;
    }


// <=============================================================================>

6. Maximum of Subarray
	vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() and arr[dq.back()]<arr[i])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        vector<int>ans;
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);
            
            while(!dq.empty() and dq.front()<=i-k)
                dq.pop_front();
                
            while(!dq.empty() and arr[dq.back()]<arr[i])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        ans.push_back(arr[dq.front()]);
        return ans;
    }


// <===============================================================================>

7. First non repeating characters in a string
	string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    int fre[26];
		    memset(fre,0,sizeof(fre));
		    queue<char>q;
		    
		    for(auto x:A)
		    {
		        fre[x-'a']++;
		        q.push(x);
		        
		        while(!q.empty())
		        {
		            if(fre[q.front()-'a']==1)
		            {
		                ans+=q.front();
		                break;
		            }
		            else
		                q.pop();
		        }
		        if(q.empty())
		            ans+='#';
		        
		    }
		    return ans;
		}


// <============================================================================>


8. Number of ways to reach top stair(Order does not matter)
	First Approach
	long long countWays(int m)
    {
        // your code here
        long long dp[m+1];
        dp[0]=1;
        dp[1] = 1;
        
        for(int i=2;i<=m;i++)
        {
            dp[i] = min(dp[i-1], dp[i-2])+1;
        }
        return dp[m];
    }

    Second Approach

    long long countWays(int m)
    {
        // your code here
        long long ans =  1+m/2;
        return ans;
        
    }

// <======================================================================================>


9. Is Sudoku VALID
    int isValid(vector<vector<int>> board){
        // code here
        map<string,int>check;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]==0)
                    continue;
                string temp = "";
                temp+="row"+to_string(i)+to_string((board[i][j]));
                if(check.find(temp)==check.end())
                    check[temp]++;
                else
                    return false;
                
                temp="";
                temp+="col"+to_string(j)+to_string((board[i][j]));
                if(check.find(temp)==check.end())
                    check[temp]++;
                else
                    return false;
                
                temp="";
                temp+="box"+to_string((i/3)*3+(j/3))+to_string((board[i][j]));
                if(check.find(temp)==check.end())
                    check[temp]++;
                else
                    return false;
                
            }
        }
        return true;
    }

// <========================================================================================>

11. serialize and deSerialize the tree
    void solve(Node* root, vector<int>&store)
    {
        if(!root)
        {
            store.push_back(-1);
            return;
        }
        store.push_back(root->data);
        solve(root->left,store);
        solve(root->right,store);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>store;
        solve(root,store);
        return store;
    }
    
    Node* build(vector<int>& A, int& i, int n)
    {
        if(i>=n or A[i]==-1)
        {
            i++;
            return NULL;
        }
            
        
        Node* root = new Node(A[i++]);
        root->left = build(A,i,n);
        root->right = build(A,i,n);
        
        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int n = A.size();
       int i = 0;
       return build(A,i,n);
    }

// <============================================================================>

12. Column Name from Column Number

    string colName (long long int n)
    {
        // your code here
        string ans = "";
        while(n)
        {
            long long rem = n%26;
            if(rem==0)
            {
                ans+='Z';
                n = n/26-1;
            }
            else
            {
                char ch = (rem-1)+'A';
                ans+=ch;
                n = n/26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

// <==================================================================================>

13. Rotten Oranges
    int xdir[4] = {-1,1,0,0};
    int ydir[4] = {0,0,-1,1};
    
    bool check(int x, int y, int n, int m)
    {
        return x>=0 and y>=0 and x<n and y<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int time = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int nx = xdir[k]+x;
                    int ny = ydir[k]+y;
                    if(check(nx,ny,n,m) and grid[nx][ny]==1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            if(q.size())
                time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return time;
    }

// <================================================================================>


14. Tree Burning
    void getNode(Node* root, Node*& targetNode, int& target,map<Node*,Node*>& store, Node* parent)
    {
        store[root] = parent;
        
        if(!root)
            return NULL;
        
        if(root->data==target)
        {
            targetNode = root;
        }
        
        getNode(root->left, targetNode, target, store,root);
        getNode(root->right,targetNode,target,store,root);
        
    }
    
    void solve(Node* root,map<Node*,Node*>& store, map<Node*,bool>& visited, int& ans, int Time)
    {
        ans = max(ans,Time);
        if(!root)
            return;
            
        if(visited.find(root->left)==visited.end())
        {
            visited[root->left] = true;
            solve(root->left,store,visited,ans,Time+1);
        }
        
        if(visited.find(root->right)==visited.end())
        {
            visited[root->right] = true;
            solve(root->right,store,visited,ans,Time+1);
        }
        
        if(store[root]!=NULL and  visited.find(store[root])==visited.end())
        {
            visited[store[root]] = true;
            solve(store[root],store,visited,ans,Time+1);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>store;
        
        Node* targetNode;
        getNode(root,targetNode,target,store, NULL);
        
        map<Node*,bool>visited;
        
        visited[targetNode] = true;
        int ans = 0;
        
        solve(targetNode,store, visited,ans,0);
        return ans;
        
    }

// <=============================================================================================>

15. Delete N nodes after M nodes of a linked list
    void linkdelete(struct Node  *head, int M, int N)
    {
        Node* cur = head;
        while(head)
        {
            for(int i=1;i<M;i++)
            {
                if(head)
                    head = head->next;
                else
                    return;
            }
            
            if(head==NULL)
                return;
            
            Node* temp = head->next;

            for(int i=0;i<N;i++)
            {
                if(temp)
                    temp = temp->next;
                else
                    break;
               
            }
            
            head->next = temp;
            head = temp;
        }
        
    }