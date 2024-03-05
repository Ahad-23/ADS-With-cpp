#include <iostream>
#include<queue>
using namespace std;
class gnode{
	int vertex;
	gnode* next;
	friend class graph;
};
class graph{
	gnode* head[20];
	int n;
	int visited[20];
	int visit[20];
	public:
		graph()
        {
			cout<<"Enter the number of vertices";
			cin>>n;
			for(int i=0;i<n;i++){
				head[i] = new gnode();
				head[i]->vertex=i;
				}
			
		}
		void create()
        {
			for(int i=0;i<n;i++){
				gnode* temp = head[i];
				int v;
				char ch;
				do{
					cout << "Enter the adjacent element to "<<i << ":"<<endl;
					cin >> v;
					if (i==v)
						cout<<"Self Loop is not allowed"<<endl;
					else{
						if (v == 999)
							continue;
						gnode* curr = new gnode();
						curr->vertex = v;
						temp->next = curr;
						temp = temp->next;
					}
					cout << "Do you want to enter more vertices(y/n)";
					cin >> ch;
				}while(ch=='y');
			}
			dfs();
		}
		void dfs(){
			int node;
			cout << "Enter the starting vertex";
			cin >> node;
			for (int i = 0;i<n;i++)
			visited[i] = 0;
			dfs(node);
			bfs(node);
		}
		void dfs(int v){
			int node;
			gnode* temp = head[v]->next;
			visited[v] = 1;
			cout << v << endl;
			while (temp != NULL){
				node = temp->vertex;
				if (!visited[node])
					dfs(node);
				temp = temp->next;
			}
		}
	void bfs(int v)
	{
		queue<int> q;
		q.push(v);
		for (int i = 0; i < n; i++)
			visit[i] = 0;
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			if (!visit[current])
			{
				cout << current << "\n";
				visit[current] = 1;
				gnode *temp = head[current]->next;
				while (temp != NULL)
				{
					int w = temp->vertex;
					if (!visit[w])
					{
						q.push(w);
					}
					temp = temp->next;
				}
			}
		}
	}
};
int main(){
	graph g;
	g.create();
	
	return 0;
}
/*
PS C:\Users\Ahad\Documents\GitHub\ADS-With-cpp> g++ graph_creation.cpp
PS C:\Users\Ahad\Documents\GitHub\ADS-With-cpp> ./a.exe
Enter the number of vertices6
Enter the adjacent element to 0:
1
Do you want to enter more vertices(y/n)y
Enter the adjacent element to 0:
3
Do you want to enter more vertices(y/n)n
Enter the adjacent element to 1:
2
Do you want to enter more vertices(y/n)n
Enter the adjacent element to 2:
4
Do you want to enter more vertices(y/n)n
Enter the adjacent element to 3:
2
Do you want to enter more vertices(y/n)n
Enter the adjacent element to 4:
999
Enter the adjacent element to 5:
3
Do you want to enter more vertices(y/n)y
Enter the adjacent element to 5:
4
Do you want to enter more vertices(y/n)n
Enter the starting vertex0
DFS
0
1
2
4
3
BFS
0
1
3
2
4*/