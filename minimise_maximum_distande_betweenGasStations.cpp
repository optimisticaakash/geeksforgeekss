//Approach1: Greedy approach 
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<int> howMany(n-1,0);
        
        for(int gasStations = 1; gasStations <= k; gasStations++){
            long double maxSection=-1;
            int maxInd = -1;
            
            for(int i = 0; i < n-1; i++){
                long double diff = (stations[i+1]-stations[i]);
                long double sectionLen = diff /(long double)(howMany[i]+1);
                
                if(sectionLen > maxSection){
                    maxSection = sectionLen;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        
        long double maxAns = -1;
        for(int i = 0; i < n-1; i++){
            long double diff = (stations[i+1]-stations[i]);
            long double sectionLen = diff/(long double)(howMany[i]+1);
            maxAns = max(maxAns , sectionLen);
        }
        return maxAns;
    }
};
//T.C: O(n*k) + O (n) 
//S.C : O(n) 

//Approach2: priority_queue
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<int>howMany(n-1,0); // n-1 sections
        
        priority_queue<pair<long double , int>> pq;
        
        for(int i = 0; i < n-1; i++){
            pq.push({stations[i+1]-stations[i] , i});
        }
        
        for(int gasStations = 1; gasStations <= k ; gasStations++){
            auto tp = pq.top();
            pq.pop();
            
            int secInd = tp.second;
            howMany[secInd]++; 
            
            long double iniDiff = stations[secInd+1]-stations[secInd];
            long double newSecLen = iniDiff/(long double)(howMany[secInd]+1);
            pq.push({newSecLen , secInd});
        }
        
        return pq.top().first;
    }
};
//T.C : O(nlogn + klogn )
//S.C : O(n-1)


//Approach3: binary search 
class Solution {
  public:
    int countOfGasStations(long double dist , vector<int> &stations){
        int cnt = 0;
        for(int i = 1; i< stations.size(); i++){
            int numberInBetween = ((stations[i]-stations[i-1])/dist);
            if((stations[i] - stations[i-1])/dist == numberInBetween * dist){
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        long double low = 0;
        long double high = 0;
        
        for(int i = 1; i < n; i++){
            high = max(high , (long double)(stations[i] - stations[i-1]));
        }
        
        long double diff = 1e-6;

        while(high - low > diff){
            long double mid = (low + high)/2.0;
            
            int cnt = countOfGasStations(mid,stations);
            
            if(cnt > k){
                low = mid;
            }else{
                
                high = mid;
                
            }
        }
        return high;
    }
};
//T.C ; O(n) + O(log(maxdistance of consecutive) * n) = O(n)
//S.C : O(1) 
