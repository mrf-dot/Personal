#!/usr/bin/env python3
def ispal(s:str) -> bool:
    return s == s[::-1]

print(ispal("AMANAPLANACANALPANAMA"))
print(ispal("racecar"))
print(ispal("not a palindrome"))
