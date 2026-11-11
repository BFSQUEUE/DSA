#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll mincost = 0;
        if(cost1+cost2>costBoth){
            if(need1>need2){
                mincost+= (ll)need2*(ll)costBoth;
                need1 -= need2;
                need2=0;
                ll temp = min(cost1, costBoth);
                mincost += (ll)temp * (ll)need1;
            }
            else{
                mincost += (ll)need1*costBoth;
                need2 -= need1;
                need1=0;
                ll temp = min(cost2, costBoth);
                mincost += (ll)temp * (ll)need2;
            }
        }
        else{
            mincost = (ll)cost1 * (ll)need1 + (ll)cost2 * (ll)need2;
        }
        return mincost;
    }
};
