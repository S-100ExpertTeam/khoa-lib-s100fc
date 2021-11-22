#include "stdafx.h"
#include "SimpleAttribute.h"
#include "S100_CD_AttributeValueType.h"

//#include "../LibMFCUtil/LibMFCUtil.h" 

SimpleAttribute::SimpleAttribute()
{
}


SimpleAttribute::~SimpleAttribute()
{
}


//void SimpleAttribute::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
//
//	((Attribute*)this)->Attribute::GetContents(pNode);
//
//	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
//
//	int cnt = pNodeList->Getlength();
//	for (int i = 0; i < cnt; i++) {
//		MSXML2::IXMLDOMNodePtr pChildNode = pNodeList->Getitem(i);
//		if (pChildNode == NULL)
//			continue;
//
//		bstr_t bstr = pChildNode->baseName;
//		if (!!bstr)
//		{
//			std::string baseName = std::string(W2A(bstr));
//
//			if (baseName.compare("valueType") == 0)
//			{
//				std::wstring value = pChildNode->Gettext();
//				valueType = FCD::StringToS100_CD_AttributeValueType(value);
//			}
//			else if (baseName.compare("uom") == 0)
//			{
//				uom.GetContents(pChildNode);
//			}
//			else if (baseName.compare("quantitySpecification") == 0)
//			{
//				std::wstring value = pChildNode->Gettext();
//				quantitySpecification = FCD::StringToS100_CD_QuantitySpecification(value);
//			}
//			else if (baseName.compare("constraints") == 0)
//			{
//				constraints.GetContents(pChildNode);
//			}
//			else if (baseName.compare("listedValues") == 0)
//			{
//				ListedValues lvs;
//				lvs.GetContents(pChildNode);
//				listedValues.push_back(lvs);
//			}
//		}
//	}
//	OutputDebugString(L"");
//}
void SimpleAttribute::GetContents(pugi::xml_node& node)
{
	((Attribute*)this)->Attribute::GetContents(node);
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();

		if (!strcmp(instructionName, "S100FC:valueType"))
		{
			std::string value = instruction.child_value();
			valueType = FCD::StringToS100_CD_AttributeValueType(value);

			//valueType.GetContents(instruction);
		}
		else if (!strcmp(instructionName, "S100FC:uom"))
		{
			uom.GetContents(instruction);
		}
		else if (!strcmp(instructionName, "S100FC:quantitySpecification"))
		{
			std::string value = instruction.child_value();
			quantitySpecification = FCD::StringToS100_CD_QuantitySpecification(value);
		}
		else if (!strcmp(instructionName, "S100FC:constraints"))
		{
			constraints.GetContents(instruction);
		}
		else if (!strcmp(instructionName, "S100FC:listedValues"))
		{
			listedValues.push_back(ListedValues());
			listedValues.back().GetContents(instruction);
		}
	}
}

UnitOfMeasure& SimpleAttribute::GetUOMRef()
{
	return uom;
}

FCD::S100_CD_AttributeValueType SimpleAttribute::GetValueType() 
{
	return valueType;
}

void SimpleAttribute::SetValueType(FCD::S100_CD_AttributeValueType value)
{
	valueType = value;
}


FCD::S100_CD_QuantitySpecification SimpleAttribute::GetQuantitySpecification()
{
	return quantitySpecification;
}

void SimpleAttribute::SetQuantitySpecification(FCD::S100_CD_QuantitySpecification value)
{
	quantitySpecification = value;
}

AttributeConstraints& SimpleAttribute::GetConstraintsPointer()
{
	return constraints;
}

std::list<ListedValues>& SimpleAttribute::GetListedValuesPointer()
{
	return listedValues;
}