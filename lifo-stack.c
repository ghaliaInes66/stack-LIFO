#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

void push(node **pile,int val){
  node *p=(node*)malloc(sizeof(node));
  p->data=val;
  if(*pile==NULL) p->next=NULL;
  else p->next=*pile;
  *pile=p;
}

void pop(node **pile){
  if(*pile==NULL) printf("empty stack");
  else {
    node *p=*pile;
    *pile=p->next;
    free(p);
  }
}

bool isVide(node **pile){
  return *pile==NULL;
}

int sommet (node **pile){
  if(*pile==NULL) printf("empty stack");
  else return (*pile)->data;
}

void displaystack(node**pile){
  node *piletmp=NULL;
  while (!isVide(&*pile))
  {
    printf("%i\n",sommet(&*pile));
    push(&piletmp,sommet(&*pile));
    pop(&*pile);
  }
  tmpstack(&piletmp,&*pile);
}

void tmpstack(node**p1,node**p2){
  while(!isVide(&*p1)){
    push(&*p2,sommet(&*p1));
    pop(&*p1);
  }
}

int sumstack(node **pile){
   int sum=0; node *piletmp=NULL;
  while(!isVide(&*pile)){
    sum=sum+sommet(&*pile);
    push(&piletmp,sommet(&*pile));
    pop(&*pile);
  }
  tmpstack(&piletmp,&*pile);
  return sum;
}


int main(){
  node *pile=NULL;
  push(&pile,1);
  push(&pile,2);
  push(&pile,3);
  displaystack(&pile);
  printf("%i",sumstack(&pile));
  displaystack(&pile);
}