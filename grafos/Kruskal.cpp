const int MAX = 2e5+7;

int n,m;
vector<pair<ll,ii>> edges;
vector<int> link(MAX);
vector<int> size(MAX);

void init_uf(){
	for (int i = 0; i <= m; i++) link[i] = i;
 	for (int i = 0; i <= m; i++) size[i] = 1;
}

int find(int x) {
	while (x != link[x]){
		link[x] = link[link[x]];
        x = link[x];
	}
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] < size[b]) 
		swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

ll kruskal() {
	//edges: lista de aristas en la forma {peso, {nodo1, nodo2}}
	sort(all(edges)); // ordena por peso
	init_uf();
	
	int u = 0; 
	ll res = 0;
	for(auto p: edges){
		int x = p.second.first, y = p.second.second;
		ll c = p.first;
		x = find(x); y = find(y);
		if(x == y) continue; // los nodos ya estan conectados
		res += c;
		u++;
		unite(x,y);
		if(u == n - 1) // completamos el arbol?
			return res;
	}
	return -1; // si llegamos hasta aca entonces no es conexo
}
