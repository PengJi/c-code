#include <iostream>
#include <cstdio>

using namespace std;

/*
 * 时间效率
 */

class Solution{
public:
    /* 
     * 39
     * 数组中出现次数超过一半的数字
     * 数组中有一个数字出现的次数超过数组长度的一半，
     * 请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
     * 于数字2在数组中出现了5次，超过数组长度的一半，
     * 因此输出2。如果不存在则输出0。
     */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n==0) return 0;

        int num = numbers[0],count = 1;
        for(int i=1;i<n;i++){
            if(numbers[i] == num)
                count++;
            else
                count--;
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }

        count = 0;
        for(int i=0;i<n;i++){
            if(numbers[i] == num)
                count++;
        }
        if(count * 2 > n)
            return num;
        return 0;
    }
    
    /*
     * 41
     * 数据流中的中位数
     * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
     * 那么中位数就是所有数值排序之后位于中间的数值。
     * 如果从数据流中读出偶数个数值，
     * 那么中位数就是所有数值排序之后中间两个数的平均值。
     *
     * 利用堆实现
     */
    priority_queue<int,vector<int>,less<int>> p; //小顶堆
    priority_queue<int,vector<int>,greater<int>> q; //大顶堆
    void Insert(int num)
    {
        if(p.empty() || num <= p.top())
            p.push(num);
        else 
            q.push(num);

        if(p.size() == q.size() + 2){
            q.push(p.top());
            p.pop();
        }
        if(p.size()+1 == q.size()){
            p.push(q.top());
            q.pop();
        }
    }
    double GetMedian()
    { 
        return p.size()==q.size()?(p.top()+q.top())/2.0:p.top();
    }
}