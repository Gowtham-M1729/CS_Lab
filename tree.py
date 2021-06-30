# Python program to draw a tree using turtle 
# Importing required modules 
import turtle 
import math 


# Function to draw rectangle 
def drawRectangle(t, width, height, color): 
	t.fillcolor(color) 
	t.begin_fill() 
	t.forward(width) 
	t.left(90) 
	t.forward(height) 
	t.left(90) 
	t.forward(width) 
	t.left(90) 
	t.forward(height) 
	t.left(90) 
	t.end_fill() 

	
# Function to draw triangle	 
def drawTriangle(t, length, color): 
	t.fillcolor(color) 
	t.begin_fill() 
	t.forward(length) 
	t.left(135) 
	t.forward(length / math.sqrt(2)) 
	t.left(90) 
	t.forward(length / math.sqrt(2)) 
	t.left(135) 
	t.end_fill() 

	
# Set the background color 
screen = turtle.Screen ( ) 
screen.bgcolor("skyblue") 


# Creating turtle object 
tip = turtle.Turtle() 
tip.color ("black") 
tip.shape ("turtle") 
tip.speed (2) 


# Tree base 
tip.penup() 
tip.goto(100, -130) 
tip.pendown() 
drawRectangle(tip, 20, 40, "brown") 


# Tree top 
tip.penup() 
tip.goto(65, -90) 
tip.pendown() 
drawTriangle(tip, 90, "green") 
tip.penup() 
tip.goto(70, -45) 
tip.pendown() 
drawTriangle(tip, 80, "white") 
tip.penup() 
tip.goto(75, -5) 
tip.pendown() 
drawTriangle(tip, 70, "orange")
from turtle import *


speed('fastest') 

# turning the turtle to face upwards 
rt(-90) 

# the acute angle between 
# the base and branch of the Y 
angle = 30

# function to plot a Y 
def y(sz, level): 

	if level > 0: 
		colormode(255) 
		
		# splitting the rgb range for green 
		# into equal intervals for each level 
		# setting the colour according 
		# to the current level 
		pencolor(0, 255//level, 0) 
		
		# drawing the base 
		fd(sz) 

		rt(angle) 

		# recursive call for 
		# the right subtree 
		y(0.8 * sz, level-1) 
		
		pencolor(0, 255//level, 0) 
		
		lt( 2 * angle ) 

		# recursive call for 
		# the left subtree 
		y(0.8 * sz, level-1) 
		
		pencolor(0, 200//level, 0) 
		
		rt(angle) 
		fd(-sz) 
		
		
# tree of size 80 and level 7 
y(80, 7) 


