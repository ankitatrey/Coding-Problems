#include<iostream>
using namespace std;

#define I 32767
#define V 7
#define E 9

void printMST(int T[][V-1]) {
	cout<< "Minimum spanning tree Edges \n" << endl;
	for(int i = 0 ; i<V-1; i++){
		cout<< "[" << T[0][i] << "]-----[" << T[1][i] << endl;
	}
	cout<<endl;
}

void Union(int u, int v, int s[]){
	if(s[u] < s[v]){
		s[u] += s[v];
		s[v] = u;
	}
	else{
		s[v] += s[u];
		s[u] = v;
	}
} 

int find(int u, int s[]){
	int x = 0;
	int v = 0;
	while(s[x] > 0){
		x = s[x];
	}

	while(u != x){
		v = s[u];
		s[u] = x;
		u = v;
	}
	return x;
}

void krushkalMST(int A[3][9]){
	int T[3][V-1];
	int track[E] {0};
	int set[V+1] {-1};

	int i {0};
	while(i<V-1){
		int min = I;
		int u = 0;
		int v = 0;
		int k {0};

		for(int j=0; j<E; j++){
			if(track[j] == 0 && A[2][j] < min){
				min = A[2][j];
				u = A[0][j];
				v = A[0][j];
				k = j;
			}
		}

		if(find(u,set) != find(v, set)){
			T[0][i] = u;
			T[1][i] = v;
			Union(find(u, set), find(v, set), set);
			i++;
		} 
		track[k] =1;
	}
	printMST(T);

}


int main(void){
	int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
					   {2, 6, 3, 7, 4, 5, 7, 6, 7},
					   {25, 5, 12, 10, 8, 16, 14, 20 ,18}};


	krushkalMST(edges);
	return 0;
}