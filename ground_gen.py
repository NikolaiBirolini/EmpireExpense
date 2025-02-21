import random
from math import nan, isnan

def max_alt(altitude, sizex, sizey):
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

def under_0_not_watter(altitude, texture, sizex, sizey):
    for y in range(sizey):
        for x in range(sizex):
            if altitude[y][x] == 0 and "ea" not in texture[y][x]:
                return True
    return False

def min_alt_close_watter(altitude, texture, sizex, sizey, minalt):
    minaltx = -1
    minalty = -1
    for y in range(sizey):
        for x in range(sizex):
            if texture[y][x] == "ea1":
                if x+1 < len(texture[y]) and texture[y][x+1] != "ea1" and altitude[y][x+1] <= minalt:
                    minalt = altitude[y][x+1]
                    minaltx = x +1 
                    minalty = y
                if x-1 >= 0 and texture[y][x-1] != "ea1" and altitude[y][x-1] <= minalt:
                    minalt = altitude[y][x-1]
                    minaltx = x - 1 
                    minalty = y
                if y+1 < len(texture) and texture[y+1][x] != "ea1" and altitude[y+1][x] <= minalt:
                    minalt = altitude[y+1][x]
                    minaltx = x 
                    minalty = y +1
                if y - 1>= 0 and texture[y-1][x] != "ea1" and altitude[y-1][x] <= minalt:
                    minalt = altitude[y-1][x]
                    minaltx = x 
                    minalty = y - 1
    return minalt, minaltx, minalty

def create_river(altitude, texture, sizex, sizey):
    trash, maxx, maxy = max_alt(altitude, sizex, sizey)
    texture[maxy][maxx] = "ea1"
    while (under_0_not_watter(altitude,texture,sizex,sizey)):
        minalt, minaltx, minalty = min_alt_close_watter(altitude, texture, sizex, sizey, 9999)
        texture[minalty][minaltx] = "ea1"
    return texture


bioms =    [[400,200,190, 180,170],
            [350,350, 350,350,160],
            [110,120,130, 140, 150],
            [100,350,350, 350, 350], 
            [90,80,0, -20, -20]]
biomsize =21

sizex = len(bioms[0])* biomsize
sizey = len(bioms) * biomsize

altitude = [[nan for i in range(sizex)] for i in range (sizey)]
texture = [["nan" for i in range(sizex)] for i in range (sizey)]

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
        altitude[y][x] += random.randint(-10, 10)
        if 0 >  altitude[y][x]:
            altitude[y][x] = 0

texture = create_river(altitude, texture, sizex, sizey)

for y in range(sizey):
    for x in range(sizex):
        if "ea" in texture[y][x]:
            continue
        elif x > 0 and y > 0 and sizex - 1 > x and sizey - 1 > y and (altitude[y-1][x] == 0 or altitude[y-1][x-1] == 0 or altitude[y-1][x+1] == 0 or altitude[y][x-1] == 0 or altitude[y][x+1] == 0 or altitude[y+1][x] == 0 or altitude[y+1][x-1] == 0 or altitude[y+1][x+1] == 0): 
            texture[y][x] = "sa" + str(random.randint(1,3))
        elif altitude[y][x] > 200:
            texture[y][x] = "ne" + str(random.randint(1,3))
        else:        
            texture[y][x] = "he" + str(random.randint(1,5))
        

print(sizex, sizey)
for y in range(0, sizey):
    for x in range(0, sizex-1):
        if altitude[y][x] > 15 and "ea" not in texture[x][y]:
            print(f"te{str(random.randint(1,3))}{altitude[y][x]-10}{texture[y][x]}10", end=" ")
        else:
            print(f"{texture[y][x]}{altitude[y][x]}", end=" ")
    print(f"{texture[y][x]}{altitude[y][x]}")