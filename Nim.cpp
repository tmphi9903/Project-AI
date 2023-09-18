#include <iostream>
#include <cstdlib>
using namespace std; 

#define HUMAN 1 
#define COMPUTER 2 

struct move 
{ 
    int pile_index; 
    int stones_removed; 
}; 
  
void showPiles (int piles[], int n) 
{ 
    int i; 
    cout <<"Game bat dau tu -> "; 
    for (i=0; i<n; i++)  cout << " " << piles[i]; 
    cout <<"\n"; 
    return; 
} 
bool gameOver(int piles[], int n) 
{ 
    int i; 
    for (i=0; i<n; i++) 
        if (piles[i]!=0) return (false); 
    return (true); 
} 
void declareWinner(int whoseTurn) 
{ 
    if (whoseTurn == COMPUTER) cout <<"\nHUMAN Win\n\n"; 
    else cout <<"\nCOMPUTER Win\n\n"; 
    return; 
} 
int calculateNimSum(int piles[], int n) 
{ 
    int i, nimsum = piles[0]; 
    for (i=1; i<n; i++) nimsum = nimsum ^ piles[i]; 
    return(nimsum); 
} 
void makeMove(int piles[], int n, struct move * moves) 
{ 
    int i, nim_sum = calculateNimSum(piles, n); 
    if (nim_sum != 0) 
    { 
        for (i=0; i<n; i++) 
        { 
            if ((piles[i] ^ nim_sum) < piles[i]) 
            { 
                (*moves).pile_index = i; 
                (*moves).stones_removed = piles[i]-(piles[i]^nim_sum); 
                piles[i] = (piles[i] ^ nim_sum); 
                break; 
            } 
        } 
    } 
    else
    { 
        int non_zero_indices[n], count; 
        for (i=0, count=0; i<n; i++) 
            if (piles[i] > 0) non_zero_indices [count++] = i; 
		(*moves).pile_index = (std::rand() % (count));
		(*moves).stones_removed = 1 + (std::rand() % (piles[(*moves).pile_index]));
        piles[(*moves).pile_index] = 
        piles[(*moves).pile_index] - (*moves).stones_removed; 
        if (piles[(*moves).pile_index] < 0) piles[(*moves).pile_index]=0; 
    } 
    return; 
} 
void playGame(int piles[], int n, int whoseTurn) 
{ 
    cout <<"\nGAME STARTS\n\n"; 
    struct move moves; 
    while (gameOver (piles, n) == false) 
    { 
        showPiles(piles, n); 
        makeMove(piles, n, &moves); 
        if (whoseTurn == COMPUTER) 
        { 
            cout <<"COMPUTER loai bo " << moves.stones_removed << " da, so da con lai la:  "  << moves.pile_index << endl; 
            whoseTurn = HUMAN; 
        } 
        else
        { 
            cout <<"HUMAN loai bo "<< moves.stones_removed << " da, so da con lai la: " << moves.pile_index << endl; 
            whoseTurn = COMPUTER; 
        } 
    } 
    showPiles(piles, n); 
    declareWinner(whoseTurn); 
    return; 
} 

int main() 
{ 
    int piles[] = {4, 6, 9}; 
    int n = sizeof(piles)/sizeof(piles[0]); 
    playGame(piles, n, COMPUTER);
    return(0); 
}

