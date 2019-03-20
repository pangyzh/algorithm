#include <stdio.h>  
#include <iostream>  
#include <string>  
#include <string.h>  
#include <queue>  
using namespace std;      
  
char G[25][25];  
 
short vis[21][21][21][21]; 
struct step {  
    int pi, pj, hi, hj, num;  
    step() {}  
    step(int i, int j, int ii, int jj, int n) {  
        pi = i;  
        pj = j;  
        hi = ii;  
        hj = jj;  
        num = n;  
    }  
};  
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
int hdir[4][2];  
step firstStep; 

 bool isValid(step & s) {  
    return G[s.pi][s.pj] != '#' && G[s.pi][s.pj] != '!' && G[s.hi][s.hj] != '!';  
}  


bool meet(step & now, step & next) {  
    return (next.pi == next.hi && next.pj == next.hj) || (now.pi == next.hi && now.pj == next.hj && now.hi == next.pi && now.hj == next.pj);  
}  


  
void BFS() {  
    queue<step> q;  
    firstStep.num = 0;  
    q.push(firstStep);  
    vis[firstStep.pi][firstStep.pj][firstStep.hi][firstStep.hj] = 1;  
  
    while (!q.empty()) {  
        step Cur = q.front();  
        q.pop();  
  
        if (Cur.num > 255) break;  
  
        for (int i = 0; i < 4; i++) {  
            step next;  
            next.pi = Cur.pi + dir[i][0];  
            next.pj = Cur.pj + dir[i][1];  
            next.hi = Cur.hi + hdir[i][0];  
            next.hj = Cur.hj + hdir[i][1];  
            next.num = Cur.num + 1;  
            if (isValid(next)) {  
                if (G[next.hi][next.hj] == '#') {  
                    next.hi = Cur.hi;  
                    next.hj = Cur.hj;  
                }  
                if (!vis[next.pi][next.pj][next.hi][next.hj]) {  
                    vis[next.pi][next.pj][next.hi][next.hj] = true;  
                    if (meet(Cur, next)) {  
                        cout << next.num << endl;  
                        return;  
                    }  
                    q.push(next);  
                }  
            }  
        }  
    }  
  
    cout << "Impossible" << endl;  
  
}  
int main() {  
  
  	int H, W; 
    while (cin >> H >> W) {  
  
        memset(vis, 0, sizeof(vis));  
        for (int i = 0; i < H; i++) cin >> G[i];  
  
        string nsew;  
        cin >> nsew;  
        for (int i = 0; i < 4; i++) {  
            if (nsew[i] == 'N') hdir[i][0] = -1, hdir[i][1] = 0;  
            if (nsew[i] == 'S') hdir[i][0] = 1, hdir[i][1] = 0;  
            if (nsew[i] == 'E') hdir[i][0] = 0, hdir[i][1] = 1;  
            if (nsew[i] == 'W') hdir[i][0] = 0, hdir[i][1] = -1;  
        }  
  
        for (int i = 0; i < H; i++)   
            for (int j = 0; j < W; j++)   
                {
				if (G[i][j] == 'H') firstStep.hi = i, firstStep.hj = j;  
                else if (G[i][j] == 'P') firstStep.pi = i, firstStep.pj = j;  
                int gui=i+1;
                gui+=j;
				}
        BFS();  
  
    }    
    return 0;  
}      
