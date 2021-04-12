# def sumOf(arr):
# 	sum = 0
# 	for i in arr:
# 		sum += i
# 	return sum

# all_time_min = 100000
# def coinChange(coins, amount, subset, prev_num_items):
# 	if sumOf(subset) == amount and len(subset) < prev_num_items:
# 		return len(subset)
# 	elif sumOf(subset) > amount:
# 		return
# 	else:
# 		for i in coins:
# 			subset.append(i)
# 			previous_change = coinChange(coins, amount, subset, previous_num_items)
# 			current_change = coinChange(coins, amount, subset, previous_change)
# 			if current_change < all_time_min:
# 				all_time_min = current_change
# 			subset.remove(i)
# 		return all_time_min

# 	if all_time_min == 100000:
# 		return -1


# A dynamic programming bottom-up approach 
def coinChange(coins, amount):
	dp = [amount+1] * (amount+1)
	dp[0] = 0
	for i in range(amount+1):
		for coin in coins:
			if coin <= i:
				dp[i] = min(dp[i], 1 + dp[i-coin])
	if dp[amount] > amount:
		return -1
	return dp[amount]


coins = [1,4,7]
amount = 8
print(coinChange(coins, amount))