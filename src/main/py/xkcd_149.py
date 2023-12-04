from os import name, system
from os import system

if name == "nt":
    _ = system("cls")
else:
    _ = system("clear")
while True:
    user_input = input("149@xkcd:~$ ")
    match (user_input):
        case "make me a sandwich":
            print("Go make it yourself.")
        case "sudo make me a sandwich":
            print("ok.")
        case "exit":
            raise SystemExit
        case _:
            system(user_input)
