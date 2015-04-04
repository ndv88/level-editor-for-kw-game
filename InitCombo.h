#include <windows.h>
#include "Map.h"

extern HWND hCB_ObjType;
extern HWND hCB_SprName;
extern HWND hCB_AnimName;
extern HWND hCB_TileType;
extern HWND hCB_PS1;
extern HWND hCB_PS2;
extern HWND hCB_ResType;

void InitComboBoxTiles()
{
	LRESULT index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)-1);
	SendMessage(hCB_ObjType, CB_SETCURSEL, 0, 0);

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMap");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_ID);
	

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMapEx");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_EXTENDED_ID);

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMapAnimation");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_ANIMATION_ID);

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMapAnimationEx");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_ANIMATION_EX_ID);

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMapParticle");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_PARTICLE_ID);

	index = SendMessage(hCB_ObjType, CB_ADDSTRING, 0, (LPARAM)"TileMapResource");
	SendMessage(hCB_ObjType, CB_SETITEMDATA, index, (LPARAM)TILE_MAP_RESOURCE_ID);

}

void InitComboBox1()
{
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_SprName, CB_SETCURSEL, 0, 0);

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"empty");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_3_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_3_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_4_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_4_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_5");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_6");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_7");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_8");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_9");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_10");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_11");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_12");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_13");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_14_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_14_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_15");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_16");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_17");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_18");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"g_1_19");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_3");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_4");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_5");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_6");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_7");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_8");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"tree1_9");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_3");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_4");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_5");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_6");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_7");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"fence1_8");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone1_2");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone2_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone2_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone2_3");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone2_4");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"grass1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"grass2");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone3");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone4");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stone5");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stub1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"stub1_2");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"grass3_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"grass3_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"grass3_3");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush1_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush1_2");

	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_1");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_2");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_3");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_4");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_5");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_6");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_7");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_8");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_9");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_10");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_11");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_12");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_13");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_14");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_15");
	SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)"bush2_16");

	for (int i = 1; i <= 18; i++)
	{
		char str[256] = {0};
		sprintf(str, "tree2_%d", i);
		SendMessage(hCB_SprName, CB_ADDSTRING, 0, (LPARAM)str);
	}
}

void InitComboBox2()
{
	SendMessage(hCB_AnimName, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_AnimName, CB_SETCURSEL, 0, (LPARAM)-1);
	SendMessage(hCB_AnimName, CB_SETCURSEL, 0, 0);

	SendMessage(hCB_AnimName, CB_ADDSTRING, 0, (LPARAM)"hard");
}

void InitComboBox3()
{
	LRESULT index = 0;

	SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)-1);
	SendMessage(hCB_TileType, CB_SETCURSEL, 0, 0);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_EMPTY");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_EMPTY);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_FULL");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_FULL);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_45DEGREE_pn");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_45DEGREE_pn);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_45DEGREE_nn");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_45DEGREE_nn);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_45DEGREE_np");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_45DEGREE_np);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_45DEGREE_pp");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_45DEGREE_pp);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_22DEGREE_pn");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_22DEGREE_pn);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_22DEGREE_nn");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_22DEGREE_nn);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_22DEGREE_np");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_22DEGREE_np);

	index = SendMessage(hCB_TileType, CB_ADDSTRING, 0, (LPARAM)"TILE_TYPE_22DEGREE_pp");
	SendMessage(hCB_TileType, CB_SETITEMDATA, index, (LPARAM)TILE_TYPE_22DEGREE_pp);
}

void InitComboBoxPS1()
{
	LRESULT index = 0;

	SendMessage(hCB_PS1, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_PS1, CB_SETCURSEL, 0, 0);
}

void InitComboBoxPS2()
{
	LRESULT index = 0;

	SendMessage(hCB_PS2, CB_ADDSTRING, 0, (LPARAM)"undefined");
	SendMessage(hCB_PS2, CB_SETCURSEL, 0, 0);
}

void InitComboBoxTileRes()
{
	LRESULT index = 0;

	index = SendMessage(hCB_ResType, CB_ADDSTRING, 0, (LPARAM)"RESOURCE_TYPES::LIFES");
	SendMessage(hCB_ResType, CB_SETITEMDATA, index, (LPARAM)RESOURCE_TYPES::LIFES);

	index = SendMessage(hCB_ResType, CB_ADDSTRING, 0, (LPARAM)"RESOURCE_TYPES::AID");
	SendMessage(hCB_ResType, CB_SETITEMDATA, index, (LPARAM)RESOURCE_TYPES::AID);

	index = SendMessage(hCB_ResType, CB_ADDSTRING, 0, (LPARAM)"RESOURCE_TYPES::ARMOUR");
	SendMessage(hCB_ResType, CB_SETITEMDATA, index, (LPARAM)RESOURCE_TYPES::ARMOUR);

	SendMessage(hCB_ResType, CB_SETCURSEL, 0, 0);
}