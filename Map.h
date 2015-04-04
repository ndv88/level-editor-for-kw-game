#pragma once

#include "Object.h"
#include "TileMap.h"
#include "TileMapEx.h"
#include "TileMapAnimation.h"
#include "TileMapParticle.h"
#include "TileMapAnimationEx.h"
#include "TileMapResource.h"

#include <vector>


class Map: public Object
{
public:
	Map(size_t layers, size_t rows, size_t cols, int screen_width, int screen_hight, short tile_width, short tile_hight);
	virtual ~Map();

	void Free();

	void InsertTile(int row, int col, TileMap *tile);
	void DeleteTile(int layer, int row, int col);

	TileMap* GetTile(int layer, const hgeVector *pos);
	TileMap* GetTile(int layer, float x, float y);
	TileMap* GetTile(int layer, int row, int col);

	float GetOffsetX()	{ return offset_x; }
	float GetOffsetY()	{ return offset_y; }

	void SetOffsetX(float offset)	{ offset_x = offset;}
	void SetOffsetY(float offset)	{ offset_y = offset;}

	void GetTileIndex(const hgeVector *pos, int &row, int &col);

	void HorizontalScroll(int offset_x);
	void VerticalScroll(int offset_y);

	void Render(int layer);

	TileMap *SelectTile(short layer, hgeVector &p);

	void Save(const char *file_name);
	void Load(const char *file_name);

	void UpdateGraphic();

	void UpdateEdges(int layer);

	bool QueryPoint(int layer, float x, float y);

	bool TestPointTile(float x, float y, TileMap *t);
	bool TestPointVsTileFull(float x, float y, TileMap *t);
	bool TestPointVsTile45Degree(float x, float y, TileMapEx *t);
	bool TestPointVsTile22Degree(float x, float y, TileMapEx *t);

protected:
	float offset_x, offset_y;
	short tile_width, tile_hight;
	int screen_width, screen_hight;

	size_t rows, cols;
	size_t layers;

	TileMap *tile;

	std::vector< std::vector< std::vector<TileMap *> > > grid;
};
