#include <stdio.h>

typedef struct _Record
{
    int step;
    int from_x;
    int from_y;
} Record;

void maze_go(int M[5][5], Record record[5][5], int x, int y, int from_x, int from_y)
{
    if (record[from_x][from_y].step == 9999)
        record[from_x][from_y].step = 0;

    record[x][y].step = record[from_x][from_y].step + 1;
    record[x][y].from_x = from_x;
    record[x][y].from_y = from_y;

    printf("record[%d][%d] step = %d, from_x=%d, from_y=%d\n", x, y, record[from_x][from_y].step + 1, from_x, from_y);

    if (x-1 >=0 && M[x-1][y] == 0 && record[x][y].step + 1 < record[x-1][y].step)
        maze_go(M, record, x-1, y, x, y);

    if (y-1 >=0 && M[x][y-1] == 0 && record[x][y].step + 1 < record[x][y-1].step)
        maze_go(M, record, x, y-1, x, y);

    if (x+1 <5 && M[x+1][y] == 0 && record[x][y].step + 1 < record[x+1][y].step)
        maze_go(M, record, x+1, y, x, y);

    if (y+1<5 && M[x][y+1] == 0 && record[x][y].step + 1 < record[x][y+1].step)
        maze_go(M, record, x, y+1, x, y);
}


int main()
{
    Record record[5][5];
    for (int i=0;i<5;++i)
    {
        for (int j=0;j<5;++j)
        {
            record[i][j].step = 9999;
            record[i][j].from_x = -1;
            record[i][j].from_y = -1;
        }
    }

    int M[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
    };

    maze_go(M, record, 4, 4, 4, 4);


    int x=0,y=0;


    while (x != 4 || y != 4)
    {
        printf("(%d, %d) from (%d, %d)\n", x, y, record[x][y].from_x, record[x][y].from_y);

        int nx = record[x][y].from_x;
        int ny = record[x][y].from_y;

        x = nx;
        y = ny;
    }
}
