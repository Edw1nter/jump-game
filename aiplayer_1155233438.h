#ifndef AI_PLAYER_1155233438_H
#define AI_PLAYER_1155233438_H
void change_1155233438(int a, int b, int graph[]);//改变棋盘位置
void print_1155233438(int graph[]);//打印棋牌
void find_1155233438(int row, int col, int valid[], int graph[]);//查找当前可移动位置
void set_1155233438(int v[], int graph[], int row, int col);
int hal_1155233438(int player, int graph[]);
int check_1155233438(int player, int num, int graph[]);//检测是否有效
int cal1_1155233438(int player, int graph[]);//计算出下棋后棋子期望最大值
int ai_player_1155233438(int player, const int* broad);
#endif