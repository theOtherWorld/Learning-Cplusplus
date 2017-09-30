//
// Created by xl on 2017/8/23.
//
//
//
//#include <iostream>
//using namespace std;
//
//int main(){
//
//    int n = 0;
//    cin >> n;
//    int* block = new int[n];
//
//    int idx = 0;
//    while(idx < n){
//        cin>>block[idx];
//        if(block[idx] > 100) return 0;
//        ++idx;
//    }
//
//    int maxRes =0, sum = 0, min = 0;
//    for(int i = 0; i< n; ++i){//
//        int p = block[i] * block[i];
//        if(p > maxRes) maxRes = p;
//        if(block[i] < min) min = block[i];
//        sum += block[i];
//    }
//    if(maxRes < (sum * min)) maxRes = sum * min;
//
//
//
//    int k = 0, j = 0, step = 1;
//    while(step <= n-1){
//        for(;j < n; ++j){
//            int min = block[j];
//            int temp = 0;
//            for(sum = 0;k <= j; ++k) {
//                if (block[k] < min) min = block[k];
//                sum += block[k];
//            }
//            k = k - step;
//            temp = min * sum;
//            if(maxRes < temp) maxRes = temp;
//        }
//        step++;
//        k = 0;
//        j = step;
//    }
//
//    cout << maxRes;
//    delete[] block;
//
//    return 0;
//}