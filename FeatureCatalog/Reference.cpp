#include "stdafx.h"
#include "Reference.h"


Reference::Reference()
{
}


Reference::~Reference()
{
}

//void Reference::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
//
//	MSXML2::IXMLDOMNamedNodeMapPtr pAttr = pNode->Getattributes();
//	MSXML2::IXMLDOMNodePtr pAttrNP;
//	pAttrNP = pAttr->getNamedItem(L"ref");
//	VARIANT value;
//	if (pAttrNP)
//	{
//		pAttrNP->get_nodeValue(&value);
//
//		XML_Attribute attr;
//		attr.Setname("ref");
//		attr.Setvalue((char*)value.bstrVal);
//		SetAttributes(attr);
//		//attributes.push_back(attr);
//	}
//
//	//MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
//
//	//int cnt = pNodeList->Getlength();
//	//for (int i = 0; i < cnt; i++) {
//	//	MSXML2::IXMLDOMNodePtr pChildNode = pNodeList->Getitem(i);
//	//	if (pChildNode == NULL)
//	//		continue;
//	//if (!pChildNode->baseName)
//	//	continue;
//
//	//	std::string baseName = std::string(W2A(pChildNode->baseName));
//
//	//	if (baseName.compare("ref") == 0)
//	//	{
//	//		ref = pChildNode->Gettext();
//	//	}
//	//}
//}

void Reference::GetContents(pugi::xml_node& node)
{
	for (auto attri =node.first_attribute(); attri; attri =attri.next_attribute())
	{
		auto attriName = attri.name();
		if (!strcmp(attriName,"ref"))
		{
			XML_Attribute attr;
			attr.Setname("ref");
			attr.Setvalue((char*)node.attribute("ref").value());
			SetAttributes(attr);

			//attributes.push_back(XML_Attribute());
			//attributes.back().Setname(L"ref");
			//attributes.back().Setvalue(pugi::as_wide(node.attribute("ref").value()));
		}
	}
}