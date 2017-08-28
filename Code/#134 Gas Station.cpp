/*
问题：
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/*
思路：
这道题问题在于初始位置的选择，比如如果有一个点是 gas = 5, cost = 6。那这个点就不能是起点，这种情况下就要从下一个位置找。
*/

class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int totPos = gas.size();
      int nowGas = 0;
      int start = 0;
      int sum = 0;
      for (int i = 0;i < totPos;i++) {
         sum += gas[i] - cost[i];
         nowGas += gas[i] - cost[i];
         if (nowGas < 0) {
            start = i + 1;
            nowGas = 0;
         }
      }
      if (sum < 0)return -1;
      return start;
   }
};