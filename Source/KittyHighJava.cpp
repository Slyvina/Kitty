// Lic:
// Kitty/Source/KittyHighJava.cpp
// Kitty High Java
// version: 24.10.05
// Copyright (C) 2019, 2024 Jeroen P. Broks
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
		void KittyHighJava() {
			static _KittyPL Me{};
            auto B{ Me.Base };
            auto KeyWords{ Me.KeyWords };
            // Since I never worked with Java this has NOT been tested, so I really won't know if this works.
            // Since Java is just one of the many C dialects out there, I don't see why it won't but, who am I to talk?
            KeyWords->push_back("abstract");
            KeyWords->push_back("assert");
            KeyWords->push_back("boolean");
            KeyWords->push_back("break");
            KeyWords->push_back("byte");
            KeyWords->push_back("case");
            KeyWords->push_back("catch");
            KeyWords->push_back("char");
            KeyWords->push_back("class");
            KeyWords->push_back("continue");
            KeyWords->push_back("const");
            KeyWords->push_back("default");
            KeyWords->push_back("do");
            KeyWords->push_back("double");
            KeyWords->push_back("else");
            KeyWords->push_back("enum");
            KeyWords->push_back("exports");
            KeyWords->push_back("extends");
            KeyWords->push_back("final");
            KeyWords->push_back("finally");
            KeyWords->push_back("float");
            KeyWords->push_back("for");
            KeyWords->push_back("goto");
            KeyWords->push_back("if");
            KeyWords->push_back("implements");
            KeyWords->push_back("import");
            KeyWords->push_back("instanceof");
            KeyWords->push_back("int");
            KeyWords->push_back("interface");
            KeyWords->push_back("long");
            KeyWords->push_back("module");
            KeyWords->push_back("native");
            KeyWords->push_back("new");
            KeyWords->push_back("package");
            KeyWords->push_back("private");
            KeyWords->push_back("protected");
            KeyWords->push_back("public");
            KeyWords->push_back("requires");
            KeyWords->push_back("return");
            KeyWords->push_back("short");
            KeyWords->push_back("static");
            KeyWords->push_back("strictfp");
            KeyWords->push_back("super");
            KeyWords->push_back("switch");
            KeyWords->push_back("synchronized");
            KeyWords->push_back("this");
            KeyWords->push_back("throw");
            KeyWords->push_back("throws");
            KeyWords->push_back("transient");
            KeyWords->push_back("try");
            KeyWords->push_back("var");
            KeyWords->push_back("void");
            KeyWords->push_back("volatile");
            KeyWords->push_back("while");
            B->Language = "Java";
            B->Langs["java"] = B;
		}
	}
}