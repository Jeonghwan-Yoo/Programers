#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

enum Op
{
    Plus = 0,
    Minus = 1,
    Mul = 2,
};

struct OpPri
{
    Op op;
    int pri;
    OpPri(Op op, int pri) : op(op), pri(pri) {}
};

void Calc(vector<long long> &sNum, vector<OpPri> &sOp)
{
    long long b = sNum.back();
    sNum.pop_back();
    long long a = sNum.back();
    int op = sOp.back().op;
    sOp.pop_back();
    if (op == Op::Plus)
        sNum.back() = a + b;
    else if (op == Op::Minus)
        sNum.back() = a - b;
    else
        sNum.back() = a * b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<int> nums;
    vector<int> ops;
    int num = 0;
    for (int i = 0; i < (int)expression.size(); ++i)
    {
        if (isdigit(expression[i]))
        {
            num *= 10;
            num += expression[i] - '0';
        }
        else
        {
            nums.emplace_back(num);
            num = 0;
            if (expression[i] == '+')
                ops.emplace_back(Op::Plus);
            else if (expression[i] == '-')
                ops.emplace_back(Op::Minus);
            else
                ops.emplace_back(Op::Mul);
        }
    }
    nums.emplace_back(num);
    
    for (int plus = 0; plus < 3; ++plus)
    {
        for (int minus = 0; minus < 3; ++minus)
        {
            for (int mul = 0; mul < 3; ++mul)
            {
                if (plus == minus || minus == mul || plus == mul)
                    continue;
                
                vector<long long> sNum;
                vector<OpPri> sOp;
                sNum.emplace_back(nums[0]);
                for (int i = 0; i < (int)ops.size(); ++i)
                {
                    int pri;
                    if (ops[i] == Op::Plus)
                        pri = plus;
                    else if (ops[i] == Op::Minus)
                        pri = minus;
                    else
                        pri = mul;
                    
                    while (!sOp.empty() && sOp.back().pri <= pri)
                        Calc(sNum, sOp);
                    
                    sOp.emplace_back((Op)ops[i], pri);
                    sNum.emplace_back(nums[i + 1]);
                }
                while (!sOp.empty())
                    Calc(sNum, sOp);
                
                if (answer < abs(sNum.back()))
                    answer = abs(sNum.back());
            }
        }
    }
    
    return answer;
}