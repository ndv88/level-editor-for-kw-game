#include <windows.h> 
#include <hge.h> 

#include "Map.h"
#include "Initiate.h"
#include "Tables.h"
#include "InitCombo.h"

#pragma comment(lib, "hge.lib")
#pragma comment(lib, "hgehelp.lib")


HGE* hge = NULL; 
hgeResourceManager *resource_manager = NULL;



HWND hwndHGE = 0;

HWND hCB_ObjType = 0;
HWND hCB_SprName = 0;
HWND hCB_AnimName = 0;
HWND hCB_TileType = 0;
HWND hCB_PS1 = 0;
HWND hCB_PS2 = 0;
HWND hCB_ResType = 0;

HWND hEdit = 0;
HWND hEditLoad = 0;
HWND hEditSave = 0;

HWND hButtonOk = 0;
HWND hButtonDel = 0;
HWND hButtonSave = 0;
HWND hButtonLoad = 0;

hgeVector mouse_pos(0, 0);
hgeRect hge_rect(0, 0, 800, 768);


Map *map = NULL;


TileMap *tile = NULL;
int layer = 0;
int row = 0, col = 0;

// #define LAYER 3
#define LAYERS 7


LRESULT CALLBACK HGEProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


void InitMap()
{
	size_t rows = 20;
	size_t cols = 250;
	map = new Map(LAYERS, rows, cols, 800, 768, 64, 64);

	TileMap *tile = NULL;
	hgeVector pos(32, 32);

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tile = new TileMap("empty", pos, 32, 32, 3);
			tile->SetTileType(TILE_TYPE_EMPTY);
			pos.x += 64;

			map->InsertTile(i, j, tile);
		}
		pos.x = 32;
		pos.y += 64;
	}
}



bool FrameFunc() 
{ 
	POINT p;
	GetCursorPos(&p);

	ScreenToClient(hwndHGE, &p);

	mouse_pos.x = (float)p.x;
	mouse_pos.y = (float)p.y;

	if (map)
		map->UpdateGraphic();

	if (hge->Input_GetKeyState(HGEK_LBUTTON) && hge_rect.TestPoint(mouse_pos.x, mouse_pos.y))
	{
		int n = GetWindowTextLength(hEdit)+1;
		char *buf = new char[n];
		GetWindowText(hEdit, buf, n);
		layer = atoi(buf);
		delete[] buf;

		if (tile)
			tile->ShowTileQuad(false);

		tile = map->SelectTile(layer, mouse_pos);
		map->GetTileIndex(&mouse_pos, row, col);

		if (!tile)
		{
			SendMessage(hCB_ObjType, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_SprName, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_AnimName, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_TileType, CB_SETCURSEL, 0, 0);
		}
		else
		{
			SendMessage(hCB_ObjType, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_SprName, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_AnimName, CB_SETCURSEL, 0, 0);
			SendMessage(hCB_TileType, CB_SETCURSEL, 0, 0);

			tile->ShowTileQuad(true);

			LRESULT index = SendMessage(hCB_ObjType, CB_FINDSTRING, -1, (LPARAM)GetTilesObjectName(tile->GetObjectType()));
			if (index != -1)
				SendMessage(hCB_ObjType, CB_SETCURSEL, index, 0);

			if (tile->GetObjectType() == TILE_MAP_RESOURCE_ID)
			{
				TileMapResource *tr = (TileMapResource *)tile;
				index = SendMessage(hCB_ResType, CB_FINDSTRING, -1, (LPARAM)GetTileMapNameResType(tr->GetResourceType()));
				if (index != -1)
					SendMessage(hCB_ResType, CB_SETCURSEL, index, 0);

				index = SendMessage(hCB_PS2, CB_FINDSTRING, -1, (LPARAM)((TileMapResource *)tile)->GetUsedPSName());
				if (index != -1)
					SendMessage(hCB_PS2, CB_SETCURSEL, index, 0);
			}

			index = SendMessage(hCB_SprName, CB_FINDSTRING, -1, (LPARAM)tile->GetResName());
			if (index != -1)
				SendMessage(hCB_SprName, CB_SETCURSEL, index, 0);

			if (tile->GetObjectType() == TILE_MAP_ANIMATION_EX_ID || tile->GetObjectType() == TILE_MAP_PARTICLE_ID)
			{
				if (tile->GetObjectType() == TILE_MAP_ANIMATION_EX_ID)
				{
					index = SendMessage(hCB_PS1, CB_FINDSTRING, -1, (LPARAM)((TileMapAnimationEx *)tile)->GetPSName());
				}
				else if (tile->GetObjectType() == TILE_MAP_PARTICLE_ID)
				{
					index = SendMessage(hCB_PS1, CB_FINDSTRING, -1, (LPARAM)((TileMapParticle *)tile)->GetPSName());
				}
				if (index != -1)
				{
					SendMessage(hCB_PS1, CB_SETCURSEL, index, 0);
				}
			}

			
			if (tile->GetObjectType() == TILE_MAP_ANIMATION_ID ||
				tile->GetObjectType() == TILE_MAP_ANIMATION_EX_ID ||
				tile->GetObjectType() == TILE_MAP_RESOURCE_ID)
			{
				index = SendMessage(hCB_AnimName, CB_FINDSTRING, -1, (LPARAM)tile->GetResName());
				if (index != -1)
					SendMessage(hCB_AnimName, CB_SETCURSEL, index, 0);
			}

			
			index = SendMessage(hCB_TileType, CB_FINDSTRING, -1, (LPARAM)GetTileMapTypeName(tile->GetTileType()));
			if (index != -1)
				SendMessage(hCB_TileType, CB_SETCURSEL, index, 0);
		}
	}
	

	int offset = 4;
	if (hge->Input_GetKeyState(HGEK_S))
	{
		map->VerticalScroll(offset);
	}
	if (hge->Input_GetKeyState(HGEK_W))
	{
		map->VerticalScroll(offset*-1);
	}
	if (hge->Input_GetKeyState(HGEK_D))
	{
		map->HorizontalScroll(offset);
	}
	if (hge->Input_GetKeyState(HGEK_A))
	{
		map->HorizontalScroll(offset*-1);
	}


	return false;
} 


bool RenderFunc() 
{ 
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	for (int i = 0; i < LAYERS; i++)
	{
		map->Render(i);
	}

	hge->Gfx_EndScene(); 
	return false; 
} 


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int iCmdShow) 
{ 
   MSG msg;
   WNDCLASS wndclass;
   char szHGEName[] = "HGE Workspace";

   wndclass.style = CS_HREDRAW|CS_VREDRAW; 
   wndclass.lpfnWndProc = HGEProc; 
   wndclass.cbClsExtra = 0; 
   wndclass.cbWndExtra = 0; 
   wndclass.hInstance = hInstance; 
   wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
   wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); 
   wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);; 
   wndclass.lpszMenuName = NULL; 
   wndclass.lpszClassName = szHGEName; 

   if ( !RegisterClass(&wndclass) ) 
   { 
      MessageBox(NULL, "Unable to open the HGE window!", szHGEName, MB_ICONERROR); 
      return 0; 
   } 

   hwndHGE = CreateWindowEx(WS_EX_CLIENTEDGE, 
                  szHGEName, 
                  szHGEName, 
                  WS_OVERLAPPEDWINDOW|WS_VISIBLE, 
                  15,128, 
                  1024,768, 
                  NULL,
                  NULL,
                  hInstance, 
                  NULL
	);

   	if (hwndHGE == NULL)
	{ 
	  MessageBox(NULL, "HGE Window Creation Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK); 
	  return 0; 
	}

  	hButtonOk = CreateWindow("BUTTON", "OK", WS_VISIBLE|WS_CHILD|WS_TABSTOP|BS_DEFPUSHBUTTON, 808,250,80,30, hwndHGE, NULL, hInstance, NULL);

	hButtonDel = CreateWindow("BUTTON", "DELETE", WS_VISIBLE|WS_CHILD|WS_TABSTOP|BS_DEFPUSHBUTTON, 914,250,80,30, hwndHGE, NULL, hInstance, NULL);
	hButtonLoad = CreateWindow("BUTTON", "Load", WS_VISIBLE|WS_CHILD|WS_TABSTOP|BS_DEFPUSHBUTTON, 937,610,60,30, hwndHGE, NULL, hInstance, NULL);
	hButtonSave = CreateWindow("BUTTON", "Save", WS_VISIBLE|WS_CHILD|WS_TABSTOP|BS_DEFPUSHBUTTON, 937,640,60,30, hwndHGE, NULL, hInstance, NULL);

	hCB_ObjType = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,10,200,500, hwndHGE, NULL, hInstance, NULL);
	hCB_SprName = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,40,200,500, hwndHGE, NULL, hInstance, NULL);	
	hCB_AnimName = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,70,200,500, hwndHGE, NULL, hInstance, NULL);
	hCB_TileType = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,100,200,500, hwndHGE, NULL, hInstance, NULL);
	hCB_PS1 = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,130,200,500, hwndHGE, NULL, hInstance, NULL);
	hCB_PS2 = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,160,200,500, hwndHGE, NULL, hInstance, NULL);
	hCB_ResType = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "", WS_VISIBLE|WS_CHILD|WS_TABSTOP|WS_VSCROLL|CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 804,190,200,500, hwndHGE, NULL, hInstance, NULL);
	
	hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",WS_VISIBLE|WS_CHILD|WS_TABSTOP|ES_AUTOHSCROLL|ES_NUMBER, 870,300,80,30, hwndHGE, NULL, hInstance, NULL);
	hEditLoad = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",WS_VISIBLE|WS_CHILD|WS_TABSTOP|ES_AUTOHSCROLL, 804,610,128,30, hwndHGE, NULL, hInstance, NULL);
	hEditSave = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",WS_VISIBLE|WS_CHILD|WS_TABSTOP|ES_AUTOHSCROLL, 804,640,128,30, hwndHGE, NULL, hInstance, NULL);

	InitComboBoxTiles();
	InitComboBox1();
	InitComboBox2();
	InitComboBox3();
	InitComboBoxPS1();
	InitComboBoxPS2();
	InitComboBoxTileRes();

	SetWindowText(hEdit, "0");
	
	ShowWindow(hwndHGE, iCmdShow);
	UpdateWindow(hwndHGE); 

	RECT hgeClient;
	GetClientRect(hwndHGE, &hgeClient); 

	hge = hgeCreate(HGE_VERSION); 

	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc); 
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc); 
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 768);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_HWNDPARENT, hwndHGE );

	if (hge->System_Initiate() ) 
	{ 
	   resource_manager = CreateResourceManager();
	   resource_manager->ChangeScript("resource.rs");

	   InitMap();

	  while (true) 
	  { 
		 if(hge->System_GetState(HGE_HWND)) 
			hge->System_Start(); 
	   
		 if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		 { 
			if(msg.message == WM_QUIT) 
			   break; 
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		 } 
	  } 
	} 

	delete map;

	hge->System_Shutdown(); 
	hge->Release(); 

	return 0; 
} 

LRESULT CALLBACK HGEProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{ 
   HDC         hdc; 
   PAINTSTRUCT   ps; 


   switch (msg) 
   { 
   case WM_CREATE:
      return 0; 

   case WM_PAINT: 
      hdc = BeginPaint(hwnd, &ps); 
      EndPaint(hwnd, &ps); 
      return 0; 
  
   case WM_DESTROY: 
      return 0;

   case WM_COMMAND:
		if ((HWND)lParam == hButtonSave)
		{
			char *path = NULL;
			int len = GetWindowTextLength(hEditSave)+1;
			path = new char[len];
			GetWindowText(hEditSave, path, len);
			map->Save(path);
			delete[] path;
		}
		else if ((HWND)lParam == hButtonLoad)
		{
			char *path = NULL;
			int len = GetWindowTextLength(hEditLoad)+1;
			path = new char[len];
			GetWindowText(hEditLoad, path, len);
			map->Load(path);
			delete[] path;
		}
		else if ((HWND)lParam == hButtonOk)
		{
			char *spr_name = NULL, *anim_name = NULL, *ps_name1 = NULL, *ps_name2 = NULL;
			int res_type = 0;

			int len = 0;
			LRESULT tile_type = -1;
			LRESULT obj_type = -1;
			LRESULT cur_index = -1;

			cur_index = SendMessage(hCB_ObjType, CB_GETCURSEL, 0, 0);
			obj_type = SendMessage(hCB_ObjType, CB_GETITEMDATA, cur_index, 0);

			cur_index = SendMessage(hCB_TileType, CB_GETCURSEL, 0, 0);
			tile_type = SendMessage(hCB_TileType, CB_GETITEMDATA, cur_index, 0);

			len = GetWindowTextLength(hCB_SprName)+1;
			spr_name = new char[len];

			GetWindowText(hCB_SprName, spr_name, len);
			if (strcmp("undefined", spr_name) == 0)
			{
				delete[] spr_name;
				spr_name = NULL;
			}

			if (obj_type == TILE_MAP_ANIMATION_ID || obj_type == TILE_MAP_ANIMATION_EX_ID || obj_type == TILE_MAP_RESOURCE_ID)
			{
				len = GetWindowTextLength(hCB_AnimName)+1;
				anim_name = new char[len];
				GetWindowText(hCB_AnimName, anim_name, len);
				if (strcmp("undefined", anim_name) == 0)
				{
					delete[] anim_name;
					anim_name = NULL;
				}
			}

			if (obj_type == TILE_MAP_ANIMATION_EX_ID || obj_type == TILE_MAP_PARTICLE_ID || obj_type == TILE_MAP_RESOURCE_ID)
			{
				len = GetWindowTextLength(hCB_PS1)+1;
				ps_name1 = new char[len];
				GetWindowText(hCB_PS1, ps_name1, len);
				if (strcmp("undefined", ps_name1) == 0)
				{
					delete[] ps_name1;
					ps_name1 = NULL;
				}
			}

			if (obj_type == TILE_MAP_RESOURCE_ID)
			{
				len = GetWindowTextLength(hCB_PS2)+1;
				ps_name2 = new char[len];
				GetWindowText(hCB_PS2, ps_name2, len);
				if (strcmp("undefined", ps_name2) == 0)
				{
					delete[] ps_name2;
					ps_name2 = NULL;
				}
			}

			
			if (obj_type == TILE_MAP_RESOURCE_ID)
			{
				len = GetWindowTextLength(hCB_ResType)+1;
				char *str = new char[len];
				GetWindowText(hCB_ResType, str, len);

				if (strcmp(str, "RESOURCE_TYPES::LIFES") == 0)
				{
					res_type = RESOURCE_TYPES::LIFES;
				}
				else if (strcmp(str, "RESOURCE_TYPES::AID") == 0)
				{
					res_type = RESOURCE_TYPES::AID;
				}
				else if (strcmp(str, "RESOURCE_TYPES::ARMOUR") == 0)
				{
					res_type = RESOURCE_TYPES::ARMOUR;
				}
			}
			
				
			hgeVector pos(32, 32);
			pos.x += col*64;
			pos.y += row*64;

			if (obj_type != -1)
			{
				map->DeleteTile(layer, row, col);
				tile = NULL;
			}

			switch (obj_type)
			{
			case TILE_MAP_ID:
				tile = new TileMap(spr_name, pos, 32, 32, layer);
				break;
			case TILE_MAP_EXTENDED_ID:
				tile = new TileMapEx(spr_name, pos, 32, 32, layer);
				break;
			case TILE_MAP_ANIMATION_ID:
				tile = new TileMapAnimation(anim_name, pos, 32, 32, layer);
				break;
			case TILE_MAP_PARTICLE_ID:
				tile = new TileMapParticle(spr_name, ps_name1, pos, 32, 32, layer);
				break;
			case TILE_MAP_ANIMATION_EX_ID:
				tile = new TileMapAnimationEx(anim_name, ps_name1, pos, 32, 32, layer);
				break;
			case TILE_MAP_RESOURCE_ID:
				tile = new TileMapResource(anim_name, ps_name1, ps_name2, pos, 32, 32, layer);
				((TileMapResource *)tile)->SetResourceType(res_type);
				break;
			}

			if (tile && -1 < tile_type)
			{
				tile->SetTileType(tile_type);		
			}

			if (tile)
			{
				tile->ShowTileQuad(true);
				map->InsertTile(row, col, tile);
			}

			delete[] spr_name;
			delete[] anim_name;
			delete[] ps_name1;
			delete[] ps_name2;
		}
	   break;

   case WM_LBUTTONDOWN:
		mouse_pos.x = LOWORD(lParam); 
		mouse_pos.y = HIWORD(lParam); 
		break;

   default: 
      return DefWindowProc(hwnd, msg, wParam, lParam); 
       
   } 

   return 0; 
}