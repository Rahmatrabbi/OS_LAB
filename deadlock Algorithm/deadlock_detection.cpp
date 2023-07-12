#include <bits/stdc++.h>
using namespace std;

int n, res, temp;
vector <vector <int>> alloc;
vector <vector <int >> request;
vector <int> available;


void input(){
    freopen("deadlock.txt", "r", stdin);
    cin >> n;  //number of processes
    cin >> res; // number of resource type

    alloc.resize(n, vector<int> (res));
    request.resize(n, vector<int> (res));
    available.resize(res);

    // allocation matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < res; j++)
            cin >> alloc[i][j];
    }

    // request matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < res; j++)
            cin >> request[i][j];
    }

    // available
    for(int i = 0; i < res; i++)
        cin >> available[i];

}

bool check(){
    int flag = 0, count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < res; j++){
            if(available[j] >= request[i][j]){
                count = count + 1;
            }
            else
                break;
        }
        if(count == res){
            temp = i;
            return true;
        }
    }
    return false;
}

bool isSafe(){
    bool finish[n];
    while(check()){
        for(int i = 0; i < res; i++){
            available[i] = available[i] + alloc[temp][i];
            finish[temp] = 1;
        }
    }


    return false;
}

void show(){
    puts("Process \tAllocation \tRequest \tAvailable");

    for(int i = 0; i < n; i++){
        // processes
        cout << "P" << i << "\t\t";
        // allocation matrix
        for(int j = 0; j < res; j++){
            cout << alloc[i][j] << " ";
        }
        // request matrix
        cout << "\t\t";
        for(int j = 0; j < res; j++){
            cout << request[i][j] << " ";
        }
        if(i == 0){
            // available matrix
            cout << "\t\t";
            for(int j = 0; j < res; j++){
                cout << available[i] << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    input();
    show();

    if(isSafe()){
        cout << "No Deadlock!";
    }
    else
        cout << "Deadlock is present";

    return 0;
}
