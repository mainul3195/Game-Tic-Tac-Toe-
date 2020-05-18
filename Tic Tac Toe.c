#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void ready();
void set();
void go();
int getposition();
void calcrotate();
int put(int);
int out(int);
void aprint();
int wintest(int);
int drawtest();



char name[20];
int a[9],tmp[9];
char choice1,choice2;
int game,wp,p1,p2,i,j,mid,me=0,op=1,rotate,position,num,turn,move,y,count=0,c=1,d=0,k=0,temporary,start;
int s1,s2;

//void tmpprint()
//{
//    k=0;
//    for(i=0; i<3; i++)
//    {
//        printf("\t");
//        for(j=0; j<3; j++)
//        {
//            if(tmp[k]==3)
//                printf("     %c", "| "[j==2]);
//            else if(tmp[k]==0)
//                printf("  X  %c", "| "[j==2]);
//            else if(tmp[k]==1)
//                printf("  O  %c", "| "[j==2]);
//            k++;
//        }
//        if(i==0)
//            printf("\t|\tP-1 |P-2 |P-3\n\t_____|_____|_____\t|\t____|____|____\n");
//        else if(i==1)
//            printf("\t|\tP-4 |P-5 |P-6\n\t_____|_____|_____\t|\t____|____|____\n");
//        else if(i==2)
//            printf("\t|\tP-7 |P-8 |P-9\n\t     |     |     \t|\t    |    |    \n\n");
//    }
//}


int main()
{

    ready();
    go();
    printf("If you don't know what \"winning point\" means, Enter 0(zero) to see informal rules...\n");

    do
    {
        do
        {
            printf("Enter a winning point.(for quick play, I would recommend 3)...\n");
            scanf("%d", &wp);
            system("cls");
            if(wp==0)
                go();
        }
        while(wp==0);

        mid=1;
        printf("Okey %s, You have fixed %d as winning point\nEnter 1 if you want to play first, else enter 0...", name, wp);
        scanf("%d", &y);
        if(y==1)
            start = 2;
        else
            start = 1;
        s1=s2=0;
        while(s1!=wp && s2!=wp)
        {
            if(start==2)
            {
                start=1;
                move =2;
            }
            else
            {
                start=2;
                move = 1;
            }
            for(i=0; i<9; i++)
            {
                a[i]=tmp[i]=3;
            }
            turn=rotate=0;
            while(move!=3)
            {
                if(move==1)
                {
                    if(turn==0)
                    {
                        srand(time(0));
                        num=rand()%5;
                        if(num==4)
                        {
                            position= mid;
                            if(mid == 1)
                                rotate = 0;
                            else if(mid == 3)
                                rotate = 1;
                            else if(mid == 5)
                                rotate = 3;
                            else if(mid == 7)
                                rotate = 2;
                            mid = (mid+2)%8;
                        }
                        else
                        {
                            rotate = num;

                            if(num==0)
                                position = 0;
                            else if(num == 1)
                                position = 6;
                            else if(num == 2)
                                position = 8;
                            else if(num == 3)
                                position = 2;
                        }
                        a[position] = me;
                        tmp[put(position)] = me;
                        aprint();
                        //tmpprint();
                        printf("I have marked at position %d\n",position + 1);
                        move = 2;
                        turn=1;
                    }
                    else
                    {
                        getposition();
                        tmp[position]= me;
                        position = out(position);
                        a[position]= me;
                        aprint();
                        //tmpprint();
                        printf("\n%s, You marked at position %d\nI marked at position %d\n", name, temporary, position+1);
                        temporary = position +1;
                    }
                    if(wintest(me)==1)
                    {
                        s1++;
                        move = 3;
                        aprint();
                        //tmpprint();
                        printf("I have marked at position %d \n", temporary);
                        printf("\n%s, it seems you have lost the game!\n", name);
                        if(s1!=wp)
                        {
                            printf("Don't worry, You still have chance to win the match. After this game,\n");
                            printf("Your point is %d\nAnd Mainul's point is %d\nN.B. Winning point is %d\n", s2, s1, wp);
                            printf("Press any key for next game...");
                            getch();
                        }
                    }
                    else if(drawtest()==1)
                    {
                        move = 3;
                        aprint();
                        //tmpprint();
                        printf("Mainul marked at position %d and It's a draw\n",  temporary);
                        printf("Your point is %d\nAnd Mainul's point is %d\nN.B. Winning point is %d\n", s2, s1, wp);
                        printf("Press any key for next game...");
                        getch();
                    }
                    else
                        move = 2;
                }

                if(move==2)
                {
                    if(turn == 0)
                    {
                        aprint();
                        //tmpprint();
                        printf("%s, Your turn first. Enter your position:", name);
                        scanf("%d", &position);
                        temporary = position--;

                        if(position == 3 || position == 6)
                            rotate = 1;
                        else if(position == 5 || position == 2)
                            rotate = 3;
                        else if(position == 7 || position == 8)
                            rotate = 2;

                        a[position]=op;
                        tmp[put(position)]=op;

                        turn = 1;
                        move = 1;
                    }
                    else
                    {
                        printf("It's your turn %s, enter the position...", name);
                        scanf("%d", &position);
                        while(a[--position]!=3)
                        {
                            printf("Opps!! This space is pre-occupied. Try another...");
                            scanf("%d", &position);
                        }
                        temporary = position+1;
                        a[position]=op;
                        tmp[put(position)]=op;
                        if(wintest(op)==1)
                        {
                            move=3;
                            aprint();
                            //tmpprint();
                            s2++;
                            printf("You marked at position %d and bingo!! You have won the game!!\n", temporary);
                            if(s2!=wp)
                            {
                                printf("Your point is %d\nAnd Mainul's point is %d\nN.B. Winning point is %d\n", s2, s1, wp);
                                printf("Press any key for next game...");
                                getch();
                            }
                        }
                        else if(drawtest()==1)
                        {
                            move = 3;
                            aprint();
                            //tmpprint();
                            printf("You marked at position %d and It's a draw\n",  temporary);
                            printf("Your point is %d\nAnd Mainul's point is %d\nN.B. Winning point is %d\n", s2, s1, wp);
                            printf("Press any key for next game...");
                            getch();
                        }
                        else
                            move = 1;
                    }
                }
            }
        }

        printf("\nIf you want to play the game again enter 1, else 0...");
        scanf("%d", &game);
        system("cls");

    }
    while(game==1);
    printf("\n%s, Thank you very much for playing with me. Stay home, stay safe.\n\n\n\t\t\t\t\t____mAINUL", name);
    printf("\n\n\n\npress any key to terminate...");

    getch();

    return 0;
}
void aprint()
{
    system("cls");
        printf("\n");

    k=0;
    for(i=0; i<3; i++)
    {
        printf("\t");
        for(j=0; j<3; j++)
        {
            if(a[k]==3)
                printf("     %c", "| "[j==2]);
            else if(a[k]==0)
                printf("  X  %c", "| "[j==2]);
            else if(a[k]==1)
                printf("  O  %c", "| "[j==2]);
            k++;
        }
        if(i==0)
            printf("\t|\tP-1 |P-2 |P-3\n\t_____|_____|_____\t|\t____|____|____\n");
        else if(i==1)
            printf("\t|\tP-4 |P-5 |P-6\n\t_____|_____|_____\t|\t____|____|____\n");
        else if(i==2)
            printf("\t|\tP-7 |P-8 |P-9\n\t     |     |     \t|\t    |    |    \n\n");
    }
}
int drawtest()
{
    for(i=0; i<9; i++)
        if(a[i]==3)
            return 0;
    return 1;
}
int wintest(int x)
{
    if((a[0]==x&&a[1]==x&&a[2]==x)
            ||(a[3]==x&&a[4]==x&&a[5]==x)||(a[6]==x&&a[7]==x&&a[8]==x)||
            (a[0]==x&&a[3]==x&&a[6]==x)||(a[1]==x&&a[4]==x&&a[7]==x)||
            (a[2]==x&&a[5]==x&&a[8]==x)||(a[0]==x&&a[4]==x&&a[8]==x)||
            (a[2]==x&&a[4]==x&&a[6]==x))
    {
        return 1;
    }
    return 0;
}
int put(int number)
{
    switch(rotate)
    {
    case 0:
        return number;
    case 1:
        switch(number)
        {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 6;
        }
    case 2:
        switch(number)
        {
        case 0:
            return 8;
        case 1:
            return 7;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 0;
        }
    case 3:
        switch(number)
        {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 7;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 8;
        case 7:
            return 5;
        case 8:
            return 2;
        }
    }
}
int out(int number)
{
    switch(rotate)
    {
    case 0:
        return number;
    case 1:
        switch(number)
        {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 0;
        case 3:
            return 7;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 8;
        case 7:
            return 5;
        case 8:
            return 2;
        }
    case 2:
        switch(number)
        {
        case 0:
            return 8;
        case 1:
            return 7;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 0;
        }
    case 3:
        switch(number)
        {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 8;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 6;
        }
    }
}

void ready(void)
{
    printf("Please enter your nickname: ");
    scanf("%s", name);
    system("cls");
    printf("**********Welcome \"%s\" in TIC-TAC-TOE game with MAINUL**********\n\n\n", name);
    printf("You know the rules for sure. But formality is formality...");
    int a;
    printf("\nIf you don't know how to play(formal rules) enter 1, else 0\n");
    scanf("%d", &a);
    system("cls");
    if(a==1)
        set();
}

void go(void)
{

    printf("%s look, these informal rules are mandatory", name);
    printf("\n\n**Informal rules for this program:\nLook at the diagram bellow\n\n");
    printf("\tP-1 |P-2 |P-3\n");
    printf("\t____|____|____\n");
    printf("\tP-4 |P-5 |P-6\n");
    printf("\t____|____|____\n");
    printf("\tP-7 |P-8 |P-9\n");
    printf("\t    |    |    \n");
    printf("\nHere P-x simply means position x\n**While playing, you have to input just value of x for any move.\n");
    printf("\n# If any player wins a match he/she will score 1.\n");
    printf("# There will be a final score(winning point) set by you.\n");
    printf("# Player who will touch the final score(winning point) first will win the game.\n\n");
    printf("\nIf you have got this, press any key to continue...");
    getch();
    system("cls");
}

void set(void)
{
    printf("Okey %s, here is some guideline for you. Read carefully.\n", name);
    printf("**Formal Rules:\n# There will be a diagram like bellow.\n");
    printf("\t    |    |\n");
    printf("\t____|____|____\n");
    printf("\t    |    |\n");
    printf("\t____|____|____\n");
    printf("\t    |    |\n");
    printf("\t    |    |    \n");
    printf("# One player will enter X and other one will O.\n");
    printf("\t*Traditionally first player enters X & the second one enters O\n");
    printf("# If any player can match the diagram horizontally, vertically or by corner, he/she will win.\n");
    printf("# Here is some winning positions\n");
    printf(" X  |    |    \t O  |    |    \t    |    |    \t    | O  |    \n");
    printf("____|____|____\t____|____|____\t____|____|____\t____|____|____\n");
    printf("    | X  |    \t O  |    |    \t    |    |    \t    | O  |    \n");
    printf("____|____|____\t____|____|____\t____|____|____\t____|____|____\n");
    printf("    |    | X  \t O  |    |    \t X  | X  | X  \t    | O  |    \n");
    printf("    |    |    \t    |    |    \t    |    |    \t    |    |    \n\n\n");

    printf(" O  | O  | O  \t    | X  |    \t    |    | X  \t    |    | X  \n");
    printf("____|____|____\t____|____|____\t____|____|____\t____|____|____\n");
    printf("    |    |    \t    | X  |    \t    | X  |    \t    |    | X  \n");
    printf("____|____|____\t____|____|____\t____|____|____\t____|____|____\n");
    printf("    |    |    \t    | X  |    \t X  |    |    \t    |    | X  \n");
    printf("    |    |    \t    |    |    \t    |    |    \t    |    |    \n");
    printf("If you have got this, press any key to continue...");
    getch();
    system("cls");
}

int getposition()
{
    //my win
    if(tmp[0]==me && tmp[1]==me)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[1]==me && tmp[2]==me)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==me && tmp[2]==me)
    {
        if(tmp[1]==3)
        {
            position = 1;
            return position;
        }
    }

    if(tmp[3]==me && tmp[4]==me)
    {
        if(tmp[5]==3)
        {
            position = 5;
            return position;
        }
    }
    if(tmp[4]==me && tmp[5]==me)
    {
        if(tmp[3]==3)
        {
            position = 3;
            return position;
        }
    }
    if(tmp[3]==me && tmp[5]==me)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }

    if(tmp[6]==me && tmp[7]==me)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[7]==me && tmp[8]==me)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[6]==me && tmp[8]==me)
    {
        if(tmp[7]==3)
        {
            position = 7;
            return position;
        }
    }

    if(tmp[0]==me && tmp[3]==me)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[3]==me && tmp[6]==me)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==me && tmp[6]==me)
    {
        if(tmp[3]==3)
        {
            position = 3;
            return position;
        }
    }


    if(tmp[4]==me && tmp[1]==me)
    {
        if(tmp[7]==3)
        {
            position = 7;
            return position;
        }
    }
    if(tmp[1]==me && tmp[7]==me)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }
    if(tmp[4]==me && tmp[7]==me)
    {
        if(tmp[1]==3)
        {
            position = 1;
            return position;
        }
    }


    if(tmp[8]==me && tmp[5]==me)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[5]==me && tmp[2]==me)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[8]==me && tmp[2]==me)
    {
        if(tmp[5]==3)
        {
            position = 5;
            return position;
        }
    }


    if(tmp[0]==me && tmp[4]==me)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[4]==me && tmp[8]==me)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==me && tmp[8]==me)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }


    if(tmp[6]==me && tmp[4]==me)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[4]==me && tmp[2]==me)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[6]==me && tmp[2]==me)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }



//defence
    if(tmp[0]==op && tmp[1]==op)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[1]==op && tmp[2]==op)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==op && tmp[2]==op)
    {
        if(tmp[1]==3)
        {
            position = 1;
            return position;
        }
    }

    if(tmp[3]==op && tmp[4]==op)
    {
        if(tmp[5]==3)
        {
            position = 5;
            return position;
        }
    }
    if(tmp[4]==op && tmp[5]==op)
    {
        if(tmp[3]==3)
        {
            position = 3;
            return position;
        }
    }
    if(tmp[3]==op && tmp[5]==op)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }

    if(tmp[6]==op && tmp[7]==op)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[7]==op && tmp[8]==op)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[6]==op && tmp[8]==op)
    {
        if(tmp[7]==3)
        {
            position = 7;
            return position;
        }
    }

    if(tmp[0]==op && tmp[3]==op)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[3]==op && tmp[6]==op)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==op && tmp[6]==op)
    {
        if(tmp[3]==3)
        {
            position = 3;
            return position;
        }
    }


    if(tmp[4]==op && tmp[1]==op)
    {
        if(tmp[7]==3)
        {
            position = 7;
            return position;
        }
    }
    if(tmp[1]==op && tmp[7]==op)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }
    if(tmp[4]==op && tmp[7]==op)
    {
        if(tmp[1]==3)
        {
            position = 1;
            return position;
        }
    }


    if(tmp[8]==op && tmp[5]==op)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[5]==op && tmp[2]==op)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[8]==op && tmp[2]==op)
    {
        if(tmp[5]==3)
        {
            position = 5;
            return position;
        }
    }


    if(tmp[0]==op && tmp[4]==op)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[4]==op && tmp[8]==op)
    {
        if(tmp[0]==3)
        {
            position = 0;
            return position;
        }
    }
    if(tmp[0]==op && tmp[8]==op)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }


    if(tmp[6]==op && tmp[4]==op)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[4]==op && tmp[2]==op)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[6]==op && tmp[2]==op)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }

//center defence
    if(tmp[0]==3 && tmp[8]==3 && tmp[2] == 3 && tmp[6]==3 && tmp[4]==op &&tmp[5]==3 && tmp[7]== 3&& tmp[3]==3&& tmp[1]==3)
    {
        srand(time(0));
        position = rand()%4;
        return position;
    }

//draw defense
    if(tmp[0]==op && tmp[8]==3 && tmp[2] == 3 && tmp[6]==3 && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }
    if(tmp[0]==op && tmp[8]==op && tmp[2] == 3 && tmp[6]==3 && tmp[4]==me &&tmp[5]==3 && tmp[7]== 3&& tmp[3]==3&& tmp[1]==3)
    {
        srand(time(0));
        num=rand()%4;
        if(num==0)
        {
            position = 1;
            return position;
        }
        else if(num == 1)
        {
            position = 3;
            return position;
        }
        else if(num == 2)
        {
            position = 5;
            return position;
        }
        else
        {
            position = 7;
            return position;
        }
    }

//triangular attack tricks


    if(tmp[0]==me && tmp[2]==me && tmp[4]==3 &&tmp[5]==3)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[0]==me && tmp[2]==me && tmp[4]==3 &&tmp[3]==3)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[0]==me && tmp[6]==me && tmp[4]==3 &&tmp[7]==3)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    if(tmp[0]==me && tmp[6]==me && tmp[4]==3 &&tmp[1]==3)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }




//defence triks
    if(
        (tmp[0]==op && tmp[1]==3 &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==3&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==3)
        ||
        (tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==3&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==3)
    )
    {
        if(tmp[4]==3)
        {
            position = 4;
            return position;
        }
    }
    if((tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==me&& tmp[5]==3 &&tmp[6]==3&& tmp[7]==3 &&tmp[8]==op)
            ||
            (tmp[0]==3 && tmp[1]==op &&tmp[2]==3 && tmp[3]==3 &&tmp[4]==me&& tmp[5]==3 &&tmp[6]==op&& tmp[7]==3 &&tmp[8]==3))
    {
        if(tmp[3]==3)
        {
            position = 3;
            return position;
        }
    }



    //tricks super 7
    if(tmp[0]==me && (tmp[1]==op || tmp[2] == op)&& tmp[4]==3 &&tmp[5]==3 && tmp[7]==3 && tmp[8]==3 && tmp[3]==3)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[0]==me && (tmp[3]==op || tmp[6] == op)&& tmp[4]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[8]==3 && tmp[1]==3)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[0]==me && (tmp[5]==op || tmp[8] == op)&& tmp[7]==3 &&tmp[3]==3 && tmp[6]== 3&& tmp[4]==3 && tmp[1]==3)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[0]==me && tmp[7]==op && tmp[4]==3 &&tmp[5]==3 && tmp[3]== 3&& tmp[2]==3 && tmp[1]==3)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }

    //trick draw or win
    if(tmp[0]==me && tmp[4]==op && tmp[2] == op && tmp[8]==me && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[6]==3)
        {
            position = 6;
            return position;
        }
    }
    if(tmp[0]==me && tmp[4]==op && tmp[6] == op && tmp[8]==me && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[2]==3)
        {
            position = 2;
            return position;
        }
    }
    if(tmp[0]==me && tmp[4]==op && tmp[6] == 3 && tmp[2]==3 && tmp[3]==3 &&tmp[5]==3 && tmp[7]== 3&& tmp[1]==3)
    {
        if(tmp[8]==3)
        {
            position = 8;
            return position;
        }
    }
    else
        while(1)
        {
            srand(time(0));
            num=rand()%9;
            if(tmp[num]==3)
            {
                position = num;
                return position;
            }
        }
}
