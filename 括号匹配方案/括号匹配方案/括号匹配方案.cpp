#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
//题目描述
//合法的括号匹配序列被定义为 :
//1. 空串""是合法的括号序列
//2. 如果"X"和"Y"是合法的序列, 那么"XY"也是一个合法的括号序列
//3. 如果"X"是一个合法的序列, 那么"(X)"也是一个合法的括号序列
//4. 每个合法的括号序列都可以由上面的规则生成
//例如"", "()", "()()()", "(()())", "(((())))"都是合法的。 东东现在有一个合法的括号序列s, 一次移除操作分为两步 :
//	1. 移除序列s中第一个左括号
//	2. 移除序列s中任意一个右括号.保证操作之后s还是一个合法的括号序列
//	东东现在想知道使用上述的移除操作有多少种方案可以把序列s变为空
//	如果两个方案中有一次移除操作移除的是不同的右括号就认为是不同的方案。
//	例如 : s = "()()()()()", 输出1, 因为每次都只能选择被移除的左括号所相邻的右括号.
//	s = "(((())))", 输出24, 第一次有4种情况, 第二次有3种情况, ..., 依次类推, 4 * 3 * 2 * 1 = 24
//	输入描述 :
//	输入包括一行, 一个合法的括号序列s, 序列长度length(2 ≤ length ≤ 20).
//	输出描述 :
//	输出一个整数, 表示方案数
//	示例1
//	输入
//	(((())))
//	输出
//	24

using namespace std;


// 只要嵌套的情况才会有多种删除方案，每种方案最后剩下的结果是一样的。所以。遍历一次可以获得结果
// 用栈进行匹配，当匹配一个时，剩下如果超过等于2个左括号，证明有嵌套。
// 还是采用统计的方式。


int main() {
	string s;
	while (getline(cin, s)) {
		int result = 1;
		int nums = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				++nums;
			}
			else {
				result *= nums;

				--nums;
			}
		}
		cout << result << endl;
	}
}