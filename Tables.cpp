#include "Tables.h"


#include "Object.h"

#include "TileMapEx.h"
#include "TileMapResource.h"


const char *GetTilesObjectName(int id)
{
	switch(id)
	{
	case TILE_MAP_ID:
		return "TileMap";

	case TILE_MAP_EXTENDED_ID:
		return "TileMapEx";

	case TILE_MAP_ANIMATION_ID:
		return "TileMapAnimation";

	case TILE_MAP_ANIMATION_EX_ID:
		return "TileMapAnimationEx";

	case TILE_MAP_PARTICLE_ID:
		return "TileMapParticle";

	case TILE_MAP_RESOURCE_ID:
		return "TileMapResource";
	}

	return "";
}

const char *GetTileMapTypeName(int id)
{
	switch (id)
	{
	case TILE_TYPE_EMPTY:
		return "TILE_TYPE_EMPTY";

	case TILE_TYPE_FULL:
		return "TILE_TYPE_FULL";

	case TILE_TYPE_22DEGREE_nn:
		return "TILE_TYPE_22DEGREE_nn";

	case TILE_TYPE_22DEGREE_np:
		return "TILE_TYPE_22DEGREE_np";

	case TILE_TYPE_22DEGREE_pn:
		return "TILE_TYPE_22DEGREE_pn";

	case TILE_TYPE_22DEGREE_pp:
		return "TILE_TYPE_22DEGREE_pp";

	case TILE_TYPE_45DEGREE_nn:
		return "TILE_TYPE_45DEGREE_nn";

	case TILE_TYPE_45DEGREE_np:
		return "TILE_TYPE_45DEGREE_np";

	case TILE_TYPE_45DEGREE_pn:
		return "TILE_TYPE_45DEGREE_pn";

	case TILE_TYPE_45DEGREE_pp:
		return "TILE_TYPE_45DEGREE_pp";
	}

	return "";
}


const char *GetTileMapNameResType(int id)
{

	switch (id)
	{
	case RESOURCE_TYPES::AID:
		return "RESOURCE_TYPES::AID";
	case RESOURCE_TYPES::ARMOUR:
		return "RESOURCE_TYPES::AID";
	case RESOURCE_TYPES::LIFES:
		return "RESOURCE_TYPES::LIFES";
	}
	return "";
}