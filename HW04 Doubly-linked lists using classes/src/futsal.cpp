#include "../include/futsal.h"

// helper: find the best player in a batch
Player *findBestInBatch(Queue *q, Queue *tmp_q, int batch_size) {
    if (!q || batch_size <= 0) {
        return nullptr;
    }

    Player *best_player = nullptr;

    for (int i = 0; i < batch_size && queueSize(q) > 0; i++) {
        const Player *front = queueFront(q);   
        Player *curr = copyPlayer(front);      
        queuePopPlayerEntry(q);   
                     
        if (!best_player || curr->num_goals > best_player->num_goals) {
            if (best_player) {
                queuePushPlayerEntry(tmp_q, best_player);
            }
            best_player = curr;
        } else {
            queuePushPlayerEntry(tmp_q, curr);
        }
    }
    return best_player; 
}

Player *teamBestOfBatch(Queue *q, int k) {
    if (!q || k <= 0) {
        return nullptr;
    }
    Queue *temp = newQueue();
    Player *best_player = findBestInBatch(q, temp, k);
    while (queueSize(temp) > 0) {
        Player *p_copy = copyPlayer(queueFront(temp));
        queuePushPlayerEntry(q, p_copy);
        queuePopPlayerEntry(temp); 
    }
    deleteQueue(temp); 
    return best_player;
}

void teamCreateFromBest(Queue *applicant_q, Queue *welcome_q, int batch_size) {
    if (!applicant_q || !welcome_q) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        Player *best_player = teamBestOfBatch(applicant_q, batch_size);
        if (best_player) {
            queuePushPlayerEntry(welcome_q, best_player);
        }
    }
}