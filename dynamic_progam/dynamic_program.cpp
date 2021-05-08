/*
动态规划的基本思路就是要列出
正确的状态转移方程：
1. 确定[base case]；
2. 确定[状态]， 也就是原问题和子问题会变化的量；
3. 确定[选择]， 也就是导致[状态]发生变化的行为；
4. 明确dp函数/数组

以凑零钱问题为例，伪码：
        def coinChange(coins, amount): #amount 为状态
            def dp(n):
                 #base case
                if n == 0: return  0
                if n < 1 : return -1
                res = float('INF')
                 #做选择
                for coin in coins:
                    sub_probelm = dp(n-coin)
                    if sub_problem == -1:continue
                    res = min(res, 1+sub_problem)

                retrun res id res != float('INT') else -1

            return dp(amount) 
*/
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<algorithm>

int CoinChange_dparray(const std::vector<int>& coins, int amount){
    std::vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i = 0;i<dp.size();i++){
        for(auto coin:coins){
            if((i - coin)<0) continue;
            dp[i] = std::min(dp[i], dp[i-coin]+1);
        }
    }

    return (dp[amount] == amount + 1)?-1:dp[amount];
}

int main(){
    std::vector<int> coins = {1,2,5};
    int amount = 12;
    int res = CoinChange_dparray(coins, amount);
    std::cout<<"CoinChange amount = "<<amount<<"res is "<<res<<std::endl;
}

