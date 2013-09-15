#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <queue>


#define MAX  200

using namespace std;


int main()
{
  int t;
  cin >> t;
  int nodeArray[MAX];
  int graph[MAX][MAX];
  queue<int> nodeQueue;


  for (int i = 1; i <= t; i++)
  {
    int nodeCount = 0;
    int m;
    string tmp1, tmp2;
    map<string, int> nodeMap;
    int index1, index2;
    memset((char *)graph, 0, MAX*MAX*sizeof(int));
    memset((char *)nodeArray, 0, MAX*sizeof(int));
    cin >> m;
    for (int j = 0; j < m; j++)
    {
      cin >> tmp1 >> tmp2;
      map<string, int>::iterator iter1 = nodeMap.find(tmp1);
      map<string, int>::iterator iter2 = nodeMap.find(tmp2);
      if (iter1 != nodeMap.end()) {
        index1 = iter1->second;
      }
      else
      {
        index1 = nodeCount++;
        nodeMap.insert(make_pair(tmp1, index1));
      }
      if (iter2 != nodeMap.end()) {
        index2 = iter2->second;
      }
      else
      {
        index2 = nodeCount++;
        nodeMap.insert(make_pair(tmp2, index2));
      }
      graph[index1][index2] = graph[index2][index1] = 1;
    }
    nodeArray[0] = 1; // color 1
    nodeQueue.push(0);
    while (!nodeQueue.empty())
    {
      int u = nodeQueue.front();
      nodeQueue.pop();
      for (int j = 0; j < nodeCount; j++)
      {
        if (graph[u][j] == 1 && nodeArray[j] == 0)
        {
            if (nodeArray[u] == 1) {
              nodeArray[j] = 2;
            }
            else {
              nodeArray[j] = 1;
            }
            nodeQueue.push(j);
        }
      }
    }

    // check
    bool flag = true;
    for (int j = 0; j < nodeCount; j++)
    {
      for (int k = 0; k < nodeCount; k++)
      {
        if (graph[j][k] == 1 && nodeArray[j] == nodeArray[k] ) {
          flag = false;
          break;
        }
      }
      if (flag == false) {
        break;
      }
    }
    if (flag) {
      printf("Case #%d: Yes\n", i);
    }
    else
      printf("Case #%d: No\n", i);
  }
}
