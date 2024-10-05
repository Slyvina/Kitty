// Lic:
// Kitty/Source/KittyHighHTML.cpp
// Kitty High HyperText MarkUp Language
// version: 24.10.05
// Copyright (C) 2020, 2023, 2024 Freezernick
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
		void KittyHighHTML() {
			static _KittyMarkup Me{};			
			auto B{ Me.Base };
			B->Langs["html"] = B;
			B->Langs["htm"] = B;
			B->Language = "HyperText Markup Language";
			Me.stringstart = "\"";
			Me.stringend = "\"";
		}
	}
}