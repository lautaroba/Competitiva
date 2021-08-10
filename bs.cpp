
// value, valor a encontrar, a es el vector en cuestion
int bsearch(vector<int> & a, int value){
int lo = 0;
int hi = a.size();
while(lo + 1 < hi){
  int mid=(lo+hi)/2;
  if(value < A[mid])
    hi = mid;
  else
    lo = mid;
}
//if a[lo] is value
if(a[lo] == value)
  return lo;
else
  return -1;
}
