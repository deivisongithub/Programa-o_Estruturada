/**********************************
 *Aluno: Deivison rodrigues jordao
 *Professor: Yuri Malheiros
 *Programaçao estrurada
 **********************************/

/***
 *
 ****/ 

#include <stdio.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
int flush, straight, four, three, pairs;

int read_cards(void);
void analyze_cards(void);
void print_result(void);

int main() {
    if(read_cards() != 1){
        analyze_cards();
        print_result();
    }
    return 0;
}

/*****************************************************
 * Reads the cards into global variables num_in_rank
 * and num_in_suit. It also checks for invalid cards.
 *****************************************************/ 
int read_cards(void) {
    int cards_read = 0;
    int rank, suit;
    char rank_ch, suit_ch;
    int rank_ch_evaluator = 0,suit_ch_evaluator = 0,card_evaluator_rank = 0,card_evaluator_suit = 0,repeated_accumulator = 0;
    int card_rank[5];
    int card_suit[5];
    char cards_rank[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
    char cards_suits[] = {'c','d','h','s'};

    for (int i=0; i<NUM_RANKS; i++)
        num_in_rank[i] = 0;

    for (int i=0; i<NUM_SUITS; i++)
        num_in_suit[i] = 0;

    for (int i=0; i<5; i++){
        card_rank[i] = 20 ;
    }

    for (int i=0; i<5; i++){
        card_suit[i] = 20 ;
    }

    while (cards_read < NUM_CARDS) {
    
        printf("Digite uma carta: ");
        rank_ch_evaluator = 0;
        suit_ch_evaluator = 0;

        rank_ch = getchar();
        switch (rank_ch) {
            case '2': rank=0; break;
            case '3': rank=1; break;
            case '4': rank=2; break;
            case '5': rank=3; break;
            case '6': rank=4; break;
            case '7': rank=5; break;
            case '8': rank=6; break;
            case '9': rank=7; break;
            case 't': rank=8; break;
            case 'j': rank=9; break;
            case 'q': rank=10; break;
            case 'k': rank=11; break;
            case 'a': rank=12; break;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': suit=0; break;
            case 'd': suit=1; break;
            case 'h': suit=2; break;
            case 's': suit=3; break;
        }

        getchar(); // get the \n character

        // checking if it is invalid

        for(int i = 0;i < NUM_RANKS;i++){
            if(rank_ch != cards_rank[i]){
                rank_ch_evaluator++;
            }
        }
        for(int i = 0;i < NUM_SUITS;i++){
            if(suit_ch != cards_suits[i]){
                suit_ch_evaluator++;
            }
        }
        if (rank_ch_evaluator == NUM_RANKS || suit_ch_evaluator == NUM_SUITS){
            printf("A carta digitada é inválida");
            return 1;
        }
 
        //checking whether it is repeated

        for(int i=0;i < 5;i++){
            if (card_rank[i] == rank && card_suit[i] == suit){
                printf("A carta digitada é repetida");         
                return 1;
            }
            
        }
        card_rank[repeated_accumulator] = rank;
        card_suit[repeated_accumulator] = suit;
        repeated_accumulator++;
        num_in_rank[rank]++;
        num_in_suit[suit]++;
        cards_read++;
    }
}


/********************************************************
 * Determines if the hand contains um straight, a flush,
 * four-of-a-kind, three-of-a-kind, and how many pairs.
 ********************************************************/ 
void analyze_cards(void) {
    int rank;
    int num_consec = 0;
    flush = 0;
    straight = 0;
    four = 0;
    three = 0;
    pairs = 0;

    // check for flush
    for (int i=0; i<NUM_SUITS; i++) {
        if (num_in_suit[i] == NUM_CARDS)
            flush = 1;
    }

    // check for straight
    rank = 0;
    while (num_in_rank[rank] == 0)
        rank++;

    for (; rank<NUM_RANKS && num_in_rank[rank]>0; rank++)
        num_consec++;

    if (num_consec == NUM_CARDS) {
        straight = 1;
        return;
    }

    for (int i=0; i<NUM_RANKS; i++) {
        if (num_in_rank[i] == 4) four = 1;
        if (num_in_rank[i] == 3) three = 1;
        if (num_in_rank[i] == 2) pairs++;
    }
}

void print_result(void) {
    if (straight && flush)
        printf("Straight Flush");
    else if (four)
        printf("Four of a kind");
    else if (three && pairs == 1)
        printf("Full house");
    else if (flush)
        printf("Flush");
    else if (straight)
        printf("Straight");
    else if (three)
        printf("Three of a kind");
    else if (pairs == 2)
        printf("Dois pares");
    else if (pairs == 1)
        printf("Pares");
    else
        printf("Carta mais alta");
}