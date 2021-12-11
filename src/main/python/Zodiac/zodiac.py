import misc

class zodiac_keys:
    western = {
        1: ["January 20 - February 16", "Capricorn"],
        2: ["February 16 - March 11", "Aquarius"],
        3: ["March 11 - April 18", "Pisces"],
        4: ["April 18 - May 13", "Aries"],
        5: ["May 13 - June 21", "Taurus"],
        6: ["June 21- July 20", "Gemini"],
        7: ["July 20 - August 10", "Cancer"],
        8: ["August 10 - September 16", "Leo"],
        9: ["September 16 - October 30", "Virgo"],
        10: ["October 30 - November 23", "Libra"],
        11: ["November 23 - 29", "Scorpio"],
        12: ["November 29 - December 17", "Ophiuchus"],
        13: ["December 17 - January 20", "Sagittarius"]
    }
    chinese = {
        4: "Rat",
        5: "Ox",
        6: "Tiger",
        7: "Rabbit",
        8: "Dragon",
        9: "Snake",
        10: "Horse",
        11: "Goat",
        12: "Monkey",
        1: "Rooster",
        2: "Dog",
        3: "Pig"
    }


class astrology_systems:
    """Calculates astrological symbols based off preferred system

    """
    def western(self):
        misc.table_dict("Input", "When you were born",zodiac_keys.western)
        selection = misc.to_int("When were you born (Input)?: ", *range(1,14))
        print(f"Your astrological sign is {zodiac_keys.western[selection][1]}.")


    def chinese(self):
        birth_year = misc.to_int("What year were you born?: ") % 12
        print(f"Your astrological sign is {zodiac_keys.chinese[birth_year]}.")




