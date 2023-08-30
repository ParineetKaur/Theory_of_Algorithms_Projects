//Question: Given a rod of length 'n' units and a list of prices for different lengths of rods. The goal is to find the maximum revenue that can be obtained by cutting the rod into smaller pieces and selling them according to the given prices.
//I used Buttom-Up Programming approach, which involves solving a problem by solving its smaller subproblems first and then using their solutions to build up to the larger problem solution.

int cutRod(int cost[], int n){ 
  int price[n+1];
  price[0] = 0;
  if (n <= 0){
    return 0;
  }

  for (i = 0 to i++ for i < n){
    int MAX = MIN;
    for (j = 0 to j++ for j < i){
      MAX = MAX(MAX, cost[j] + cutRod(cost, i-j-1));
    }
    price[i] = MAX;
  }
  return price[n];
}

int main(){
  int cost[] = {5, 10, 15, 20, 25, 30, 35, 40}; 
  int n = sizeof(cost) / sizeof(cost[0]); //Calculate Lenght of array
  int answer = cutRod(cost, n); 
  cout << answer << endl; 
  return 0; 
}
