class Solution {
public:
int minOperations(vector& nums, vector& numsDivide) {
int gcd=numsDivide[0];
for(int i=1;i<numsDivide.size();i++)
{
gcd= __gcd(gcd,numsDivide[i]);
}
cout<<gcd;
sort(nums.begin(),nums.end());
int c=0;
for(int i=0;i<nums.size();i++)
{

            if(gcd%nums[i]==0)
            break;
        else
            c++;
    }
    if(c==nums.size())
        return -1;
    else
        return c;
}
};
