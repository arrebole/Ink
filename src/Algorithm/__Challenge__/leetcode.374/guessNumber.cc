// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int lo = 0, hi = n;
        while (true){
            if (guess( mid(lo, hi) ) == 0)       return mid(lo, hi);
            if (guess( mid(lo, hi) ) == 1)       lo = mid(lo, hi) + 1;
            else if (guess( mid(lo, hi) ) == -1) hi = mid(lo, hi) - 1;
        }
        return -1;
    }
    inline int mid(long long int a, long long int b) {
        return (a+b)/2;
    }
};