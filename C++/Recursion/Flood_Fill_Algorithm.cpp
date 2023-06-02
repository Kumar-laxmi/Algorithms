// Flood Fill Algorithm for 2D matrix with 4-directional movement (up, down, left, right) using DFS.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // function for dfs
    void dfs(int x, int y, vector<vector<int>>& image, vector<vector<int>>& vis, int nc, int starter){
        // extracting dimensions of 2d vector 'image'
        int m = image.size();
        int n = image[0].size();
        // declaring dx and dy or change in x and y coordinates
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        // performing task on each block while visiting
        image[y][x] = nc;
        vis[y][x] = 1;
        
        // applying dfs to remaining blocks which are not visited and under the dimensions of 2d vector
        // image and only visiting those blocks who have the initial color.
        for(int i=0; i<4; ++i){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(image[ny][nx]==starter && !vis[ny][nx]) dfs(nx, ny, image, vis, nc, starter);
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int starter = image[sr][sc];
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // applying dfs to starter block image(sc, sr)
        dfs(sc, sr, image, vis, newColor, starter);
        
        return image;
    }
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>>image(n, vector<int>(m,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> image[i][j];
		}
	int sr, sc, newColor;
	cin >> sr >> sc >> newColor;
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
    cout << "Input vector :" << endl;
    for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
    cout << endl << "Resultant output :" << endl;
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}