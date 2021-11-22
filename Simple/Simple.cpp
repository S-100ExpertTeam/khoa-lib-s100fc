// Simple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Simple.h"

#include "../FeatureCatalog/FeatureCatalogue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
            FeatureCatalogue fc;

            // Read a S-100 FC
            fc.Read(L"../SampleData/S-101_FC.xml");

            // Get a feature type
            auto featureDepthArea = fc.GetFeatureType(L"DepthArea");
            if (featureDepthArea)
            {
                // Retrieve attributes of a feature type
                auto attributeList = featureDepthArea->GetAttributeBindingPointer();
                for (auto i = attributeList.begin(); i != attributeList.end(); i++)
                {
                    // Get a code of attribute
                    std::wstring code = i->GetAttribute().GetReference();
                }
            }
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
