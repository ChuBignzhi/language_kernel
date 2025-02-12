//省份数量
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void dfs(int i, int citynum, vector<bool> &visited, const vector<vector<int>> &city){
    for(int j=0; j<citynum; j++){
        if (city[i][j]==1 && !visited[j]){
            visited[j]=true;
            dfs(j, citynum, visited, city);
        }
    }
}

int getProvince(const vector<vector<int>> &city, int citynum){
    vector<bool> visited(citynum, false);
    int province = 0;
    for(int i=0; i<citynum; i++){
        if(!visited[i]){
            dfs(i, citynum, visited, city);
            province++;
        }
    }
    return province;
}

int main()
{
    vector<vector<int>> city1 = {{1,1,0}, {1,1,0}, {0,0,1}};
    vector<vector<int>> city2 = {{1,0,0}, {0,1,0}, {0,0,1}};
    cout << getProvince(city1, 3) << endl;
    cout << getProvince(city2, 3) << endl;
    return 0;
}