class Solution {
public:
    int dayOfYear(const string& s) {
        int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int m = (s[0] - '0') * 10 + (s[1] - '0');
        int d = (s[3] - '0') * 10 + (s[4] - '0');

        int total = 0;
        for (int i = 0; i < m - 1; i++) total += daysInMonth[i];
        return total + d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end   = min(dayOfYear(leaveAlice),  dayOfYear(leaveBob));
        return max(0, end - start + 1);
    }
};