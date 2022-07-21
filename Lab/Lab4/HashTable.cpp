#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> readCompanyList(string file_name)
{
	fstream fs(file_name, ios::in);
	string s;
	getline(fs, s);
	Company c;
	vector<Company> cList;
	while (!fs.eof())
	{
		getline(fs, c.name, '|');
		getline(fs, c.profit_tax, '|');
		getline(fs, c.address);
		cList.push_back(c);
	}
	fs.close();
	return cList;
}

long long hashCalculate(int p, int i, int m)
{
	long long res = 1;
	for (int j = 0; j < i; j++)
	{
		res *= p;
		res %= m;
	}
	return res;
}

long long hashString(string company_name)
{
	int len = company_name.size() > 20 ? 20 : company_name.size();
	int begin = company_name.size() > 20 ? company_name.size() - 20 : 0;
	long long m = pow(10, 9) + 9;
	long long hashValue = 0;
	for (int i = begin; i < (begin + len); i++)
		hashValue += int(company_name[i]) * hashCalculate(31, i - begin, m);
	return hashValue % m;
}

Company *createHashTable(vector<Company> list_company) {
	Company *pC = new Company[2000];
	for(int i=0; i<list_company.size(); i++) {
		int hval = hashString(list_company[i].name);

		if(pC[hval % 2000].name == "") 
			pC[hval % 2000] = list_company[i];	
		else {
			int tmp = hval % 2000 + 1;
			while(pC[tmp].name != "") {
				tmp = (tmp + 1) % 2000;
			}
			pC[tmp] = list_company[i];
		}
	}	
	return pC;
}

void Insert(Company *hash_table, Company company) {
	int hval = hashString(company.name);
	if(hash_table[hval % 2000].name == "")
		hash_table[hval % 2000] = company;
	else {
		int tmp = hval % 2000 + 1;
		while(hash_table[tmp].name != "")
			tmp = (tmp + 1) % 2000;
		hash_table[tmp] = company;
	}
}

Company *Search(Company *hash_table, string company_name) {
	int hval = hashString(company_name);
	while(hash_table[hval % 2000].name != company_name) {
		if(hash_table[hval % 2000].name == "")
			return NULL;
		hval = (hval + 1) % 2000;
	}
	return &hash_table[hval % 2000];
}

int main() {
	Company *pC = createHashTable(readCompanyList("MST.txt"));

	for (int i = 0; i < 2000; i++)
		if (pC[i].name != "")
			cout << i << "  " << pC[i].name << endl;

	Company myC{"ABC", "123456", "Khongco"};
	Insert(pC, myC);
	Company *found = Search(pC, "ABC");
	cout << found->name << " " << found->profit_tax << " " << found->address;
	return 0;
}
