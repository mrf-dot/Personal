#!/bin/env python3

def permute(s, lo=0):
    if (lo == len(s)):
        print("".join(s))
    else:
        s = [*s]
        for i in range(lo, len(s)):
            s[lo], s[i] = s[i], s[lo]
            permute(s, lo+1)
            s[lo], s[i] = s[i], s[lo]

def main():
    permute("extra stuff")


if __name__ == "__main__":
    main()
