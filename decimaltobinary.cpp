//appraoch
// User function Template for C++

void toBinary(int n) {
    // your code here
    string s = "";
    if(n==0)cout<<0;
    while(n>0){
        if(n%2 == 1) s+='1';
        else s+='0';
        n=n/2;
    }
    reverse(s.begin(),s.end());
    int num = stoi(s);
    cout<<num;
    
}
//T.C : O(log2n)
//S.C : O(log2n)
