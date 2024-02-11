class Solution {
    int rows;
    int cols;
    
    public void transpose(int[][] matrix){
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }

       public void reflect(int[][] matrix) {
        for (int i = 0; i < rows; i++) {
            reverseArray(matrix[i]);
        }
    }

    private void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    public void rotate(int[][] matrix) {
        rows=matrix.length;
        cols=matrix[0].length;
        transpose(matrix);
        reflect(matrix);
    }
}