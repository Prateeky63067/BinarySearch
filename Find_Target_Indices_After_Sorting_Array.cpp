//  Find Target Indices After Sorting Array
class Solution {
public:
     int firstOcc(vector<int>& nums, int target)
     {
        int ans=-1;
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
     }
     int lastOcc(vector<int>& nums, int target)
     {
        int ans=-1;
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
     }

    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int ans1=firstOcc(nums,target);
        int ans2=lastOcc(nums,target);
        if(ans1==-1||ans2==-1)
        return ans;
        for(int i=ans1;i<=ans2;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};








#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class BinarySemaphore {
private:
    bool available = true; 
     mutex mtx;
     condition_variable cv;

public:
    void wait() {
         unique_lock< mutex> lock(mtx);
        cv.wait(lock, [this]() { return available; }); 
        available = false; 
    }

    void signal() {
         unique_lock< mutex> lock(mtx);
        available = true; 
        cv.notify_one(); 
    }
};

BinarySemaphore semaphore;
int sharedCounter = 0;

void increment(int id) {
    semaphore.wait();
    sharedCounter++;
     cout << "Thread " << id << " incremented counter to " << sharedCounter <<  endl;
    semaphore.signal();
}

int main() {
    const int numThreads = 5;
     thread threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        threads[i] =  thread(increment, i + 1);
    }

    for (auto& t : threads) {
        t.join();
    }

     cout << "Final  value: " << sharedCounter <<  endl;
    return 0;
}
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
      
       int count =0,c=0;
       for(int i=0;i<n;i++){
         c=0;
          for(int j=0;j<m;j++){
            if(arr1[i]>arr2[j]){
                if(arr1[i] - arr2[j] > d){
                    c++;
                }else{
                    break;
                }
            }else{
                 if(arr2[j] - arr1[i] > d){
                    c++;
                }else{
                    break;
                }
            }
          }
          if(c == m){
            count++;
          }
       }
       return count; 
    }
};