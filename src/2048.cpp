#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int MAX_SIZE = 10;
const int gridSize = 4;
int board[MAX_SIZE][MAX_SIZE];
int prevBoard[MAX_SIZE][MAX_SIZE];
int score = 0;
int highscore = 0;

void menu();

void copyBoard(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE])
{
    for(int i = 0; i<gridSize; i++)
    {
        for(int j = 0; j<gridSize; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void addRandomTile()
{
    int emptyTiles[MAX_SIZE * MAX_SIZE][2];
    int emptyCount = 0;
    
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            if (board[i][j] == 0)
            {
                emptyTiles[emptyCount][0] = i;
                emptyTiles[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }
    
    if (emptyCount > 0)
    {
        int i = rand() % emptyCount;
        int v;
        
        if (rand() % 10 == 0)
        {
            v = 4;
        }
        else
        {
            v= 2;
        }
        board[emptyTiles[i][0]][emptyTiles[i][1]] = v;
    }
}

void initializeBoard()
{
    for(int i = 0; i<gridSize; i++)
    {
        for(int j = 0; j<gridSize; j++)
        {
            board[i][j] = 0;
        }
    }
    
    copyBoard(prevBoard, board);
    addRandomTile();
    addRandomTile();
}

void printBoard()
{
    //  system("cls")
    system("clear");
    
    cout << "Score: " << score << endl;
    cout << "High Score: " << highscore << endl;
    cout << endl;
    
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (board[i][j] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool moveLeft()
{
    copyBoard(prevBoard, board);
    
    bool moved = false;
    
    for (int i = 0; i < gridSize; i++)
    {
        int pos = 0;
        for (int j = 0; j < gridSize; j++)
        {
            if (board[i][j] != 0)
            {
                if (pos > 0 && board[i][pos - 1] == board[i][j])
                {
                    board[i][pos - 1] *= 2;
                    score += board[i][pos - 1];
                    board[i][j] = 0;
                    moved = true;
                }
                
                else if (pos != j)
                {
                    board[i][pos] = board[i][j];
                    board[i][j] = 0;
                    moved = true;
                }
                pos++;
            }
        }
    }
    return moved;
}

bool moveRight()
{
    copyBoard(prevBoard, board);
    bool moved = false;
    
    for (int i = 0; i < gridSize; i++)
    {
        int pos = gridSize - 1;
        for (int j = gridSize - 1; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                if (pos < gridSize - 1 && board[i][pos + 1] == board[i][j])
                {
                    board[i][pos + 1] *= 2;
                    score += board[i][pos + 1];
                    board[i][j] = 0;
                    moved = true;
                }
                
                else if (pos != j)
                {
                    board[i][pos] = board[i][j];
                    board[i][j] = 0;
                    moved = true;
                }
                pos--;
            }
        }
    }
    return moved;
}

bool moveUp()
{
    copyBoard(prevBoard, board);
    bool moved = false;
    
    for (int j = 0; j < gridSize; j++)
    {
        int pos = 0;
        for (int i = 0; i < gridSize; i++)
        {
            if (board[i][j] != 0)
            {
                if (pos > 0 && board[pos - 1][j] == board[i][j])
                {
                    board[pos - 1][j] *= 2;
                    score += board[pos - 1][j];
                    board[i][j] = 0;
                    moved = true;
                }
                else if (pos != i)
                {
                    board[pos][j] = board[i][j];
                    board[i][j] = 0;
                    moved = true;
                }
                pos++;
            }
        }
    }
    return moved;
}

bool moveDown()
{
    copyBoard(prevBoard, board);
    bool moved = false;
    
    for (int j = 0; j < gridSize; j++){
        int pos = gridSize - 1;
        for (int i = gridSize - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                if (pos < gridSize - 1 && board[pos + 1][j] == board[i][j])
                {
                    board[pos + 1][j] *= 2;
                    score += board[pos + 1][j];
                    board[i][j] = 0;
                    moved = true;
                }
                else if (pos != i)
                {
                    board[pos][j] = board[i][j];
                    board[i][j] = 0;
                    moved = true;
                }
                pos--;
            }
        }
    }
    return moved;
}

bool canMove()
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (board[i][j] == 0)
            {
                return true;
            }
            
            if (i > 0 && board[i][j] == board[i - 1][j])
            {
                return true;
            }
            
            if (j > 0 && board[i][j] == board[i][j - 1])
            {
                return true;
            }
        }
    }
    return false;
}

void restartGame()
{
    score = 0;
    initializeBoard();
}

void saveHighScore()
{
    if (score > highscore)
    {
        highscore = score;
        ofstream outFile("highscore.txt");
        outFile << highscore;
        outFile.close();
    }
}

void loadHighScore()
{
    ifstream inFile("highscore.txt");
    
    if (inFile.is_open())
    {
        inFile >> highscore;
    }
    
    else
    {
        cout << "No highscore yet" << endl;
    }
    inFile.close();
}

bool isGameOver()
{
    if (canMove())
    {
        return false;
    }
    
    saveHighScore();
    
    cout << "Game Over" << endl;
    cout << "Final Score: " << score << endl;
    
    char choice;
    while (true)
    {
        cout << "Do you want to restart? (Y/N): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (choice == 'y' || choice == 'Y')
        {
            restartGame();
            return false;
        }
        
        else if (choice == 'n' || choice == 'N')
        {
            exit(0);
        }
        
        else
        {
            cout << "Enter 'Y' or 'N' only" << endl;
        }
    }
}

void undo()
{
    copyBoard(prevBoard, board);
    score = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            score += board[i][j];
        }
    }
    cout << "Undo done" << endl;
}

void menu()
{
    while (true)
    {
        printBoard();
        char choice;
        cout << "Options:" << endl;
        cout << "W: Move Up, S: Move Down, A: Move Left, D: Move Right" << endl;
        cout << "U: Undo, R: Restart, Q: Quit" << endl;
        cin >> choice;
        
        bool moved = false;
        
        switch (toupper(choice))
        {
            case 'W':
                moved = moveUp();
                break;
            case 'S':
                moved = moveDown();
                break;
            case 'A':
                moved = moveLeft();
                break;
            case 'D':
                moved = moveRight();
                break;
            case 'U':
                undo();
                break;
            case 'R':
                restartGame();
                break;
            case 'Q':
                saveHighScore();
                exit(0);
                break;
            default:
                cout << "Invalid option, try again" << endl;
        }
        
        if (moved)
        {
            addRandomTile();
            if (isGameOver())
            {
                return;
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // srand(time(0));
    
    loadHighScore();
    initializeBoard();
    menu();
    
    return 0;
}
