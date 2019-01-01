#include <iostream>
#include <vector>
#include <map>
#include<iterator>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 *Copyright 2019 Tencent Inc
 *Created by 李源 leeyuan on 01/01/2019.
 */

/*
 * Question: Input:
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation:
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
 */

/*
 * Use queue
 */

class Solution1{
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid,int kill){
        vector<int> res;
        queue<int> q{{kill}};
        unordered_map<int,vector<int>> m;
        for (int i =0; i < pid.size();++i){
            m[ppid[i]].push_back(pid[i]);
        }
        while (!q.empty()){
            int t =q.front();q.pop();
            res.push_back(t);
            for (int p : m[t]){
                q.push(p);
            }
        }
        return res;
    }
};

/*
 * Use Recursion
 */
class Solution2{
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid,int kill){
        vector<int> res;
        unordered_map<int,vector<int>> m;
        for (int i =0; i < pid.size();++i){
            m[ppid[i]].push_back(pid[i]);
        }
        process_helper(res,m,kill);
        return res;
    }

    void process_helper(vector<int>& res, unordered_map<int,vector<int>>& m, int kill){
        res.push_back(kill);
        for (int p : m[kill]){
            process_helper(res,m,p);
        }
    }
};