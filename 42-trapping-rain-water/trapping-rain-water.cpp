class Solution {
public:
    int trap(vector<int>& height) {
        int answer=0;
        int leftmax=0;
        int rightmax=0;
        int left=0;
        int right=height.size()-1;

        while(left<=right){
            if(height[left]<height[right]){
                leftmax=max(leftmax,height[left]);
                answer+=(leftmax-height[left]);
                left++;
            }else{
                rightmax=max(rightmax,height[right]);
                answer+=(rightmax-height[right]);
                right--;
            }
        }
        return answer;
    }
};