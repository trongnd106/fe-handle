// PRUFERCODE
/* 
// Tap hop cac canh - lien ket
edge[0] = {2,3}
edge[1] = {6}
edge[2] = {0,4,6,9}
edge[3] = {0}
edge[4] = {2}
edge[5] = {6}
edge[6] = {2,1,5}
edge[7] = {9}
edge[8] = {9}
edge[9] = {8,7,2}

// Tap hop cac dinh(value dang set) theo deg
group[deg=2] : {0}
group[deg=1] : {1, 3, 4, 5, 7, 8}
group[deg=4] : {2}
group[deg=3] : {6,9}
*/

#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

vector<long> deg;                         // store: deg
vector<set<long>> edge;                   // store: v_friends (connect  _ex: 0 with 2,3)
map<long,set<long>> group;                // store: group of vertices with a determined deg
long N;                         // N < 100000
long count = 0;                 // make sure that (N-1) deletions

void initiated(){
    edge.resize(N+1,set<long>());
	deg.resize(N+1,0);         
}

void pruferConstructor(){
	long v1,v2;
	cin >> N;
	initiated();
	for(int i = 0; i < N; i++){      // N egde
		cin >> v1 >> v2;
		deg[v1]++; deg[v2]++;
		// connect v1 and v2
			edge[v1].insert(v2);
			edge[v2].insert(v1);
	}
	for(int i = 0; i <= N; i++){    // N+1 vertices
	    group[deg[i]].insert(i);    
	}   
	while(group[1].size() != 0){
		long remove = *(group[1].begin());
	    long pair = *(edge[remove].begin()); 
	    
	    if (remove != 0){
			// delete
			group[1].erase(remove);      // delete 'remove' from group(deg=1)
			edge[pair].erase(remove);    // delete 'remove' from pair_friends
			// print
			if (count <= N-2) {         // no 0
				cout << pair << " ";
				++count;	  
			} 
			// decrease deg 
			group[deg[pair]].erase(pair);  // deg -1
				--deg[pair];			
				// re-add	
			if(pair != 0){  
				group[deg[pair]].insert(pair);    
			}
     	}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	pruferConstructor();
	return 0;
}




