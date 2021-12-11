from cmu_graphics import Group, Line, Polygon, Rect, app, cmu_graphics, gradient, rgb
# index to keep track of the armor level
app.level = 0

def defineArmor():
    # armor colors
    leather = gradient('peru', 'saddleBrown')
    gold = gradient(rgb(255, 240, 0), rgb(235, 180, 20))
    iron = gradient('snow', 'silver')
    diamond = gradient('aqua', 'darkTurquoise')
    netherite = gradient('dimGrey', rgb(60, 60, 60))

    # store the armor colors
    app.helmetColors = [ None, leather, gold, iron, diamond, netherite ]
    app.chestplateColors = [ 'mediumTurquoise', leather, gold, iron, diamond,
                            netherite ]
    app.leggingsColors = [ 'darkSlateBlue', leather, gold, iron, diamond,
                           netherite ]
    app.borderColors = [ None, 'saddleBrown', rgb(235, 180, 20), 'silver',
                        'darkTurquoise', rgb(60, 60, 60) ]

defineArmor()

# background
app.background = 'lightCyan'
Rect(0, 300, 400, 100, fill='limeGreen')
Rect(310, 10, 80, 80, fill='lightGoldenrodYellow')
Rect(325, 25, 50, 50, fill='gold')
Rect(260, 130, 100, 150, fill='darkGrey',
     border=gradient('white', 'dimGrey', start='left-top'), borderWidth=4)

# upgrade and downgrade buttons
upgradeButton = Group(
    Rect(280, 180, 60, 5), Rect(285, 175, 50, 5),
    Rect(290, 170, 40, 5), Rect(295, 165, 30, 5),
    Rect(300, 160, 20, 5), Rect(305, 155, 10, 5)
    )
upgradeButton.fill = gradient('dimGray', rgb(75, 75, 75), start='left-top')

downgradeButton = Group(
    Rect(280, 225, 60, 5), Rect(285, 230, 50, 5),
    Rect(290, 235, 40, 5), Rect(295, 240, 30, 5),
    Rect(300, 245, 20, 5), Rect(305, 250, 10, 5)
    )
downgradeButton.fill = gradient('dimGray', rgb(75, 75, 75), start='left-top')


# steve's head
Rect(80, 50, 80, 80, fill='burlyWood')
Rect(105, 130, 30, 10, fill='burlyWood')
Rect(40, 170, 40, 80, fill='burlyWood')
Rect(160, 170, 40, 80, fill='burlyWood')
Polygon(80, 80, 80, 50, 160, 50, 160, 80, 150, 80, 150, 70,
        90, 70, 90, 80, fill=rgb(55, 20, 10))
Rect(90, 90, 10, 10, fill='white')
Rect(100, 90, 10, 10, fill='darkSlateBlue')
Rect(140, 90, 10, 10, fill='white')
Rect(130, 90, 10, 10, fill='darkSlateBlue')
Rect(110, 100, 20, 10, fill=rgb(150, 30, 20), opacity=30)
Polygon(100, 110, 100, 130, 140, 130, 140, 110,
        130, 110, 130, 120, 110, 120, 110, 110, fill=rgb(55, 20, 10))

# body
helmet = Polygon(75, 45, 165, 45, 165, 90, 150, 90, 150, 80, 130, 80,
                 130, 100, 110, 100, 110, 80, 90, 80, 90, 90, 75, 90,
                 fill=app.helmetColors[app.level],
                 border=app.borderColors[app.level], borderWidth=4)
chestplate = Polygon(40, 130, 105, 130, 105, 140, 135, 140, 135, 130,
                     200, 130, 200, 170, 160, 170, 160, 230, 80, 230,
                     80, 170, 40, 170, fill=app.chestplateColors[app.level],
                     border=app.borderColors[app.level], borderWidth=4)

leggings = Rect(80, 230, 80, 120, fill=app.leggingsColors[app.level],
                border=app.borderColors[app.level], borderWidth=4)

# detail lines
Line(120, 235, 120, 350, opacity=10)
Line(80, 130, 80, 170, opacity=10)
Line(160, 130, 160, 170, opacity=10)

def onMousePress(mouseX, mouseY):
    # If an arrow button is clicked, Steve should upgrade or downgrade his armor.
    # Downgrading from no armor should put Steve in netherite and upgrading from
    # netherite should put Steve with no armor.
    ### (HINT: Use the app level property to keep track of the list index.)
    ### Place Your Code Here ###
    if upgradeButton.contains(mouseX, mouseY):
        app.level += 1
    elif downgradeButton.contains(mouseX, mouseY):
        app.level -= 1
    if app.level < 0:
        app.level = 5
    elif app.level > 5:
        app.level = 0
    # Update the fill and border of the helmet, chestplate, and leggings
    # accordingly.
    ### (HINT: The defineArmor() function creates lists that store the fill
    #          for each of the pieces.)
    ### Place Your Code Here ###
    helmet.fill = app.helmetColors[app.level]
    helmet.border = app.borderColors[app.level]
    chestplate.fill = app.chestplateColors[app.level]
    chestplate.border = app.borderColors[app.level]
    leggings.fill = app.leggingsColors[app.level]
    leggings.border = app.borderColors[app.level]
cmu_graphics.loop()
