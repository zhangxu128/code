//题目描述
//我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
//如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
//现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
//输入描述 :
//输入正整数N
//输出描述 :
//输出1到N中好数个数
//示例1
//输入
//10
//输出
//4

#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		int x = i;
		bool flag = false;
		while (x != 0)
		{
			int t = x % 10;
			if (t == 4 || t == 7 || t == 3)
			{
				flag = false;
				break;
			}
			if (t == 2 || t == 5 || t == 6 || t == 9)
			{
				flag = true;
			}
			x = x / 10;
		}
		if (flag)
			count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}
