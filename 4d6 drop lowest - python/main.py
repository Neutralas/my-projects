import numpy as np
import random

# What is 4d6 drop lowest?
#  It is one of the traditional ways to generate six character’s ability scores in Dungeons & Dragons 5e
#
# How do you roll?
#  1. Roll 4 six-sided dice and remove the lowest dice result
#  2. Add up the remaining numbers to get an ability score
#  3. Repeat until you have 6 ability scores
#
# What does this program do?
#  It calculates what is an average ability score statistically,
#  and then simulates randomly rolling dice to check how close it gets to that.
#  Lastly, it prints out two sets of 6 randomly generated ability scores, generated using two different methods

# math approach to 4d6 drop lowest:
math_array = np.zeros((6, 6, 6, 6))
for a in range(1, 7):
    for b in range(1, 7):
        for c in range(1, 7):
            for d in range(1, 7):
                suma = (a + b + c + d) - min(a, b, c, d)
                math_array[a-1][b-1][c-1][d-1] = suma

math_result = np.sum(math_array) / (6 * 6 * 6 * 6)
print(f"math approach: {math_result}")

# random dice rolling approach to 4d6 drop lowest:
a = np.random.randint(1, 7, (6, 6, 6, 6), dtype=int)
b = np.random.randint(1, 7, (6, 6, 6, 6), dtype=int)
c = np.random.randint(1, 7, (6, 6, 6, 6), dtype=int)
d = np.random.randint(1, 7, (6, 6, 6, 6), dtype=int)

dice_array = a + b + c + d - np.min(np.array((a, b, c, d)), axis=0)

rand_result = np.sum(dice_array) / (6 * 6 * 6 * 6)
print(f"random dice rolling: {rand_result}")
print(f"difference: {np.abs(rand_result / math_result - 1) * 100}%\n")


# And for variety and flamboyance, same calculation but in one line:
math_array_2 = np.sum([ (a+b+c+d) - min(a,b,c,d) for a in range(1, 7) for b in range(1, 7) for c in range(1, 7) for d in range(1, 7) ]) / (6*6*6*6)
print(f"does one line math approach give the same result as the long approach? {math_array_2 == math_result}\n")


# Full list of your 6 ability scores:
ability_scores = np.random.choice(dice_array.flatten(), 6)
print(f"6 ability scores {sorted(ability_scores)} using np.random.choice, with average of {np.average(ability_scores)}")

# Full list of your 6 ability scores using a dictionary and weighted choices:
ability_scores_dict = {k:np.count_nonzero(dice_array == k) for k in np.arange(3,19)} # Counts how many times an ability score is rolled and stores it in a dictionary
ability_scores_2 = random.choices(list(ability_scores_dict.keys()), weights=ability_scores_dict.values(), k=6)
print(f"6 ability scores {sorted(ability_scores_2)} using random.choice and weights, with average of {np.average(ability_scores_2)}")