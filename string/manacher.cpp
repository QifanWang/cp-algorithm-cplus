#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e5 + 5;
/*
 * In this implementation, 
 * d2[i] specify the number of palindromes which center is before str[i]. Like this,
 * str:  str[i-1]    str[i]     str[i+1] 
 *                i         i+1
 * */
struct Manacher {
    char str[MAX_SIZE];
    int n = MAX_SIZE;
    vector<int> d1, d2; // d1 is odd, d2 is even

    void input() {
        scanf("%s", str);
    }

    void solve(){
        n = strlen(str);
        d1.assign(n, 1);
        d2.assign(n, 0);

        for(int i = 0, l = 0, r = -1 ;i < n; ++i) {
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while(0 <= i - k && i + k < n && str[i-k] == str[i+k])
                k ++;
            d1[i] = k;
            if(i + k - 1 > r){
                r = i + k - 1;
                l = i - k + 1;
            }
        }

        for(int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while(0 <= i - k - 1 && i + k < n && str[i-k-1] == str[i+k])
                k++;
            d2[i] = k;
            if(i + k - 1 > r){
                r = i + k - 1;
                l = i - k;
            }
        }
    }
};

