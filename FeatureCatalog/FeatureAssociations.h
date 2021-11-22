#pragma once

#include "..\\extlibs\\pugixml\\include\\pugixml.hpp"

#include "FeatureAssociation.h"

class FeatureAssociations :
	public XML_Item
{
public:
	FeatureAssociations(void);
	virtual ~FeatureAssociations(void);

private:
	std::unordered_map<std::wstring, FeatureAssociation> featureAssociation;
	
public:
	//void GetContents(MSXML2::IXMLDOMNodePtr pNode);
	void GetContents(pugi::xml_node& node);

	std::unordered_map<std::wstring, FeatureAssociation>& GetFeatureAssociationPointer();
};