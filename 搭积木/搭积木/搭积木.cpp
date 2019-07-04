//题目描述
//小明有一袋子长方形的积木，如果一个积木A的长和宽都不大于另外一个积木B的长和宽，则积木A可以搭在积木B的上面。好奇的小明特别想知道这一袋子积木最多可以搭多少层，你能帮他想想办法吗？
//定义每一个长方形的长L和宽W都为正整数，并且1 <= W <= L <= INT_MAX, 袋子里面长方形的个数为N, 并且 1 <= N <= 1000000.
//假如袋子里共有5个积木分别为(2, 2), (2, 4), (3, 3), (2, 5), (4, 5), 则不难判断这些积木最多可以搭成4层, 因为(2, 2) < (2, 4) < (2, 5) < (4, 5)。
//	输入描述 :
//第一行为积木的总个数 N
//
//之后一共有N行，分别对应于每一个积木的宽W和长L
//输出描述 :
//输出总共可以搭的层数
//示例1
//输入
//5
//2 2
//2 4
//3 3
//2 5
//4 5
//输出
//4

/*
对长方形的宽w排序，本题化简为对长l求最长上升子序列。
本题只需求 最长上升子序列 的长度，可优化到O(nlogn)
另外本题对时间控制非常严格
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > vp(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &vp[i].first, &vp[i].second);
	}
	sort(vp.begin(), vp.end());
	vector<int> res(n);
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (start == 0 || vp[i].second >= res[start - 1]) {
			res[start] = vp[i].second;
			start++;
		}
		else {
			auto it = lower_bound(res.begin(), res.begin() + start, vp[i].second);
			*it = vp[i].second;
		}
	}
	cout << start << endl;
	system("pause");
	return 0;
}