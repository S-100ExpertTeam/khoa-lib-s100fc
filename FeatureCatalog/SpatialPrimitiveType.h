#pragma once

#include "Restriction_Item.h"

#include "..\\extlibs\\pugixml\\include\\pugixml.hpp"

class SpatialPrimitiveType :
	public Restriction_Item 
{
public:
	SpatialPrimitiveType();
	virtual ~SpatialPrimitiveType();

public:
	//void GetContents(MSXML2::IXMLDOMNodePtr pNode);
	void GetContents(pugi::xml_node& node);
};