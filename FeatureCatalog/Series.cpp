#include "stdafx.h"
#include "Series.h"


Series::Series()
{
}


Series::~Series()
{
}


//void Series::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
//
//	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
//
//	int cnt = pNodeList->Getlength();
//	for (int i = 0; i < cnt; i++) {
//		MSXML2::IXMLDOMNodePtr pChildNode = pNodeList->Getitem(i);
//		if (pChildNode == NULL)
//			continue;
//		if (!pChildNode->baseName)
//			continue;
//
//		std::string baseName = std::string(W2A(pChildNode->baseName));
//
//		if (baseName.compare("name") == 0)
//		{
//			name = pChildNode->Gettext();
//		}
//		else if (baseName.compare("issueIdentification") == 0)
//		{
//			issueIdentification = pChildNode->Gettext();
//		}
//		else if (baseName.compare("page") == 0)
//		{
//			page = pChildNode->Gettext();
//		}
//	}
//}

void Series::GetContents(pugi::xml_node& node)
{
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100CI:name"))
		{
			name = pugi::as_wide(instruction.child_value());
		}
		else if (!strcmp(instructionName, "S100CI:issueIdentification"))
		{
			issueIdentification = pugi::as_wide(instruction.child_value());
		}
		else if (!strcmp(instructionName, "S100CI:page"))
		{
			page = pugi::as_wide(instruction.child_value());
		}
	}
	//auto findNode = node.child("S100CI:name");
	//if (findNode)
	//{
	//	name = pugi::as_wide(findNode.child_value());
	//}
	//findNode = node.child("S100CI:issueIdentification");
	//if (findNode)
	//{
	//	issueIdentification = pugi::as_wide(findNode.child_value());
	//}
	//findNode = node.child("S100CI:page");
	//if (findNode)
	//{
	//	page = pugi::as_wide(findNode.child_value());
	//}
}

void Series::SetName() 
{
	name = Getvalue();
}
const std::wstring& Series::GetName()
{
	return name;
}

void Series::SetIssueIdentification(std::wstring value) 
{
	issueIdentification = value;
}
const std::wstring& Series::GetIssueIdentification()
{
	return issueIdentification;
}

void Series::SetPage(std::wstring valeu) 
{
	page = Getvalue();
}

const std::wstring& Series::GetPage()
{
	return page;
}