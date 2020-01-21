#include "EnemyManager.h"
#include <stdio.h>
#include "GraphFactory.h"

EnemyManager::EnemyManager()
{

}

void EnemyManager::Stage1()
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
		case 8: data[n].scount = atoi(inputc); break;
		case 9: data[n].s_pattern = atoi(inputc); break;
		case 10:data[n].s_velocity = atoi(inputc); break;
		}
		num++;
		if (num == 11)
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
		data[i].count = 0;
	}
	time_count = 0;
	bossflag = false;
}

void EnemyManager::Stage2()
{
	int n, num, i, fp;

	char fname[32] = ("data\\storyH1.csv");
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
		case 8: data[n].scount = atoi(inputc); break;
		case 9: data[n].s_pattern = atoi(inputc); break;
		case 10:data[n].s_velocity = atoi(inputc); break;
		}
		num++;
		if (num == 11)
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
		data[i].count = 0;
	}
	time_count = 0;
	bossflag = false;
}

void EnemyManager::Start()
{
	agrp = GraphFactory::Instance().LoadGraph("img\\Enemy01.png");
	bgrp = GraphFactory::Instance().LoadGraph("img\\Enemy02.png");
	cgrp = GraphFactory::Instance().LoadGraph("img\\Enemy03.png");

}
void EnemyManager::Render()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].endflag != true && data[i].type == 0)
		{

			DrawGraph(data[i].pos.x, data[i].pos.y, agrp, TRUE);
		}
		if (data[i].endflag != true && data[i].type == 1)
		{

			DrawGraph(data[i].pos.x, data[i].pos.y, bgrp, TRUE);
		}
		if (data[i].endflag != true && data[i].type == 2)
		{

			DrawGraph(data[i].pos.x, data[i].pos.y, cgrp, TRUE);
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
		if (data[i].hp <= 0 && data[i].type == 2)
		{
			bossflag = true;
		}

	}

	//auto siz = std::count(data, data + (sizeof(data)), data->endflag);

	time_count++;
	Move();
	Shot();
}

void EnemyManager::Move()
{
	int count = 0;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].endflag == false)
		{
			switch (data[i].m_pattern)
			{
			case 0:
				if (data[i].in_time < time_count &&time_count < data[i].stop_time)
				{
					data[i].pos.y += 2;
				}
				if (time_count > data[i].out_time)
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
			case 4:
				if (data[i].in_time <= time_count && time_count < data[i].stop_time)
				{
					data[i].pos.x++;
				}
				if (time_count > data[i].out_time)
				{
					data[i].pos.y -= 2;
				}
				break;
			case 5:
				if (data[i].in_time <= time_count && time_count < data[i].stop_time)
				{
					data[i].pos.x--;
				}
				if (time_count > data[i].out_time)
				{
					data[i].pos.y -= 2;
				}
				break;
			case 6:
				if (data[i].in_time <= time_count && time_count < data[i].stop_time)
				{
					data[i].pos.y += sin(PI / 2);
					data[i].pos.x += cos(PI / 2);
				}
			case 100:
				if (data[i].in_time < time_count &&time_count < data[i].stop_time)
				{
					data[i].pos.y++;
				}
				if (time_count > data[i].stop_time)
				{

					if (count < 5)
					{
						data[i].pos.x++;
						count++;
					}
					if (count > 5 && count < 10)
					{
						data[i].pos.x--;
						count++;
					}
					if (count > 10)
					{
						count = 0;
					}
				}
				break;
			}
			if (time_count >= data[i].out_time)
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
		if (data[i].pos.x < -50 || data[i].pos.x > 510 ||
			data[i].pos.y < -50 || data[i].pos.y > 610)
		{
			data[i].endflag = true;
		}
	}
}

void EnemyManager::Shot()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (data[i].count > data[i].scount&& data[i].in_time <= time_count)
		{
			data[i].shotflag = true;
		}
		else
		{
			data[i].shotflag = false;
			data[i].count++;
		}
	}
}

EnemyManager::~EnemyManager()
{
	GraphFactory::Instance().EraseGraph("img\\Enemy01.png");
	GraphFactory::Instance().EraseGraph("img\\Enemy02.png");
	GraphFactory::Instance().EraseGraph("img\\Enemy03.png");
}