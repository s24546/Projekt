#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>

int main()
{
    char board[25][25];
    char direction='g';
    int up, down, left, right;
    int sx, sy;
    int fx, fy;
    int lenght=2, hx[10000],hy[10000],amount=0;
    int key;
    std::cout << "Instrukcja:" <<"\n";
    std::cout <<"Jedzenie symbolizuje x"<<"\n";
    std::cout <<"GORA:"<<"\n"<<"strzalka w gore" <<"\n";
    std::cout <<"DOL:"<<"\n"<<"strzalka w dol"<<"\n";
    std::cout <<"LEWO:"<<"\n"<<"strzalka w lewo"<<"\n";
    std::cout <<"PRAWO:"<<"\n"<<"strzalka w prawo"<<"\n"<<"Aby rozpoczac wcisnij strzalke do gory dwa razy";


    up=getch();
    up=224+72;
    down=getch();
    down=224+80;
    left=getch();
    left=224+75;
    right=getch();
    right=224+77;


    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            board[j][i]='p';
        }
    }
    sx=12;
    sy=13;
    srand(time(NULL));
    do
    {
        fx=rand()%25;
        fy=rand()%25;
    }
    while (board[fx][fx]!='p' && board[fx][fx]!='w' && board[fx][fx]!='g');

    board[fx][fy]='j';

    while(1)
    {
        amount++;

        hx[amount]=sx;
        hy[amount]=sy;

        system("cls");

        board[sx][sy]='g';
        for(int i=0; i<=25; i++)
        {
            std::cout<<" *";
        }
        for(int i=0; i<25; i++)
        {
            std::cout<<"\n"<<"*";
            for(int j=0; j<25; j++)
            {
                if (board[j][i]=='p')
                {
                    std::cout<<"  ";
                }
                if (board[j][i]=='w')
                {
                    std::cout<<" #";
                }
                if (board[j][i]=='j')
                {
                    std::cout<<" x";
                }
                if (board[j][i]=='g')
                {
                    std::cout<<" @";
                }

            }

            std::cout<<"*";

        }
        board[sx][sy]='w';
        std::cout<<"\n";
        for(int i=0; i<=25; i++)
        {
            std::cout<<" *";
        }


        Sleep(300);

        if(kbhit())

        {
            key=getch();
            if(key==224)key+=getch();
            if(key==up) direction='g';
            if(key==down) direction='d';
            if(key==left) direction='l';
            if(key==right) direction='p';
        }



        if(direction=='d') sy++;
        if(direction=='g') sy--;
        if(direction=='l') sx--;
        if(direction=='p') sx++;

        if(board[sx][sy]=='j')
        {
            lenght++;
            do
            {
                fx=rand()%25;
                fy=rand()%25;
            }
            while (board[fx][fx]!='p' && board[fx][fx]!='w' && board[fx][fx]!='g');

            board[fx][fy]='j';
        }
        else
        {
            board[hx[amount-lenght]][hy[amount-lenght]]='p';
        }


        if(sx==25)
        {
            std::cout <<"\n"<< "GAME OVER    wynik : " << lenght-2;
            break;
        }
        if(sx==-1)
        {
            std::cout <<"\n"<< "GAME OVER    wynik : " << lenght-2;
            break;
        }
        if(sy==25)
        {
            std::cout <<"\n"<< "GAME OVER    wynik : " << lenght-2;
            break;
        }
        if(sy==-1)
        {
            std::cout <<"\n"<< "GAME OVER    wynik : " << lenght-2;
            break;
        }
        if(board[sx][sy]=='w')
        {
            std::cout <<"\n"<< "GAME OVER    wynik : " << lenght-2;
            break;
        }


    }
    return 0;
}
