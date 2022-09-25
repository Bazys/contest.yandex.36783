def get_number_of_good_pairs(numbers: list) -> int:
  m = [0]*200
  for i in numbers:
    m[i%200] += 1
  return sum(x*(x-1)//2 for x in m)


n = int(input())
numbers = list(map(int, input().split()))
print(get_number_of_good_pairs(numbers))
