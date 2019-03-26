#include <iostream>
#include <vector>
using namespace std;
int triple_step(int n){
  vector<int>dp(n+1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for(int i = 4; i <= n; i++){
    dp[i] = dp[i-1]*dp[1] + dp[i-2]+ dp[i-3];
  }
  return dp[n];
}

int main(){
  int n;
  cin>>n;
  cout<<"cin "<<n<<" sol: "<<triple_step(n)<<endl;
  }
/*#include <vector>
#include <iostream>

using namespace std;

int countWays(int n , vector<int> v){

  if (n==0){
    return 1;
  }

  int sum = 0;

  for (int i = 0; i < v.size(); ++i)
    {
      if(n>=v[i]){
	sum = sum + countWays((n-v[i]),v);
      }
    }
  return sum;
}

int main(int argc, char const *argv[])
{

  vector<int> v;// vector to store possible step sizes
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  int noOfWays = countWays(6,v);
  cout<<noOfWays<<endl;// Total number of stairs = 6

  return 0;
}
*/
