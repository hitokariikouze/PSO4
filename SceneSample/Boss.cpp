#include "Boss.h"
#include "GraphFactory.h"
#include "WindowInfo.h"
#include <math.h>

Boss::Boss(Vector2D pos,int type) : _position(pos), _size(Vector2D(32, 32)),_type(type)
{
	
}

void Boss::Start()
{
	shot = new EnemyShot;
	grp = GraphFactory::Instance().LoadGraph("img\\Boss.png");
	gh = GraphFactory::Instance().LoadGraph("img\\Boss1.png");
	hp = 1000;
	count = 0;
	waitcount = 0;
	angle = 0;
	raise = 2;
	raise1 = 2;
	move_pattern = 0;
	prev_x = 200;
	prev_y = -100;
	movex = 0;
	movey = 180;
	shot_pattern = 0;
	scount[0] = 40;
	scount[1] = 5;
	scount[2] = 3;
	scount[3] = 15;
	shotflag = false;
	wait = false;
	p3_state = 0;
}

void Boss::Render()
{
	if (_type == 0)
	{
		DrawGraph(_position.x, _position.y, grp, TRUE);
	}
	if (_type == 1)
	{
		DrawGraph(_position.x, _position.y, gh, TRUE);
	}
}

void Boss::Update()
{
	shot_position.x = _position.x + 32;
	shot_position.y = _position.y + 32;
	if (_type == 0)
	{
		MoveChange();
	}
	if (_type == 1)
	{
		MoveChange1();
	}
	Move();
	Shot();
	ShotChange();
	
}

void Boss::Move()
{
	switch (move_pattern)
	{
	case 0:
		MovePattern0();
		break;
	case 1:
		MovePattern1();
		break;
	case 2:
		MovePattern2();
		break;
	case 3:
		MovePattern3();
		break;
	}
}

void Boss::Shot()
{
	int s = shot_pattern;
	if (count > scount[s])
	{
		shotflag = true;
	}
	else
	{
		shotflag = false;
		count++;
	}
}

void Boss::MovePattern0()
{
	float temp;

	angle += 1;
	temp = sin(angle*DX_PI / 180);

	_position.x = prev_x + temp * movex;
	_position.y = prev_y + temp * movey;

	if (angle == 90)
	{
		if (p3_state == 0)
		{
			MoveInit(70, 80, 1);
		}
		else if (p3_state == 1)
		{
			MoveInit(200, 160, 2);
		}
		else if(p3_state == 2)
		{
			MoveInit(330, 80, 3);
		}
		else if (p3_state == 3)
		{
			MoveInit(330, 240, 4);
		}
		else
		{
			MoveInit(70, 240, 0);
		}
	}
}

void Boss::MovePattern1()
{
	angle += raise;

	_position.y = 80 + sin(angle*DX_PI / 180) * 20;

	if (angle == 90)
	{
		raise = -2;
	}
	else if (angle == -90)
	{
		raise = 2;
	}
	_position.x = 200;
}

void Boss::MovePattern2()
{
	if (!wait)
	{
		_position.x += raise1;

		if (_position.x == 70)
		{
			raise1 = 2;
			wait = true;
		}
		else if (_position.x == 330)
		{
			raise1 = -2;
			wait = true;
		}
	}
	if (wait)
	{
		waitcount++;
		if (waitcount == 20)
		{
			wait = false;
			waitcount = 0;
		}
	}
}

void Boss::MovePattern3()
{
	angle += raise;

	_position.y = 80 + sin(angle*DX_PI / 180) * 20;

	if (angle == 90)
	{
		raise = -2;
	}
	else if (angle == -90)
	{
		raise = 2;
	}
	_position.x = 200;
}

void Boss::ShotChange()
{
	if (hp >750)
	{
		shot_pattern = 0;
	}
	if (hp < 750 && hp > 500)
	{
		shot_pattern = 1;
	}
	if (hp < 500 && hp > 250)
	{
		shot_pattern = 2;
	}
	if (hp < 250 && hp > 0)
	{
		shot_pattern = 3;
	}
}

void Boss::MoveChange()
{
	if (hp >750)
	{
		move_pattern = 0;
	}
	if (hp < 750 && hp > 500)
	{
		move_pattern = 1;
	}
	if (hp < 500 && hp > 250)
	{
		move_pattern = 2;
	}
	if (hp < 250 && hp > 0)
	{
		move_pattern = 3;
	}
}

void Boss::MoveChange1()
{
	if (hp >750)
	{
		move_pattern = 1;
	}
	if (hp < 750 && hp > 500)
	{
		move_pattern = 0;
	}
	if (hp < 500 && hp > 250)
	{
		move_pattern = 3;
	}
	if (hp < 250 && hp > 0)
	{
		move_pattern = 2;
	}
}

void Boss::MoveInit(double bx, double by, int state)
{
	prev_x = _position.x;
	prev_y = _position.y;

	movex = bx - _position.x;
	movey = by - _position.y;

	angle = 0;

	p3_state = state;
}

