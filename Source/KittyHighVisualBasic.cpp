// Lic:
// Kitty/Source/KittyHighVisualBasic.cpp
// Kitty High Visual Basic
// version: 24.10.05
// Copyright (C) 2019 freezernick & Jeroen P. Broks
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
		void KittyHighVB() {
			static _KittyPL Me{};
			auto B{ Me.Base };
			auto KeyWords{ Me.KeyWords }, BaseTypes{ Me.BaseTypes };
			B->Langs["vb"] = B;
			B->Language = "VisualBasic";
			Me.singcomment = "'";
			Me.mulcomment = false;
			Me.caseinsensitive = true;
			KeyWords->push_back("addhandler");
			KeyWords->push_back("addressof");
			KeyWords->push_back("alias");
			KeyWords->push_back("and");
			KeyWords->push_back("andalso");
			KeyWords->push_back("as");
			KeyWords->push_back("byref");
			KeyWords->push_back("byval");
			KeyWords->push_back("call");
			KeyWords->push_back("case");
			KeyWords->push_back("catch");
			KeyWords->push_back("cbool");
			KeyWords->push_back("cbyte");
			KeyWords->push_back("cchar");
			KeyWords->push_back("cdate");
			KeyWords->push_back("cdbl");
			KeyWords->push_back("cdec");
			KeyWords->push_back("cint");
			KeyWords->push_back("class");
			KeyWords->push_back("clng");
			KeyWords->push_back("cobj");
			KeyWords->push_back("const");
			KeyWords->push_back("continue");
			KeyWords->push_back("csbyte");
			KeyWords->push_back("cshort");
			KeyWords->push_back("csng");
			KeyWords->push_back("cstr");
			KeyWords->push_back("ctype");
			KeyWords->push_back("cuint");
			KeyWords->push_back("culng");
			KeyWords->push_back("cushort");
			KeyWords->push_back("declare");
			KeyWords->push_back("default");
			KeyWords->push_back("delegate");
			KeyWords->push_back("dim");
			KeyWords->push_back("directcast");
			KeyWords->push_back("do");
			KeyWords->push_back("each");
			KeyWords->push_back("else");
			KeyWords->push_back("elseif");
			KeyWords->push_back("end");
			KeyWords->push_back("enum");
			KeyWords->push_back("erase");
			KeyWords->push_back("error");
			KeyWords->push_back("event");
			KeyWords->push_back("exit");
			KeyWords->push_back("false");
			KeyWords->push_back("finally");
			KeyWords->push_back("for");
			KeyWords->push_back("friend");
			KeyWords->push_back("function");
			KeyWords->push_back("get");
			KeyWords->push_back("gettype");
			KeyWords->push_back("getxmlnamespace");
			KeyWords->push_back("global");
			KeyWords->push_back("goto");
			KeyWords->push_back("handles");
			KeyWords->push_back("if");
			KeyWords->push_back("implements");
			KeyWords->push_back("imports");
			KeyWords->push_back("in");
			KeyWords->push_back("inherits");
			KeyWords->push_back("interface");
			KeyWords->push_back("is");
			KeyWords->push_back("isnot");
			KeyWords->push_back("let");
			KeyWords->push_back("lib");
			KeyWords->push_back("like");
			KeyWords->push_back("loop");
			KeyWords->push_back("me");
			KeyWords->push_back("mod");
			KeyWords->push_back("module");
			KeyWords->push_back("mustinherit");
			KeyWords->push_back("mustoverride");
			KeyWords->push_back("mybase");
			KeyWords->push_back("myclass");
			KeyWords->push_back("namespace");
			KeyWords->push_back("narrowing");
			KeyWords->push_back("new constraint");
			KeyWords->push_back("new operator");
			KeyWords->push_back("next");
			KeyWords->push_back("not");
			KeyWords->push_back("nothing");
			KeyWords->push_back("noninheritable");
			KeyWords->push_back("notoverridable");
			KeyWords->push_back("of");
			KeyWords->push_back("on");
			KeyWords->push_back("operator");
			KeyWords->push_back("option");
			KeyWords->push_back("optional");
			KeyWords->push_back("or");
			KeyWords->push_back("orelse");
			KeyWords->push_back("out");
			KeyWords->push_back("overloads");
			KeyWords->push_back("overridable");
			KeyWords->push_back("overrides");
			KeyWords->push_back("paramarray");
			KeyWords->push_back("partial");
			KeyWords->push_back("private");
			KeyWords->push_back("property");
			KeyWords->push_back("protected");
			KeyWords->push_back("public");
			KeyWords->push_back("raiseevent");
			KeyWords->push_back("readonly");
			KeyWords->push_back("redim");
			KeyWords->push_back("rem");
			KeyWords->push_back("removehandler");
			KeyWords->push_back("resume");
			KeyWords->push_back("return");
			KeyWords->push_back("select");
			KeyWords->push_back("set");
			KeyWords->push_back("shadows");
			KeyWords->push_back("shared");
			KeyWords->push_back("static");
			KeyWords->push_back("step");
			KeyWords->push_back("stop");
			KeyWords->push_back("structure constraint");
			KeyWords->push_back("sub");
			KeyWords->push_back("synclock");
			KeyWords->push_back("then");
			KeyWords->push_back("throw");
			KeyWords->push_back("to");
			KeyWords->push_back("true");
			KeyWords->push_back("try");
			KeyWords->push_back("trycast");
			KeyWords->push_back("typeof");
			KeyWords->push_back("using");
			KeyWords->push_back("when");
			KeyWords->push_back("while");
			KeyWords->push_back("widening");
			KeyWords->push_back("with");
			KeyWords->push_back("withevents");
			KeyWords->push_back("writeonly");
			KeyWords->push_back("xor");

			// unreserved keywords

			KeyWords->push_back("aggregate");
			KeyWords->push_back("ansi");
			KeyWords->push_back("assembly");
			KeyWords->push_back("async");
			KeyWords->push_back("auto");
			KeyWords->push_back("await");
			KeyWords->push_back("binary");
			KeyWords->push_back("compare");
			KeyWords->push_back("custom");
			KeyWords->push_back("distinct");
			KeyWords->push_back("equals");
			KeyWords->push_back("explicit");
			KeyWords->push_back("from");
			KeyWords->push_back("group");
			KeyWords->push_back("by");
			KeyWords->push_back("join");
			KeyWords->push_back("into");
			KeyWords->push_back("isfalse");
			KeyWords->push_back("istrue");
			KeyWords->push_back("iterator");
			KeyWords->push_back("key");
			KeyWords->push_back("mid");
			KeyWords->push_back("off");
			KeyWords->push_back("order");
			KeyWords->push_back("preserve");
			KeyWords->push_back("skip");
			KeyWords->push_back("while");
			KeyWords->push_back("strict");
			KeyWords->push_back("take");
			KeyWords->push_back("text");
			KeyWords->push_back("unicode");
			KeyWords->push_back("until");
			KeyWords->push_back("where");
			KeyWords->push_back("yield");

			// Base Types
			BaseTypes->push_back("boolean");
			BaseTypes->push_back("byte");
			BaseTypes->push_back("char");
			BaseTypes->push_back("date");
			BaseTypes->push_back("decimal");
			BaseTypes->push_back("double");
			BaseTypes->push_back("integer");
			BaseTypes->push_back("long");
			BaseTypes->push_back("object");
			BaseTypes->push_back("sbyte");
			BaseTypes->push_back("short");
			BaseTypes->push_back("single");
			BaseTypes->push_back("string");
			BaseTypes->push_back("uinteger");
			BaseTypes->push_back("ulong");
			BaseTypes->push_back("ushort");
		}
	}
}