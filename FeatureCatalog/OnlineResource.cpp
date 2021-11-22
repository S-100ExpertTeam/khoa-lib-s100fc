#include "stdafx.h"
#include "OnlineResource.h"

//#include "..\\DLL_MessageProcess\DLL_MessageProcess.h"
OnlineResource::OnlineResource()
{
}

OnlineResource::~OnlineResource()
{
}

//void OnlineResource::GetContents(MSXML2::IXMLDOMNodePtr pNode)
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
//		if (baseName.compare("url") == 0)
//		{
//			url = pChildNode->Gettext();
//		}
//		else if (baseName.compare("protocol") == 0)
//		{
//			protocol = pChildNode->Gettext();
//		}
//		else if (baseName.compare("applicationProfile") == 0)
//		{
//			applicationProfile = pChildNode->Gettext();
//		}
//		else if (baseName.compare("name") == 0)
//		{
//			name = pChildNode->Gettext();
//		}
//		else if (baseName.compare("description") == 0)
//		{
//			description = pChildNode->Gettext();
//		}
//		else if (baseName.compare("function") == 0)
//		{
//			function.GetContents(pChildNode);
//		}
//	}
//}

void OnlineResource::GetContents(pugi::xml_node& node)
{
	//S100CI
	for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
	{
		const pugi::char_t* instructionName = instruction.name();

		if (!strcmp(instructionName, "S100CI:url"))
		{
			SetUrl(pugi::as_wide(instruction.child_value()));
			//url = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:url setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:protocol"))
		{
			SetProtocol(pugi::as_wide(instruction.child_value()));
			//protocol = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:protocol setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:applicationProfile"))
		{
			SetApplicationProfile(pugi::as_wide(instruction.child_value()));
			//applicationProfile = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:applicationProfile setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:name"))
		{
			SetName(pugi::as_wide(instruction.child_value()));
			//name = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:name setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:description"))
		{
			SetDescription(pugi::as_wide(instruction.child_value()));
			//description = pugi::as_wide(instruction.child_value());
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:description setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:function"))
		{
			function.GetContents(instruction);
			////KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, L"S100CI:function setting Clear", ENCCommon::Developer_Mode, ENCCommon::FC);
		}
		else if (!strcmp(instructionName, "S100CI:linkage"))
		{
			SetLinkage(instruction.child_value());
			//linkage = instruction.child_value();
		}
		else
		{
			std::wstring content = pugi::as_wide(instructionName);
			content.append(L" is another data");
			//KRS_MSG_PROCESS::SendMessageToTargetWindow(KRS_MSG_INFO, content.c_str(),//KRS_MSG_PROCESS::Developer_Mode,//KRS_MSG_PROCESS::FC);
		}
	}
}

void OnlineResource::SetUrl(std::wstring value)
{
	url = value;
}

const std::wstring& OnlineResource::GetUrl()
{
	return url;
}

void OnlineResource::SetProtocol(std::wstring value) 
{
	protocol = value;
}

const std::wstring& OnlineResource::GetProtocol()
{
	return protocol;
}

void OnlineResource::SetApplicationProfile(std::wstring value) 
{
	applicationProfile = value;
}
const std::wstring& OnlineResource::GetApplicationProfile()
{
	return applicationProfile;
}

void OnlineResource::SetName(std::wstring value) 
{
	name = value;
}
const std::wstring& OnlineResource::GetName()
{
	return name;
}

void OnlineResource::SetDescription(std::wstring value) 
{
	description = value;
}
const std::wstring& OnlineResource::GetDescription()
{
	return description;
}

void OnlineResource::SetFunction(OnlineFunctionCode value)
{
	function = value;
}

OnlineFunctionCode& OnlineResource::GetFunction() 
{
	return function;
}

void OnlineResource::SetLinkage(std::string value) 
{
	linkage = value;
}
const std::string& OnlineResource::GetLinkage()
{
	return linkage;
}