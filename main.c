#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 10
typedef struct linked_list{
    char data[5];
    int link;
}linked_list;

void initialize_the_array(linked_list[]);
void add_next_name(char*,linked_list[],int*,int*);
void delete_item(linked_list[],char*,int*,int*);
void display(linked_list[]);
void sort(int [], int);
void swap(int *, int *);

int main() {
    linked_list array_of_names[maxsize];
    int next_empty_location=0;
    int arr[7]={23,2,4,0,1,43,10};
    int real_array_starting_index=-1;
    sort(arr,7);
    initialize_the_array(array_of_names);
    add_next_name("okan",array_of_names,&next_empty_location,&real_array_starting_index);
    display(array_of_names);
    printf("empty_location: %d------ array_starting_index: %d\n",next_empty_location,real_array_starting_index);

    add_next_name("muge",array_of_names,&next_empty_location,&real_array_starting_index);
    display(array_of_names);
    printf("empty_location: %d------ array_starting_index: %d\n",next_empty_location,real_array_starting_index);

    add_next_name("ugur",array_of_names,&next_empty_location,&real_array_starting_index);
    display(array_of_names);
    printf("empty_location: %d------ array_starting_index: %d\n",next_empty_location,real_array_starting_index);

    add_next_name("nila",array_of_names,&next_empty_location,&real_array_starting_index);
    display(array_of_names);
    printf("empty_location: %d------ array_starting_index: %d\n",next_empty_location,real_array_starting_index);

    delete_item(array_of_names,"muge",&next_empty_location,&real_array_starting_index);
    display(array_of_names);
    printf("empty_location: %d------ array_starting_index: %d\n",next_empty_location,real_array_starting_index);

}
void initialize_the_array(linked_list based_array[]){
    int i;
    for(i=0;i<maxsize;i++)
        based_array[i].link=i+1;
}
void display(linked_list based_array[]){
    int i;
    printf("index\tname\tlink\t\n");
    for(i=0;i<maxsize;i++){
        printf("[%d]\t%s\t%d\n",i,based_array[i].data,based_array[i].link);
    }
}

/*Real_array_starting_index indicates the first element's index*/
/*Next_empty_location shows us the current empty index of the array*/
/*Rear shows us first nothing and if we want to add an element to the middle it chase front and take fronts place*/
/*Front first shows us the first element of the array not the array[0] actually it shows the first element in the array thah
 * can be place in also array[5] or array[7] I mean it shows the index of the first element of the array*/
void add_next_name(char *name,linked_list based_array[],int *next_empty_location,int *real_array_starting_index){
    int rear=-1;
    int front=*real_array_starting_index;
    int current_empty_location=*next_empty_location;  /*Temp means the empty location of the array index which we can insert our item*/

    strcpy(based_array[current_empty_location].data,name);
    *next_empty_location=based_array[*next_empty_location].link;

    while (front!=-1 && strcmp(based_array[front].data,name)<0){
        rear=front;
        front=based_array[front].link;
    }
    if(rear==-1){                                    /*That means there is no  node to show the current adding item*/
        based_array[current_empty_location].link=front;               /*Inserting an element into the head of the array*/
        *real_array_starting_index=current_empty_location; /*Changing the starting index of the real array*/
    } else{
        based_array[rear].link=current_empty_location;
        based_array[current_empty_location].link=front;
    }
}

void delete_item(linked_list based_array[],char *name,int *real_array_starting_index,int *new_empty_location){
    int rear=-1;
    int front=*real_array_starting_index;
    while (front!=-1 && strcmp(based_array[front].data,name)!=0){
            rear=front;
            front=based_array[front].link;
    }
    if(front==-1){ /*So that means the list is empty*/
        printf("You cannot delete an item from an empty list");
        exit(123);
    }
    if(rear==-1){ /*Deleting an item from the head of the list*/
        *real_array_starting_index=based_array[front].link;
    } else {                    /*This means deleting the first element of the array*/
        /*So the array starting moves to next element.Next element can locate in any
 * index of array but when we delete the first element ıts link shows us the next element so second element becomes first element
 * when we delete the first element*/
        based_array[rear].link=based_array[front].link;
    }
    based_array[front].link=*new_empty_location; /*The item that we deleted ıts link shows the next free_location on the list */
    *new_empty_location=front; /*The new empty location will be the deleted item index*/

}
