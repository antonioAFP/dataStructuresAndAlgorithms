#include <QCoreApplication>
#include "Queue.h"
#include <iostream>

#define I INT32_MAX

int cost [][8] = {
  {I,I,I,I,I,I,I,I},
  {I,I,25,I,I,I,5,I},
  {I,25,I,12,I,I,I,10},
  {I,I,12,I,8,I,I,I},
  {I,I,I,8,I,16,I,14},
  {I,I,I,I,16,I,20,18},
  {I,5,I,I,I,20,I,I},
  {I,I,10,I,14,18,I,I}
};

int near[8] = {I,I,I,I,I,I,I,I};
int t[2][6];

using namespace std;

//Breadth First Search
void bfs(int g[][7], int start, int n){
  int i = start;
  Queue queue;
  int visited[7] = {0};

  cout << i;
  visited[i] = 1;
  queue.enqueue(i);

  while(!queue.isEmpty()){
      i = queue.dequeue();
      for(int j = 1; j < n; j++){
          if(g[i][j] == 1 && visited[j] == 0){
              cout << j;
              visited[j] = 1;
              queue.enqueue(j);
            }
        }
    }
}


//Depth First Seach
void dfs(int g[][7], int start, int n){
  static int visited[7];

  if(visited[start] == 0){
      cout << start;
      visited[start] = 1;
      for(int j = 1; j < n; j++){
          if(g[start][j] == 1 && visited[j] == 0){
              dfs(g, j, n);
            }
        }
    }
}


int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  //adjacency matrix
  int graph[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
  };

  bfs(graph, 1, 7);
  cout << endl;
  dfs(graph, 1, 7);

  //spanning tree, Prims
  int i, j, k, u, v, n = 7, min = I;

  for(i = 1; i <= n; i++){
      for(j = i; j <= n; j++){
          if(cost[i][j] < min){
              min = cost[i][j];   //minimun cost from whole tree
              u = i;
              v = j;
            }
        }
    }

  t[0][0] = u;
  t[1][0] = v;
  near[u] = near[v] = 0;

  for(i = 1; i <= n; i++){
      if(near[i] != 0){
        if(cost[i][u] < cost[i][v])
          near[i] = u;
        else
          near[i] = v;
        }
    }

  for(i = 1; i < n - 1; i++){
      min = I;
      for(j = 1; j <= n; j++){
          if(near[j] != 0 && cost[j][near[j]] < min){
              k = j;
              min = cost[j][near[j]];
            }
        }

      t[0][i] = k;
      t[1][i] = near[k];
      near[k] = 0;

      for(j = 1; j <= n; j++){
          if(near[j] != 0 && cost[j][k] < cost[j][near[j]]){
              near[j] = k;
            }
        }
    }

  cout << endl << " -- Spanning tree:  -- " << endl;
  for(i = 0; i < n - 1; i++)
    cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;

  return a.exec();
}
