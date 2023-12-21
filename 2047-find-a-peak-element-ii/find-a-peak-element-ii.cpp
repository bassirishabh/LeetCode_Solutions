class Solution {
public:
    int findmaxindex(vector<vector<int>>& mat,int n,int m,int mid){
        int maxvalue=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxvalue){
                maxvalue=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int low=0;
        int high=m-1;

        while(low<=high){
            int mid=(low+high)/2;
            int maxrow=findmaxindex(mat,n,m,mid);
            int left=mid-1>=0?mat[maxrow][mid-1]:-1;
            int right=mid+1<m?mat[maxrow][mid+1]:-1;
            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right){
                return {maxrow,mid};
            }else if(mat[maxrow][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};