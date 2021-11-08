#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int getNum(queue<int>& w)
{
	int n = 0;
	while (!w.empty())
	{
		n *= 10;
		n += w.front();
		w.pop();
	}
	return n;
}

int main()
{
	string input;
	while (cin >> input && !input.empty())
	{
		unordered_map<int, int> ele;
		queue<int> words;

		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] >= '0' && input[i] <= '9')
				words.push(input[i] - '0');
			else if (!words.empty())
				++ele[getNum(words)];
		}
		if (ele.empty()) continue;

		queue<unordered_map<int, int>::iterator> uni;
		for (auto it = ele.begin(); it != ele.end(); ++it)
			if (it->second == 1) uni.push(it);

		uni.size() == 1 ? 
			cout << uni.front()->first << '\n' :
			cout << "There is no target element in the array.\n";
	}
	return 0;
}