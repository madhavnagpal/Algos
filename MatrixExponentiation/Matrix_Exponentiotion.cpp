// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();
int mod = 1000000000;

int k,n;
vector<int> firstKTerms,coeff;

vector<vector<int> > matMultiply(vector<vector<int> > a,vector<vector<int> > b){
  // got two k*k matrices return a*b
  vector<vector<int> > c(k+1,vector<int>(k+1));

  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      c[i][j]=0;

      for(int x=1;x<=k;x++){
        c[i][j] = (c[i][j]%mod + (a[i][x]*b[x][j])%mod)%mod;
      }
    }
  }
  return c;
}

vector<vector<int> > findPowerOfMat(vector<vector<int> > m,int p){
  if(p==1)
    return m;
  
  vector<vector<int> > subProduct = findPowerOfMat(m,p/2);
  vector<vector<int> > subSq = matMultiply(subProduct,subProduct);

  if(p&1){
    return matMultiply(m,subSq); 
  }
  return subSq;
}

int findNThTermMatrixExponentiation(){
  
  // step1 get f1 vector
  
  vector<int> f1(k+1);

  for(int i=1;i<=k;i++)
    f1[i]=firstKTerms[i-1];

  // build transformation matrix
  vector<vector<int> > trans(k+1,vector<int>(k+1));

  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){

      // i<k means all rows before coefficients row
      if(i<k){
        if(i+1==j)
          trans[i][j]=1;
        else
          trans[i][j]=0;
      }else{
          trans[i][j] = coeff[k-j];
      }
    }
  }
  // find exponention power of transformation matrix
  vector<vector<int> > powOfTrans = findPowerOfMat(trans,n-1);

  // got t^n-1 extract first elemet of t^n-1 * f1

  int nthTerm =0;

  for(int i=1;i<=k;i++){
    nthTerm = (nthTerm%mod + (powOfTrans[1][i]*f1[i])%mod)%mod;
  }
  return nthTerm%mod;
}

int32_t main()
{
  letsStart();
  
  int test,num;
  cin>>test;

  while(test--){
    cin>>k;

    firstKTerms.clear();
    coeff.clear();
    firstKTerms.reserve(k);
    coeff.reserve(k);

    for(int i=0;i<k;i++){
      cin>>num;
      firstKTerms.push_back(num);
    }
    for(int i=0;i<k;i++){
      cin>>num;
      coeff.push_back(num);
    }
    cin>>n;
    cout<<"n th term is: "<<findNThTermMatrixExponentiation()<<endl;
  }
  return 0;
}

void letsStart()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
  #endif
}

