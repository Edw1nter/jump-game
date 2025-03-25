#include<stdio.h>
#include<string.h>
#include<math.h>
#include"aiplayer_1155233438.h"
int max, temp, cons;
int value[89], nowvalid[89];
void change_1155233438(int a, int b, int graph[])//改变棋盘位置
{
	int tmp = graph[a];
	graph[a] = graph[b];
	graph[b] = tmp;
	return;
}
void print_1155233438(int graph[])//打印棋牌
{
	printf("  1 2 3 4 5 6 7 8\n");
	for (int i = 1; i <= 8; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= 8; j++)
		{
			if (graph[i * 10 + j] == 1) printf("# ");
			else if (graph[i * 10 + j] == 2)printf("0 ");
			else printf(". ");
		}
		printf("\n");
	}
}
void find_1155233438(int row, int col, int valid[], int graph[])//查找当前可移动位置
{
	int tmp = graph[row * 10 + col];
	graph[row * 10 + col] = 0;
	for (int i = row + 1; i <= 8; i++)//向下找
	{
		if (graph[i * 10 + col])
		{
			if (2 * i - row > 8) break;
			int tagg = 1;
			for (int j = i + 1; j <= 2 * i - row; j++) if (graph[10 * j + col]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + col]) break;
			else
			{
				valid[(2 * i - row) * 10 + col] = 1;
				find_1155233438(2 * i - row, col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = row - 1; i >= 1; i--)//向上找
	{
		if (graph[i * 10 + col])
		{
			if (2 * i - row < 1) break;
			int tagg = 1;
			for (int j = i - 1; j >= 2 * i - row; j--) if (graph[10 * j + col]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + col]) break;
			else
			{
				valid[(2 * i - row) * 10 + col] = 1;
				find_1155233438(2 * i - row, col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = col + 1; i <= 8; i++)//向右找
	{
		if (graph[row * 10 + i])
		{
			if (2 * i - col > 8) break;
			int tagg = 1;
			for (int j = i + 1; j <= 2 * i - col; j++) if (graph[row * 10 + j]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[row * 10 + 2 * i - col]) break;
			else
			{
				valid[row * 10 + 2 * i - col] = 1;
				find_1155233438(row, 2 * i - col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = col - 1; i >= 1; i--)//向左找
	{
		if (graph[row * 10 + i])
		{
			if (2 * i - col < 1) break;
			int tagg = 1;
			for (int j = i - 1; j >= 2 * i - col; j--) if (graph[row * 10 + j]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[row * 10 + 2 * i - col]) break;
			else
			{
				valid[row * 10 + 2 * i - col] = 1;
				find_1155233438(row, 2 * i - col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = row + 1, j = col + 1; i <= 8 && j <= 8; i++, j++)//右下找
	{
		if (graph[i * 10 + j])
		{
			if (2 * i - row > 8 || 2 * j - col > 8) break;
			int tagg = 1;
			for (int m = i + 1, n = j + 1; m <= i * 2 - row, n <= j * 2 - col;m++, n++) if (graph[m * 10 + n]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + 2 * j - col]) break;
			else
			{
				valid[(2 * i - row) * 10 + 2 * j - col] = 1;
				find_1155233438(2 * i - row, 2 * j - col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = row - 1, j = col + 1; i >= 1 && j <= 8; i--, j++)//右上找
	{
		if (graph[i * 10 + j])
		{
			if (2 * i - row < 1 || 2 * j - col>8) break;
			int tagg = 1;
			for (int m = i - 1, n = j + 1; m >= i * 2 - row, n <= j * 2 - col;m--, n++) if (graph[m * 10 + n]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + 2 * j - col]) break;
			else
			{
				valid[(2 * i - row) * 10 + 2 * j - col] = 1;
				find_1155233438(2 * i - row, 2 * j - col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = row + 1, j = col - 1; i <= 8 && j >= 1; i++, j--)//左下找
	{
		if (graph[i * 10 + j])
		{
			if (2 * i - row > 8 || 2 * j - col < 1) break;
			int tagg = 1;
			for (int m = i + 1, n = j - 1; m <= i * 2 - row, n >= j * 2 - col;m++, n--) if (graph[m * 10 + n]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + 2 * j - col]) break;
			else
			{
				valid[(2 * i - row) * 10 + 2 * j - col] = 1;
				find_1155233438(2 * i - row, 2 * j - col, valid, graph);
				break;
			}
			break;
		}
	}
	for (int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)//左上找
	{
		if (graph[i * 10 + j])
		{
			if (2 * i - row < 1 || 2 * j - col < 1) break;
			int tagg = 1;
			for (int m = i - 1, n = j - 1; m >= i * 2 - row, n >= j * 2 - col;m--, n--) if (graph[m * 10 + n]) { tagg = 0; break; }
			if (tagg == 0) break;
			else if (valid[(2 * i - row) * 10 + 2 * j - col]) break;
			else
			{
				valid[(2 * i - row) * 10 + 2 * j - col] = 1;
				find_1155233438(2 * i - row, 2 * j - col, valid, graph);
				break;
			}
			break;
		}
	}
	graph[row * 10 + col] = tmp;
	return;
}
void set_1155233438(int v[], int graph[], int row, int col)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
			v[i * 10 + j] = 0;
	}
	find_1155233438(row, col, v, graph);
	if (row + 1 <= 8 && col + 1 <= 8 && !graph[(row + 1) * 10 + col + 1]) v[(row + 1) * 10 + col + 1] = 1;//右下
	if (row + 1 <= 8 && !graph[(row + 1) * 10 + col]) v[(row + 1) * 10 + col] = 1;//下
	if (row + 1 <= 8 && col - 1 >= 1 && !graph[(row + 1) * 10 + col - 1]) v[(row + 1) * 10 + col - 1] = 1;//左下
	if (row - 1 >= 1 && col + 1 <= 8 && !graph[(row - 1) * 10 + col + 1]) v[(row - 1) * 10 + col + 1] = 1;//右上
	if (row - 1 >= 1 && col - 1 >= 1 && !graph[(row - 1) * 10 + col - 1]) v[(row - 1) * 10 + col - 1] = 1;//左上
	if (row - 1 >= 1 && !graph[(row - 1) * 10 + col]) v[(row - 1) * 10 + col] = 1;//上
	if (col - 1 >= 1 && !graph[(row) * 10 + col - 1]) v[(row) * 10 + col - 1] = 1;//左
	if (col + 1 <= 8 && !graph[(row) * 10 + col + 1]) v[(row) * 10 + col + 1] = 1;//右
	v[row * 10 + col] = 0;
}
int hal_1155233438(int player, int graph[])
{
	int tag = 0, sum = 20, tagg = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)//找出下完棋后棋盘上棋子的位置
		{
			if (graph[i * 10 + j] == player)
			{
				if (player == 1)
				{
					if (i + j <= sum) sum = i + j;
					for (int m = i; m <= 8; m++)
					{
						for (int n = j; n <= 8; n++)
						{
							if (graph[m * 10 + n] == player % 2 + 1)
							{
								tag++;
							}
						}
					}
				}
				else
				{
					if (18 - i - j <= sum) sum = 18 - i - j;
					for (int m = i; m >= 1; m--)
					{
						for (int n = j; n >= 1; n--)
						{
							if (graph[m * 10 + n] == player % 2 + 1)
							{
								tag++;
							}
						}
					}
				}
				if (tag >= tagg) tagg = tag;
			}
		}
	}
	if (tagg <= 2 && sum >= 9) return 1;
	return 0;
}
int check_1155233438(int player, int num, int graph[])//检测是否有效
{
	int row = num / 1000, col = num / 100 % 10;
	int thing = num;
	int p[10], l = 0, tag = 0;
	while (thing != 0)
	{
		p[++l] = thing % 10;
		if (thing % 10 > 8 || thing % 10 < 1) tag = 1;
		thing /= 10;
	}
	if (l != 4)
	{
		printf("Invalid input format, please input again :\n"); return 0;
	}
	else if (tag == 1)
	{
		printf("Input out of the game board, please input again:\n"); return 0;;
	}
	if (player == 1)
	{
		if (graph[num / 100] != 1)
		{
			printf("Invalid starting location, please input again : \n"); return 0;
		}
		if (graph[num % 100])
		{
			printf("Invalid ending location, please input again :\n"); return 0;
		}
	}
	else
	{
		if (graph[num / 100] != 2)
		{
			printf("Invalid starting location, please input again : \n"); return 0;
		}
		if (graph[num % 100])
		{
			printf("Invalid ending location, please input again :\n"); return 0;
		}
	}
	int v[89];
	set_1155233438(v, graph, row, col);
	if (!v[num % 100])
	{
		printf("“The move violates the game rule, please input again :\n");
		return 0;
	}
	return 1;
}
int cal1_1155233438(int player, int graph[])//计算出下棋后棋子期望最大值
{
	int lsum = 0, rsum = 0, temp = 0, tmp = 0;
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)//找出下完棋后棋盘上棋子的位置
		{
			if (graph[i * 10 + j] == player)
			{
				int v[89];
				set_1155233438(v, graph, i, j);
				int lnow = 0;
				for (int m = 1; m <= 8; m++)
				{
					for (int n = 1; n <= 8; n++)
					{
						if (v[m * 10 + n])
						{
							if (player == 1 && m - i + n - j > lnow) lnow = m - i + n - j;
							if (player == 2 && i + j - m - n > lnow) lnow = i + j - m - n;
						}
					}
				}
				if (lnow > tmp)
				{
					tmp = lnow;
				}
				lsum += lnow;
			}
			else if (graph[i * 10 + j])
			{
				int v[89];
				int rnow = 0;
				set_1155233438(v, graph, i, j);
				for (int m = 1; m <= 8; m++)
				{
					for (int n = 1; n <= 8; n++)
					{
						if (v[m * 10 + n])
						{
							if (player == 2 && m - i + n - j > rnow) rnow = m - i + n - j;
							if (player == 1 && i + j - m - n > rnow) rnow = i + j - m - n;
						}
					}
				}//找出可下棋子的位置，找出最大的可下棋子处，并将它们累加
				if (rnow > temp) temp = rnow;
				rsum += rnow;
			}
		}
	}
	if (hal_1155233438(player, graph)) return (lsum - rsum) - 2 * temp;
	else if (player == 1)return (lsum - rsum) - 2 * temp;//返回最大棋子位置之差!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!2
	else return lsum - rsum - 2 * temp;//3
}
int ai_player_1155233438(int player, const int* broad)
{

	int graph[89], ltag = 0, rtag = 0, sum = -100000;
	for (int m = 1; m <= 8; m++)
	{
		for (int n = 1; n <= 8; n++)
		{
			graph[m * 10 + n] = broad[m * 10 + n];
		}
	}
	/*if (graph[88] && graph[87] && graph[86] && graph[78] && graph[77] && graph[68] && graph[11] && graph[31] && graph[13] && graph[21] && graph[22] && graph[12]) return 1314;*/
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)//找出棋子的位置
		{
			if (broad[i * 10 + j] == player)
			{
				int now, before;
				int v[89];
				set_1155233438(v, broad, i, j);
				for (int m = 1; m <= 8; m++)
				{
					for (int n = 1; n <= 8; n++)
					{
						if (v[m * 10 + n])
						{
							before = cal1_1155233438(player, graph);
							change_1155233438(i * 10 + j, m * 10 + n, graph);
							now = cal1_1155233438(player, graph) - before;
							if (player == 1)
							{
								if (!hal_1155233438(player, graph))	now += (m + n - i - j) * 4;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!6
								else now += (m + n - i - j) * 8;
							}
							else
							{
								if (!hal_1155233438(player, graph)) now += (i + j - m - n) * 6;//!!!!!!!!!!!!!!!!!!!!!!!!!6
								else now += (i + j - m - n) * 8;
							}
							if (player == 1 && i + j >= 14)
							{
								int lsum = 0, rsum = 0, tag = 0;
								for (int p = 1; p <= 8; p++)
								{
									for (int q = 1; q <= 8; q++)
									{
										if (broad[p * 10 + q] == 1) { lsum += p + q; }
										if (broad[p * 10 + q] == 2) rsum += 18 - p - q;
									}
								}
								if (i + j >= m + n && lsum > rsum && lsum < 80) now -= 10000000;
							}
							if (player == 2 && i + j <= 4)
							{
								int lsum = 0, rsum = 0, tag = 0;
								for (int p = 1; p <= 8; p++)
								{
									for (int q = 1; q <= 8; q++)
									{
										if (broad[p * 10 + q] == 1) { lsum += p + q; }
										if (broad[p * 10 + q] == 2) { rsum += 18 - p - q; }
									}
								}
								if (i + j <= m + n && rsum > lsum && rsum < 80) now -= 10000000;//强制拖平
							}
							if (hal_1155233438(player, broad))
							{
								if (player == 1 && now >= sum)
								{
									sum = now; ltag = i * 10 + j; rtag = m * 10 + n;
								}
								if (player == 2 && now > sum)
								{
									sum = now; ltag = i * 10 + j; rtag = m * 10 + n;
								}
							}
							else
							{
								if (player == 1 && now > sum)
								{
									sum = now; ltag = i * 10 + j; rtag = m * 10 + n;
								}
								if (player == 2 && now >= sum)
								{
									sum = now; ltag = i * 10 + j; rtag = m * 10 + n;
								}
							}
							change_1155233438(i * 10 + j, m * 10 + n, graph);
						}//找出可以下棋的位置，进行下棋，并对棋盘操作
					}
				}
			}
		}
	}
	return ltag * 100 + rtag;
}