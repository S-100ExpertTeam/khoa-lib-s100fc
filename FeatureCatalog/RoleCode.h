#pragma once

#include "Restriction_Item.h"

#include "..\\extlibs\\pugixml\\include\\pugixml.hpp"

class RoleCode :
	public Restriction_Item
{
public:
	RoleCode();
	virtual ~RoleCode();

public:
	//void GetContents(MSXML2::IXMLDOMNodePtr pNode);
	void GetContents(pugi::xml_node& node);
};