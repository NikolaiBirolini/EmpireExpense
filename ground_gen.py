import random
from math import nan, isnan
from sys import argv
import numpy as np

maxalt = 1200
 
bioms =     [[random.randint(int(0.8*maxalt), maxalt) for i in range (6)],
            [random.randint(int(0.7*maxalt), int(0.9*maxalt)) for i in range (6)],
            [random.randint(int(0.6*maxalt), int(0.8*maxalt)) for i in range (6)],
            [random.randint(int(0.5*maxalt), int(0.7*maxalt)) for i in range (6)],
            [random.randint(int(0.4*maxalt), int(0.6*maxalt)) for i in range (6)],
            [random.randint(int(0.3*maxalt), int(0.5*maxalt)) for i in range (6)],
            [random.randint(int(0.2*maxalt), int(0.4*maxalt)) for i in range (6)],
            [random.randint(int(0.1*maxalt), int(0.3*maxalt)) for i in range (6)],
            [random.randint(0, int(0.2*maxalt)) for i in range (6)]]


pd =  ["sa1", "sa2" ,"sa3","he1", "he2", "he3", "he4", "he5"]
d = ["sa1", "sa2" ,"sa3"] 
p =  ["he1", "he2", "he3", "he4", "he5"]


texture =  [[p, p, p, p, p, p],
            [p, p, p, p, p, p],
            [p, p, p, p, p, p],
            [p, p, p, p, p, p],
            [p, p, p, p, p, p],
            [pd, pd, pd, pd, pd, pd],
            [pd, pd, pd, pd, pd, pd],
            [d, d, d, d, d, d],
            [d, d, d, d, d, d]]
biomsize = 15

sizex = len(bioms[0])* biomsize 
sizey = len(bioms) * biomsize
size = sizex*sizey

altitude = np.array([[nan for i in range(sizex)] for i in range (sizey)])
riverid = np.array([[nan for i in range(sizex)] for i in range (sizey)])

characters = []

def max_alt():
    maxaltx = -1
    maxalty = -1
    maxalt = -1
    for y in range(sizey):
        for x in range(sizex):
            if altitude[y][x] > maxalt:
                maxalt = altitude[y][x]
                maxaltx = x
                maxalty = y
    return maxalt, maxaltx, maxalty

for i in range(len(bioms)):
    for j in range(len(bioms[i])):
        altitude[i*biomsize + int(biomsize/2)][j*biomsize + int(biomsize/2)] = bioms[i][j] 
        if len(bioms[0]) - 1 > j:
            incr = (bioms[i][j+1] - bioms[i][j])/biomsize
            for k in range(biomsize):
                altitude[i*biomsize + int(biomsize/2)][j*biomsize + int(biomsize/2) + k] = int(bioms[i][j] + k * incr)
    for j in range(int(biomsize/2)):
        altitude[i*biomsize + int(biomsize/2)][j] = bioms[i][0]
        altitude[i*biomsize + int(biomsize/2)][-j-1] = bioms[i][-1]
        

for j in range(len(altitude[0])):
    for i in range(0, len(bioms)-1):
        incr = (altitude[int(biomsize/2)+(i+1)*biomsize][j] - altitude[int(biomsize/2)+i*biomsize][j]) / biomsize
        for k in range(biomsize):
            #print(int(biomsize/2)+i*biomsize, j)
            altitude[int(biomsize/2)+i*biomsize+k][j] = int(altitude[int(biomsize/2)+i*biomsize][j] + k * incr)



for i in range(int(biomsize/2)):
    for j in range(len(altitude[i])):
        altitude[i][j] = altitude[int(biomsize/2)+1][j]
        altitude[-i-1][j] = altitude[-int(biomsize/2)-2][j]


for y in range(sizey):
    for x in range(sizex):
        if bioms[y//biomsize][x//biomsize] % 10 != 7:
            altitude[y][x] += random.randint(-10, 10)
        if 0 >  altitude[y][x]:
            altitude[y][x] = 0

maxalt, mxx, mxy = max_alt()

#create_river()

ground = open(argv[1], "w")
ground.write(str(sizex) + " " + str(sizey) + "\n")

to_write = ""
for y in range(0, sizey):
    for x in range(0, sizex):
        tex = texture[y//biomsize][x//biomsize][random.randint(0,len(texture[y//biomsize][x//biomsize])-1)]
        if altitude[y][x] > int(0.8*maxalt) and "sa" not in tex:
            to_write+=("gra"+str(int(altitude[y][x]*0.7))+tex+str(int(altitude[y][x]*0.2))+"ne"+str(random.randint(1,3))+str(int(altitude[y][x]*0.1))+ " ")
        else:
            to_write+=("gra"+str(int(altitude[y][x]*0.7))+tex+str(int(altitude[y][x]*0.3))+" ")
            if "he" in tex:
                if random.randint(1,50) == 1:
                    characters.append("01 " + str(len(characters)+1 )   + " 50 none " + str(x) + " " + str(y) + " " + str(altitude[y][x]) + " -1.000000 908.785156 a 0 0 -1 none none none none 0 none none 0 none 0 3 0 0 empty empty empty empty empty empty [] [] []\n")
    to_write = to_write[:-1] + "\n"

ground.write(to_write)

map = open(argv[2], "w")
for i in characters:
    map.write(i)
map.write("0 0 10 thyma 3.00000 3.000000 25 -1.000000 908.785156 a 0 9999 -1 thyma thyma none none 0 none none 0 none 0 3 0 0 empty empty empty empty empty empty [] [] [001002]\n")