/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int res = guess(n);
        while (res != 0) {
            if (res == -1) {
                n--;
                res = guess(n);
            } else {
                n++;
                res = guess(n);
            }
        }
        return n;
    }
};