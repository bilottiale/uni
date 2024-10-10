#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARDS 52
#define FACES 13

typedef struct card {
  const char *face;
  const char *suit;
} Card;

void fillDeck(Card * const deck, const char * faces[], const char * suits[]);
void shuffle(Card * const deck);
void deal(const Card * const deck);

int main(void){
  Card deck[CARDS]; // definisci l'array di carte

  // inizializza l'array di puntatori dei valori
  const char *face[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

  // inizia l'array di puntatori dei semi
  const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  srand(time(NULL)); // randomizza

  fillDeck(deck, face, suit); // carica il mazzo con le carte

  shuffle(deck); // metti le carte in ordine casuale

  deal(deck); // distribuisci le 52 carte

  return 0;
}

// metti le stringhe nelle strutture Card
void fillDeck(Card * const deck, const char * faces[], const char * suits[]){
  for(size_t i = 0; i < CARDS; ++i){
    deck[i].face = faces[i % FACES];
    deck[i].suit = suits[i / FACES];
  }
}

// mescola le carte
void shuffle(Card * const deck){
  for(size_t i = 0; i < CARDS; ++i){
    size_t j = rand() % CARDS;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

// distribuisci le carte
void deal(const Card * const deck){
  for (size_t i = 0; i < CARDS; i++){
    printf("%5s of %-8s%s", deck[i].face, deck[i].suit, (i + 1) % 4 ? " " : "\n");
  }
}
