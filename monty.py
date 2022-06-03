from random import randint


def createInstance():
    #generate an instance of the problem
    scene = ['goat','goat','goat']
    scene[randint(0,2)] = 'car'
    return scene

def show(scene, choice):
    #player picks a door
    playerPicks = randint(0,2)
    #show host reveals(removes) another door that has a goat
    while(True):
        toRemove = randint(0,2)
        if(toRemove != playerPicks and scene[toRemove] == 'goat'):
            scene[toRemove] = 'seen'
            break
    if choice == 'stay':
        if(scene[playerPicks]) == 'car':
            return 'won'
        return 'lost'
    if choice == 'switch':
        choiceList = [0,1,2]
        choiceList.remove(playerPicks) 
        choiceList.remove(toRemove)
        if(scene[choiceList[0]] == 'car'):
            return 'won'
        return 'lost'

win = 0
loss = 0
numIter = 2000000

for x in range(numIter):
    result = show(createInstance(), 'stay')
    if result == 'won':
        win+=1
    else:
        loss+=1
print("Stay: "+str(100*round((win/(win+loss)),5))+"%")

win = 0
loss = 0
for x in range(numIter):
    result = show(createInstance(), 'switch')
    if result == 'won':
        win+=1
    else:
        loss+=1
print("Switch: "+str(100*round((win/(win+loss)),5))+"%")



