#include "stdafx.h"
#include "FeatureAssociation.h"


FeatureAssociation::FeatureAssociation()
{
}


FeatureAssociation::~FeatureAssociation()
{
}

//void FeatureAssociation::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
//
//	this->NamedType::GetContents(pNode);
//
//	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
//
//	int roleCnt = 0;
//
//	int cnt = pNodeList->Getlength();
//	for (int i = 0; i < cnt; i++) 
//	{
//		MSXML2::IXMLDOMNodePtr pChildNode = pNodeList->Getitem(i);
//		if (pChildNode == NULL)
//			continue;
//		if (!pChildNode->baseName)
//			continue;
//
//		std::string baseName = std::string(W2A(pChildNode->baseName));
//
//		if (baseName.compare("superType") == 0)
//		{
//			superType = pChildNode->Gettext();
//		}
//		else if (baseName.compare("subType") == 0)
//		{
//			subType.push_back(std::wstring(pChildNode->Gettext()));
//		}
//		else if (baseName.compare("role") == 0)
//		{
//			role[roleCnt].GetContents(pChildNode);
//			roleCnt++;
//		}
//	}
//}

void FeatureAssociation::GetContents(pugi::xml_node& node)
{
	this->NamedType::GetContents(node);

	int count = 0;
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100FC:role"))
		{
			Reference reference;
			reference.GetContents(instruction);
			role[count] = reference;
			count++;
		}
		else if (!strcmp(instructionName, "S100FC:superType"))
		{
			superType = pugi::as_wide(instruction.child_value());
		}

		else if (!strcmp(instructionName, "S100FC:subType"))
		{
			subType.push_back(pugi::as_wide(instruction.child_value()));
		}
	}
}

std::list<std::wstring> &FeatureAssociation::GetSubTypePointer()
{
	return subType;
}

std::wstring& FeatureAssociation::GetSuperType()
{
	return superType;
}

Reference(&FeatureAssociation::GetRolePointer())[2]
{
	return role;
}