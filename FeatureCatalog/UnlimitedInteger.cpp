#include "stdafx.h"
#include "UnlimitedInteger.h"

//#include "..\\DLL_MessageProcess\DLL_MessageProcess.h"

#include <string>

UnlimitedInteger::UnlimitedInteger()
{
}


UnlimitedInteger::~UnlimitedInteger()
{
}


//void UnlimitedInteger::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
//	MSXML2::IXMLDOMNamedNodeMapPtr pAttr = pNode->Getattributes();
//	MSXML2::IXMLDOMNodePtr pAttrNP;
//	pAttrNP = pAttr->getNamedItem(L"infinite");
//	VARIANT value;
//	if (pAttrNP)
//	{
//		pAttrNP->get_nodeValue(&value);
//
//		XML_Attribute attr;
//		attr.Setname("infinite");
//		attr.Setvalue((char*)value.bstrVal);
//		//attributes.push_back(attr);
//
//		SetAttributes(attr);
//
//	}
//
//	this->Setvalue(std::wstring(pNode->Gettext()));
//}
void UnlimitedInteger::GetContents(pugi::xml_node& node)
{
	std::wstring name = pugi::as_wide(node.name());

	if (node.attribute("infinite")) 
	{
		XML_Attribute value;
		value.Setname("infinite");
		value.Setvalue((char*)node.attribute("infinite").value());
		/*attributes.push_back(XML_Attribute());
		attributes.back().name = L"infinite";
		attributes.back().value = pugi::as_wide(node.attribute("infinite").value());*/
		
		SetAttributes(value);

	/*	name.append(attributes.back().name);
		name.append(L"is clear");

		//KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, name.c_str(), ENCCommon::Developer_Mode, ENCCommon::FC);*/
	}
	if (node.attribute("xsi:nil"))
	{
		XML_Attribute value;
		value.Setname("nil");
		value.Setvalue((char*)node.attribute("xsi:nil").value());
		SetAttributes(value);

		/*attributes.push_back(XML_Attribute());
		attributes.back().name = L"nil";
		attributes.back().value = pugi::as_wide(node.attribute("xsi:nil").value());*/

		//name.append(attributes.back().name);
		//name.append(L"is clear");

		////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, name.c_str(), ENCCommon::Developer_Mode, ENCCommon::FC);
	}

	this->Setvalue(pugi::as_wide(node.child_value()));
}