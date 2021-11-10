N = int(input())

def get_rhyme(word):
  vowels = {'a', 'e', 'i', 'o', 'u'}
  l = len(word)
  for i in range(l-1, -1, -1):  #starting from the end, go backwards
    if word[i] in vowels:
      break
  else:
    i = 0 #whole word
  return word[i:]

for _ in range(N):
  rhymes = []
  for _ in range(4):
    words = input().split()
    end = words[-1].lower()
    rhymes.append(get_rhyme(end))

  if rhymes[0] == rhymes[1] == rhymes[2] == rhymes[3]:
    print("perfect")
  elif rhymes[0] == rhymes[1] and rhymes[2] == rhymes[3]:
    print("even")
  elif rhymes[0] == rhymes[2] and rhymes[1] == rhymes[3]:
    print("cross")
  elif rhymes[0] == rhymes[3] and rhymes[1] == rhymes[2]:
    print("shell")
  else:
    print("free")
  