
//General statement to the Problem is to Provide Resources to the Procesess by Avoiding Deadlock
//This can be done By the Algorithms that are specially Designed for the Avoidance of Deadlock
//Such as Banker's Algorithm

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void conditions() {
    printf("Please Give Inputs According to Following Conditions : \n\n");
    printf("1. Maximum Resource Need of each Process is in between 1 and No. of Process.\n");
    printf("2. Summation of all Maximum needs should be less than No of process + No. of Resources.\n");
}

int input_of_maxNeeds(int maxNeeds[], int P, int R) {
    int totalCount = 0;
    for(int i = 0 ;  i < P; i++) {
    printf("Enter Max Number of Resources Need for Process P%d : ", i + 1);
    scanf("%d", &maxNeeds[i]);
    if(maxNeeds[i] >= R) {
        return -1;
    }
    totalCount += maxNeeds[i];
  }
  return totalCount;
}

int main() {
    conditions();
  int R, P;
  printf("\nEnter the Number of Intsances of Resource : ");
  scanf("%d", &R);
  printf("\n");
  printf("Enter total Number of Processes : ");
  scanf("%d", &P);
  printf("\n");
  int Max_need_of_Processes[P];
  int check = input_of_maxNeeds(Max_need_of_Processes, P, R);
  if(check == -1) {
      while(check == -1) {
          printf("\nWrong Input. Input not Satisfying the Condition No 1. Please Give Re-Input :-(\n\n");
          check = input_of_maxNeeds(Max_need_of_Processes, P, R);
      }
  }
  while(check > (P + R)) {
      printf("\nThese Inputs are Not Satisfying the Condition No 2. Please Give Re-Inputs :-)\n\n");
      check = input_of_maxNeeds(Max_need_of_Processes, P, R);
  }
  printf("\n");

  int needOfResources[P][R];
}