#include "StdAfx.h"
#include "InformationTypes.h"

InformationTypes::InformationTypes(void)
{
	//informationType = NULL;
}


InformationTypes::~InformationTypes(void)
{
}

//void InformationTypes::GetContents(MSXML2::IXMLDOMNodePtr pNode)
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
//		if (baseName.compare("S100_FC_InformationType") == 0)
//		{
//			InformationType it;
//			it.GetContents(pChildNode);
//			informationType.insert(
//				//std::unordered_map<std::wstring, InformationType>::value_type(it.code.GetValueString(), it)
//				std::unordered_map<std::wstring, InformationType>::value_type(it.GetCodeAsWString(), it)
//			);
//		}
//	}
//}
void InformationTypes::GetContents(pugi::xml_node& node)
{
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100FC:S100_FC_InformationType"))
		{
			InformationType sa;
			sa.GetContents(instruction);
			//informationType[sa.code.GetValueString()] = sa;
			informationType[sa.GetCodeAsWString()] = sa;
			if (instruction.attribute("isAbstract"))
			{
				XML_Attribute value;
				value.Setname("isAbstract");
				value.Setvalue((char*)instruction.attribute("isAbstract").value());

				SetAttributes(value);
			}
		}
	}
}

bool InformationTypes::SetAssociationFromSuperType(InformationType* it)
{
	if (it->GetSuperType().size() > 0)
	{
		auto itor = informationType.find(it->GetSuperType());
		if (itor == informationType.end())
		{
			return false;
		}
		else
		{
			InformationType* sit = &itor->second;
			if (SetAssociationFromSuperType(sit))
			{
				it->GetInformationBindingPointer().insert(sit->GetInformationBindingPointer().begin(), sit->GetInformationBindingPointer().end());
			}
			return true;
		}

	}
	else
		return true;

	return false;

}

std::unordered_map<std::wstring, InformationType>& InformationTypes::GetInformationTypePointer()
{
	return informationType;
}
