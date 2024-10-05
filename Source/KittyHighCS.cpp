// Lic:
// Kitty/Source/KittyHighCS.cpp
// Kitty - C# support
// version: 24.10.05
// Copyright (C) 2019, 2020, 2023, 2024 Jeroen P. Broks
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
#include "../Headers/Kitty_High.hpp"

namespace Slyvina {
	namespace Kitty { 
		void KittyHighCS() {
			static _KittyPL Me{};
			Me.BaseTypes->push_back("bool");
			Me.BaseTypes->push_back("byte");
			Me.BaseTypes->push_back("sbyte");
			Me.BaseTypes->push_back("char");
			Me.BaseTypes->push_back("decimal");
			Me.BaseTypes->push_back("double");
			Me.BaseTypes->push_back("float");
			Me.BaseTypes->push_back("int");
			Me.BaseTypes->push_back("uint");
			Me.BaseTypes->push_back("long");
			Me.BaseTypes->push_back("ulong");
			Me.BaseTypes->push_back("short");
			Me.BaseTypes->push_back("ushort");
			Me.KeyWords->push_back("abstract");
			Me.KeyWords->push_back("as");
			Me.KeyWords->push_back("base");
			Me.KeyWords->push_back("break");
			Me.KeyWords->push_back("case");
			Me.KeyWords->push_back("catch");
			Me.KeyWords->push_back("checked");
			Me.KeyWords->push_back("class");
			Me.KeyWords->push_back("const");
			Me.KeyWords->push_back("continue");
			Me.KeyWords->push_back("default");
			Me.KeyWords->push_back("delegate");
			Me.KeyWords->push_back("do");
			Me.KeyWords->push_back("else");
			Me.KeyWords->push_back("enum");
			Me.KeyWords->push_back("event");
			Me.KeyWords->push_back("explicit");
			Me.KeyWords->push_back("extern");
			Me.KeyWords->push_back("false");
			Me.KeyWords->push_back("finally");
			Me.KeyWords->push_back("fixed");
			Me.KeyWords->push_back("for");
			Me.KeyWords->push_back("foreach");
			Me.KeyWords->push_back("goto"); // EEEEW!
			Me.KeyWords->push_back("if");
			Me.KeyWords->push_back("implicit");
			Me.KeyWords->push_back("in");
			Me.KeyWords->push_back("interface");
			Me.KeyWords->push_back("internal");
			Me.KeyWords->push_back("is");
			Me.KeyWords->push_back("lock");
			Me.KeyWords->push_back("namespace");
			Me.KeyWords->push_back("new");
			Me.KeyWords->push_back("null");
			Me.KeyWords->push_back("object");
			Me.KeyWords->push_back("operator");
			Me.KeyWords->push_back("out");
			Me.KeyWords->push_back("override");
			Me.KeyWords->push_back("params");
			Me.KeyWords->push_back("private");
			Me.KeyWords->push_back("protected");
			Me.KeyWords->push_back("public");
			Me.KeyWords->push_back("readonly");
			Me.KeyWords->push_back("ref");
			Me.KeyWords->push_back("return");
			Me.KeyWords->push_back("sealed");
			Me.KeyWords->push_back("sizeof");
			Me.KeyWords->push_back("stackalloc");
			Me.KeyWords->push_back("static");
			Me.KeyWords->push_back("string");
			Me.KeyWords->push_back("struct");
			Me.KeyWords->push_back("switch");
			Me.KeyWords->push_back("this");
			Me.KeyWords->push_back("throw");
			Me.KeyWords->push_back("true");
			Me.KeyWords->push_back("try");
			Me.KeyWords->push_back("typeof");
			Me.KeyWords->push_back("unchecked");
			Me.KeyWords->push_back("unsafe");
			Me.KeyWords->push_back("using");
			Me.KeyWords->push_back("virtual");
			Me.KeyWords->push_back("volatile");
			Me.KeyWords->push_back("while");

			// Since we've them for VB here are unreserved Me.KeyWords

			Me.KeyWords->push_back("add");
			Me.KeyWords->push_back("alias");
			Me.KeyWords->push_back("ascending");
			Me.KeyWords->push_back("async");
			Me.KeyWords->push_back("await");
			Me.KeyWords->push_back("by");
			Me.KeyWords->push_back("descending");
			Me.KeyWords->push_back("dynamic");
			Me.KeyWords->push_back("equals");
			Me.KeyWords->push_back("from");
			Me.KeyWords->push_back("get");
			Me.KeyWords->push_back("global");
			Me.KeyWords->push_back("group");
			Me.KeyWords->push_back("into");
			Me.KeyWords->push_back("join");
			Me.KeyWords->push_back("let");
			Me.KeyWords->push_back("nameof");
			Me.KeyWords->push_back("notnull");
			Me.KeyWords->push_back("on");
			Me.KeyWords->push_back("oderby");
			Me.KeyWords->push_back("partial");
			Me.KeyWords->push_back("remove");
			Me.KeyWords->push_back("select");
			Me.KeyWords->push_back("set");
			Me.KeyWords->push_back("unmanaged");
			Me.KeyWords->push_back("value");
			Me.KeyWords->push_back("var");
			Me.KeyWords->push_back("void");
			Me.KeyWords->push_back("when");
			Me.KeyWords->push_back("where");
			Me.KeyWords->push_back("yield");

			_KittyHigh::Langs["cs"] = Me.Base;
			Me.Base->Language = "C#";
		} 
	}
}