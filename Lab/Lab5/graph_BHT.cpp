#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
using namespace std;

/*
9
0 0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0
1 0 0 0 0 0 1 1 0
0 0 0 0 1 1 0 0 0
0 0 0 1 0 1 0 0 0
1 0 0 1 1 0 0 1 0
0 1 1 0 0 0 0 0 0
0 0 1 0 0 1 0 0 1
0 0 0 0 0 0 0 1 0

9
2 5
6
0 6 7
4 5
3 5
0 3 4 7
1 2
2 5 8
7
*/

// using v2d = vector<vector<int>>;

//#1 Ma trận kề: Nếu đỉnh i và j có nối với nhau:
//		> a[i][j] = 1 / a[i][j] = trọng số
//#2 Danh sách kề:
// 		> Tại đỉnh i sẽ nối với các đỉnh ...

vector<vector<int>> toAdjList()
{
	ifstream fi("graph1.txt");
	string s, s1;
	getline(fi, s);
	int v = stoi(s);
	vector<vector<int>> adjList;
	for (int i = 0; i < v; i++)
	{
		getline(fi, s);
		stringstream ss(s);
		vector<int> temp;
		for (int i = 0; i < v; i++)
		{
			getline(ss, s1, ' ');
			if (s1 == "1")
			{
				temp.push_back(i);
			}
		}
		adjList.push_back(temp);
	}
	return adjList;
}

vector<vector<int>> toAdjMatrix()
{
	ifstream fi("graph2.txt");
	string s, s1;
	getline(fi, s);
	int v = stoi(s);
	vector<vector<int>> adjMatrix;
	for (int i = 0; i < v; i++)
	{
		getline(fi, s);
		stringstream ss(s);
		vector<int> temp(v, 0);
		while (!ss.eof())
		{
			getline(ss, s1, ' ');
			temp[stoi(s1)] = 1;
		}
		adjMatrix.push_back(temp);
	}
	return adjMatrix;
}

bool isDirected1(vector<vector<int>> adjList)
{
	bool check;
	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			if (!count(adjList[adjList[i][j]].begin(), adjList[adjList[i][j]].end(), i))
				return 1;
			/*
			check = false;
			for(int k = 0; k < adjList[adjList[i][j]].size(); k++){
				if(adjList[adjList[i][j]][k] == i){
					check = true;
					break;
				}
			}
			if(check == false)
				return 1;
			*/
		}
	}
	return 0;
}

bool isDirected2(vector<vector<int>> adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[i].size(); j++)
		{
			if (adjMatrix[i][j] != adjMatrix[j][i])
				return 1;
		}
	}
	return 0;
}

int numberOfVertices(vector<vector<int>> adjList)
{
	return adjList.size();
}

int numberOfEdges1(vector<vector<int>> adjList)
{
	int sum = 0;
	for (int i = 0; i < adjList.size(); i++)
	{
		sum += adjList[i].size();
	}
	if (isDirected2(adjList))
		return sum;
	return sum / 2;
}

int numberOfEdges2(vector<vector<int>> adjMatrix)
{
	int sum = 0;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		sum += count(adjMatrix[i].begin(), adjMatrix[i].end(), 1);
	}
	if (isDirected1(adjMatrix))
		return sum;
	return sum / 2;
}

// Trong đồ thị vô hướng, bậc của 1 đỉnh là số cạnh bắt đầu từ đỉnh đó
// Trong đồ thị có hướng, bậc vào (in degree) là số cạnh đi đến đỉnh đó
//						  bậc ra (out degree) là số cạnh từ đỉnh đó đi ra
//						  bậc của đỉnh = bậc vào + bậc ra

int outDegree1(vector<vector<int>> adjList, int vertex)
{
	return adjList[vertex].size();
}

int outDegree2(vector<vector<int>> adjMatrix, int vertex)
{
	return count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1);
}

int inDegree1(vector<vector<int>> adjList, int vertex)
{
	int sum = 0;
	for (int i = 0; i < adjList.size(); i++)
	{
		sum += count(adjList[vertex].begin(), adjList[vertex].end(), vertex);
	}
	return sum;
}

int inDegree2(vector<vector<int>> adjMatrix, int vertex)
{
	int count = 0;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (adjMatrix[i][vertex])
			count++;
	}
	return 0;
}

int degreeOf1(vector<vector<int>> adjList, int vertex)
{
	if (isDirected1(adjList))
		return inDegree1(adjList, vertex) + outDegree1(adjList, vertex);
	return adjList[vertex].size();
}

int degreeOf2(vector<vector<int>> adjMatrix, int vertex)
{
	if (isDirected2(adjMatrix))
		return inDegree2(adjMatrix, vertex) + outDegree2(adjMatrix, vertex);
	return count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1);
}

// đỉnh cô lập (isolated vetex) là đỉnh không nối với đỉnh nào khác (bậc = 0)
// đỉnh treo (leaf vetex) là đỉnh chỉ nối với 1 đỉnh khác nó duy nhất (bậc = 1)

vector<int> listOfIsolated1(vector<vector<int>> adjList)
{
	vector<int> IsolatedVetices;
	for (int i = 0; i < adjList.size(); i++)
	{
		if (adjList[i].size() == 0)
			IsolatedVetices.push_back(i);
		if (adjList[i].size() == 1)
		{
			if (adjList[i][0] == i)
				IsolatedVetices.push_back(i);
		}
	}
	return IsolatedVetices;
}

vector<int> listOfIsolated2(vector<vector<int>> adjMatrix)
{
	vector<int> IsolatedVetices;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 0)
			IsolatedVetices.push_back(i);
		if ((count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 1) && (adjMatrix[i][i] == 1))
			IsolatedVetices.push_back(i);
	}
	return IsolatedVetices;
}

vector<int> listOfLeaf1(vector<vector<int>> adjList)
{
	vector<int> LeafVetices;
	for (int i = 0; i < adjList.size(); i++)
	{
		if ((adjList[i].size() == 1) && (adjList[i][0] != i))
			LeafVetices.push_back(i);
		if (adjList[i].size() == 2)
		{
			if ((adjList[i][0] == i) || (adjList[i][1] == i))
				LeafVetices.push_back(i);
		}
	}
	return LeafVetices;
}

vector<int> listOfLeaf2(vector<vector<int>> adjMatrix)
{
	vector<int> LeafVetices;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if ((count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 1) && (adjMatrix[i][i] != 1))
			LeafVetices.push_back(i);
		if ((count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 2) && (adjMatrix[i][i] == 1))
			LeafVetices.push_back(i);
	}
	return LeafVetices;
}

//Đồ thị hoàn chỉnh (giữa 2 đỉnh bất kì  luôn có cạnh nối), không có đỉnh khuyên, vô hướng.

bool isCompletedGraph1(vector<vector<int>> adjList)
{
	for (int i = 0; i < adjList.size(); i++)
	{
		if (adjList[i].size() != adjList.size() - 1)
			return false;
	}
	return true;
}

bool isCompletedGraph2(vector<vector<int>> adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[i].size(); j++)
		{
			if (adjMatrix[i][j] == 0)
				return false;
		}
	}
	return true;
}

//Đồ thị vòng (Circular graph) là đồ thị xếp thành vòng. Mỗi đỉnh sẽ nối với 2 đỉnh khác duy nhất.
bool isCircularGraph1(vector<vector<int>> adjList)
{
	int vertex;
	vector<bool> check(adjList.size(), false);
	queue<int> Q;
	Q.push(0);
	check[0] = true;
	while (!Q.empty())
	{
		vertex = Q.front();
		Q.pop();
		if (adjList[vertex].size() != 2)
			return false;
		else
		{
			if (check[adjList[vertex][0]] == false)
			{
				Q.push(adjList[vertex][0]);
				check[adjList[vertex][0]] == true;
			}
			if (check[adjList[vertex][1]] == false)
			{
				Q.push(adjList[vertex][1]);
				check[adjList[vertex][1]] == true;
			}
		}
	}
	return true;
}

bool isCircularGraph2(vector<vector<int>> adjMatrix)
{
	int vertex;
	vector<bool> check(adjMatrix.size(), false);
	queue<int> Q;
	Q.push(0);
	check[0] = true;
	while (!Q.empty())
	{
		vertex = Q.front();
		Q.pop();
		if (count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1) != 2)
			return false;
		else
		{
			for (int j = 0; j < adjMatrix[vertex].size(); j++)
			{
				if (adjMatrix[vertex][j] == 1)
				{
					if (check[j] == false)
					{
						Q.push(j);
						check[j] = true;
					}
				}
			}
		}
	}
	return true;
}

// Đồ thị phân đôi (Bigraph) có thể chia làm 2 tập đỉnh (A) và (B) sao cho
// các đỉnh của A không nói được với nhau và các đỉnh của B không nối được với nhau.

/*
bool isBigraph1(vector <vector <int>> adjList){
	int v;
	vector <int> s1;
	vector <int> s2;
	deque <int> q1;
	deque <int> q2;
	q1.push_back(0);
	while(!q1.empty() || !q2.empty()){
		if(!q1.empty()){
			v = q1.front();
			q1.pop_front();
			s1.push_back(v);
			for(int i = 0; i < adjList[v].size(); i++){
				bool check = false;
				for(int j = 0; j < q2.size(); j++){
					if(q2[j] == adjList[v][i])
						check = true;
				}
				if(count(s2.begin(), s2.end(), adjList[v][i]) != 0)
					check = true;
				if(check == false){
					q2.push_back(adjList[v][i]);
					//cout << "q2  " << adjList[v][i]  <<endl;
				}
			}
		}

		if(!q2.empty()){
			v = q2.front();
			q2.pop_front();
			s2.push_back(v);
			for(int i = 0; i < adjList[v].size(); i++){
				bool check = false;
				for(int j = 0; j < q1.size(); j++){
					if(q1[j] == adjList[v][i])
						check = true;
				}
				if(count(s1.begin(), s1.end(), adjList[v][i]) != 0)
					check = true;
				if(check == false){
					q1.push_back(adjList[v][i]);
					//cout << "q1  " << adjList[v][i] << endl;
				}
			}
		}
	}
	for(int i = 0; i < s1.size(); i++){
		for(int j = 0; j < s2.size(); j++){
			if(s1[i] == s2[j])
				return false;
		}
	}
	return true;
}
*/

bool isBigraph1(vector<vector<int>> adjList)
{
	int v;
	queue<int> Q;
	vector<int> color(adjList.size(), 0);
	Q.push(0);
	color[0] = 1;
	while (!Q.empty())
	{
		v = Q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjList[v].size(); i++)
			{
				if (color[adjList[v][i]] == color[v])
					return false;
				if (color[adjList[v][i]] == 0)
				{
					color[adjList[v][i]] = -color[v];
					Q.push(adjList[v][i]);
				}
			}
		}
		Q.pop();
	}
	return true;
}

bool isBigraph2(vector<vector<int>> adjMatrix)
{
	int v;
	queue<int> Q;
	vector<int> color(adjMatrix.size(), 0);
	Q.push(0);
	color[0] = 1;
	while (!Q.empty())
	{
		v = Q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjMatrix[v].size(); i++)
			{
				if ((adjMatrix[v][i]) && (color[i] == color[v]))
					return false;
				if ((adjMatrix[v][i]) && (color[i] == 0))
				{
					color[i] = -color[v];
					Q.push(i);
				}
			}
		}
		Q.pop();
	}
	return true;
}

//Đồ thị phân đôi đủ: là đồ thị phân đôi
// mà mỗi đỉnh của tập A đều nối với TẤT CẢ các đỉnh của B và ngược lại.

bool isCompletedBigraph1(vector<vector<int>> adjList)
{
	int v;
	queue<int> Q;
	vector<int> color(adjList.size(), 0);
	Q.push(0);
	color[0] = 1;
	while (!Q.empty())
	{
		v = Q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjList[v].size(); i++)
			{
				if (color[adjList[v][i]] == color[v])
					return false;
				if (color[adjList[v][i]] == 0)
				{
					color[adjList[v][i]] = -color[v];
					Q.push(adjList[v][i]);
				}
			}
		}
		Q.pop();
	}
	int count1 = count(color.begin(), color.end(), 1);
	int count_1 = count(color.begin(), color.end(), -1);
	for (int i = 0; i < adjList.size(); i++)
	{
		if (color[i] == 0)
			return false;
		if (color[i] == 1)
		{
			if (degreeOf1(adjList, i) != count_1)
				return false;
		}
		if (color[i] == -1)
		{
			if (degreeOf1(adjList, i) != count1)
				return false;
		}
	}
	return true;
}

bool isCompletedBigraph2(vector<vector<int>> adjMatrix)
{
	int v;
	queue<int> Q;
	vector<int> color(adjMatrix.size(), 0);
	Q.push(0);
	color[0] = 1;
	while (!Q.empty())
	{
		v = Q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjMatrix[v].size(); i++)
			{
				if ((adjMatrix[v][i]) && (color[i] == color[v]))
					return false;
				if ((adjMatrix[v][i]) && (color[i] == 0))
				{
					color[i] = -color[v];
					Q.push(i);
				}
			}
		}
		Q.pop();
	}
	int count1 = count(color.begin(), color.end(), 1);
	int count_1 = count(color.begin(), color.end(), -1);
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (color[i] == 0)
			return false;
		if (color[i] == 1)
		{
			if (degreeOf2(adjMatrix, i) != count_1)
				return false;
		}
		if (color[i] == -1)
		{
			if (degreeOf2(adjMatrix, i) != count1)
				return false;
		}
	}
	return true;
}

int countConnectedComponents1(vector<vector<int>> adjList)
{
	vector<int> check(adjList.size(), 0);
	queue<int> Q;
	int c = 0, v;
	while (count(check.begin(), check.end(), 0))
	{
		for (int i = 0; i < adjList.size(); i++)
		{
			if (check[i] == 0)
			{
				Q.push(i);
				c++;
				while (!Q.empty())
				{
					v = Q.front();
					Q.pop();
					if (check[v] == 0)
					{
						check[v] = 1;
						for (int j = 0; j < adjList[v].size(); j++)
						{
							if (check[adjList[v][j]] == 0)
							{
								Q.push(adjList[v][j]);
							}
						}
					}
				}
			}
		}
	}
	return c;
}

int countConnectedComponents2(vector<vector<int>> adjMatrix)
{
	vector<int> check(adjMatrix.size(), 0);
	queue<int> Q;
	int c = 0, v;
	while (count(check.begin(), check.end(), 0))
	{
		for (int i = 0; i < adjMatrix.size(); i++)
		{
			if (check[i] == 0)
			{
				Q.push(i);
				c++;
				while (!Q.empty())
				{
					v = Q.front();
					Q.pop();
					if (check[v] == 0)
					{
						check[v] = 1;
						for (int j = 0; j < adjMatrix.size(); j++)
						{
							if (adjMatrix[v][j] == 1 && check[j] == 0)
							{
								Q.push(j);
							}
						}
					}
				}
			}
		}
	}
	return c;
}

//Đỉnh cắt (cut vertex): là đỉnh mà khi bỏ đỉnh đó ra khỏi đồ thị
// thì số thành phần liên thông tăng lên

bool isCutVertex1(vector<vector<int>> adjList, int v)
{
	int comp = countConnectedComponents1(adjList);
	// cout << comp << endl;
	adjList[v] = {};
	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			if (adjList[i][j] == v)
				adjList[i].erase(adjList[i].begin() + j);
		}
	}
	int comp_ = countConnectedComponents1(adjList);
	// cout << comp_ << endl;
	return ((comp + 1) != comp_);
}

bool isCutVertex2(vector<vector<int>> adjMatrix, int v)
{
	int comp = countConnectedComponents2(adjMatrix);
	// cout << comp << endl;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (adjMatrix[i][v] == 1)
		{
			adjMatrix[i][v] = 0;
			adjMatrix[v][i] = 0;
		}
	}
	int comp_ = countConnectedComponents2(adjMatrix);
	// cout << comp_ << endl;
	return ((comp + 1) != comp_);
}
// Cạnh cầu (Bridge edge): là cạnh mà khi bỏ cạnh nó ra khỏi đồ thị
// thì số thành phần liên thông tăng lên

bool isBridgeEdge1(vector<vector<int>> adjList, int v1, int v2)
{
	int comp = countConnectedComponents1(adjList);
	for (int i = 0; i < adjList[v1].size(); i++)
	{
		if (adjList[v1][i] == v2)
			adjList[v1].erase(adjList[i].begin() + i);
	}

	for (int i = 0; i < adjList[v2].size(); i++)
	{
		if (adjList[v2][i] == v1)
			adjList[v2].erase(adjList[i].begin() + i);
	}
	int comp_ = countConnectedComponents1(adjList);
	return (comp != comp_);
}

bool isBridgeEdge2(vector<vector<int>> adjMatrix, int v1, int v2)
{
	int comp = countConnectedComponents1(adjMatrix);
	adjMatrix[v1][v2] = 0;
	adjMatrix[v2][v1] = 0;
	int comp_ = countConnectedComponents1(adjMatrix);
	return (comp != comp_);
}

vector<vector<int>> toBaseUndirectedGraph1(vector<vector<int>> adjList)
{
	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList[i].size(); j++)
		{
			int check = true;
			for (int k = 0; k < adjList[adjList[i][j]].size(); k++)
			{
				if (adjList[adjList[i][j]][k] == i)
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				adjList[adjList[i][j]].push_back(i);
				sort(adjList.begin(), adjList.end());
			}
		}
	}
	return adjList;
}

vector<vector<int>> toBaseUndirectedGraph2(vector<vector<int>> adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix.size(); j++)
		{
			if (adjMatrix[i][j] == 1)
				adjMatrix[j][i] = 1;
		}
	}
	return adjMatrix;
}

// Complement graph: đồ thị bù. Cho đồ thị A và B bù nhau.
// Nếu 2 cạnh i và j có nối với nhau trong A thì trong B không nối.
// Nếu 2 cạnh i và j không nối với nhau trong A thì trong B có nối.

vector<vector<int>> toComplement1(vector<vector<int>> adjList)
{
	vector<vector<int>> comp;
	vector<int> temp;
	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList.size(); j++)
		{
			if (j != i)
			{
				if (count(adjList[i].begin(), adjList[i].end(), j) == 0)
				{
					temp.push_back(j);
				}
			}
		}
		comp.push_back(temp);
	}
	return comp;
}

vector<vector<int>> toComplement2(vector<vector<int>> adjMatrix)
{
	// Số 0 đổi thành 1 và 1 đổi thành 0;
}
// Converse graph: đồ thị ngược. Cho đồ thị có hướng A. B là bù của A khi:
// Nếu đỉnh i đi tới j trong A thì trong B j sẽ đi tới i.

vector<vector<int>> toConverse(vector<vector<int>> adjList)
{
	vector<int> temp = {};
	vector<vector<int>> Conv(adjList.size(), temp);
	for (int i = 0; i < adjList.size(); i++)
	{
		for (int j = 0; j < adjList.size(); j++)
		{
			Conv[adjList[i][j]].push_back(i);
		}
	}
	for (int i = 0; i < adjList.size(); i++)
	{
		sort(Conv[i].begin(), Conv[i].end());
	}
	return Conv;
}

vector<vector<int>> toConverse(vector<vector<int>> adjMatrix)
{
	// Khởi tạo Conv giá trị 0 hết
	// Nếu adjMatrix[i][j] = 1 thì Conv[j][i] = 1
}
int main()
{
	vector<vector<int>> adjList = toAdjList();
	// vector <vector <int>> adjMatrix = toAdjMatrix();
	vector<vector<int>> adjList1 = toBaseUndirectedGraph1(adjList);

	for (int i = 0; i < adjList1.size(); i++)
	{
		for (int j = 0; j < adjList1[i].size(); j++)
		{
			cout << adjList1[i][j] << "  ";
		}
		cout << endl;
	}
	// cout << isCutVertex2(adjMatrix, 1);

	// cout << countConnectedComponents1(adjList) << "  " << countConnectedComponents2(adjMatrix);
	/*
	vector <int> Leaf1 = listOfLeaf1(adjList);
	for(int i = 0; i < Leaf1.size(); i++){
		cout << Leaf1[i] << "   ";
	}

	cout << endl;

	vector <int> Leaf2 = listOfLeaf2(adjMatrix);
	for(int i = 0; i < Leaf2.size(); i++){
		cout << Leaf2[i] << "   ";
	}

	//cout << isDirected1(adjMatrix) << "  " << isDirected2(adjList);
	for(int i = 0; i < adjMatrix.size(); i++){
		for(int j = 0; j < adjMatrix[i].size(); j++){
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
