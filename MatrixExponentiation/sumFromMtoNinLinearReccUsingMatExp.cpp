// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();

int k,mod;
vector<int> firstkTerms,coeff;

vector<vector<int>> matMultiply(vector<vector<int> > a,vector<vector<int> > b){

  vector<vector<int>> c(k+1,vector<int>(k+1));

  for(int i=0;i<=k;i++){
    for(int j=0;j<=k;j++){
      c[i][j]=0;
      for(int x=0;x<=k;x++){
        c[i][j] += a[i][x] * b[x][j];
        c[i][j] %= mod;
      }
    }
  }

  return c;
}

vector<vector<int>> powMat(vector<vector<int> > m,int p){

  if(p==1)
    return m;
  vector<vector<int> > subProduct = powMat(m,p/2);
  vector<vector<int> > subProductSquare = matMultiply(subProduct,subProduct);

  if(p&1)
    return matMultiply(m,subProductSquare);
  return subProductSquare;

}

int findSum(int n){
  
  int sum=0;

  if(n<=k){
    for(int i=0;i<n;i++){
      sum += firstkTerms[i];
      sum %= mod;
    }
    return sum;
  
  }
  //step1 get f1 vector

  vector<int> f1(k+1);
  sum=0;

  for(int i=1;i<=k;i++){
    f1[i]=firstkTerms[i-1];
    sum += firstkTerms[i-1];
    sum %= mod;
  }
  f1[0]=sum;

  // step 2 form transformation matrix

  vector<vector<int> > trans(k+1,vector<int>(k+1));

  for(int j=1;j<=k;j++){
    trans[k][j]=coeff[k-j];
    trans[0][j]=coeff[k-j];
  }
  trans[0][0]=1;
  trans[k][0]=0;

  for(int i=1;i<k;i++){
    for(int j=0;j<=k;j++){
      if(i+1==j)
        trans[i][j]=1;
      else
        trans[i][j]=0;
    }
  }

  //step 3 trans^n-1

  vector<vector<int> > powOfTrans = powMat(trans,n-k);

  // get first element of powOfTrans*f1
  sum = 0;
  for(int j=0;j<=k;j++){
    sum += powOfTrans[0][j] * f1[j];
    sum %= mod;
  }
  return sum;
}

int32_t main()
{
  letsStart();
  int test,m,n,num;
  cin>>test;

  while(test--){
    cin>>k;
    
    firstkTerms.clear();
    firstkTerms.reserve(k);
    coeff.clear();
    coeff.reserve(k);

    for(int i=0;i<k;i++){
      cin>>num;
      firstkTerms.push_back(num);
    }

    for(int i=0;i<k;i++){
      cin>>num;
      coeff.push_back(num);
    }

    cin>>m>>n>>mod;

    int lower = findSum(m-1);
    int upper = findSum(n);
    int ans=(upper-lower)%mod;
   
    if(ans<0)
      ans+=mod;

    cout<<ans<<endl;
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
