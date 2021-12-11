import os
from prettytable import PrettyTable

clear = lambda: os.system("cls" if os.name == "nt" else "clear")

def to_int(message: str, *valids) -> int:
    """Turns input into a valid integer

    """
    while True:
        answer = input(message)
        try: answer = int(answer) 
        except: continue
        if valids and answer not in valids: continue
        else: return answer

            
def table_dict(head1, head2, cases: dict):
    """Formats a dictionary as a table

    """
    table = PrettyTable()
    table.field_names = [head1, head2]
    for x in cases: table.add_row([x, cases[x][0]])
    print(table)