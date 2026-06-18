class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(((double)(hour%12) + (double)(minutes)/60)*30 - (double)(minutes)*6);
        return min(ans, 360 - ans);
    }
};