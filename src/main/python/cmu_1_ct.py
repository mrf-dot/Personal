#!/usr/bin/env python3
from cmu_graphics import *
"""This program allows for the user to create a pattern of columns and rows of colors"""
def main():
    # Documents the program
    explain()
    # Get the direction of the color which will go on the bottom of the design
    direction = get_direction()
    # Gets the colors for the first direction
    colors = get_colors(direction)
    # Gets the width/height for the first direction
    thickness = get_thickness(direction)
    # Colors the first direction
    paint(thickness, colors, direction)
    # Changes the direction for the second part of the program
    direction = not direction
    colors = get_colors(direction)
    thickness = get_thickness(direction)
    # Colors the direction which has not been colored yet
    paint(thickness, colors, direction)


def paint(thickness, colors, direction):
    # Iterates until the entire canvas is colored
    for i in range(0, 400, thickness):
        # colors the rows
        if direction:
            Line(0, i, 400, i, lineWidth=thickness, opacity=50, fill=choice(colors))
        # colors the columns
        else:
            Line(i, 0, i, 400, lineWidth=thickness, opacity=50, fill=choice(colors))


def explain():
    # Documents the program to the client
    print("This program is designed to make displays of overlapping columns and rows.")
    print("You will enter the direction, colors, and desired weight of the columns and rows.")
    print("The program will then take those values and create a design with them.")


def get_direction():
    # Returns true if the user wishes to paint rows first, otherwise returns false
    rows_or_cols = app.getTextInput("Would you like to paint rows or columns first?")
    # Checks if the user entered a valid option, prompts the user to enter again if their option is invalid
    while True:
        if rows_or_cols == "rows":
            return True
        elif rows_or_cols == "columns":
            return False
        else:
            rows_or_cols = app.getTextInput("Please either type 'rows' or 'columns'")


def get_colors(direction):
    # Prompts the user to enter the colors they want
    colors = app.getTextInput(f"What colors would you like your {'rows' if direction else 'columns'} to be? (eg blue,green,orange)")
    # Splits the colors into a list which can be iterated through
    colorList = colors.split(",")
    return colorList


def get_thickness(direction):
    # Asks the user to input the width or height of their rows or columns
    thickness = app.getTextInput(f"How {'high' if direction else 'wide'} would you like your {'rows' if direction else 'columns'} to be?")
    # Converts the number inputted by the user into an integer and returns it
    return int(thickness)


if __name__ == "__main__":
    main()
cmu_graphics.loop()
