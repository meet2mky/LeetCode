class Solution {
    private static int N;
    private static int[][] dp;
    static{
      N = 500;
      dp = new int[N+1][N+1];
      for(int cards = 0; cards <= N; cards++){
        for(int space = 0; space <= N; space++){
          if(cards == 0){
            dp[cards][space] = 1;
          }else{
            for(int useSpace = 1, useCards = 2; useSpace <= space && useCards <= cards; useSpace++, useCards += 3){
              dp[cards][space] += dp[cards-useCards][useSpace-1];
            }
          }
        }
      }
    }
    public int houseOfCards(int n) {
        return dp[n][n];
    }
}