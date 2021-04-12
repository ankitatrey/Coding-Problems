import sys

def number_needed(a, b):
    total=0
    for letter in "abcdefghijklmnopqrstuvwxyz":
        total+=abs(a.count(letter)-b.count(letter))
    return total

a = input().strip()
b = input().strip()
print(number_needed(a, b))