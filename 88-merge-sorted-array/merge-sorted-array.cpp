class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums_copy=nums1;
        int k=0;
        int i=0;
        int j=0;

        while(i<m && j<n){
            if(nums_copy[i]<nums2[j]){
                nums1[k]=nums_copy[i];
                k++;
                i++;
            }else{
                nums1[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<m){
            nums1[k]=nums_copy[i];
            k++;
            i++;
        }
        while(j<n){
            nums1[k]=nums2[j];
            k++;
            j++;
        }


    }
};