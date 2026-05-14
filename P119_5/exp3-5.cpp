#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int x;
    int y;
    int dir;
};
int maze[6][6]={
        {1,1,1,1,1,1},
        {1,0,0,0,1,1},
        {1,0,1,0,0,1},
        {1,0,0,0,1,1},
        {1,1,0,0,0,1},
        {1,1,1,1,1,1}};
bool visited[6][6]={false};
bool canGo(int x,int y){
    return x>=0 && x<6 && y>=0 && y<6 && maze[x][y]==0 && !visited[x][y];
}
int main(){
    vector <pair<int,int>> path;
    vector<vector<pair<int, int>>> allPaths;
    stack<Node> s;
    //0,1,2,3分别表示向右、向下、向左、向上走
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    s.push({1,1,0});
    path.push_back({1,1});
    visited[1][1]=true;
    while(!s.empty()){
        Node &top=s.top();
        int x=top.x;
        int y=top.y;
        if(x==4 && y==4){
            allPaths.push_back(path);
            visited[x][y]=false;
            path.pop_back();
            s.pop();
            continue;
        }
        bool moved=false;
        while(top.dir<4){
            int dir=top.dir;
            top.dir++;
            int nextX=x+dx[dir];
            int nextY=y+dy[dir];
            if(canGo(nextX,nextY)){
                s.push({nextX,nextY,0});
                path.push_back({nextX,nextY});
                visited[nextX][nextY]=true;
                moved=true;
                break;
            }
        }
        if(!moved){
            s.pop();
            visited[x][y]=false;
            path.pop_back();
        }
    }
    if (allPaths.empty()) {
        cout << "No path found!" << endl;
        return 0;
    }
    for(const auto &p:allPaths){
        cout<<"Path:"<<" ";
        for(const auto &p2:p){
            cout<<"("<<p2.first<<","<<p2.second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
    auto shortestPath=min_element(
        allPaths.begin(),
        allPaths.end(),
        [](const vector<pair<int,int>> &a,const vector<pair<int,int>> &b){
            return a.size()<b.size();
        }
    );
    cout<<"Shortest Path:"<<" "<<shortestPath->size()-1<<endl;
    for(const auto &p:*shortestPath){
        cout<<"("<<p.first<<","<<p.second<<") ";
    }
    return 0;
}