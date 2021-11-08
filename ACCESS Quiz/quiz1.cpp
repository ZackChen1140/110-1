#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct num {
	int e;
	int n;

	bool operator<(const num& r) const
	{
		return (n < r.n) || (n == r.n && e > r.e);
	}
};

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
		int en = 0;

		for (int i = 0; i < input.length(); ++i)
		{
			if (input[i] >= '0' && input[i] <= '9')
				words.push(input[i]-'0');
			else if (!words.empty())
				++ele[getNum(words)], ++en;
		}
		if (ele.empty()) continue;

		priority_queue<num> oe;
		for (auto it = ele.begin(); it != ele.end(); ++it)
			oe.push({ it->first, it->second });

		oe.top().n > en / 2 ? 
			cout << oe.top().e << '\n' : 
			cout << "There is no majority element in the array.\n";
	}
	return 0;
}