#include <stdio.h>
#include<Windows.h>
#include<conio.h>

void SetConsoleView()//����â ���� ���� ���ϱ�
{
    system("mode con:cols=60 lines=45"); //cols=���� ũ�� lines=���� ũ��
    system("title gallog");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}



    void main_character(int now_x,int now_y){//����ĳ���� ���
        GotoXY(now_x, now_y);
        printf("   i0i   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   ###   ");

    }

    void enemy_character(int now_x,int now_y){//����1 ���
        GotoXY(now_x, now_y-1);
        GotoXY(now_x, now_y);
        printf("   @@@   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   #0#   ");

    }

    void enemy_character2(int now_x,int now_y){//����2 ���
        GotoXY(now_x, now_y);
        printf("   @@@   ");
        GotoXY(now_x, now_y+1);
        printf("i-------i");
        GotoXY(now_x, now_y+2);
        printf("   #0#   ");

    }

    void missile(int now_x,int now_y){//�̻��� ���
        GotoXY(now_x, now_y);
        printf("|");
    }

int main(){
    SetConsoleView();

    int main_character_x=22;//����ĳ���� ��Ÿ���� ��ġ
    int main_character_y=35;

    int enemy_character_x=22;//����1 ������ ��ġ
    int enemy_character_y=10;
    int enemy_life=1;

    int enemy_character2_x=22;//����2 ������ ��ġ
    int enemy_character2_y=20;
    int enemy2_life=1;

    int missile_x=0;//�̻��� ����
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
