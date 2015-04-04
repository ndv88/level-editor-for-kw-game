#pragma once

#include "Object.h"

#include <hge.h>
#include <hgevector.h>
#include <hgeresource.h>
#include <string>

class GraphicObject: public Object
{
public:
	GraphicObject();
	GraphicObject(const char *resource_name, hgeVector pos, short xw, short yw, short layer);

	virtual ~GraphicObject();

	void SetResName(char *name)				{ resource_name = name; }
	const char *GetResName()			{ return resource_name.c_str(); }

	void SetPos(hgeVector pos)				{ this->pos = pos; }
	void SetPos(float x, float y)			{ this->pos.x = x; this->pos.y = y; }
	hgeVector GetPos()						{ return pos; }
	
	void SetWidth(short width)				{ this->xw = width; }
	short GetWidth() const					{ return xw; }

	void SetHeight(short height)			{ this->yw = height; }
	short GetHeight() const					{ return yw; }

	void SetLayer(short layer)				{ this->layer = layer; }
	short GetLayer()						{ return layer; }

	
	virtual void UpdateGraphic()			{ /*empty*/	}

	virtual void Render() = 0;

	static void SetResourceManager(hgeResourceManager *rm) { resources_manager = rm; }

protected:
	hgeVector		pos;
	short			xw, yw;
	short			layer; //������� ��������� � ������������

	std::string		resource_name;

	static HGE		*hge;

	static hgeResourceManager *resources_manager;
	
};
