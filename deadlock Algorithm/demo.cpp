#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> alloc, maxNeed, remNeed;
vector <int> available;
int n;  // number of processes
int res; // number of resource type

void input(){
	freopen("bankers.txt", "r", stdin);
	cin >> n >> res;

	alloc.resize(n, vector<int> (res));
	maxNeed.resize(n, vector<int> (res));
	remNeed.resize(n, vector<int> (res));
	available.resize(res);

	// allocation matrix
	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			cin >> alloc[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			cin >> maxNeed[i][j];
		}
	}
	for(int i = 0; i < res; i++){
		cin >> available[i];
	}
}

void calculateNeed(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < res; j++){
			remNeed[i][j] = maxNeed[i][j] - alloc[i][j];
		}
	}
}

int main(){
	input();
	calculateNeed();

	isSafe();
	return 0;

}
