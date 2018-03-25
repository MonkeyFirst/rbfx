//
// Copyright (c) 2008-2018 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once


#include <Urho3D/Core/Object.h>
#include "Pass/CppPass.h"
#include "Printer/CSharpPrinter.h"

namespace Urho3D
{

class DiscoverInterfacesPass;

class GeneratePInvokePass : public CppApiPass
{
    URHO3D_OBJECT(GeneratePInvokePass, CppApiPass);
public:
    explicit GeneratePInvokePass(Context* context) : CppApiPass(context) { };

    void Start() override;
    bool Visit(MetaEntity* entity, cppast::visitor_info info) override;
    void Stop() override;

    static std::string ToPInvokeTypeReturn(const cppast::cpp_type& type);
    static std::string ToPInvokeTypeParam(const cppast::cpp_type& type);
    static std::string ToPInvokeType(const cppast::cpp_type& type, bool disallowReferences=false);

protected:
    CSharpPrinter printer_;
    DiscoverInterfacesPass* discoverInterfacesPass_ = nullptr;
};

}
