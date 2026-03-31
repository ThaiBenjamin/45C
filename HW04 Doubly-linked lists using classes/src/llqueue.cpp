// include the header file here
#include "../include/llqueue.h"
// add all your llqueue functions in here.
LLNode *newLLNode(Player *p){
    LLNode *node = new LLNode();
    node->entry = p;
    node->next = nullptr;
    return node;
    
}

void deleteLLNode(LLNode *lln){
    if (!lln){
        return;  
    }
    deletePlayer(lln->entry);
    delete lln;
}
Queue *newQueue(){
    Queue *queue = new Queue();
    queue->head = nullptr;
    queue->tail = nullptr;
    queue->size = 0;
    return queue;
}
void queuePushPlayerEntry(Queue *q, Player *entry){
    if(!q){
        return;
    }
    LLNode *node = newLLNode(entry);
    if (!q->head) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->size++;
}

void queuePopPlayerEntry(Queue *q){
    if (!q || !q->head) {
        return;
    } 

    LLNode *tempNode;
    tempNode = q->head;
    q->head = tempNode->next;
    if (!q->head){
         q->tail = nullptr;
    }
    q->size--;
    deleteLLNode(tempNode);   
    
}

// front function
Player *queueFront(Queue *q){
    if (!q || !q->head){
        return nullptr;
    } 
    return q -> head -> entry;
}

// back function
Player *queueBack(Queue *q){
    if (!q || !q->tail){
        return nullptr;
    } 
    return q -> tail -> entry;
}
// size function
std::size_t queueSize(const Queue *q){
    if(!q){
        return 0;
    }
    return q->size;
}

// print out the queue players in order
void printQueue(const Queue *q){
    if (!q || !q->head) {
        std::cout << "Queue is empty.\n";
        return;
    }

    LLNode *tempNode = q->head;
    while(tempNode != nullptr){
        printPlayer(tempNode->entry);
        tempNode = tempNode->next;
    }
}

// deleteQueue only deletes the LLNodes it is the caller's responsibility to delete the players contained within!
void deleteQueue(Queue *q){
    if(!q){
        return;
    }
    LLNode *tempNode = q->head;

    while(tempNode){
        LLNode *nextNode = tempNode->next;
        deleteLLNode(tempNode);
        tempNode = nextNode;
    }

    delete q;
}
