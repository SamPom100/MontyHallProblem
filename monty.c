//
//  monty.c
//  MontyC
//
//  Created by Sam Pomerantz on 6/3/22.
//

#include "monty.h"

int main(){
    srand( (unsigned int) time(NULL) );
    
    int win = 0;
    int loss = 0;
    int numIter = 20000000;
    
    for(int i=0; i<numIter; i++){
        int *resultScene = generateScene();
        int a = show(resultScene, 'S');
        if(a == 0){
            win++;
        }
        else{
            loss++;
        }
        free(resultScene);
    }
    printf("Stay: %.3f%%", 100*(double)win/(win+loss));
    
    win = 0;
    loss = 0;
    for(int i=0; i<numIter; i++){
        int *resultScene = generateScene();
        int a = show(resultScene, 'G');
        if(a == 0){
            win++;
        }
        else{
            loss++;
        }
        free(resultScene);
    }
    printf("\nSwitch: %.3f%%", 100*(double)win/(win+loss));
    printf("\n");
    return 0;
}

// 0 = GOAT
// 1 = CAR
// 2 = SEEN
//generate and return Monty Hall Scene
int * generateScene(void){
    int *scene = malloc (sizeof (int) * 3);
    for (int i=0; i<3; i++)
    {
      scene[i] = 0;
    }
    scene[rand() % 3] = 1;
    return scene;
}

// Inputs:
// CHOICE 'S' = STAY
// CHOICE 'G' = (GO) SWITCH

// Results:
// 0 = WIN
// 1 = LOSS
int show(int* scene, char choice){
    int playerPicks = rand() % 3;
    int toRemove;
    while(1){
        toRemove = rand() % 3;
        if(toRemove != playerPicks && scene[toRemove] == 0){
            scene[toRemove] = 2;
            break;
        }
    }
    
    if(choice == 'S'){
        if(scene[playerPicks] == 1){
            return 0;
        }
        return 1;
    }
    if(choice == 'G'){
        int choiceList[] = {0,1,2};
        for(int i=0; i<3; i++){
            if(choiceList[i] != playerPicks && choiceList[i] != toRemove){
                choiceList[0] = choiceList[i];
            }
        }
        if(scene[choiceList[0]] == 1){
            return 0;
        }
        return 1;
    }
    return -1;
}


