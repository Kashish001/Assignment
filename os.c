
//General statement to the Problem is to Provide Resources to the Procesess by Avoiding Deadlock
//This can be done By the Algorithms that are specially Designed for the Avoidance of Deadlock
//Such as Banker's Algorithm

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//Condition to be Satisfied in this Assignment
//----------------------------------------------------------------------------
void conditions() {
    printf("\nPlease Give Inputs According to Following Conditions : \n\n");
    printf("1. Maximum Resource Need of each Process is in between 1 and No. of Process.\n");
    printf("2. Summation of all Maximum needs should be less than No of process + No. of Resources.\n");
}
//----------------------------------------------------------------------------

//For Taking Inputs and For Checking Condition 1
//-----------------------------------------------------------------------------------
int input_of_maxNeeds(int maxNeeds[], int P, int R) {
    int totalCount = 0;
    for(int i = 0 ;  i < P; i++) {
    printf("Enter Max Number of Resources Need for Process P%d : ", i + 1);
    scanf("%d", &maxNeeds[i]);
    if(maxNeeds[i] > R) {
        return -1;
    }
    totalCount += maxNeeds[i];
  }
  return totalCount;
}

//------------------------------------------------------------------------------------

//For Finding Remaining Needs of Processes
//------------------------------------------------------------------------------------
void remNeed(int need[], int P, int Max_need[], int allocated[]) {
    for(int i = 0 ;  i < P; i++) {
        need[i] = Max_need[i] - allocated[i];
        printf("\nRemaing Need of Resources to Process P%d are : %d", i+1, need[i]);
    }
    printf("\n");
}
//-------------------------------------------------------------------------------------

//For Checking The State of System
//-------------------------------------------------------------------------------------
void isSafe(int P, int R, int available, int Max_Need[], int allocate[]) {
    
    int need[P];
    remNeed(need, P, Max_Need, allocate);
    int Sequence[P], seq = 1;
    for(int i = 0 ;  i < P; i++) Sequence[i] = 0;
    bool is_safe = true;
    while(seq <= P) {
        int count = 0;
        for(int i = 0 ; i < P; i++) {
        if(need[i] < available && Sequence[i] == 0) {
            Sequence[i] = seq;
            seq++;
            available += allocate[i];
            } else if(Sequence[i] == 0) count++;
        }
        //A check if Remaining Need of All the Processes are more than Available Resorces then it is Not in Safe state, Hence Deadlock Occurs.
        if(count == P) {
            is_safe = false;
            printf("\nSystem is Not in Safe State :-( \n\n");
            exit(0);
        }
    }

    printf("\nSystem is in Safe State\n\n");
    printf("Safe Sequence is : ");
    int just = P - 1, reqSequence = 1;
    while(just--) {
        for(int i = 0 ; i < P; i++) if(Sequence[i] == reqSequence) printf("P%d --> ",i + 1);
        reqSequence++;
    }
    for(int i = 0 ; i < P; i++) if(Sequence[i] == reqSequence) printf("P%d \n\n",i + 1);
}
//-------------------------------------------------------------------------------------

int main() {
    conditions();
  int R, P;// R is No of Available Resources and P is No of Processes
  printf("\nEnter the Number of Intsances of Resource : ");
  scanf("%d", &R);
  printf("\n");
  printf("Enter total Number of Processes : ");
  scanf("%d", &P);
  printf("\n");
  int Max_need_of_Processes[P]; // Array to Store Max No of Needs of the Processes
  int check = input_of_maxNeeds(Max_need_of_Processes, P, R);
   while(check == -1) {
        printf("\nWrong Input. Input not Satisfying the Condition No 1. Please Give Re-Input :-(\n\n");
        check = input_of_maxNeeds(Max_need_of_Processes, P, R);
      }
  printf("\nCondition 1 Satisfied.\n");
  while(check >= (P + R)) {
      printf("\nThese Inputs are Not Satisfying the Condition No 2. Please Give Re-Inputs :-)\n\n");
      check = input_of_maxNeeds(Max_need_of_Processes, P, R);
  }
  printf("\n");
  printf("Condition 2 Satisfied. Summation is : %d\n\n", check);
  int allot[P]; // How Many Resources are Already Allocated to the Process
  for(int i = 0 ;  i < P; i++) {
      if(Max_need_of_Processes[i]) {
          allot[i] = Max_need_of_Processes[i] / 2;
      } else {
          allot[i] = 0;
      }
  }
  int totalAlloted_resources = 0;
  for(int i = 0  ; i < P; i++) {
      printf("Already Alloted Resources to the Process P%d are : %d\n", i + 1, allot[i]);
      totalAlloted_resources += allot[i];
  }

  printf("\nTotal Available Resorces After Allocation of Resources : %d\n", R - totalAlloted_resources);
  isSafe(P, R, R - totalAlloted_resources, Max_need_of_Processes, allot); // Calling function isSafe to Check Whether System is in safe state or not

  return 0;
}
