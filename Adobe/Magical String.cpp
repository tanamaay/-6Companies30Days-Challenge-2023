class Solution {
public:
    int magicalString(int n) {
        if(n <= 0) return 0;
      if(n <= 3) return 1;
      int ret = 1;
      vector <int> arr(n);
      arr[0] = 1;
      arr[1] = 2;
      arr[2] = 2;
      int head = 2;
      int tail = 3;
      int num = 1;
      while(tail < n){
         for(int i = 0; i < arr[head]; i++){
            arr[tail] = num;
            if(num == 1 && tail < n) ret++;
            tail++;
            if(tail >= n) break;
         }
         num ^= 3;
         head++;
      }
      return ret;
    }
};
