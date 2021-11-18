 #include<iostream> 
#include<climits> 
using namespace std; 
#include <vector>
#include <array>
#include <algorithm>
   int search(std::vector<int>& nums, int target){
        if (nums.size() == 0) return -1;
        
		int left = 0;
		int right = nums.size() - 1;
        
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        
        int start = left;
        left = 0;
        right = nums.size() - 1;
        
        if (target >= nums[start] && target <= nums[right])
            left = start;
        else
            right = start;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
                
        }
		
		return -1;
	
};
int main()
{
    
   vector<int> nums{ 1, 2, 3 ,4,5,6};
int target=5;
search(nums,target);
return 0;
}

