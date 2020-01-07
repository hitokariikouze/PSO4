#include "EnemyManager.h"
#include <stdio.h>
#include "GraphFactory.h"



EnemyManager::EnemyManager()
{
	
	int n, num, i, fp;
	
	char fname[32] = ("data\\storyH0.csv");
	int input[64];
	char inputc[64];

	fp = FileRead_open(fname);
	if (fp == NULL)
	{
		printfDx("read error\n");
		return;
	}
	for (i = 0; i < 1; i++)
	while (FileRead_getc(fp) != '\n');

	n = 0, num = 0;
	while (1)
	{
		for (i = 0; i < 64; i++)
		{
			inputc[i] = input[i] = FileRead_getc(fp);//1文字取得する
			if (inputc[i] == '/') {//スラッシュがあれば
				while (FileRead_getc(fp) != '\n');//改行までループ
				i = -1;
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}
			if (input[i] == EOF) {
				goto EXFILE;
			}
		}
		switch (num)
		{
		case 0: data[n].type = atoi(inputc); break;
		case 1: data[n].m_pattern = atoi(inputc); break;
		case 2: data[n].in_time = atoi(inputc); break;
		case 3: data[n].stop_time = atoi(inputc); break;
		case 4: data[n].out_time = atoi(inputc); break;
		case 5: data[n].x = atoi(inputc); break;
		case 6: data[n].y = atoi(inputc); break;
  		case 7: data[n].hp = atoi(inputc); break;
		}
		num++;
		if (num == 8)
		{
			num = 0;
			n++;
		}
	}
EXFILE:
	
	FileRead_close(fp);
 	for (int i = 0; i < ENEMY_NUM; i++)
	{
		data[i].endflag = false;
		data[i].pos.x = data[i].x;
		data[i].pos.y = data[i].y;
	}
	time_count = 0;
	
}
void EnemyManager::Start()
{
	grp = GraphFactory::Instance().LoadGraph("img\\pipo-chara.png");
	gh = GraphFactory::Instance().LoadGraph("img\\enemy04.png");
}
void EnemyManager::Render()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].endflag != true && data[i].type == 0)
		{
			
			DrawGraph(data[i].pos.x, data[i].pos.y, grp, TRUE);
		}
		if (data[i].endflag != true && data[i].type == 1)
		{

			DrawGraph(data[i].pos.x, data[i].pos.y, gh, TRUE);
		}
	}
	
}
void EnemyManager::Update()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].hp <= 0)
		{
			data[i].endflag = true;
		}
	}
	time_count++;
	Move();
	
}

void EnemyManager::Move()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].endflag == false)
		{
			switch (data[i].m_pattern)
			{
			case 0:
				if (data[i].in_time<time_count &&time_count  <data[i].stop_time)
				{
					data[i].pos.y += 2;
				}
				if (time_count>data[i].out_time)
				{
					data[i].pos.y -= 2;
				}
				break;
			case 1:
				if (data[i].in_time <= time_count)
				{
					data[i].pos.y += 2;
				}
				break;
			case 2:
				if (data[i].in_time <= time_count)
				{
					data[i].pos.y += 1;
					data[i].pos.x -= 1;
					
				}
				break;
			case 3:
				if (data[i].in_time <= time_count)
				{
					data[i].pos.y += 1;
					data[i].pos.x += 1;
					
				}
				break;		
			}
			if (time_count >= data[i].stop_time)
			{
				Out();
			}
		}
		
	}
	
}

void EnemyManager::Out()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].pos.x < -50 || data[i].pos.x > 810 ||
			data[i].pos.y < -50 || data[i].pos.y > 610)
		{
			data[i].endflag = true;

		}
	}
}
