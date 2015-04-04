#include "Initiate.h"

#include <hgeresource.h>

#include "GraphicObject.h"
#include "GraphicDynamicObject.h"


hgeResourceManager* CreateResourceManager()
{
	hgeResourceManager *rm = new hgeResourceManager;
	GraphicObject::SetResourceManager(rm);
	return rm;
}
