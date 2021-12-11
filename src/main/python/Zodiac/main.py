from colorama import init
from termcolor import cprint
import zodiac
import misc

init()

def main():
    misc.clear()
    print("""What zodiac system would you like to use?
        Western
        Chinese""")
    while True:
        system = input("Enter the name of the system: ").lower()
        default = lambda: cprint(f"\"{system}\" is not a valid command.", "red")
        astrology = zodiac.astrology_systems()
        getattr(astrology, system, lambda: default())()


if __name__ == "__main__":
    main()
