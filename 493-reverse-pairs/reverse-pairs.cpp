class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right){
        int i=left;
        int j=mid+1;
        vector<long long> temp;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
    }
    int countpairs(vector<int>& nums,int left,int mid,int right){
        int count=0;
        int high=mid+1;
        for(int i=left;i<=mid;i++){
            while(high<=right && (long long)nums[i]>(long long)2*nums[high]) high++;
            count+=(high-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>& nums,int left,int right){
        int count=0;
        if(left>=right) return count;
        int mid=(left+right)/2;
        count+=mergeSort(nums,left,mid);
        count+=mergeSort(nums,mid+1,right);
        count+=countpairs(nums,left,mid,right);
        merge(nums,left,mid,right);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};