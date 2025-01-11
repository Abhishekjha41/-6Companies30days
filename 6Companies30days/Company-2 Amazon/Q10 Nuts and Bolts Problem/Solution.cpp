class Solution {
  public:
    int partition(char arr[],int low,int high,char pivot){
        int i = low;
        char temp1,temp2;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                temp1 = arr[i];
                arr[i] = arr[j];
                arr[j] = temp1;
                i++;
            }
            else if(arr[j]==pivot){
                temp1 = arr[j];
                arr[j] = arr[high];
                arr[high] = temp1;
                j--;
            }
        }
        temp2 = arr[i];
        arr[i] = arr[high];
        arr[high] = temp2;
        
        return i;
    }
    void quicksort(char nuts[] ,char bolts[],int low, int high){
        if(low<high){
            int pivotidx = partition(nuts,low,high,bolts[high]);
            
            partition(bolts,low,high,nuts[pivotidx]);
            
            quicksort(nuts,bolts,low,pivotidx-1);
            quicksort(nuts,bolts,pivotidx+1,high);
        }
    }
    void matchPairs(int n, char nuts[], char bolts[]) {
        quicksort(nuts,bolts,0,n-1);
    }
};