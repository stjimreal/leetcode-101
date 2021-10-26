/*
 * @Date: 2021-10-13 19:37:32
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-10-13 20:52:23
 */
/* 
简单 S 表达式整数计算器
时间限制： 3000MS
内存限制： 589824KB
题目描述：
首先，我们介绍下什么是 S 表达式。S 表达式常见于各类 Lisp 语言，比如 (+ 1 2) 就是一个 S 表达式。S 表达式的一个特点就是将函数和对应的参数用一对括号括起来。

现在，我们需要实现一个整数计算器，他的输入是一个 S 表达式，输出是一个表示计算结果的字符串。

输入描述
输入的 S 表达式的详细规则如下：

1. 仅支持 +、-、*、/ 这 4 中运算方法，计算时都按照整数规则进行。

2. +、* 支持至少 1 个参数，例如 (+ 1)、(* 1 2 3 4 5)

3. -、/ 仅支持 2 个参数，例如 (- 2 1)、(/ 6 2)

4. S 表达式支持嵌套，例如 (+ (* 1 2 3 4) (/ 6 2) (- 1 4))、(+ (* (/ 2 1) (- 6 3)) (+ 1 2))

5. 输入的 S 表达式可能是非法的，比如括号不配对、计算符错误、参数数量错误、非整数参数等。

输出描述
输出规则如下：

1. 最终结果通过标准输出打印即可

2. 对于非法的 S 表达式，输出 invalid expression

3. 对于除 0 这种整数无法支持的运算场景，输出 division by zero


样例输入
(+ (* 1 2 3) (/ 6 2) (- 1 4))
样例输出
6
 */

#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <cstring>
#include <numeric>

using namespace std;

inline bool is_single_calc(char ch) {
    return (ch == '+' || ch == '*');
}
inline bool is_double_calc(char ch) {
    return ch == '-' || ch == '/';
}

inline bool is_lparenthese(char ch) {
    return ch == '(';
}

inline bool is_rparenthese(char ch) {
    return ch == ')';
}

void calc_all (vector<vector<int>> val, vector<int> v) {
    while (!v.empty()) {
        if (val.empty()) {
            cout<<"invalid expression"<<endl;
            exit(0);
        }
        vector<int> nums = val.back();
        val.pop_back();
        char calc = v.back();
        v.pop_back();
        int res ;
        switch(calc) {
            case '+':
                if (nums.size() < 1) {
                    return;
                }
                res = accumulate(nums.begin(), nums.end(), 0);
                val.back().push_back(res);
                break;
            case '*':
                if (nums.size() < 1) {
                    return;
                }
                res = 1;
                for (int i=0; i < nums.size(); ++i) res *= nums[i];
                break;
            case '-':
                if (nums.size() != 2) {
                   return;
                }
                res = nums[0] - nums[1];
                val.back().push_back(res);
                break;
            case '/':
                if (nums.size() != 2) {
                    return;
                }
                if (nums[1] == 0) {
                    cout<<"division by zero"<<endl;
                    exit(0);
                }
                res = nums[0] / nums[1];
                val.back().push_back(res);
                break;
            default:
                return;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    vector<int> parentheses;
    vector<vector<int>> val;
    val.push_back(vector<int>());
    /* parse token */
    /* 括号不配对、计算符错误、参数数量错误、非整数参数 */

    /* parse expression */
    char ch;
    int num = 0;
    bool num_flag = false;
    vector<int> nums_to_calc;
    char prev = ' ';
    while ((ch = getchar()) != EOF) {
        if (isdigit(ch)) {
            cout<<"digit"<<endl;
            if (!num_flag && !(is_single_calc(prev) || is_double_calc(prev))) {
                goto error_exp;
            }
            num_flag = true;
            num = num * 10 + ch - '0';
            
        } else {
            if (num_flag) {
                nums_to_calc.push_back(num);
                num = 0;
                num_flag = false;
            }

            if (is_single_calc(ch)) {
                cout<<"is_single_calc"<<endl;
                if (!is_lparenthese(prev)) {
                    goto error_exp;
                }
                prev = ch;
                

            } else if (is_double_calc(ch)) {
                cout<<"is_double_calc"<<endl;
                if (!is_lparenthese(prev)) {
                    goto error_exp;
                }
                prev = ch;

                
            } else if (isblank(ch) || ch == '\n') {
                cout<<"blank"<<endl;
                continue;
            } else if (is_lparenthese(ch)){
                cout<<"left parenthese"<<endl;
                val.push_back(nums_to_calc);
                v.push_back(prev);
                prev = ch;
                nums_to_calc = vector<int>();
                parentheses.push_back(1);
            } else if (is_rparenthese(ch)) {
                cout<<"right parenthese"<<endl;
                if ((is_single_calc(ch) && nums_to_calc.size() < 1) || 
                (is_double_calc(ch) && nums_to_calc.size() != 2) ||
                (parentheses.empty())) {
                    goto error_exp;
                }
                parentheses.pop_back();
                val.push_back(nums_to_calc);
                nums_to_calc = vector<int>();
                v.push_back(prev);
                prev = ch;
                calc_all(val, v);
                
            } else {
                goto error_exp;
            }
        }
            
    }
    /* calc all */
    
    
    if (val.size() > 1 || parentheses.empty() || prev != ')')  {
        goto error_exp;
    }
    cout<<val[0][0]<<endl;

    return 0;

error_exp:
    cout<<"invalid expression"<<endl;
    return 0;
}
