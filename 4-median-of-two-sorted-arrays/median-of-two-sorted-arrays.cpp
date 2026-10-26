class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> c;
    int i =0;
    int j = 0 ;
    while(i<nums1.size() && j <nums2.size()){
        if(nums1[i]>nums2[j]){
            c.push_back(nums2[j]);
            j++;
        }
        else {
            c.push_back(nums1[i]);
            i++;
        }
    }
    
    while(i<nums1.size())c.push_back(nums1[i++]);
    while(j<nums2.size())c.push_back(nums2[j++]);
    int n = c.size();
    if(n%2==0)return (c[n/2-1]+c[n/2])/2.0;
    return c[n/2];
    }
};