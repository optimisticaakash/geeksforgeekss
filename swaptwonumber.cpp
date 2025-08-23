//Approach1 : using variable
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        int temp = a;
        a = b;
        b = temp;
        
        return {a,b};
    }
};

//Approach2 : using + , - arithmetic operator
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a+b;
        b = a-b;
        a = a-b;
        return {a,b};
    }
};

//Appraoch3 : using xor
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a^b;
        b = a^b;
        a= a^b;
        
        return {a,b};
    }
};

//Approach using multiplication division
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a*b;
        b = a/b;
        a = a/b;
        return {a,b};
    }
};

