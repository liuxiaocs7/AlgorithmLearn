#include <bits/stdc++.h>
using namespace std;
 
int n;
string s;
vector<int> nums;
vector<char> op;
 
int main()
{
	cin >> n;
	while(n -- )
	{
		nums.clear();
		op.clear();
		cin >> s;
		for(auto it : s)
		{
			if(isdigit(it))
				nums.push_back(it - '0');
			else
				op.push_back(it);
		}
		
		// 先处理乘除法 
		for(int i = 0; i < op.size(); i++)
		{
			if(op[i] == 'x' || op[i] == '/')
			{
				if(op[i] == 'x')
					nums[i] *= nums[i + 1];
				if(op[i] == '/')
					nums[i] /= nums[i + 1];
				nums.erase(nums.begin() + i + 1);
				op.erase(op.begin() + i);
				i--;	
			}
		}
	
		// 再处理加减法 
		for(int i = 0; i < op.size(); i++)
		{
			if(op[i] == '+')
				nums[i] += nums[i + 1];
			if(op[i] == '-')
				nums[i] -= nums[i + 1];
			nums.erase(nums.begin() + i + 1);
			op.erase(op.begin() + i);
			i--;	
		}
		printf("%s\n", nums[0] == 24 ? "Yes" : "No");
	} 
	
	return 0; 
}