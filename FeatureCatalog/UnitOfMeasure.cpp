#include "stdafx.h"
#include "UnitOfMeasure.h"

//#include "..\\DLL_MessageProcess\DLL_MessageProcess.h"

UnitOfMeasure::UnitOfMeasure()
{
}


UnitOfMeasure::~UnitOfMeasure()
{
	if (definition!=nullptr)
	{
		delete definition;
		definition = nullptr;
	}


	if (symbol!=nullptr)
	{
		delete symbol;
		symbol = nullptr;
	}

}

//void UnitOfMeasure::GetContents(MSXML2::IXMLDOMNodePtr pNode)
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
//		else if (baseName.compare("definition") == 0)
//		{
//			std::wstring value = pChildNode->Gettext();
//			SetDefinition(value);
//		}
//		else if (baseName.compare("symbol") == 0)
//		{
//			std::wstring value = pChildNode->Gettext();
//			SetSymbol(value);
//		}
//	}
//}

void UnitOfMeasure::GetContents(pugi::xml_node& node)
{
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100Base:name"))
		{
			name = pugi::as_wide(instruction.child_value());
		}
		else if (!strcmp(instructionName, "S100Base:definition"))
		{
			auto value = pugi::as_wide(instruction.child_value());
			SetDefinition(value);
		}
		else if (!strcmp(instructionName, "S100Base:symbol"))
		{
			auto value = pugi::as_wide(instruction.child_value());
			SetSymbol(value);
		}
	}
}

void UnitOfMeasure::SetName(std::wstring value)
{
	name = value;
}

const std::wstring UnitOfMeasure::GetName()
{
	return name;
}

const std::wstring& UnitOfMeasure::GetNameRef()
{
	return name;
}

void UnitOfMeasure::NullCheckDefinition()
{
	if (nullptr == definition)
	{
		definition = new std::wstring();
	}
}

void UnitOfMeasure::SetDefinition(std::wstring& value)
{
	NullCheckDefinition();
	std::wstring tmp = value;
	*definition = tmp;
}

const std::wstring& UnitOfMeasure::GetDefinition()
{
	return *definition;
}

void UnitOfMeasure::NullCheckSymbol()
{
	if (nullptr == symbol)
	{
		symbol = new std::wstring();
	}
}

void UnitOfMeasure::SetSymbol(std::wstring& value) 
{
	NullCheckSymbol();
	*symbol = value;
}

const std::wstring& UnitOfMeasure::GetSymbol()
{
	return *symbol;
}