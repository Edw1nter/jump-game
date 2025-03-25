#include<stdio.h>
#include<string.h>
#include"aiplayer_1155233438.h"
int graph[89],num,count;
int bwin_1155233438()
{
	if (graph[88] && graph[87] && graph[86] && graph[78] && graph[77] && graph[68])
	{
		if (graph[88] == 1 || graph[87] == 1 || graph[86] == 1 || graph[78] == 1 || graph[77] == 1 || graph[68] == 1) return 1;
	}
	return 0;
}
int rwin_1155233438()
{
	if (graph[11] && graph[31] && graph[13] && graph[21] && graph[22] && graph[12])
	{
		if (graph[11] == 2 || graph[31] == 2 || graph[13] == 2 || graph[21] == 2 || graph[22] == 2 || graph[12] == 2) return 1;
	}
	return 0;
}
int main()
{
	int tag = 0,mod;
	graph[11] = graph[12] = graph[21] = graph[31] = graph[13] = graph[22] = 1;
	graph[77] = graph[68] = graph[86] = graph[87] = graph[78] = graph[88] = 2;
	scanf("%d", &mod);
	if(mod==1)
	while (1)
	{	
		if (tag != 1)
		{
			count++;
			if (count % 2 == 1) printf("Blue's turn\n");
			else printf("Red's turn\n");
		}
		tag = 0;
		scanf("%d",&num);
		if (check_1155233438(count %2,num,graph)==0)
		{
			tag = 1;
			continue;
		}
		change_1155233438(num / 100, num % 100,graph);
		print_1155233438(graph);
		if (count == 200)
		{
			printf("draw"); break;
		}
		if (rwin_1155233438())
		{
			printf("Red(O) wins!");
			break;
		}
		if (bwin_1155233438())
		{
			printf("Blue(#) wins!");
			break;
		}
	}
	else
	{
		int side,player;
		printf("Choose your side!\n");
		scanf("%d", &side);
		if (side == 1) player = 2;
		else player = 1;
		while (1)
		{
			if (tag != 1)
			{
				count++;
				if (count % 2 == 1) printf("Blue's turn\n");
				else printf("Red's turn\n");
			}
			tag = 0;
			if (count % 2 == side % 2)
			{
				scanf("%d", &num);
				/*num = ai_player1(side, graph);
				printf("%d\n", num);*/
			}
			else
			{
				num = ai_player_1155233438(player, graph);
				printf("%d\n", num);
			}
			if (check_1155233438(count % 2, num, graph) == 0)
			{
				tag = 1;
				continue;
			}
			change_1155233438(num / 100, num % 100,graph);
			print_1155233438(graph);
			if (count == 200)
			{
				printf("Draw"); break;
			}
			if (rwin_1155233438())
			{
				printf("Red(O) wins!");
				break;
			}
			if (bwin_1155233438())
			{
				printf("Blue(#) wins!");
				break;
			}
		}
	}
	return 0;
}