#include <QCoreApplication>
#include "Queue.h"
#include <iostream>

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

  return a.exec();
}
