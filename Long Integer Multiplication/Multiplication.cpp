// 	Nail Emre Kayapýnar
#include <iostream>
#include <string>
#include<fstream>
#include<stdlib.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

string add(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());
	int carry = 0;
	int sum_col;  // sum of two digits in the same column
	string result;

	// pad the shorter string with zeros
	while (lhs.size() < length)
		lhs.insert(0, "0");

	while (rhs.size() < length)
		rhs.insert(0, "0");

	// build result string from right to left
	for (int i = length - 1; i >= 0; i--) {
		sum_col = (lhs[i] - '0') + (rhs[i] - '0') + carry;
		carry = sum_col / 10;
		result.insert(0, to_string(sum_col % 10));
	}

	if (carry)
		result.insert(0, to_string(carry));

	// remove leading zeros
	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string subtract(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());
	int diff;
	string result;

	while (lhs.size() < length)
		lhs.insert(0, "0");

	while (rhs.size() < length)
		rhs.insert(0, "0");

	for (int i = length - 1; i >= 0; i--) {
		diff = (lhs[i] - '0') - (rhs[i] - '0');
		if (diff >= 0)
			result.insert(0, to_string(diff));
		else {

			// borrow from the previous column
			int j = i - 1;
			while (j >= 0) {
				lhs[j] = ((lhs[j] - '0') - 1) % 10 + '0';
				if (lhs[j] != '9')
					break;
				else
					j--;
			}
			result.insert(0, to_string(diff + 10));
		}

	}

	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string multiply(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());

	while (lhs.size() < length)
		lhs.insert(0, "0");

	while (rhs.size() < length)
		rhs.insert(0, "0");

	if (length == 1)
		return to_string((lhs[0] - '0')*(rhs[0] - '0'));

	string lhs0 = lhs.substr(0, length / 2);
	string lhs1 = lhs.substr(length / 2, length - length / 2);
	string rhs0 = rhs.substr(0, length / 2);
	string rhs1 = rhs.substr(length / 2, length - length / 2);

	string p0 = multiply(lhs0, rhs0);
	string p1 = multiply(lhs1, rhs1);
	string p2 = multiply(add(lhs0, lhs1), add(rhs0, rhs1));
	string p3 = subtract(p2, add(p0, p1));

	for (int i = 0; i < 2 * (length - length / 2); i++)
		p0.append("0");
	for (int i = 0; i < length - length / 2; i++)
		p3.append("0");

	string result = add(add(p0, p1), p3);

	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
	
}

int main() 
{
	int i = 0,n;
	cout << "enter the n value";
	cin >> n;
	string s1, s2,result,txt1,txt2;
	cout << "Enter first file name:  ";
	cin >> txt1;
	cout << "Enter second file name:  ";
	cin >> txt2;
	ifstream d1;
	d1.open(txt1);
	while (!d1.eof())
	{
		d1 >> s1;
		s1= s1.substr(0, n);
		reverse(s1.begin(), s1.end());
	}
	cout << endl;
	ifstream d2;
	d2.open(txt2);
	while (!d2.eof())
	{
		d2 >> s2;
		s2 = s2.substr(0, n);
		reverse(s2.begin(), s2.end());
	}
	cout << endl;
	result = multiply(s1, s2);
	reverse(result.begin(), result.end());
	cout << "The resulting integer is written to Result.txt"<<endl;
	ofstream c("Result.txt");
	if (c.is_open())
	{
		c << result;
		c.close();
	}
	system("pause");
}
