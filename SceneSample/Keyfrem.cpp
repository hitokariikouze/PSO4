#include "Keyfrem.h"
#include "DxLib.h"


int Keyfrem::gadUpdateKey()
{
		
		GetHitKeyStateAll(tmpKey);
		for (int i = 0; i < 256; i++)
		{
			if (tmpKey[i] != 0)
			{
				Key[i]++;
			}
			else
			{
				Key[i] = 0;
			}
		}
		
		return 0;
}

