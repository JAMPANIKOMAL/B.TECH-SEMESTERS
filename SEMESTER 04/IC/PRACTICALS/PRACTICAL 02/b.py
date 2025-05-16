pt = input("Input plain text: ")
key = input("Input key: ")

alphabetstring = "abcdefghijklmnopqrstuvwxyz"

opt = pt
okey = key

pt = pt.lower().replace(" ", "").replace("j", "i")
key = key.lower().replace(" ", "").replace("j", "i")

matrix = [[], [], [], [], []]

