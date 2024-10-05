// Lic:
// Kitty/Source/KittyHighPascal.cpp
// Kitty High Pascal
// version: 24.10.05
// Copyright (C) 2019, 2023, 2024 Jeroen P. Broks
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
		void KittyHighPascal() {
            static _KittyPL Me{};
            Me.caseinsensitive = true;
            Me.mulcomment = true;
            Me.mulcommentstart = "{";
            Me.mulcommentend = "}";
            _KittyHigh::Langs["pas"] = Me.Base;
            Me.Base->Language = "Pascal";
            auto
                KeyWords{ Me.KeyWords },
                BaseTypes{ Me.BaseTypes };
            KeyWords->push_back("and");
            KeyWords->push_back("array");
            KeyWords->push_back("asm");
            KeyWords->push_back("begin");
            KeyWords->push_back("break");
            KeyWords->push_back("case");
            KeyWords->push_back("const");
            KeyWords->push_back("constructor");
            KeyWords->push_back("continue");
            KeyWords->push_back("destructor");
            KeyWords->push_back("div");
            KeyWords->push_back("do");
            KeyWords->push_back("downto");
            KeyWords->push_back("else");
            KeyWords->push_back("end");
            KeyWords->push_back("false");
            KeyWords->push_back("file");
            KeyWords->push_back("for");
            KeyWords->push_back("function");
            KeyWords->push_back("goto");
            KeyWords->push_back("if");
            KeyWords->push_back("implementation");
            KeyWords->push_back("in");
            KeyWords->push_back("inline");
            KeyWords->push_back("interface");
            KeyWords->push_back("label");
            KeyWords->push_back("mod");
            KeyWords->push_back("nil");
            KeyWords->push_back("not");
            KeyWords->push_back("object");
            KeyWords->push_back("of");
            KeyWords->push_back("operator");
            KeyWords->push_back("packed");
            KeyWords->push_back("procedure");
            KeyWords->push_back("program");
            KeyWords->push_back("record");
            KeyWords->push_back("repeat");
            KeyWords->push_back("set");
            KeyWords->push_back("shl");
            KeyWords->push_back("shr");
            KeyWords->push_back("string");
            KeyWords->push_back("then");
            KeyWords->push_back("to");
            KeyWords->push_back("true");
            KeyWords->push_back("type");
            KeyWords->push_back("unit");
            KeyWords->push_back("until");
            KeyWords->push_back("uses");
            KeyWords->push_back("var");
            KeyWords->push_back("while");
            KeyWords->push_back("with");
            KeyWords->push_back("xor");

            KeyWords->push_back("Object");

            KeyWords->push_back("as");
            KeyWords->push_back("class");
            KeyWords->push_back("dispose");
            KeyWords->push_back("except");
            KeyWords->push_back("exit");
            KeyWords->push_back("exports");
            KeyWords->push_back("finalization");
            KeyWords->push_back("finally");

            KeyWords->push_back("initialization");
            KeyWords->push_back("is");
            KeyWords->push_back("library");
            KeyWords->push_back("new");
            KeyWords->push_back("on");
            KeyWords->push_back("out");
            KeyWords->push_back("property");
            KeyWords->push_back("raise");
            KeyWords->push_back("self");
            KeyWords->push_back("threadvar");
            KeyWords->push_back("try");


            KeyWords->push_back("absolute");
            KeyWords->push_back("abstract");
            KeyWords->push_back("alias");
            KeyWords->push_back("assembler");
            KeyWords->push_back("cdecl");
            KeyWords->push_back("cppdecl");
            KeyWords->push_back("default");
            KeyWords->push_back("export");
            KeyWords->push_back("external");
            KeyWords->push_back("forward");
            KeyWords->push_back("generic");
            KeyWords->push_back("index");
            KeyWords->push_back("local");
            KeyWords->push_back("name");
            KeyWords->push_back("nostackframe");
            KeyWords->push_back("oldfpccall");
            KeyWords->push_back("override");

            KeyWords->push_back("private");
            KeyWords->push_back("protected");
            KeyWords->push_back("public");
            KeyWords->push_back("published");
            KeyWords->push_back("read");
            KeyWords->push_back("register");
            KeyWords->push_back("reintroduce");
            KeyWords->push_back("safecall");
            KeyWords->push_back("softfloat");
            KeyWords->push_back("specialize");

            KeyWords->push_back("stdcall");
            KeyWords->push_back("virtual");
            KeyWords->push_back("write");


            KeyWords->push_back("far");
            KeyWords->push_back("near");

            BaseTypes->push_back("integer");
            BaseTypes->push_back("word");
            BaseTypes->push_back("shortint");
            BaseTypes->push_back("byte");
            BaseTypes->push_back("char");
            BaseTypes->push_back("string");
		}
	}
}