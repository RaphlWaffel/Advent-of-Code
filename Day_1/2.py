import re


def textToInt(text:str):
    number_map = {
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9
    }
    
    if text in number_map:
        return number_map[text]
    elif text == '':
        return 0
    elif text[0] >= '1' and text[0] <= '9':
        return int(text[0])
    else:
        return 0

# Use the regex to find the flag in the output
regex = re.compile("(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|([0-9])")
sums = 0
f = open("input.txt", "r")
for j in range(1000):
  text = f.readline()
  matches = regex.findall(text)
  first = 0
  second = 0
  for i in range(len(matches[0])):
      first = (10 * textToInt(matches[0][i]))
      if first != 0:
          break
  for i in range(len(matches[-1])):
      second = textToInt(matches[-1][i])
      if second != 0:
          break
  sums += (first + second)
  print(f'For {j} its {(first+second)}')
f.close()
print(sums)
