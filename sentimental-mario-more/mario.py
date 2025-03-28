from cs50 import get_int
while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break



for row in range(height):
   # Space 1:
   for i in range(height - row - 1):
       print(" ", end="")

   # Left:
   for j in range(row + 1):
       print("#", end="")

   # Space 2:
   print("  ", end="")

   # Right:
   for j in range(row + 1):
       print("#", end="")

   print()