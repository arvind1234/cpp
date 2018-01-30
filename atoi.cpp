#include <math.h>
#include <limits>

class Solution {
public:
    int myAtoi(string str) {
        int sum = 0;
        int maxInt = numeric_limits<int>::max();
        int minInt = numeric_limits<int>::min();

        bool isNeg = false;

        int i = 0;
        while(str[i] == ' ') {
            i++;
        }

        if (str[i] == '-') {
            isNeg = true;
            i++;
        } else if (str[i] == '+') {
            i++;
        }

        int l = str.length();
        while(i < l) {
            int digit = str[i] - '0';
            if (digit >= 0 && digit <=9) {
                if (!isNeg) {
                    cout << "1 ##" << sum << endl;
                    int diff = maxInt - ((maxInt / 10) >= sum ? (sum * 10) : maxInt);
                    if (diff > digit) {
                        sum = (sum * 10) + digit;
                    } else {
                        sum = maxInt;
                        break;
                    }
                } else {
                    cout  << minInt << " " << (sum * -10) << endl;
                    // int diff = minInt + ((minInt / -10) >= sum ? (sum * -10) : minInt);
                    // cout << "diff: " << diff <<endl;
                    if (sum == 0 || (
                        (minInt / 10) <= sum &&
                        (-1 * (minInt + sum * -10)) > digit
                        )
                    ) {
                        sum = sum * 10 - digit;
                    } else {
                        sum = minInt;
                        cout << " 4 ##";
                        break;
                    }
                    
                }
                
            } else {
                cout << "2 ##";
                break;
            }
            i++;
        }
        
     //   cout << " sum:" << sum << endl;
      
        // 10522545459
        //  1932610867
        //  1052254545
        //  2147483647
        //   410755940
     
        // cout << " sum:" << sum << endl;
        
        return sum;
    }
};