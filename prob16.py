#https://www.hackerrank.com/challenges/game-of-thrones
input_str = input().strip()
result_flag = True

if len(input_str)%2 != 0:
	odd_flag = False
	visited_set = set()
	for i in input_str:
		if i in visited_set:
			continue
		else:
			visited_set.add(i)
			if input_str.count(i)%2 != 0: 
				if odd_flag == False:
					odd_flag = True
				else:
					result_flag = False
else:
	visited_set = set()
	for i in input_str:
		if i in visited_set:
			continue
		else:
			visited_set.add(i)
			if input_str.count(i)%2 != 0: 
				result_flag = False
if result_flag:
	print("YES")
else:
	print("NO")

