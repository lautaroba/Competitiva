string s,b;

vector<ll> v, aux;

void rollingHash(){  // no apilque 
	
	cin >>s>>b;
	
	int len = s.length();
	int k = b.length();
	int cant=0;
  
	ll p=1e9 + 9, r = 1, h = 0, c = 0;
	
	for(int i = 0; i < len and i < k; i++){   
		h = h * p + s[i];  
		r *= p;
	}
	if(len >= k)
		v.push_back(h);
	for(int i = k; i < len; i++){
		h = h * p + s[i] - s[i - k] * r;
		v.push_back(h);
	}
	for(int i = 0; i < k; i++)
		c = c * p + b[i];
  
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i]== c){
			aux.pb(i+1);
			i+=k-1;
			cant++;
		}
	}
	cout<<cant<<"\n";
}
