// Lic:
// Kitty/Source/KittyHighCobra.cpp
// Kitty High Cobra
// version: 24.10.05
// Copyright (C) 2020, 2023, 2024 Jeroen P. Broks
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
		void KittyHighCobra() {
			// Since Cobra has been discontinued since 2013, as a matter of fact, the official website seems to link to the wikipedia page about it
			// in stead of a site where you can actually download the language itself, I guess it's only logical, the cobra module won't see much
			// update either. It's for the time being not deprecated, since it's not in the way or anything, but no promises for the future.
			static _KittyPL Me{};
			auto KeyWords{ Me.KeyWords };
			Me.Base->Language = "Cobra";
			Me.Base->Langs["cobra"] = Me.Base;
			Me.singcomment = "#";
			KeyWords->push_back("abstract");
			KeyWords->push_back("adds");
			KeyWords->push_back("all");
			KeyWords->push_back("and");
			KeyWords->push_back("any");
			KeyWords->push_back("as");
			KeyWords->push_back("assert");
			KeyWords->push_back("base");
			KeyWords->push_back("be");
			KeyWords->push_back("body");
			KeyWords->push_back("bool");
			KeyWords->push_back("branch");
			KeyWords->push_back("break");
			KeyWords->push_back("callable");
			KeyWords->push_back("catch");
			KeyWords->push_back("char");
			KeyWords->push_back("class");
			KeyWords->push_back("const");
			KeyWords->push_back("continue");
			KeyWords->push_back("cue");
			KeyWords->push_back("decimal");
			KeyWords->push_back("def");
			KeyWords->push_back("do");
			KeyWords->push_back("dynamic");
			KeyWords->push_back("each");
			KeyWords->push_back("else");
			KeyWords->push_back("end");
			KeyWords->push_back("ensure");
			KeyWords->push_back("enum");
			KeyWords->push_back("event");
			KeyWords->push_back("every");
			KeyWords->push_back("except");
			KeyWords->push_back("expect");
			KeyWords->push_back("extend");
			KeyWords->push_back("extern");
			KeyWords->push_back("fake");
			KeyWords->push_back("false");
			KeyWords->push_back("finally");
			KeyWords->push_back("float");
			KeyWords->push_back("for");
			KeyWords->push_back("from");
			KeyWords->push_back("get");
			KeyWords->push_back("has");
			KeyWords->push_back("if");
			KeyWords->push_back("ignore");
			KeyWords->push_back("implements");
			KeyWords->push_back("implies");
			KeyWords->push_back("import");
			KeyWords->push_back("in");
			KeyWords->push_back("inherits");
			KeyWords->push_back("inlined");
			KeyWords->push_back("inout");
			KeyWords->push_back("int");
			KeyWords->push_back("interface");
			KeyWords->push_back("internal");
			KeyWords->push_back("invariant");
			KeyWords->push_back("is");
			KeyWords->push_back("listen");
			KeyWords->push_back("lock");
			KeyWords->push_back("mixin");
			KeyWords->push_back("must");
			KeyWords->push_back("namespace");
			KeyWords->push_back("new");
			KeyWords->push_back("nil");
			KeyWords->push_back("nonvirtual");
			KeyWords->push_back("not");
			KeyWords->push_back("number");
			KeyWords->push_back("objc");
			KeyWords->push_back("of");
			KeyWords->push_back("off");
			KeyWords->push_back("old");
			KeyWords->push_back("on");
			KeyWords->push_back("or");
			KeyWords->push_back("out");
			KeyWords->push_back("override");
			KeyWords->push_back("par");
			KeyWords->push_back("partial");
			KeyWords->push_back("pass");
			KeyWords->push_back("passthrough");
			KeyWords->push_back("post");
			KeyWords->push_back("print");
			KeyWords->push_back("private");
			KeyWords->push_back("pro");
			KeyWords->push_back("protected");
			KeyWords->push_back("public");
			KeyWords->push_back("raise");
			KeyWords->push_back("ref");
			KeyWords->push_back("require");
			KeyWords->push_back("return");
			KeyWords->push_back("same");
			KeyWords->push_back("set");
			KeyWords->push_back("shared");
			KeyWords->push_back("sig");
			KeyWords->push_back("stop");
			KeyWords->push_back("struct");
			KeyWords->push_back("success");
			KeyWords->push_back("test");
			KeyWords->push_back("this");
			KeyWords->push_back("throw");
			KeyWords->push_back("to");
			KeyWords->push_back("to?");
			KeyWords->push_back("trace");
			KeyWords->push_back("true");
			KeyWords->push_back("try");
			KeyWords->push_back("uint");
			KeyWords->push_back("use");
			KeyWords->push_back("using");
			KeyWords->push_back("var");
			KeyWords->push_back("vari");
			KeyWords->push_back("virtual");
			KeyWords->push_back("where");
			KeyWords->push_back("while");
			KeyWords->push_back("yield");
		}
	}
}