//1st
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parenthesis.push(s[i]);
            } else {
                if (parenthesis.empty()) {
                    return false;
                }

                char top = parenthesis.top();
                if ((s[i] == ')' && top == '(') ||
                    (s[i] == ']' && top == '[') ||
                    (s[i] == '}' && top == '{')) {
                    parenthesis.pop();
                } else {
                    return false; 
                }
            }
        }

        return parenthesis.empty(); 
    }
};

// 2nd
class MinStack {
public:
    stack<long long int> set1;
    stack<long long int> set2;
    MinStack() {
    }
    
    void push(int val) {
    set1.push(val);
    if(set2.empty() || val < getMin())
    {
        set2.push(val);
    }    
    }
    
    void pop() {
        if(set1.top() == set2.top())
        {
            set1.pop();
            set2.pop();
        }
        else
        {
            set1.pop();
        }

    }
    
    int top() {
        return set1.top();
    }
    
    int getMin() {
         return set2.top();
    }
};

// 3rd

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ngl(n), ngr(n);

        ngl[0] = height[0];
        ngr[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            ngl[i] = max(height[i], ngl[i-1])+ 0ll;
        }

        for(int i=n-2; i>=0; i--){
            ngr[i] = max(height[i], ngr[i+1]) + 0ll;
        }
        int ans =0ll; 
        for(int i=0; i<n; i++){
            ans+= min(ngl[i],ngr[i]) - height[i];
        }
        return ans;
    }
};

//4th
class Solution {
public:
    string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;
    string cr = "";
    int currentNum = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(currentNum);
            strStack.push(cr);
            currentNum = 0;
            cr = "";
        } else if (c == ']') {
            int repeatCount = numStack.top();
            numStack.pop();
            string p = strStack.top();
            strStack.pop();
            for (int i = 0; i < repeatCount; ++i) {
                p += cr;
            }
            cr = p;
        } else {
            cr += c;
        }
    }

    return cr;
}
};
// 5th
class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right =  height.size() - 1;
       int maxArea = 0;
       while(left < right)
       {
           int currentArea = min(height[left],height[right]) * (right -left);
           maxArea = max(maxArea,currentArea);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
       }
       return maxArea;
    }
};

// 6th
class MyStack {

public:
    /* Initialize your data structure here. */
    MyStack() {}

    /* Push element x onto the stack. */
    void push(int x) {
        // Move all elements from q1 b 0'to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element to q1
        q1.push(x);

        // Move elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    /* Removes the element on the top of the stack and returns it. */
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;


};

// 7th
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> qu;

        for(int i = 0; i < students.size(); i++)
        {
            st.push(sandwiches[sandwiches.size() - 1 - i]);
            qu.push(students[i]);
        }
        int n = 0;
        while(!st.empty()){
            if(st.top() == qu.front()) {
                st.pop();
                qu.pop();
                n = 0;
            }
            else
            {
                qu.push(qu.front());
                qu.pop();
                n++;
            }
            if(n == qu.size()) 
            {
                break;
            }
        }
        return qu.size();
    }
};
//8th

class FrontMiddleBackQueue
{
public:
    deque<int> dq;
    FrontMiddleBackQueue()
    {
    }

    void pushFront(int val)
    {
        dq.push_front(val);
    }

    void pushMiddle(int val)
    {
        int m = dq.size() / 2;
        auto it = dq.begin();
        it = it + m;
        dq.insert(it, val);
    }

    void pushBack(int val)
    {
        dq.push_back(val);
    }

    int popFront()
    {
        if (dq.empty())
        {
            return -1;
        }
        int k = dq.front();
        dq.pop_front();
        return k;
    }

    int popMiddle()
    {
        if (dq.empty())
        {
            return -1;
        }
        int m = dq.size() / 2;
        if (dq.size() % 2 == 0)
        {
            m--;
        }
        auto it = dq.begin();
        it = it + m;
        int k = *it;
        dq.erase(it);
        return k;
    }

    int popBack()
    {
        if (dq.empty())
        {
            return -1;
        }
        int k = dq.back();
        dq.pop_back();
        return k;
    }
};

// 9th
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    
        int max_sum = nums[0], min_sum = nums[0], sum = nums[0], prev_min = nums[0], prev_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            
            prev_max = max(prev_max + nums[i], nums[i]);
            max_sum = max(max_sum, prev_max);
            
            prev_min = min(prev_min + nums[i], nums[i]);
            min_sum = min(min_sum, prev_min);
        }
        
        return sum == min_sum ? max_sum : max(max_sum, sum-min_sum);
    }
};

//10th

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++)
        {
            while(!s.empty() && asteroids[i]<0 && s.top()>0)  
            {
                int magnitude=s.top()+asteroids[i]; 
                if(magnitude<0) s.pop();
                else if(magnitude>0) asteroids[i]=0;
                else{
                    s.pop();
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]) s.push(asteroids[i]);
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};