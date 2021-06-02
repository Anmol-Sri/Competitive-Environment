auto bfs = [&](pair < int, int > p){ // dijkstra_shortest path on 2d array.
        vector < vector < int > > d(n, vector < int > (m, INF));
        d[p.first][p.second] = 0;
        queue < pair < int, int > > q; q.emplace(p);
        while(!q.empty()){ 
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int x1 = x + dx[i], y1 = y + dy[i];
                if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue; // validity check condition 
                if(a[x1][y1] == -1) continue; / condition specific to question. (here movement not possible)
                if(d[x1][y1] <= d[x][y] + 1) continue; // condition specific to question (here movement not possible).
                d[x1][y1] = d[x][y] + 1;
                q.emplace(x1, y1);
            }
        }
        return d;
    };