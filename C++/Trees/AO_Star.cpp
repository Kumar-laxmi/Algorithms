#include<bits/stdc++.h>
#define MAX 1000
#define EDGE 5
using namespace std;
bool or_map[MAX],and_map[MAX];

vector<int > or_edges;
vector< vector<int> > and_edges;

vector<int> adj[MAX];

int cost[MAX];
bool isSolved[MAX],visited[MAX];
int min(int a,int b){return a<b?a:b;}
void init(){
	adj[1].push_back(2);adj[1].push_back(3);adj[1].push_back(4);
	adj[2].push_back(5);adj[2].push_back(6);adj[2].push_back(7);
	adj[3].push_back(8);adj[3].push_back(9);
	adj[4].push_back(10);adj[4].push_back(11);
	adj[5].push_back(12);adj[5].push_back(13);
	adj[6].push_back(14);adj[6].push_back(15);
	adj[7].push_back(16);adj[7].push_back(17);
	adj[8].push_back(18);adj[9].push_back(19);adj[10].push_back(20);adj[11].push_back(21);
	
	cost[1]=0;cost[2]=40;cost[3]=2;cost[4]=4;cost[5]=1;cost[6]=2;cost[7]=3;cost[8]=50;
	cost[9]=60;cost[10]=70;cost[11]=80;cost[12]=4;cost[13]=5;cost[14]=8;cost[15]=9;
	cost[16]=6;cost[17]=7;cost[18]=cost[19]=cost[20]=cost[21]=90;
	for(int i=0;i<=21;i++){
		visited[i]=false;
		isSolved[i]=false;
		and_map[i]=or_map[i]=false;
		if(adj[i].size()==0) isSolved[i]=true;
	}
	vector<int> v;v.push_back(3);v.push_back(4); 
	and_map[3]=and_map[4]=true;
	and_edges.push_back(v); v.clear();
	
	v.push_back(5);v.push_back(6);v.push_back(7);
	and_map[5]=and_map[6]=and_map[7]=true;
	and_edges.push_back(v); v.clear();	
	
	for(int i=1;i<=21;i++)
		if(and_map[i]==false) or_map[i]=true;
	
	cout<<"and_edges: "<<endl;
	for(int i=0;i<and_edges.size();i++){
		cout<<i<<": ";
		for(int j=0;j<and_edges[i].size();j++)
			cout<<and_edges[i][j]<<", ";
		cout<<endl;
	}
}

void aoStarUtil(int head){
	if(visited[head]==false){
		/*exploring the options and 
		also check if any of the options were solved, if yes then set head as solved
		and
		return*/
		cout<<"head: "<<head<<", cost: "<<cost[head]<<endl;
		visited[head]=true;
		int temp_cost=MAX;bool flag=true;
		int ii=-1,jj=-1;
		map<int,int> temp_map;
		for(int i=0;i<adj[head].size();i++){
			if(temp_map[adj[head][i]]) continue;
			if( and_map[adj[head][i]] ){
			
				bool temp_solved=true;
				for( ii=0;ii<and_edges.size() ;ii++){
					for( jj=0;jj<and_edges[ii].size() ;jj++){
						if(and_edges[ii][jj]==adj[head][i]){
							flag=false;break;
						}
					}
					if(jj<and_edges[ii].size()){
						int cc=0;
						for(int k=0;k<and_edges[ii].size();k++){
							cc+=cost[and_edges[ii][k]]+EDGE;
							temp_map[and_edges[ii][k]]=1;
							temp_solved=temp_solved && isSolved[and_edges[ii][k] ];
						}
						temp_cost=min(temp_cost,cc);
						//cout<<"temp_cost: "<<temp_cost<<endl;
						break;
					}
				}
				if(temp_solved) isSolved[head]=true;
				//value of ii is the index of hyper edge containing adj[head][i]
			}else {
				temp_cost=min(temp_cost,cost[adj[head][i] ]+EDGE );
				temp_map[adj[head][i]]=true;
				if(isSolved[adj[head][i] ]) isSolved[head]=true;
			}
		}
		/*head is explored now update the best value of head i.e. temp_cost */
		if(temp_cost<=MAX)
			cost[head]=temp_cost;
		cout<<"updated head cost: "<<cost[head]<<endl;
	} else {
		/*finding best move*/
		bool isAnd=false;
		int bestCost=MAX,bestMove=-1,bestAndIndex=-1;
		map<int,int> temp_map1;
		for(int i=0;i<adj[head].size();i++){
			if(temp_map1[adj[head][i]]) continue;
			if(or_map[adj[head][i]]){
				if(bestCost>cost[adj[head][i] ]+EDGE){
					bestCost=cost[adj[head][i] ]+EDGE;
					bestMove=i;isAnd=false;
					temp_map1[adj[head][i]]=1;
					
					//cout<<"or_edge: "<<adj[head][i]<<", cost: "<<bestCost<<endl;
				}
			} else {
				int ii=0,jj=0;int c=0;
				for( ii=0;ii<and_edges.size();ii++){
					for( jj=0;jj<and_edges[ii].size();jj++){
						if(and_edges[ii][jj]==adj[head][i]) break;
					}
					if(jj<and_edges[ii].size()){
						for(int k=0;k<and_edges[ii].size();k++){
							c+=cost[and_edges[ii][k]]+EDGE;
							temp_map1[and_edges[ii][k]]=1;
						}
						cout<<"ii: "<<ii<<", jj: "<<jj<<endl;
						break;
					}
				}
				
				if(bestCost>c && c!=0){
					bestCost=c;bestAndIndex=ii;
					bestMove=i;isAnd=true;
				}
			}
			cout<<"moving forward, finding the best move,i: <<"<<adj[head][i]<<"\n";
			if(isAnd){
				cout<<"and edge, cost: "<<bestCost<<endl;
			}else cout<<"or edge, cost: "<<bestCost<<endl;
		}
		if(isAnd){
			for(int k=0;k<and_edges[bestAndIndex].size();k++){
				cout<<"isAnd: "<<isAnd<<endl;
				cout<<"and, aoStarUtil( "<<and_edges[bestAndIndex][k]<<")"<<endl;
				aoStarUtil(and_edges[bestAndIndex][k]);
			}
		}
		else{
			cout<<"isAnd: "<<isAnd<<endl;
			cout<<"or, aoStarUtil( "<<adj[head][bestMove]<<")"<<endl;
			aoStarUtil(adj[head][bestMove]);
		}
		/*check if any of the options were solved*/
		/*if there are multiple solved nodes , select the best out of them */
		/*also update the current cost i.e. head cost while backtracking to the root */
		int temp_cost=MAX;map<int,int> temp_map;
		for(int i=0;i<adj[head].size();i++){
			if(temp_map[adj[head][i]]) continue;
			if(or_map[adj[head][i] ] ){
				if(isSolved[adj[head][i] ]) isSolved[head]=true;
				temp_cost=min(temp_cost,cost[adj[head][i]]+EDGE);
				temp_map[adj[head][i]]=true;
			}
			else if(and_map[adj[head][i]]){
			
				int ii=0,jj=0;
				
				for(ii=0;ii<and_edges.size();ii++){
					for(jj=0;jj<and_edges[ii].size();jj++){
						if(and_edges[ii][jj]==adj[head][i]){
							break;
						}
					}
					if(jj<and_edges[ii].size()){
						int f=true;int cc=0;
						for(int k=0;k<and_edges[ii].size();k++){
							f=f&&(isSolved[and_edges[ii][k]]);
							cc+=cost[and_edges[ii][k]]+EDGE;
							temp_map[and_edges[ii][k]]=true;
						}
						temp_cost=min(temp_cost,cc);
						if(f) isSolved[head]=true;
						break;
					}
				}				
			}
		}
		if(temp_cost<=MAX)
			cost[head]=temp_cost;
		cout<<"updated cost["<<head<<"] : "<<cost[head]<<endl;
	}
}

void aoStar(int head){
	int iterations=0;
	//cout<<"head: "<<isSolved[head]<<endl;
	while(!isSolved[head] && iterations<MAX){
		aoStarUtil(head);
		iterations++;
	}
	cout<<"iterations: "<<iterations<<endl;
	for(int i=1;i<=21;i++){
		cout<<i<<": "<<cost[i]<<", ";
	}cout<<endl;
}

int main(){
	init();
	aoStar(1);
	
	return 0;
}