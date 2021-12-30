from prettytable import PrettyTable
from termcolor import cprint

import misc
import zodiac


def table_dict(head1, head2, cases: dict):
    """Formats a dictionary as a table

    """
    table = PrettyTable()
    table.field_names = [head1, head2]
    for x in cases:
        table.add_row([x, cases[x][0]])
    print(table)


def main():
    misc.clear()
    print("""What zodiac system would you like to use?
        Western
        Chinese""")
    while True:
        system = input("Enter the name of the system: ").lower()

        def default(): return cprint(
            f"\"{system}\" is not a valid command.", "red")
        astrology = zodiac.astrology_systems()
        getattr(astrology, system, lambda: default())()


if __name__ == "__main__":
    main()
