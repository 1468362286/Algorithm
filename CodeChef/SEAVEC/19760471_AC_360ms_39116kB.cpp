#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long ll;
int min(int a, int b) { return a > b ? b : a; }
int n, k, t;
vector<vector<long long> >a;
vector<long long>res;
vector<int>CurrentAns;
vector<int>NewAns;
const int ansLen=20;
int AnsLen;

void ReadDate()
{
	cin >> n >> k;
	a.resize(n + 1, vector<long long>(k + 1));
	res.resize(k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
		{
			cin >> a[i][j];
		}
	for (int i = 0; i < k; i++)cin >> res[i];
}
void init()
{
	vector<vector<int>>max(100, vector<int>(n + 1));
	long long diff = 10000000000ULL;
	long long pos = 0;
	int ans = 0;
	int AnsLen = min(ansLen, n);
	for (int p = 0; p < AnsLen ; p++)
	{
		ans = 0;
		long long buff[100001] = { 0 };
		for (int i = p; i < n; i++)
		{
			bool over = false;
			for (int j = 0; j < k; j++)
			{
				if (buff[j] + a[i][j] > res[j])
				{
					over = true;
					break;
				}
			}
			if (!over)
			{
				for (int j = 0; j < k; j++)
					buff[j] += a[i][j];
				ans++;
				max[p][ans] = i + 1;
			}
		}
		max[p][0] = ans;
		long long tempdiff = 0;
		for (int j = 0; j < k; j++)
		{
			tempdiff += res[j] - buff[j];
		}
		if (tempdiff < diff)
		{
			pos = p; diff = tempdiff;
		}
	}
	CurrentAns.clear();
	for (int i = 1; i <= max[pos][0]; i++)
		CurrentAns.push_back(max[pos][i]);
}

double CalValue(vector<int>& vec)
{
	vector<ll> tmp(k+1,0);
	for (int i = 0; i < vec.size(); i++)
	{
		for(int j = 0 ; j < k ; j++)
			tmp[j] += a[vec[i]-1][j];
	}
	ll tempdiff = 0;
	for (int i = 0; i < k; i++)
	{
		if (res[i] - tmp[i] < 0)
			return -1;
		tempdiff += res[i] - tmp[i];
	}
	return 1.0*vec.size()/(tempdiff+1);
}

vector<int> ChangeSolution1(vector<int>& vec)
{
	vector<int>tmp;
	for (int i = 1; i <= n; i++)
	{
		tmp.push_back(i);
	}
	srand(unsigned(time(0)));
	random_shuffle(tmp.begin(), tmp.end());
	vector<int>ans;
	int random_len = rand() % n;
	for (int i = 0; i < random_len; i++)
	{
		ans.push_back(tmp[i]);
	}
	return ans;
}

vector<int> ChangeSolution2(vector<int>& vec)
{
	vector<int>vist(n+1,0);
	for (int i = 0; i < vec.size(); i++)
	{
		vist[vec[i]] = 1;
	}
	vector<int>tmp;
	for (int i = 1; i <= n; i++)
	{
		if (!vist[i])
			tmp.push_back(i);
	}
	vector<int>ans;
	random_shuffle(vec.begin(), vec.end());
	random_shuffle(tmp.begin(), tmp.end());
	int changeLen = min(10,min(tmp.size(), vec.size()));
	for (int i = 0; i < vec.size()-changeLen; i++)
			ans.push_back(vec[i]);
	for(int i = 0 ; i < changeLen ; i++)
		ans.push_back(tmp[i]);
	return ans;
}
void Climb()
{
	int t = 50;
	if (CurrentAns.size() > 0 && CurrentAns.size() < n)
	{
		while (t--)
		{
			NewAns = ChangeSolution1(CurrentAns);
			double NewDiff = CalValue(NewAns);
			double CurDiff = CalValue(CurrentAns);
			if (NewDiff != -1 && NewDiff > CurDiff)
			{
				CurrentAns.clear();
				CurrentAns.assign(NewAns.begin(), NewAns.end());
			}
		}
	}
}

void Print()
{
	sort(CurrentAns.begin(), CurrentAns.end());
	cout << CurrentAns.size() << endl;
	for (int i = 0; i < CurrentAns.size(); i++)
	{
		cout << CurrentAns[i] << " ";
	}
	if(CurrentAns.size()!=0)
		cout << endl;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	cin >> t;
	while (t--)
	{
		ReadDate();
		init();
		Climb();
		Print();
	}
    return 0;
}