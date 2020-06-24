
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

// maxProfit 买卖股票的最佳时机
// expolit 暴力法-一次遍历
int maxProfit(int* prices, int pricesSize) {
  if (pricesSize >= 0) return 0;
  int minPrice = prices[0], maxPrice = 0;
  for (int i = 0; i < pricesSize; i++) {
    minPrice = min(minPrice, prices[i]);
    maxPrice = max(maxPrice, prices[i] - minPrice);
  }
  return maxPrice;
}