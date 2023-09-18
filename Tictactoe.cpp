#include <bits/stdc++.h>
using namespace std;

int Initialize(char[], const int);
int OuputGameBoard(char[], const int);
int InputMove(int, char[], int);
int validateMove(int, char[], int);
int InsertGamePiece(int, char[], int, const int);
int IsspaceOccupied(char[], int);
int winCondition(char[], char);
int drawCondition(char[], const int);
int playAgain(void);
int main(void)
{
    char GameBoard[] = {'0','0','0','0','0','0','0','0','0'};
    int    iIndex = 0, iSwitch = 0, iGameOver = 0, i_IndexPosition=0;
    Initialize(GameBoard, 9);
    while(iGameOver==0)
    {
        iIndex = InputMove(iSwitch, GameBoard, i_IndexPosition);
        iGameOver = InsertGamePiece(iSwitch, GameBoard, iIndex, 9);
        OuputGameBoard(GameBoard, 9);
        iSwitch = iSwitch + 1;
        if (iSwitch==2)  iSwitch = 0;
        if (iGameOver==1)  iGameOver = playAgain();
        if (iGameOver==2)
        {
            iIndex = 0;
            iSwitch = 0;
            iGameOver=0;
            Initialize(GameBoard, 9);
        }   
    }
    return 0;
}
int Initialize(char cGameBoard[], const int iMaxNumberOfSpaces)
{
    int iReturnValue = 0;
    for (int iIndex=0;iIndex<iMaxNumberOfSpaces;iIndex++)
    {
        cGameBoard[iIndex] = char(49+iIndex);
    }
    return iReturnValue;
}
int OuputGameBoard(char cGameBoard[], const int iMaxNumberOfSpaces)
{
    int iReturnValue = 0;
    cout << "     |     |     " << endl;
    cout << "  " << cGameBoard[0] << "  |  " << cGameBoard[1] << "  |  " << cGameBoard[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << cGameBoard[3] << "  |  " << cGameBoard[4] << "  |  " << cGameBoard[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << cGameBoard[6] << "  |  " << cGameBoard[7] << "  |  " << cGameBoard[8] << endl;
    cout << "     |     |     " << endl << endl;
    return iReturnValue;
}
int InputMove(int iSwitch, char c_GameBoard[], int i_IndexPosition)
{
    string sBuffer; 
    int iReturnValue = 0;
    while (iReturnValue==0)
    {
        if (iSwitch==0)
        {
            cout << "Hay nhap nuoc di: " << endl;
            getline(cin, sBuffer);
            istringstream buffer(sBuffer);
            buffer >> iReturnValue;
        }
        else iReturnValue = 0;
        if (iSwitch==1)  iReturnValue = rand() % 9;
        iReturnValue = validateMove(iReturnValue, c_GameBoard, i_IndexPosition);
        
    }
    iReturnValue = iReturnValue - 1;
    return iReturnValue;
}
int validateMove(int entryNumber, char c_GameBoard[], int i_IndexPosition)
{
    int iReturnVaue = 0;
    if ((entryNumber>=1) && (entryNumber<=9))  iReturnVaue = entryNumber;
    if(IsspaceOccupied(c_GameBoard, i_IndexPosition)==0) cout << "Tro choi dang cap nhat" << endl;
    else cout << "Tro choi dang cap nhat" << endl;
    return iReturnVaue;
}
int InsertGamePiece(int iPlayerNumber, char c_GameBoard[], int i_IndexPosition, const int i_MaxNumberOfSpaces)
{    
    int iReturnValue = 0;
    int iWinCondtionTest = 0;
    int idrawConditionTest = 0;
    char cGamePiece = NULL;
    string sPlayerType = "NOTHING";
    if(iPlayerNumber==0)
        cGamePiece ='X';
    if(iPlayerNumber==1)
        cGamePiece ='O';
    if (IsspaceOccupied(c_GameBoard, i_IndexPosition)==0)
    {
        if (cGamePiece!=NULL)  c_GameBoard[i_IndexPosition] = cGamePiece;
    }
    else
    {
        if (iPlayerNumber==1)
        { 
            for (int iIndex=0;iIndex<i_MaxNumberOfSpaces;iIndex++)
            {
                if(IsspaceOccupied(c_GameBoard, iIndex)==0)
                {
                    c_GameBoard[iIndex]=cGamePiece;
                    iIndex=i_MaxNumberOfSpaces;
                }   
            }    
        }    
    }
    iWinCondtionTest = winCondition(c_GameBoard, cGamePiece);
    idrawConditionTest = drawCondition(c_GameBoard, i_MaxNumberOfSpaces);
    if (iWinCondtionTest==1)
    {
        if (iPlayerNumber==0)   sPlayerType = "Human";
        if (iPlayerNumber==1)   sPlayerType = "Computer";
        cout <<  sPlayerType << " wins!!!" << endl;
    }
    if (idrawConditionTest==1)   cout << "Draw" << endl;
    if ((iWinCondtionTest==1) || (idrawConditionTest==1))
    {
        cout << "Game Over" << endl;
        iReturnValue = 1;
    }
    return iReturnValue;    
}
int IsspaceOccupied(char c_GameBoard[], int i_IndexPosition)
{    
    int iReturnValue = 0;
    int iAsciiValue  = 0;
    iAsciiValue = (int) c_GameBoard[i_IndexPosition];
    if ((iAsciiValue>=49) && (iAsciiValue<=57)) iReturnValue = 0;
    else iReturnValue = 1;
    return iReturnValue;    
}
int winCondition(char c_GameBoard[], char c_GamePiece)
{
    int iReturnValue = 0;
    
    if ((c_GameBoard[0]==c_GamePiece) && (c_GameBoard[1]==c_GamePiece) && (c_GameBoard[2]==c_GamePiece))
        iReturnValue=1;
    if ((c_GameBoard[3]==c_GamePiece) && (c_GameBoard[4]==c_GamePiece) && (c_GameBoard[5]==c_GamePiece))
        iReturnValue=1;
    if ((c_GameBoard[6]==c_GamePiece) && (c_GameBoard[7]==c_GamePiece) && (c_GameBoard[8]==c_GamePiece))
        iReturnValue=1;
    
    if ((c_GameBoard[0]==c_GamePiece) && (c_GameBoard[3]==c_GamePiece) && (c_GameBoard[6]==c_GamePiece))
        iReturnValue=1;
    if ((c_GameBoard[1]==c_GamePiece) && (c_GameBoard[4]==c_GamePiece) && (c_GameBoard[7]==c_GamePiece))
        iReturnValue=1;
    if ((c_GameBoard[2]==c_GamePiece) && (c_GameBoard[5]==c_GamePiece) && (c_GameBoard[8]==c_GamePiece))
        iReturnValue=1;
    
    if ((c_GameBoard[0]==c_GamePiece) && (c_GameBoard[4]==c_GamePiece) && (c_GameBoard[8]==c_GamePiece))
        iReturnValue=1;
    if ((c_GameBoard[2]==c_GamePiece) && (c_GameBoard[4]==c_GamePiece) && (c_GameBoard[6]==c_GamePiece))
        iReturnValue=1;
    return iReturnValue;
}
int drawCondition(char c_GameBoard[], const int iMaxNumberOfSpaces)
{
    int iCounter    = 0;
    int iAsciiValue = 0;
    int iReturnValue = 0;
    for (int iIndex=0;iIndex<iMaxNumberOfSpaces;iIndex++)
    {
        iAsciiValue = (int) c_GameBoard[iIndex];
        if ((iAsciiValue<49) || (iAsciiValue>57))
            iCounter = iCounter + 1;
    }
    if (iCounter==iMaxNumberOfSpaces)
    {
        cout << "Tat ca khong gian da duoc su dung" << endl;
        iReturnValue = 1;
    }
    return iReturnValue;
}
int playAgain(void)
{
    int iReturnValue = -1;
    char cCharacter = NULL;
    while(iReturnValue==-1)
    {
        cout << "Ban muon choi lai khong? Y/N";
        cCharacter = getchar();
        if (cCharacter=='y') cCharacter = 'Y';
        if (cCharacter=='n') cCharacter = 'N';
        if (cCharacter=='N') iReturnValue = 1;
        if (cCharacter=='Y') iReturnValue = 2;
        if ((cCharacter!='N') && (cCharacter!='Y'))   cout << "Error";
    } 
    return iReturnValue; 
}

