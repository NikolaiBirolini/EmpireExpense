import random
from math import nan, isnan

bioms =    [[-20,-20,100, -20,-20],
            [-20,-20,200,-20,-20],
            [100,200,300, 200, 100],
            [-20,-20,200, -20, -20], 
            [-20,-20,100, -20, -20]]
biomsize =21

sizex = len(bioms[0])* biomsize
sizey = len(bioms) * biomsize

altitude = [[nan for i in range(sizex)] for i in range (sizey)]
texture = [[nan for i in range(sizex)] for i in range (sizey)]

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
        

"""for i in altitude:
    print(i)"""


for j in range(len(altitude[0])):
    for i in range(0, len(bioms)-1):
        incr = (altitude[int(biomsize/2)+(i+1)*biomsize][j] - altitude[int(biomsize/2)+i*biomsize][j]) / biomsize
        for k in range(biomsize):
            #print(int(biomsize/2)+i*biomsize, j)
            altitude[int(biomsize/2)+i*biomsize+k][j] = int(altitude[int(biomsize/2)+i*biomsize][j] + k * incr)

"""print("---------------------")
for i in altitude:
    print(i)"""

for i in range(int(biomsize/2)):
    for j in range(len(altitude[i])):
        altitude[i][j] = altitude[int(biomsize/2)+1][j]
        altitude[-i-1][j] = altitude[-int(biomsize/2)-2][j]

"""print("---------------------")
for i in altitude:
    print(i)
exit()"""

for y in range(sizey):
    for x in range(sizex):
        altitude[y][x] += random.randint(-10, 10)
        if 0 >  altitude[y][x]:
            altitude[y][x] = 0
        
for y in range(sizey):
    for x in range(sizex):
        if 0 == altitude[y][x]:
            texture[y][x] = "ea" + str(random.randint(1,3))
        elif x > 0 and y > 0 and sizex - 1 > x and sizey - 1 > y and (altitude[y-1][x] == 0 or altitude[y-1][x-1] == 0 or altitude[y-1][x+1] == 0 or altitude[y][x-1] == 0 or altitude[y][x+1] == 0 or altitude[y+1][x] == 0 or altitude[y+1][x-1] == 0 or altitude[y+1][x+1] == 0): 
            texture[y][x] = "sa" + str(random.randint(1,3))
        elif altitude[y][x] > 200:
            texture[y][x] = "ne" + str(random.randint(1,3))
        else:        
            texture[y][x] = "he" + str(random.randint(1,5))
        

print(sizex, sizey)
for y in range(0, sizey):
    for x in range(0, sizex-1):
        print(f"{texture[y][x]}{altitude[y][x]}", end=" ")
    print(f"{texture[y][x]}{altitude[y][x]}")