#include "stdafx.h"
#include "Telephone.h"

//#include "..\\DLL_MessageProcess\DLL_MessageProcess.h"

Telephone::Telephone()
{
}

Telephone::~Telephone()
{
}

//void Telephone::GetContents(MSXML2::IXMLDOMNodePtr pNode)
//{
//	USES_CONVERSION;
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
//		if (baseName.compare("voice") == 0)
//		{
//			voice.push_back(std::wstring(pChildNode->Gettext()));
//		}
//		else if (baseName.compare("facsimile") == 0)
//		{
//			facsimile = pChildNode->Gettext();
//		}
//	}
//}

void Telephone::GetContents(pugi::xml_node& node)
{
	//S100CI
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();
		if (!strcmp(instructionName, "S100CI:voice"))
		{
			voice.push_back(pugi::as_wide(instruction.child_value()));
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:voice setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:facsimile"))
		{
			facsimile = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:facsimile setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else 
		{
			std::wstring content = pugi::as_wide(instructionName);
			content.append(L"is another data");
			//KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, content.c_str(),//KRS_MSG_PROCESS::Developer_Mode,//KRS_MSG_PROCESS::FC);
		}
	}
}

void Telephone::SetVoice(std::wstring value) 
{
	voice.push_back(value);
}

void Telephone::SetVoice(std::list<std::wstring> value)
{
	voice = value;
}

std::list<std::wstring>& Telephone::GetVoicePointer()
{
	return voice;
}

const std::wstring& Telephone::GetVoice(int index)
{
	auto it = voice.begin();
	std::advance(it,index);


	return *it;
}

void Telephone::SetFacsimile(std::wstring value) 
{
	facsimile = value;
}

const std::wstring& Telephone::GetFacsimile()
{
	return facsimile;
}