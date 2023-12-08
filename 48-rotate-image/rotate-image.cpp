class Solution {
public:
    int rows;
    int cols;
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
    void reflect(vector<vector<int>>& matrix){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][cols-j-1];
                matrix[i][cols-j-1]=temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        rows=matrix.size();
        cols=matrix[0].size();
        transpose(matrix);
        reflect(matrix);

    }
};