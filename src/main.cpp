#include "ip_address.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> split(const string& str, char d)
{
	vector<string> r;

	string::size_type start = 0;
	string::size_type stop = str.find_first_of(d);
	while (stop != string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

int main(int argc, char const* argv[])
{
	try
	{
		vector<ip_address> ip_pool;

		for (string line; std::getline(cin, line);)
		{
			vector<string> v = split(line, '\t');
			ip_pool.push_back(ParseIp(v.at(0)));
		}

		sort(ip_pool.begin(), ip_pool.end(), [](const ip_address& rhs, const ip_address& lhs) { return rhs > lhs; });

		for (const auto& a : ip_pool)
		{
			cout << a << endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}


	
	cin.get();
	cin.get();

	return 0;
}

