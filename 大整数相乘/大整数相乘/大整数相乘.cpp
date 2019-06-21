//题目描述
//有两个用字符串表示的非常大的大整数, 算出他们的乘积，也是用字符串表示。不能用系统自带的大整数类型。
//输入描述 :
//空格分隔的两个字符串，代表输入的两个大整数
//输出描述 :
//输入的乘积，用字符串表示

#include<iostream>
#include<string>
using namespace std;
//移位进位法
string Mul(string left, string right)
{

	size_t Lsize = left.size();
	size_t Rsize = right.size();
	size_t Size = Lsize + Rsize;
	string res(Size, '0');

	int takevoer = 0;//进位
	int offset = 0;//移位

	size_t idx = 1, j = 1;
	for (idx = 1; idx <= Rsize; ++idx)
	{
		takevoer = 0;
		int rightnum = right[Rsize - idx] - '0';
		//计算每一位与left相乘
		for (j = 1; j <= Lsize; ++j)
		{
			char resBit = res[Size - j - offset] - '0';
			int num = rightnum * (left[Lsize - j] - '0') + takevoer + resBit;
			takevoer = num / 10;
			res[Size - j - offset] = num % 10 + '0';
		}
		if (takevoer != 0)
			res[Size - j - offset] = takevoer + '0';
		offset++;
	}

	//如果没有进位的话，res最高位没有数字
	if (res[0] == '0')
		res.erase(0, 1);
	return res;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	string str = Mul(s1, s2);
	cout << str << endl;
	system("pause");
	return 0;
}