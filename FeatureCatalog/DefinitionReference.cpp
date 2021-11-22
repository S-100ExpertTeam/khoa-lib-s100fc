#include "stdafx.h"
#include "DefinitionReference.h"


DefinitionReference::DefinitionReference()
{
}


DefinitionReference::~DefinitionReference()
{
}

//void DefinitionReference::GetContents(MSXML2::IXMLDOMNodePtr pNode)
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
//		if (baseName.compare("sourceIdentifier") == 0)
//		{
//			sourceIdentifier = pChildNode->Gettext();
//		}
//		else if (baseName.compare("definitionSource") == 0)
//		{
//			definitionSource.GetContents(pChildNode);
//		}
//	}
//}
void DefinitionReference::GetContents(pugi::xml_node& node) 
{
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100FC:sourceIdentifier"))
		{
			sourceIdentifier = pugi::as_wide(instruction.child_value());
		}
		else if (!strcmp(instructionName, "S100FC:definitionSource"))
		{
			definitionSource.GetContents(instruction);
		}
	}
	/*auto findNode = node.child("S100FC:sourceIdentifier");
	if (findNode)
	{
		sourceIdentifier = pugi::as_wide(findNode.child_value());
	}

	findNode = node.child("S100FC:definitionSource");
	if (findNode)
	{
		definitionSource.GetContents(findNode);
	}*/
}

void DefinitionReference::SetSourceIdentifier(std::wstring value)
{
	sourceIdentifier = value;
}

const std::wstring& DefinitionReference::GetSourceIdentifier()
{
	return sourceIdentifier;
}

void DefinitionReference::SetDefinitionSource(Reference value) 
{
	definitionSource = value;
}

Reference& DefinitionReference::GetDefinitionSource() 
{
	return definitionSource;
}