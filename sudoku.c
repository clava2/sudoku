#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Sudoku
{
   char main[9][9][9];                  //man body
    _Bool StaticNumber[9][9];                  //if the number at the position is static
}Sudoku;

_Bool ReadFromFile(Sudoku* sudoku,char* FileName)
{
    FILE* source = NULL;
    source = fopen(FileName,"r");
    if(source == NULL)
    {
        printf("failed in opening the file :%s",FileName);
        return false;
    }
    char c = ' ';
    for(int i = 0;i != 9; ++i)
    {
        for(int j = 0;j != 9; ++j)
        {
            while((c == ' ')||(c == '\n'))
            {
                c = fgetc(source);
            }
            sudoku->main[i][j][4] = c - '0';
            c = ' ';
            if(sudoku->main[i][j][4])
            {
                sudoku->StaticNumber[i][j] = true;
            }
        }
        printf("\n");
    }
    fclose(source);
}

void SetPuzzle(Sudoku* sudoku)
{
    int x = 0;                          //new x ordinary of static point;
    int y = 0;                          //new y ordinary of static point;
    int num = 0;                        //the static number
    while(1)
    {
        scanf("%d%d%d",&x,&y,&num);
        if((x>9)||(x <= 0))
        {
            printf("error: you input the false x ordinary!\n\n\n");
            break;
        }
        if((y > 9)||(y <= 0))
        {
            printf("error: you input the false y ordinary!\n\n\n");
            break;
        }
        if(num > 9)
        {
            printf("error: you input the false number!\n\n\n");
            break;
        }

        if(num <= 0)
        {
            printf("you quit the input process!\n\n\n");
            break;
        }

        sudoku->main[x-1][y-1][4] = num;
        sudoku->StaticNumber[x-1][y-1] = true;
        
        sudoku->main[x-1][y-1][0] = 0;
        sudoku->main[x-1][y-1][1] = 0;
        sudoku->main[x-1][y-1][2] = 0;
        sudoku->main[x-1][y-1][3] = 0;
        sudoku->main[x-1][y-1][5] = 0;
        sudoku->main[x-1][y-1][6] = 0;
        sudoku->main[x-1][y-1][7] = 0;
        sudoku->main[x-1][y-1][8] = 0;
        
        printf("(%d,%d) has been set as %d\n",x,y,num);
    }
}

void Print(Sudoku* sudoku)
{
    printf("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");
    printf("\n");
    for(int i = 0;i != 9;i++)
    {
        if((!((i)%3))&&i)
        {
            printf("┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫\n");
            printf("┃ ");
        }
        else if(i != 0)
        {
            printf("┠───┼───┼───╂───┼───┼───╂───┼───┼───┨\n");
            printf("┃ ");
        }
        else
        {
            printf("┃ ");
        }
        for(int j = 0;j != 9;j++)
        {
            if(sudoku->StaticNumber[i][j])
            {
                printf("%d",sudoku->main[i][j][4]);
            }
            else
            {
                printf(" ");
            }
            if((j+1)%3)
            {
                printf(" │ ");
            }
            else
            {
                printf(" ┃ ");
            }
        }
        printf("\n");
    }
    printf("┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛\n");
}

void PrintAll(Sudoku* sudoku)
{
    
    printf("┏━━━━━━━┯━━━━━━━┯━━━━━━━┳━━━━━━━┯━━━━━━━┯━━━━━━━┳━━━━━━━┯━━━━━━━┯━━━━━━━┓\n");
    for(int i = 0;i != 9;++i)
    {
        for(int k = 0;k != 3; ++k)
        {
            printf("┃");
            for(int j = 0; j != 9; ++j)
            {
                printf(" ");
                for(int l = 0;l != 3;++l)
                {
                    if(sudoku->main[i][j][3*k+l])
                    {
                        printf("%d ",sudoku->main[i][j][3*k+l]);
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                if(((j+1)%3))
                {
                    printf("│");
                }
                else
                {
                    printf("┃");
                }
            }
            printf("\n");
        }
        if((i != 8)&&((i+1)%3))
        {
            printf("┠───────┼───────┼───────╂───────┼───────┼───────╂───────┼───────┼───────┨");
            printf("\n");
        }
        else if(i != 8)
        {
            printf("┣━━━━━━━┿━━━━━━━┿━━━━━━━╋━━━━━━━┿━━━━━━━┿━━━━━━━╋━━━━━━━┿━━━━━━━┿━━━━━━━┫\n");
        }
    }

    printf("┗━━━━━━━┷━━━━━━━┷━━━━━━━┻━━━━━━━┷━━━━━━━┷━━━━━━━┻━━━━━━━┷━━━━━━━┷━━━━━━━┛");
    printf("\n");
}

_Bool CheckEnd(Sudoku* sudoku)
{
    for(int i = 0;i != 9; ++i)
    {
        for(int j = 0;j != 9; ++j)
        {
            if(!sudoku->StaticNumber[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void Init(Sudoku* sudoku)
{
    for(int i = 0;i != 9;i ++)
    {
        for(int j = 0;j != 9;j ++)
        {
            for(int k = 0;k != 9;k++)
            {
                sudoku->main[i][j][k] = 0;
            }
            sudoku->StaticNumber[i][j] = false;
        }
    }
}

_Bool Equal(char* array1,char* array2)
{
    _Bool result = true;
    for(int i = 0;i != 9; ++ i)
    {
        if(array1[i] != array2[i])
        {
            result = false;
        }
    }
    return result;
}

_Bool FindSame(Sudoku* sudoku,int state,int x_position,int y_position,_Bool* SamePosition,_Bool* NonZero)
{
    for(int i = 0;i != 9; ++i)
    {
        NonZero[i] = false;
        if(sudoku->main[x_position][y_position][i])
        {
            NonZero[i] = true;
        }
    }

    for(int i = 0;i != 9;++i)
    {
        SamePosition[i] = false;
    }
    switch(state)
    {
        case 1:
            SamePosition[y_position] = true;
            break;
        case 2:
            SamePosition[x_position] = true;
            break;
        case 3:
            SamePosition[x_position%3*3+y_position%3] = true;
            break;
    }

    switch(state)
    {
    case 1:
        {
            for(int i = 0;i != 9; ++i)
            {
                if(Equal(sudoku->main[x_position][y_position],sudoku->main[x_position][i]))
                {
                    SamePosition[i] = true;
                }
            }
            break;
        }
    case 2:
        {
            for(int i = 0;i != 9; ++i)
            {
                    for(int j = 0;j != 9; ++j)
                    {
                    }
                if(Equal(sudoku->main[x_position][y_position],sudoku->main[i][y_position]))
                {
                    SamePosition[i] = true;
                }
            }
            break;
        }
    case 3:
        {
            for(int i = (x_position)/3*3;i != (x_position)/3*3+3; ++i)
            {
                for(int j = (y_position)/3*3;j != (y_position)/3*3+3; ++j)
                {
                    //printf("i = %d,j = %d,\n",i,j);
                    if(Equal(sudoku->main[i][j],sudoku->main[x_position][y_position]))
                    {
                        //printf("%d,%d,%d,%d,\n",i,j,x_position,y_position);
                        SamePosition[(i%3)*3+j%3] = true;
                    }
                }
            }
            break;
        }
    }
    int SamePositionCount = 0;
    int NonZeroCount = 0;
    for(int i = 0;i != 9; ++i)
    {
        if(SamePosition[i])
        {
            SamePositionCount++;
        }
        if(NonZero[i])
        {
            NonZeroCount++;
        }
    }
    //for(int i = 0;i != 9;++i)
    //{
        //printf("\nNonZero[%d] = %d,same[%d] = %d\n",i,NonZero[i],i,SamePosition[i]);
    //}
    //printf("\n\nNonZeroCount = %d,SamePositionCount = %d\n\n",NonZeroCount,SamePositionCount);
    return (NonZeroCount == SamePositionCount);
}

void Clear(Sudoku* sudoku,int state,int x_position,int y_position,_Bool* same)
{
    switch(state)
    {
        case 1:
            {
                for(int i = 0;i != 9; ++i)
                {
                    if((!same[i])&&(!sudoku->StaticNumber[x_position][i]))
                    {
                        for(int j = 0;j !=9; ++j)
                        {
                            if(sudoku->main[x_position][y_position][j])
                            {
                                sudoku->main[x_position][i][sudoku->main[x_position][y_position][j]-1] = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            {
                for(int i = 0;i != 9;++i)
                {
                    if((!same[i])&&(!sudoku->StaticNumber[i][y_position]))
                    {
                        for(int j = 0;j !=9;++j)
                        {
                            if(sudoku->main[x_position][y_position][j])
                            {
                                sudoku->main[i][y_position][sudoku->main[x_position][y_position][j]-1] = 0;
                            }
                        }
                    }
                }
                break;
            }
        case 3:
            {
                for(int i = (x_position)/3*3;i != (x_position)/3*3+3;++i)
                {
                    for(int j = (y_position)/3*3;j != (y_position)/3*3+3;++j)
                    {
                        if((!same[(i%3)*3+j%3])&&(!sudoku->StaticNumber[i][j]))
                        {
                            for(int x = 0;x != 9;++x)
                            {
                                if(sudoku->main[x_position][y_position][x])
                                {
                                    sudoku->main[i][j][sudoku->main[x_position][y_position][x]-1] = 0;
                                }
                            }
                        }
                    }
                }
                break;
        }
     }
}

void ClearSome(Sudoku* sudoku)
{
    _Bool same[9];
    _Bool NonZero[9];
   
    for(int i = 0;i != 9;i++)
    {
        for(int j = 0;j != 9;++j)
        {
            //printf("\n\n\nx = %d,y = %d,mode = 1\n\n\n",i,j);
           if(FindSame(sudoku,1,i,j,same,NonZero))
           {
               //for(int i = 0;i != 9;++i)
               //{
                   //printf("%d ",same[i]);
               //}
               //printf("\n");
               Clear(sudoku,1,i,j,same);
           }
           //printf("\n\n\nx = %d,y = %d,mode = 2\n\n\n",i,j);
           if(FindSame(sudoku,2,i,j,same,NonZero))
           {

               //for(int i = 0;i != 9;++i)
               //{
                   //printf("%d ",same[i]);
               //}
               //printf("\n");
               Clear(sudoku,2,i,j,same);
               //PrintAll(sudoku);
           }
           //printf("\n\n\nx = %d,y = %d,mode = 3\n\n\n",i,j);
           if(FindSame(sudoku,3,i,j,same,NonZero))
           {
               //for(int i = 0;i != 9;++i)
               //{
                   //printf("%d ",same[i]);
               //}
               //printf("\n");
               Clear(sudoku,3,i,j,same);
               //PrintAll(sudoku);
               //printf("\n\n");
           }
        }
    }
}

void FindAllPosibility(Sudoku* sudoku)
{
    for(int i = 0;i != 9;i++)
    {
        for(int j = 0;j != 9;j++)
        {
            if(sudoku->StaticNumber[i][j])
            {
                continue;
            }
            int row[9] = {1,2,3,4,5,6,7,8,9};
            for(int x = 0;x != 9;x++)
            {
                if(sudoku->StaticNumber[x][j])
                {
                    row[sudoku->main[x][j][4]-1] = 0;
                }
                if(sudoku->StaticNumber[i][x])
                {
                    row[sudoku->main[i][x][4]-1] = 0;
                }
            }
            for(int x = i/3*3;x != i/3*3+3;x++)
            {
                for(int y = j/3*3; y != j/3*3+3;y++)
                {
                    if(sudoku->StaticNumber[x][y])
                    {
                        row[sudoku->main[x][y][4]-1] = 0;
                    }
                }
            }
            for(int x = 0;x != 9; ++x)
            {
                {
                    sudoku->main[i][j][x] = row[x];
                }
            }
        }
    }
}

void SetStatic(Sudoku* sudoku)
{
    for(int i = 0;i != 9; ++i)
    {
        for(int x = 0; x != 9;++x)
        {
            int count = 0;
            int position = 0;
            for(int y = 0; y != 9; ++y)
            {
                if(sudoku->main[i][y][x])
                {
                    position = y;
                    ++count;
                }
            }
            if(count == 1)
            {
                int value = sudoku->main[i][position][x];
                for(int y = 0; y != 9;++y)
                {
                    sudoku->main[i][position][y] = 0;
                }
                sudoku->main[i][position][4] = value;
                sudoku->StaticNumber[i][position] = true;
            }
        }
        for(int x = 0; x != 9;++x)
        {
            int count = 0;
            int position = 0;
            for(int y = 0;y != 9;++y)
            {
                if(!sudoku->StaticNumber[y][i])
                {
                    break;
                }
                if(sudoku->main[y][i][x])
                {
                    ++count;
                    position = y;
                }
            }
            if(count == 1)
            {
                char value = sudoku->main[position][i][x];
                for(int y = 0;y != 9; ++y)
                {
                    sudoku->main[position][i][y] = 0;
                }
                sudoku->main[position][i][4] = value;
                sudoku->StaticNumber[position][i] = true;
            }
        }
        for(int x = 0;x != 9; ++x)
        {
            int count = 0;
            int x_position = 0;
            int y_position = 0;
            for(int j = i/3*3; j != i/3*3+3; ++j)
            {
                for(int y = 0; y != 3; ++y)
                {
                    if(sudoku->main[j][y][x])
                    {
                        x_position = j;
                        y_position = y;
                        ++count;
                    }
                }
            }
            if(count == 1)
            {
                int value = sudoku->main[x_position][y_position][x];
                sudoku->main[x_position][y_position][4] = value;
                sudoku->StaticNumber[x_position][y_position] = true;
            }
        }
    }
    for(int i = 0;i != 9; ++i)
    {
        for(int j = 0;j != 9; ++j)
        {
            int count = 0;
            int position = 0;
            for(int x = 0; x != 9;++x)
            {
                if(sudoku->main[i][j][x])
                {
                    ++count;
                    position = x;
                }
            }
            if((count == 1)&&(!sudoku->StaticNumber[i][j]))
            {
                sudoku->StaticNumber[i][j] = true;
                sudoku->main[i][j][4] = sudoku->main[i][j][position];
                if(position != 4)
                {
                    sudoku->main[i][j][position] = 0;
                }
            }
        }
    }
}


void Menu(Sudoku* sudoku)
{
    system("clear");
    printf("*****************************************************\n");
    printf("*                  Sudoku World                     *\n");
    printf("*****************************************************\n");
    printf("\n\n\n");
    printf("*****************************************************\n");
    printf("*****************************************************\n");
    printf("*    1.set puzzle                                   *\n");
    printf("*    2.read puzzle from file                        *\n");
    printf("*    3.help                                         *\n");
    printf("*    4.exit                                         *\n");
    printf("*****************************************************\n");
    printf("*****************************************************\n\n\n");
    int select = 0;
    scanf("%d",&select);
    switch(select)
    {
        case 1:
            {
                system("clear");
                SetPuzzle(sudoku);
                break;
            }
        case 2:
            {
                system("clear");
                printf("intput the file name:\n");
                char filename[20];
                scanf("%s",filename);
                ReadFromFile(sudoku,filename);
                break;
            }
        case 3:
            {
                system("clear");
                printf("1.this program is used to solve the sudoku!\n");
                printf("2.this program is still in debug,some errors may happen when using it.Report to the author if possible!\n");
                printf("3.author: zhengcong!    ALL RIGHTS RESERVED!\n");
            }
            break;
    }
}

int main(int argc,char* argv[])
{
    Sudoku sudoku;
    Init(&sudoku);
    Menu(&sudoku);
    printf("\n\nafter reading the file:\n");
    Print(&sudoku);
    FindAllPosibility(&sudoku);
    printf("\n\nafter find all posibility:\n");
    PrintAll(&sudoku);
    SetStatic(&sudoku);
    //printf("\n\nafter set static first:\n");
    //PrintAll(&sudoku);
    
    int count = 0;
    while(!CheckEnd(&sudoku))
    {
        ClearSome(&sudoku);
        //printf("\n\nafter clear some element:\n");
        //PrintAll(&sudoku);
        SetStatic(&sudoku);
        //printf("\n\n after set static second:\n");
        //PrintAll(&sudoku);
        count ++;
        if(count >= 10000)
        {
            system("clear");
            printf("the sudoku is too dificulit!we cann't solve it!\n");
            break;
        }
    }
    printf("\n\nafter all!:\n");
    Print(&sudoku);
    PrintAll(&sudoku);
    return 0;
}
