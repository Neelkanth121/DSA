class Solution {
public:
    double angleClock(int hour, int minutes) {
        float a = ((hour % 12) * 5) + (double)minutes/12;
        float b = minutes;
        float degree = (abs(b - a)) * 6;
        double ans = round(degree * 10000) / 10000;
        return min(ans, abs(360 - ans));
    }
};