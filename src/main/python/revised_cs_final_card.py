from getpass import getuser
import os
from re import search
import secrets
from time import sleep
from prettytable import PrettyTable
from termcolor import cprint
from tqdm import tqdm
name = ""
format_cards = True
card_ranks = list(map(lambda card: str(card),
                      ["Ace", *range(2, 11), "Jack", "Queen", "King"]))
card_symbols = {
    "Spades": "♠",
    "Hearts": '♥',
    "Diamonds": '♦',
    "Clubs": "♣"
}
# Creates a list of cards
cards = []
for symbol in card_symbols:
    cards.append(list(map(lambda card: f"{card} of {symbol}", card_ranks)))
cards = sum(cards, [])


def cardify(card):
    """Formats an element as a playing card"""
    global format_cards
    if format_cards:
        cardname = search(r"\w+", card).group()
        match cardname:
            case "10":
                space = " " * 5
            case "Ace":
                cardname = "A"
                space = " " * 6
            case "Jack":
                cardname = "\N{guardsman}"
                space = " " * 5
            case "Queen":
                cardname = "\N{princess}"
                space = " " * 5
            case "King":
                cardname = "\N{prince}"
                space = " " * 5
            case _:
                space = " " * 6
        suite = card_symbols[search(r"\w+$", card).group()]
        color = "red" if "Hearts" in card or "Diamonds" in card else "grey"
        print()
        cprint(f"{cardname}{space}", color, "on_white")
        cprint(" " * 7, color, 'on_white')
        cprint(f"{' ' * 3}{suite}{' ' * 3}", color, 'on_white')
        cprint(" " * 7, color, 'on_white')
        cprint(f"{space}{cardname}", color, 'on_white')
        print()
    else:
        print(card)


def roll(entity: str) -> int:
    """Rolls two dice, returning the sum of the rolls"""
    one = 1 + secrets.randbelow(6)
    two = 1 + secrets.randbelow(6)
    for i in tqdm(range(2), desc=f'{entity} Rolling', ascii=False, ncols=100):
        sleep(0.5)
    print(f'''Dice 1: {one}
Dice 2: {two}''')
    return one + two


def prep_dice(sum: int, player="") -> int:
    print(f'How much money would you like {player} to start with?')
    try:
        player_sum = int(input('$'))
    except:
        return sum
    return sum if player_sum < 1 else player_sum


def valid_bet(player_sum):
    while True:
        bet = input("Your bet: $").lower().strip()
        if bet == "all":
            return player_sum
        elif bet == "quit":
            return -1
        elif bet.isdigit():
            bet = int(bet)
            if player_sum >= bet:
                return bet
        cprint("Enter a valid bet.", "red")


def main_game(player: str, player_sum: int, bot_sum: int):
    turns = 0
    balance = PrettyTable(['Player', 'Balance'])
    while player_sum > 0 and bot_sum > 0:
        balance.add_rows([[player, f'${player_sum}'], ['CPU', f'${bot_sum}']])
        print(balance)
        balance.clear_rows()
        bet = valid_bet(player_sum)
        if bet == -1:
            return -1
        elif bot_sum < bet:
            pot = bot_sum + bet
            bot_sum = 0
        else:
            pot = bet * 2
            bot_sum -= bet
        player_sum -= bet
        print(f"Pot is ${pot:,}")
        input('Press enter to roll')
        player_score = roll('You are')
        sleep(1)
        bot_score = roll('CPU is')
        if player_score > bot_score:
            player_sum += pot
        elif player_score < bot_score:
            bot_sum += pot
        else:
            pot //= 2
            bot_sum += pot
            player_sum += pot
        pot = 0
        turns += 1
    return [bot_sum, player_sum, turns]


def recap(info_list: list):
    bot_sum, player_sum, turns = info_list
    if bot_sum == 0:
        print(f'''You won in {turns} turns.
Your remaining balance was ${player_sum:,}.''')
    else:
        print(f'''The CPU won in {turns} turns
The CPU\'s remaining balance was ${bot_sum:,}.''')


# Used to implement switcher for user functions
instructions = {
    'help': 'Print the program instructions',
    'clear': 'Clear program output',
    'format': 'Toggles the formatting of the cards',
    'fetch': 'Fetch a card from an ordered deck',
    'random': 'Print a random card',
    'order': 'Print an ordered deck',
    'shuffle': 'Print a shuffled deck',
    'dice': 'Play a game of dice',
    'exit': 'Quit the program'
}


def help():
    commands = PrettyTable()
    commands.field_names = ['Command', 'Description']
    for x, y in instructions.items():
        commands.add_row([x, y])
    print(commands)


def format():
    global format_cards
    """Toggles formatting"""
    format_cards = not format_cards
    print(f"formatting is {'on' if format_cards else 'off'}.")


def clear():
    os.system("cls" if os.name == "nt" else "clear")


def fetch():
    """Returns a card based on it's position in an ordered deck (1-52)"""
    fetch_num = int(input('Select a position in the deck (1-52): '))
    if 53 > fetch_num > 1:
        cardify(cards[fetch_num - 1])
    else:
        cprint('Enter a number between one and 52', 'red')


def random():
    """Returns a cryptographically random element in a list"""
    cardify(secrets.choice(cards))


def order():
    """Prints out every element in a list"""
    for x in cards:
        cardify(x)


def shuffle():
    """Prints out every element in a list in a random order
    """
    shuf_cards = []
    while len(shuf_cards) != len(cards):
        local = secrets.choice(cards)
        if local not in shuf_cards:
            shuf_cards.append(local)
    for x in shuf_cards:
        cardify(x)


def dice():
    """Plays a game of dice with an automatic system
    """
    global name
    preperation_round = PrettyTable(['Preperation Round'])
    preperation_round.add_rows([
        ['In the preparation round, you will determine how much each player will get.'],
        ['You must enter a valid integer or else you will be given the default value.'],
    ])
    print(preperation_round)
    default_values = PrettyTable(['Player', 'Default value'])
    default_values.add_rows([[name, '$1000'], ['CPU', '$1250']])
    print(default_values)
    player_sum = prep_dice(1000, 'yourself')
    bot_sum = prep_dice(1250, 'the CPU')
    main_round = PrettyTable(['Main Round'])
    main_round.add_rows([
        ['Now that you have completed the preparation round, we can get into the main game.'],
        ['At the beginning of each round, you will have a bet. The CPU will match your bet.'],
        ['If your bet is higher than the CPU\'s funds, the CPU will bet all its remaining funds.'],
        ['If you wish to bet all of your funds, input "all".'],
        ['If you wish to quit, input "quit".'],
        ['Both you and the CPU will roll two dice.'],
        ['Your score is equivalent to the sum of the dice.'],
        ['Whoever achieves the highest score will take the entire pot.'],
        ['If there is a tie, the pot will be split equally.'],
    ])
    print(main_round)
    results = main_game(name, player_sum, bot_sum)
    if results != -1:
        recap(results)


def exit():
    """Raises a system exit and greets the user."""
    clear()
    raise SystemExit("Thank you for playing!")


def changeName():
    global name
    clear()
    changeName = input('What would you like me to call you?: ')
    name = changeName if changeName else getuser()
    clear()


def main():
    """Initiates the program"""
    changeName()
    help()
    while True:
        selection = input('Select an option: ').lower()
        if selection in instructions:
            eval(f"{selection}()")
        else:
            cprint(f"'{selection}' is not a valid command.", "red")


if __name__ == '__main__':
    main()
