#ifndef UTILH
#define UTILH
#include "main.h"

#define REQQUEUE    1
#define ACKQUEUE    2
#define GROUPFORMED 3
#define REQRES      4
#define ACKRES      5
#define START       6
#define END         7

#define RESNUM 2
#define GROUPSIZE 2
/* typ pakietu */
typedef struct {
    int ts;
    int src;  
    int inGroup[GROUPSIZE];
} packet_t;
#define NITEMS 3

typedef enum {WantGroup, WaitingForQueue, WaitingForGroup, InFinish} state_t;

typedef struct {
    int id;
    int lamport;
} idLamportPair;

extern int inGroup[GROUPSIZE];
extern std::vector<idLamportPair> groupQueue;
extern state_t state;
extern pthread_mutex_t stateMut;
extern pthread_mutex_t lamportMut;
extern pthread_mutex_t groupQueueMut;
extern pthread_mutex_t waitingForQueueMut;
extern pthread_mutex_t waitingForGroupMut;
extern MPI_Datatype MPI_PAKIET_T;

void inicjuj_typ_pakietu();

/* wysyłanie pakietu, skrót: wskaźnik do pakietu (0 oznacza stwórz pusty pakiet), do kogo, z jakim typem */
void sendPacket(packet_t *pkt, int destination, int tag);
void sendPacketToAllNoInc(packet_t *pkt, int tag);
void changeState(state_t);
#endif