
#include <vector>
#include <iostream>
#include <stack>
#include <utility>
#include <map>
using namespace std;

template<typename T, typename U>
pair<T, U> operator+(const pair<T, U>& p1, const pair<T, U>& p2){
  return make_pair(p1.first+p2.first, p1.second+p2.second);
  }
vector<vector<int> >& paint_fill(vector<vector<int> >& paint, int x, int y, int newcolor){
 
  if(paint.size() == 0 || x < 0 || x >= paint.size() || y < 0 || y >= paint[0].size()) return paint;
  int origin = paint[x][y];
  stack<pair<int, int> > q;
  map<pair<int, int>, int> visited;
  q.push(make_pair(0,0));
  while(!q.empty()){
    int x = q.top().first;
    int y = q.top().second;
    pair<int, int> top = q.top();
    // visited[top] = 1;
    q.pop();
    //    visited[q.top()] = 1;
    if(x < 0 || y < 0 || x >= paint.size() || y >= paint[0].size() || visited.find(top) != visited.end()) continue;
    if(paint[x][y] == origin){
      paint[x][y] == newcolor;
    }
    visited[top] = 1;
    if(x == paint.size()-1 && y == paint[0].size()-1){
      break;
    }
    vector<pair<int, int> >dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    for(int i = 0; i < 4; i ++){
      if(x == 0 && i == 3) continue;
      if(y == 0 && i == 2) continue;
      pair<int, int> ele = top + dir[i];
      if(ele.first >= 0 && ele.first < paint.size() && ele.second >= 0 && ele.second < paint[0].size()){
      if(paint[ele.first][ele.second] == origin){
	paint[ele.first][ele.second] = newcolor;
      }
      //      visited[ele] = 1;
      q.push(ele);
    }
    }
    }
  return paint;
}

int main(){
  /* int rows, col;
  cin>>rows>>col;
  vector<int> row;
  vector<vector<int> > paint;
   while(cin){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < col; ++j){
      int color;
      cin>>color;
      row.push_back(color);
    }
    paint.push_back(row);
    row.clear();
  }
  }*/
  vector<vector<int> > paint = {{1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 1, 1},
				{1, 2, 2, 2, 2, 0, 1, 0},
				{1, 1, 1, 2, 2, 0, 1, 0},
				{1, 1, 1, 2, 2, 2, 2, 0},
				{1, 1, 1, 1, 1, 2, 1, 1},
				{1, 1, 1, 1, 1, 2, 2, 1},
  };
  paint = paint_fill(paint, 4, 4, 3);
  int rows = paint.size();
  int col = paint[0].size();
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < col; ++j){
      cout<<paint[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
