# khoa-lib-s100fc
Visual C++ IHO S-100 Feature Catalogue library

## Major features
- Read a feature catalogue. 
- Support S-100 4.0
- Retreive detailed information of a feature catalogue.

## Requiremtns
- Visual Studio 2017+
- Visual C++ 32bit
- Windows 7+
- [pugixml](https://pugixml.org/)

## Usage at a glance
~~~~~~~~~~cpp
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
~~~~~~~~~~


# Project participants
- [Korea Hydrographic and Oceanographic Agency (KHOA)](https://www.khoa.go.kr/eng/)
- [Korea Research Institute of Ships and Ocean (KRISO)](https://www.kriso.re.kr/eng/)
- THE PROST Inc.

## Copyright and Licensing
You can use, modify and distribute under the MPL 2.0. 
