class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int car=0; 
        int i = a.size()-1;
        int j =b.size()-1;

        while(i>=0 || j>=0 || car){
            if(i>=0)car+=a[i]-'0';
            if(j>=0)car+=b[j]-'0';

            c+=(car%2)+'0';
            car=car/2;
            i--;
            j--;
        }
        reverse(c.begin(),c.end());
        return c;
    }
};