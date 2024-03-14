#include <stdio.h>
#include<Windows.h>
#include<conio.h>

void SetConsoleView()//실행창 가로 세로 정하기
{
    system("mode con:cols=60 lines=45"); //cols=가로 크기 lines=세로 크기
    system("title gallog");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}



    void main_character(int now_x,int now_y){//메인캐릭터 모습
        GotoXY(now_x, now_y);
        printf("   i0i   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   ###   ");

    }

    void enemy_character(int now_x,int now_y){//적군1 모습
        GotoXY(now_x, now_y-1);
        GotoXY(now_x, now_y);
        printf("   @@@   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   #0#   ");

    }

    void enemy_character2(int now_x,int now_y){//적군2 모습
        GotoXY(now_x, now_y);
        printf("   @@@   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   #0#   ");

    }

    void missile(int now_x,int now_y){//미사일 모습
        GotoXY(now_x, now_y);
        printf("|");
    }

int main(){
    SetConsoleView();

    int main_character_x=22;//메인캐릭터 나타나는 위치
    int main_character_y=35;

    int enemy_character_x=22;//적군1 나오는 위치
    int enemy_character_y=10;
    int enemy_life=1;

    int enemy_character2_x=22;//적군2 나오는 위치
    int enemy_character2_y=20;
    int enemy2_life=1;

    int missile_x=0;//미사일 설정
    int missile_y=0;
    int missile_move=0;


    int enemy_move=0;
    int enemy_move2=0;


    while(1){
        main_character(main_character_x,main_character_y);

        if(enemy_life==1){
                enemy_character(enemy_character_x,enemy_character_y);
        }

        if(enemy2_life==1){
                enemy_character(enemy_character2_x,enemy_character2_y);
        }


        if(missile_move==1){
            missile(missile_x,missile_y);
        }

        int key = GetKeyDown();

        if(key=='w' && main_character_y>=30){
            main_character_y--;
        }else if(key=='a' && main_character_x>=1){
            main_character_x--;
        }else if(key=='s' && main_character_y<=41){
            main_character_y++;
        }else if(key=='d' && main_character_x<=50){
            main_character_x++;
        }else if(key==32&&missile_move==0){
            missile_x=main_character_x+4;
            missile_y=main_character_y-1;
            missile_move=1;
        }
        if(missile_move==1){
            missile_y=missile_y-2;
        }
        if(missile_y<2){
           missile_move=0;
        }

        if(enemy_move==1){
            enemy_character_x--;
        }

        if(enemy_move==0){
            enemy_character_x++;
        }

        if(enemy_character_x==0){
            enemy_move=0;
            enemy_character_y=enemy_character_y+2;
        }

        if(enemy_character_x==50){
            enemy_move=1;
            enemy_character_y=enemy_character_y+2;
        }
//
        if(enemy_move2==1){
            enemy_character2_x++;

        }

        if(enemy_move2==0){
            enemy_character2_x--;

        }

        if(enemy_character2_x==50){
            enemy_move2=0;
            enemy_character2_y=enemy_character2_y+1;
        }

        if(enemy_character2_x==0){
            enemy_move2=1;
            enemy_character2_y=enemy_character2_y+1;
        }

        if(enemy_character2_y>=43){
            printf("lose");
            break;
        }

        if(enemy_character_y>=43){
            printf("lose");
            break;
        }

        if(main_character_x <= enemy_character_x && enemy_character_x <= main_character_x+8){
            if(main_character_y <= enemy_character_y && enemy_character_y <= main_character_y+2){
                    if(enemy_life=1){
                            printf("lose");
                            break;
                    }
         }
        }

        if(main_character_x <= enemy_character_x+8 && enemy_character_x+8 <= main_character_x+8){
            if(main_character_y <= enemy_character_y+2 && enemy_character_y+2 <= main_character_y+2){
                    if(enemy_life=1){
                            printf("lose");
                            break;
                    }
         }
        }

        if(main_character_x <= enemy_character2_x && enemy_character2_x <= main_character_x+8){
            if(main_character_y <= enemy_character2_y && enemy_character2_y <= main_character_y+2){
                    if(enemy2_life=1){
                            printf("lose");
                            break;
                    }
         }
        }

        if(main_character_x <= enemy_character2_x+8 && enemy_character2_x+8 <= main_character_x+8){
            if(main_character_y <= enemy_character2_y+2 && enemy_character2_y+2 <= main_character_y+2){
                    if(enemy2_life=1){
                            printf("lose");
                            break;
                    }
         }
        }

        if(enemy_character_x <= missile_x && missile_x <= enemy_character_x+9){
            if(enemy_character_y <= missile_y && missile_y <= enemy_character_y+3){
                    if(enemy_life){
                        enemy_life=0;
                        missile_move=0;
                    }
            }
        }

        if(enemy_character2_x <= missile_x && missile_x <= enemy_character2_x+9){
            if(enemy_character2_y <= missile_y && missile_y <= enemy_character2_y+3){
                    if(enemy2_life=0){
                        enemy2_life=0;
                        missile_move=0;
                    }
            }
        }

        if(enemy_life==0 && enemy2_life==0){
            printf("Win");
            break;
        }


        Sleep(20);
        system("cls");
    }


}
