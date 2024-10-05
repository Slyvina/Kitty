// Lic:
// Kitty/Source/KittyHighSASKIA.cpp
// Kitty High SASKIA
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

		void KittyHighSASKIA() {
			static _KittyPL Me{};
			auto B{ Me.Base };
			auto KeyWords{ Me.KeyWords };
			Me.caseinsensitive = true;
			Me.singcomment = ";";
			Me.mulcomment = false;


			B->Langs["saskia"] = B;
			B->Language = "Serial Adventure Scripting Keeping Interface Advancements (SASKIA)";

			KeyWords->push_back("call");
			KeyWords->push_back("jmp");
			KeyWords->push_back("chk");
			KeyWords->push_back("mov");
			KeyWords->push_back("end");
			KeyWords->push_back("group");
			KeyWords->push_back("return");
			KeyWords->push_back("gosub");
		}
	}
}