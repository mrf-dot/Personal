for i in range(1, 101):
   print(f"{(i % 3 == 0) * 'Fizz'}{(i % 5 == 0) * 'Buzz'}" or i)
