// Lic:
// Kitty/Source/KittyHighGo.cpp
// Kitty High Go
// version: 24.10.05
// Copyright (C) 2019-2024 Jeroen P. Broks
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
// EndLic
#include <Kitty_High.hpp>
namespace Slyvina {
	namespace Kitty {
		void KittyHighGo() {
            static _KittyPL Me{};
            auto B{ Me.Base };
            auto KeyWords{ Me.KeyWords }, BaseTypes{ Me.BaseTypes };
            B->Langs["go"] = B;
            B->Language = "Go";
            KeyWords->push_back("break");
            KeyWords->push_back("default");
            KeyWords->push_back("func");
            KeyWords->push_back("interface");
            KeyWords->push_back("select");
            KeyWords->push_back("case");
            KeyWords->push_back("defer");
            KeyWords->push_back("go");
            KeyWords->push_back("map");
            KeyWords->push_back("struct");
            KeyWords->push_back("chan");
            KeyWords->push_back("else");
            KeyWords->push_back("goto");
            KeyWords->push_back("package");
            KeyWords->push_back("switch");
            KeyWords->push_back("const");
            KeyWords->push_back("fallthrough");
            KeyWords->push_back("if");
            KeyWords->push_back("range");
            KeyWords->push_back("type");
            KeyWords->push_back("continue");
            KeyWords->push_back("for");
            KeyWords->push_back("import");
            KeyWords->push_back("return");
            KeyWords->push_back("var");

            BaseTypes->push_back("string");
            BaseTypes->push_back("int");
            BaseTypes->push_back("int32");
            BaseTypes->push_back("int64");
            BaseTypes->push_back("map");
            BaseTypes->push_back("array");
		}
	}
}