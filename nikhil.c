#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 100

struct dll {
    struct dll* left1;
    struct dll* right1;
    int data_data;
};

struct stack {
    struct stack* right1;
    int data_data;
};

struct queue {
    int data_data;
    struct queue* right1;
};

//Implementation of Queue 
struct Queue {
    struct queue *first1, *last1;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->first1 = q->last1 = NULL;
    return q;
}


int queuelen = 0;
int currentcqueuelen = 0;

void dll_display(struct dll*, FILE* pt3);
void dll_delete(struct dll**, int, FILE* pt3);
void dll_insert(struct dll**, int, FILE* pt3);
void dll_find(struct dll**, int, FILE* pt3);

void stack_display(struct stack*, FILE* pt2);
void stack_POP(struct stack**, FILE* pt2);
void stack_PUSH(struct stack**, int, FILE* pt2);
void stack_find(struct stack**, int, FILE* pt2);

void queue_display(struct Queue*, FILE* GOLD);
void queue_DEQUEUE(struct Queue*, FILE* GOLD);
void queue_ENQUEUE(struct Queue*, int, FILE* GOLD);
void queue_find(struct Queue*, int, FILE* GOLD);


void queue_display123(struct queue* head, FILE* GOLD);
void queue_display456(struct queue* head, FILE* GOLD);
void queue_ENQUEUE123(struct queue** head, int value,FILE* GOLD);
void queue_ENQUEUE456(struct queue** head, int value,FILE* GOLD);
void queue_DEQUEUE123(struct queue** head,FILE* GOLD);
void queue_find123(struct queue** q, int num, FILE* GOLD);
void queue_display789(struct queue* head, FILE* GOLD);


int stacklen = 0;
int currentlen = 0;

char ch[L];


void dll_insert(struct dll** s, int num, FILE* pt3) {
    struct dll* q = malloc(sizeof(struct dll));
    q->left1 = NULL;
    q->data_data = num;
    q->right1 = *s;

    fprintf(pt3, "inserted %d\n", q->data_data);

    if (*s != NULL) {
        (*s)->left1 = q;
    }

    *s = q;
}

void dll_display(struct dll* q, FILE* pt3) {
    while (q != NULL) {
        fprintf(pt3, "%d ", q->data_data);
        q = q->right1;
    }
}

void dll_find(struct dll** q, int num, FILE* pt3) {
    struct dll* s = *q;
    while (s != NULL) {
        if (s->data_data == num) {
            fprintf(pt3, "found %d\n", num);
            return;
        }
        s = s->right1;
    }
    fprintf(pt3, "not found %d\n", num);
}

void dll_delete(struct dll** s, int num, FILE* pt3) {
    struct dll* q = *s;
    int count2 = 0;
    while (q != NULL) {
        if (q->data_data == num) {
            count2++;
            if (q == *s) {
                *s = (*s)->right1;
                if (*s != NULL) {
                    (*s)->left1 = NULL;
                }
                fprintf(pt3, "deleted %d\n", num);
            } else {
                if (q->right1 == NULL) {
                    fprintf(pt3, "deleted %d\n", num);
                    q->left1->right1 = NULL;
                } else {
                    fprintf(pt3, "deleted %d\n", num);
                    q->left1->right1 = q->right1;
                    q->right1->left1 = q->left1;
                }
                free(q);
            }
            return;
        }
        q = q->right1;
    }
    if (count2 == 0) {
        fprintf(pt3, "cannot delete %d\n", num);
    }
}

void stack_PUSH(struct stack** s, int num, FILE* pt2) {
    struct stack* q = malloc(sizeof(struct stack));
    if (currentlen == stacklen) {
        fprintf(pt2, "overflow\n");
        return;
    }
    currentlen++;
    q->data_data = num;
    q->right1 = *s;

    fprintf(pt2, "pushed %d\n", q->data_data);
    *s = q;
}

void stack_POP(struct stack** s, FILE* pt2) {
    if (currentlen == 0) {
        fprintf(pt2, "underflow\n");
        return;
    }
    currentlen--;
    struct stack* q = *s;
    fprintf(pt2, "popped %d\n", q->data_data);
    *s = (*s)->right1;
    free(q);
}

void stack_display(struct stack* q, FILE* pt2) {
    while (q != NULL) {
        fprintf(pt2, "%d ", q->data_data);
        q = q->right1;
    }
}

void stack_find(struct stack** q, int num, FILE* pt2) {
    struct stack* s = *q;
    while (s != NULL) {
        if (s->data_data == num) {
            fprintf(pt2, "found %d\n", num);
            return;
        }
        s = s->right1;
    }
    fprintf(pt2, "not found %d\n", num);
}

//function enqueue using linked list
void queue_ENQUEUE(struct Queue* q, int value,FILE* GOLD) {

    if (currentcqueuelen == queuelen) {
        fprintf(GOLD, "overflow\n");
        return;
    }
    currentcqueuelen++;

    struct queue* node = (struct queue*)malloc(sizeof(struct queue));
    node->data_data = value;
    if (q->first1 == NULL) {
//linked list is traversed
        q->first1 = q->last1 = node;
        q->last1->right1 = q->first1;

    } else {
        q->last1->right1 = node;
        q->last1 = node;
        q->last1->right1 = q->first1;
    }
    fprintf(GOLD,"enqueued %d\n", value);
}


//function dequeue using linked list
void queue_DEQUEUE(struct Queue* q,FILE* GOLD) {

    
if (currentcqueuelen == 0) {
        fprintf(GOLD, "underflow\n");
        return;
    }
 currentcqueuelen--;

    //if (q->first1 == NULL) {
       // printf("Queue is Empty\n");
      //  return;
    //}
     if (q->first1 == q->last1) {
        fprintf(GOLD,"dequeued %d\n", q->first1->data_data);
        q->first1 = q->last1 = NULL;
    } else {
        struct queue* temp = q->first1;
        fprintf(GOLD,"dequeued %d\n", temp->data_data);
        q->first1 = q->first1->right1;
        q->last1->right1 = q->first1;
    }
}


//Function to display elements
void queue_display(struct Queue* q,FILE* GOLD) {
   // if (q->first1 == NULL) {
      //  printf("Queue is Empty\n");
      //return;
    //}
     if(q->first1!=NULL){
        struct queue* temp = q->first1;
    //    printf("Elements of the queue: ");
        do {
            fprintf(GOLD,"%d ", temp->data_data);
            temp = temp->right1;
        } while (temp != q->first1);
       // printf("\n");
    }
}

void queue_find(struct Queue* q, int o,FILE* GOLD) {

    if (currentcqueuelen == 0) {
        fprintf(GOLD, "\n");
        return;
    }

   // if (isEmpty(q)) {
     //    fprintf(GOLD,"not found %d",o); 
      //  return 0;
   // }
    struct queue* current1 = q->first1;
    while (current1->right1 != q->first1) {
        if (current1->data_data == o) {
            fprintf(GOLD,"found %d\n",o);
            return; // Element found
        }
        current1 = current1->right1;
    }
    fprintf(GOLD,"not found %d\n",o); // Element not found
}

int main(int argc, char* argv[]) {
    FILE* GOLD = fopen("queue.txt", "w");
    FILE* pt2 = fopen("stack.txt", "w");
    FILE* pt3 = fopen("dll.txt", "w");

    FILE* pp = fopen(argv[1], "r");
    int size = atoi(argv[2]);
    stacklen = size;
    queuelen=size;

    struct dll* abc = NULL;
    struct stack* def = NULL;
    // struct queue* pqr = NULL;

    struct Queue* q = createQueue();


    while (fscanf(pp, "%s", ch) != EOF) {
        if (strcmp("+", ch) == 0) {
            int num1 = 0;
            fscanf(pp, "%d", &num1);
            dll_insert(&abc, num1, pt3);
            stack_PUSH(&def, num1, pt2);
            queue_ENQUEUE(q,num1,GOLD);
        } 

        else if (strcmp("-", ch) == 0)
         {
            int num2 = 0;
            fscanf(pp, "%d", &num2);
            dll_delete(&abc, num2, pt3);
            stack_POP(&def, pt2);
         queue_DEQUEUE(q,GOLD);
        }

         else if (strcmp("?", ch) == 0)
          {
            int num3 = 0;
            fscanf(pp, "%d", &num3);
            dll_find(&abc, num3, pt3);
            stack_find(&def, num3, pt2);
          queue_find(q,num3,GOLD);
        } 
        
        else 
        {
            dll_display(abc, pt3);
            stack_display(def, pt2);
           queue_display(q,GOLD);
            fprintf(pt2, "\n");
            fprintf(pt3, "\n");
            fprintf(GOLD,"\n");
        }
    }

    fclose(pp);
    fclose(GOLD);
    fclose(pt2);
    fclose(pt3);
    return 0;


}

void queue_find123(struct queue** q, int num, FILE* GOLD) {
    if (*q == NULL) {
        fprintf(GOLD, "Queue is empty\n");
        return;
    }

    struct queue* current = *q;
    int found = 0;

    do {
        if (current->data_data == num) {
            found = 1;
            break;
        }
        current = current->right1;
    } while (current != *q);

    if (found) {
        fprintf(GOLD, "found %d\n", num);
    } else {
        fprintf(GOLD, "not found %d\n", num);
    }
}

void queue_display789(struct queue* head, FILE* GOLD) {
    if (head == NULL) {
   //     fprintf(GOLD, "Queue is empty.\n");
        return;
    }
struct queue* currentNode = head;
    int count=0;
    while(count<currentcqueuelen)
    {
        count++;
        fprintf(GOLD,"%d ",currentNode->data_data);
        currentNode=currentNode->right1;

    }
}

void queue_ENQUEUE789(struct queue** q, int value, FILE* GOLD) {
    if (currentcqueuelen == queuelen) {
        fprintf(GOLD, "overflow\n");
        return;
    }
    currentcqueuelen++;

    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data_data = value;

    if ((*q)->right1 == NULL) {
        newNode->right1 = newNode;
        *q = newNode;
    } else {
        newNode->right1 = (*q)->right1;
        (*q)->right1 = newNode;
        *q = newNode;
    }

    fprintf(GOLD, "enqueued %d\n", value);
}

void queue_DEQUEUE123(struct queue** head,FILE* GOLD) {

if (currentcqueuelen == 0) {
        fprintf(GOLD, "underflow\n");
        return;
    }
 currentcqueuelen--;
    /*if (head->next == NULL) {
        fprintf(GOLD, "Queue is empty.\n");
        return;
    }*/
    int value = (*head)->right1->data_data;
    (*head)->right1 = (*head)->right1->right1;
    fprintf(GOLD, "dequeued %d\n", value);
}




void queue_display456(struct queue* head, FILE* GOLD) {
    if (head == NULL) {
       // fprintf(GOLD, "Queue is empty.\n");
        return;
    }

    struct queue* currentNode = head->right1;
   // fprintf(GOLD, "Elements of the queue: ");
    while (currentNode != head) {
        fprintf(GOLD, "%d ", currentNode->data_data);
        currentNode = currentNode->right1;
    }
    //fprintf(GOLD, "\n");
}


void queue_display123(struct queue* head, FILE* GOLD) {
   /* if (head == NULL) {
        fprintf(pt3, "\n");
        return;
    }
    */
    while (head != NULL) {
        fprintf(GOLD, "%d ", head->data_data);
        head = head->right1;
    }
    
   // fprintf(pt3, "\n");

   struct queue* currentNode = head->right1;
    //fprintf("Elements of the queue: ");
    while (currentNode != head) {
        fprintf(GOLD,"%d ", currentNode->data_data);
        currentNode = currentNode->right1;
    }
}


void queue_ENQUEUE123(struct queue** head, int value,FILE* GOLD) {
    struct queue* currentNode = *head;
    if (currentcqueuelen == queuelen) {
        fprintf(GOLD, "overflow\n");
        return;
    }
    currentcqueuelen++;

    if (currentNode->right1==NULL){
        struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
        newNode->data_data=value;
        newNode->right1 = NULL;
        currentNode->right1 = newNode;
        fprintf(GOLD, "enqueued %d\n", value);
        return;
    }
    while (currentNode->right1 != NULL) {
        currentNode = currentNode->right1;
    }
    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data_data=value;
    newNode->right1 = NULL;
    currentNode->right1 = newNode;
    fprintf(GOLD, "enqueued %d\n", value);
}

// To remove the first1 element of the queue


void queue_ENQUEUE456(struct queue** q, int value, FILE* GOLD) {
     
     if (currentcqueuelen == queuelen) {
        fprintf(GOLD, "overflow\n");
        return;
    }
    currentcqueuelen++;

    if (*q == NULL) {
        *q = (struct queue*)malloc(sizeof(struct queue));
        (*q)->data_data = value;
        (*q)->right1 = *q;
        fprintf(GOLD, "enqueued %d\n", value);
        return;
    }

    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->data_data = value;
    newNode->right1 = (*q)->right1;
    (*q)->right1= newNode;
    *q = newNode;
    fprintf(GOLD, "enqueued %d\n", value);
}



  //  struct queue* currentNode = head;
  //  fprintf(GOLD, "Elements of the queue: ");
  // while (currentNode != head); {
    //    fprintf(GOLD, "%d ", currentNode->data_data);
      //  currentNode = currentNode->right1;
  //  } 
   // fprintf(GOLD, "\n");
   //


