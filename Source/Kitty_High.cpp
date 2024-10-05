// Lic:
// Kitty/Source/Kitty_High.cpp
// Kitty High
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
#include <SlyvSilly.hpp>
#include <SlyvString.hpp>

using namespace Slyvina::Units;



namespace Slyvina {
	namespace Kitty {

		void _KittyOutput::ResetColor() {
			ForegroundColor = qColor::Grey;
			BackgroundColor = qColor::Black;
		}

#pragma region KittyCLI
		static void KittyCLI_Write(_KittyOutput* SELF, String a) {
			QCol->Color(
				SELF->ForegroundColor,
				SELF->BackgroundColor);
			printf("%s", a.c_str());
		}
		static void KittyCLI_WriteLine(_KittyOutput* SELF, String a) { KittyCLI_Write(SELF, a + "\n"); }
		KittyOutput KittyCLI() {
			//WindowHeight = Console.WindowHeight;
			auto ret{ new _KittyOutput() };
			ret->WindowHeight = 25; // I don't think there's a cross-platform way to do the auto check anyway, but who knows!
			ret->abstract_Write = KittyCLI_Write;
			ret->abstract_WriteLine = KittyCLI_WriteLine;
			return std::shared_ptr<_KittyOutput>(ret);
		}
#pragma endregion

#pragma region KittyHigh
		std::map<String, KittyHigh> _KittyHigh::Langs{};
		KittyOutput _KittyHigh::_ko{ nullptr };
		int _KittyHigh::NumLines() { return Console()->WindowHeight; }
		KittyOutput _KittyHigh::Console() {
			if (_ko == nullptr) _ko = KittyCLI();
			return _ko;
		}

		void _KittyHigh::Console(KittyOutput value) {
			//System.Diagnostics.Debug.WriteLine("New Console For KittyHigh set");
			_ko = value;
		}

		void _KittyHigh::PageBreak() {
			if (!BrkLines) return;
			PagLines++;
			if (PagLines >= NumLines() - 2) {
				/* Due to C++ not having a good cross-platform equivalent to C#'s Console.ReadKey, I will (for now) dummy this code.
				Console.Write(" ");
				Console.ForegroundColor = ConsoleColor.Blue;
				Console.BackgroundColor = ConsoleColor.Cyan;
				Console.Write(" More ");
				Console.ResetColor();
				Console.Write("\b\b\b\b\b\b\b");
				ConsoleKeyInfo k;
				bool loopme = true;
				do {
					loopme = false;
					k = Console.ReadKey(true);
					Console.Write("       ");
					Console.Write("\b\b\b\b\b\b\b");
					switch (k.Key) {
					case ConsoleKey.Enter:
						PagLines = 0;
						break;
					case ConsoleKey.Spacebar:
						PagLines--;
						break;
					case ConsoleKey.Escape:
						BrkLines = false;
						break;
					default:
						loopme = true;
						break;
					}
				} while (loopme);
				*/
				pause(); // This will have to do the trick (for now)
			}
		}

		void _KittyHigh::Show(String src, bool linenumbers) {
			if (!abstract_Show) {
				throw std::runtime_error("Now show function set for highlighting language \"" + Language + "\"");
				return;
			}
			abstract_Show(this, src, linenumbers);
		}

		void _KittyHigh::LineNumber(int ln) {
			Console()->ForegroundColor = KittyColors.LineNumbers;
			//Console.Write($"{ln.ToString("D9")} | ");
			Console()->Write(TrSPrintF("%9d |", ln));
		}

		void _KittyHigh::Init() { Langs["OTHER"] = KittyNiks(); }

		int _KittyHigh::PagLines{ 0 };
		bool _KittyHigh::BrkLines{ false };
#pragma endregion

#pragma region "PL (Programming Language)"

		// Disgusting, but it helps with this C# -> C++ problem.
#define pl_showword() __showword(SELF->PLKid,word,mle)
		static void __showword(_KittyPL* PL, String& word, int& mle) {
			//static String word{ "" };
			//static int mle{ 0 };
			//if (resetshowword) { word = ""; mle = 0; return; }
			auto col = KittyColors.Other;
			auto KeyWords{ PL->KeyWords };
			auto BaseTypes{ PL->BaseTypes };
			auto caseinsensitive{ PL->caseinsensitive };
			auto Console{ PL->Base->Console() };
			if (VecHasString(KeyWords, word) || (caseinsensitive && VecHasString(KeyWords, Lower(word))))
				col = KittyColors.KeyWord;
			else if (VecHasString(BaseTypes, word) || (caseinsensitive && VecHasString(BaseTypes, Lower(word))))
				col = KittyColors.BaseType;
			else {
				// Not the most elegant method, but what works, that works!

				//switch (word.Substring(0, 1).ToUpper()) { 
				auto uword{ Upper(word) };
				switch (uword[0]) {
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
				case 'K':
				case 'L':
				case 'M':
				case 'N':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
				case 'S':
				case 'T':
				case 'U':
				case 'V':
				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
				case '_':
					col = KittyColors.Identifier;
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					col = KittyColors.Number;
					break;
				}
			}
			Console->ForegroundColor = col;
			Console->Write(word);
		}
		static void _PLShow(_KittyHigh* SELF, String src, bool linenumbers = false) {
			//showword(SELF->PLKid,true); // Reset
			String word{ "" };
			int mle{ 0 };
			src = StReplace(src, "\r\n", "\n");
			auto lines{ Split(src,'\n') }; //= src.Split('\n');
			auto mulcomm = false;
			auto Console{ SELF->Console() };
			// Not supporting abstracts has its downsizes, but we'll manage!
			auto& singcomment{ SELF->PLKid->singcomment };
			auto& mulcommentstart{ SELF->PLKid->mulcommentstart };
			auto& mulcomment{ SELF->PLKid->mulcomment };
			auto& stringstart{ SELF->PLKid->stringstart };
			auto& stringend{ SELF->PLKid->stringend };
			auto& escape{ SELF->PLKid->escape };
			auto& mulcommentend{ SELF->PLKid->mulcommentend };
			auto& supcom{ SELF->PLKid->supcom };
			for (int i = 0; i < lines->size(); i++) {
				if (linenumbers) SELF->LineNumber(i + 1);
				word = "";
				auto singcomm = false;
				auto singstring = false;
				auto stringescape = false;
				auto wassingstring = false;
				for (int p = 0; p < (*lines)[i].size(); p++) {
					auto ch = (*lines)[i][p];
					// Console.WriteLine($"DEBUG! {(*lines)[i].Substring(p, singcomment.Length)} {singcomment}");
					wassingstring = singstring;
					singcomm = singcomm || (p < (*lines)[i].size() - 1 && (*lines)[i].substr(p, singcomment.size()) == singcomment && (!singstring) && (!mulcomm) && supcom);
					try {
						mulcomm = mulcomm || (p < (*lines)[i].size() - 1 && (*lines)[i].substr(p, std::min((*lines)[i].size() - p, mulcommentstart.size())) == mulcommentstart && (!singstring) & (!singcomm) && mulcomment);
					} catch (std::runtime_error e) {
#ifndef NDEBUG
						//System.Diagnostics.Debug.WriteLine($"Error: {e.Message} (parsing line {i+1}/{lines.size()}; pos {p})");
						QCol->Error(String(e.what()) + TrSPrintF(" (parsing line %d/%d; pos %s", i + 1, lines->size(), p));
#endif
						//System.Console.Beep(); mle++;
						//mulcomm = false;
						Beep();
					}
					singstring = singstring || (p < (*lines)[i].size() - 1 && (*lines)[i].substr(p, stringstart.size()) == stringstart && (!singcomm) && (!mulcomm));
					if (singstring) {
						Console->ForegroundColor = KittyColors.String;
						Console->Write(TrSPrintF("%c", ch));
						if (wassingstring && p < (*lines)[i].size() && (*lines)[i].substr(p, stringend.size()) == stringend && !stringescape)
							singstring = false;
						else
							stringescape = ch == escape && !stringescape;
					} else if (mulcomm) {
						Console->ForegroundColor = KittyColors.Comment;
						Console->Write(ch);
						if (p < (*lines)[i].size() - (mulcommentend.size() - 1) && (*lines)[i].substr(p, mulcommentend.size()) == mulcommentend)
							mulcomm = false;
					} else if (singcomm) {
						Console->ForegroundColor = KittyColors.Comment;
						Console->Write(ch);
					} else {
						if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || (ch >= '0' && ch <= '9')) {
							//word += $"{ch}";							
							word += ch;
						} else {
							char chnw[2]{ ch,0 };
							if (word != "") pl_showword(); word = chnw; pl_showword(); word = "";
						}
					}
				}
				if (word != "") pl_showword();
				SELF->WriteLine();
			}
#ifndef NDEBUG
			if (mle > 0)
				printf("Number of errors on multi-line-comments: %d", mle);
			//System.Diagnostics.Debug.WriteLine($"Number of errors on multi-line-comments: {mle}");
#endif
		}


		_KittyPL::_KittyPL() {
			Base->PLKid = this;
			Base->abstract_Show = _PLShow;
		}

#pragma endregion

#pragma region KittyNiks

		static void _Niks_Show(_KittyHigh* SELF, String src, bool linenumbers = false) {
			src = StReplace(src, "\r\n", "\n");
			auto lines{ Split(src,'\n') };
			for (int i = 0; i < lines->size(); i++) {
				if (linenumbers) SELF->LineNumber(i + 1);
				SELF->Console()->ForegroundColor = KittyColors.Other; SELF->Console()->WriteLine((*lines)[i]);
			}
		}
		KittyHigh KittyNiks() {
			// Fun fact: "Niks" means "Nothing" in Dutch.
			//public KittyNiks() { Language = "Unrecognized"; }
			auto KN = new _KittyHigh();
			KN->Language = "Unrecognized";
			KN->abstract_Show = _Niks_Show;
			return std::shared_ptr<_KittyHigh>(KN);
		}

#pragma endregion


#pragma region "Markup"
#define mu_showword() __showword(SELF->MLKid,word,intag)

		static void __showword(_KittyMarkup* ML, std::string& word, bool& intag) {
			auto col = KittyColors.Other;
			auto& opentagchar{ ML->opentagchar };
			auto& closetagchar{ ML->closetagchar };
			auto& endtagchar{ ML->endtagchar };
			auto Console{ ML->Base->Console() };			
			// if (word.StartsWith(opentagchar) || word.EndsWith(endtagchar) || word.EndsWith(closetagchar)) // C# syntax ain't gonna work here.
			if (Prefixed(word,opentagchar) || Suffixed(word,endtagchar) || Suffixed(word,closetagchar) )
				col = KittyColors.KeyWord;
			if (intag)
				col = KittyColors.Attribute;
			Console->ForegroundColor = col;
			Console->Write(word);
			}

			static void __ML__Show(_KittyHigh* SELF, String src, bool linenumbers = false) {
				auto ME{ SELF->MLKid };
			bool intag = false;
			String word = "";
			src = StReplace(src,"\r\n", "\n");
			auto plines = Split(src,'\n');
			auto lines{ *plines };
			bool mulcomm = false;
			auto Console{ SELF->Console() };
			auto& stringstart{ ME->stringstart };
			auto& mulcommentstart{ ME->mulcommentstart };
			auto& mulcomment{ ME->mulcomment };
			auto& mulcommentend{ ME->mulcommentend };
			auto& escape{ ME->escape };
			auto& stringend{ ME->stringend };
			for (int i = 0; i < lines.size(); i++) {
				if (linenumbers) SELF->LineNumber(i + 1);
				word = "";
				intag = false;
				auto singstring = false;
				auto stringescape = false;
				bool wassingstring;
				for (int p = 0; p < lines[i].size(); p++) {
					auto ch = lines[i][p];
					wassingstring = singstring;
					singstring = singstring || (p < lines[i].size() - 1 && lines[i].substr(p, stringstart.size()) == stringstart);
					mulcomm = mulcomm || (p < lines[i].size() - 3 && lines[i].substr(p, mulcommentstart.size()) == mulcommentstart && !singstring && mulcomment);
					if (singstring) {
						Console->ForegroundColor = KittyColors.String;
						Console->Write(ch);
						if (wassingstring && p < lines[i].size() && lines[i].substr(p, stringend.size()) == stringend && !stringescape)
							singstring = false;
						else
							stringescape = ch == escape && !stringescape;
					} else if (mulcomm) {
						Console->ForegroundColor = KittyColors.Comment;
						Console->Write(ch);
						if (p < lines[i].size() - 2 && lines[i].substr(p, mulcommentend.size()) == mulcommentend) {
							Console->Write(lines[i][p + 1]);
							Console->Write(lines[i][p + 2]);
							p = p + 2;
							mulcomm = false;
						}
					} else if (word == "" && ch == '<') {
						word += ch; // $"{ch}";
						int q = p;
						bool in_line = true; // had to chance inline to in_line. inline is a keyword in C++ (apparently not in C#)
						while (in_line) {
							q++;
							if (lines[i][q] == '=') {
								word += lines[i][q];
								p = q;
								mu_showword();
								word = "";
								intag = true;
								in_line = false;
							} else if (lines[i][q] == '>') {
								word += lines[i][q];
								p = q;
								in_line = false;
								intag = false;
								mu_showword();
								word = "";
							} else if (lines[i][q] == ' ') {
								word += lines[i][q];
								p = q;
								mu_showword();
								word = "";
								in_line = false;
								intag = true;
							} else {
								word += lines[i][q];
							}
						}
					} else if (word == "" && intag && ch != ' ' && ch != '>' && ch != '/') {
						word += ch; // $"{ch}";
						int q = p;
						bool in_line = true;
						while (in_line) {
							q++;
							if (lines[i][q] == '=') {
								word += lines[i][q];
								p = q;
								mu_showword();
								word = "";
								in_line = false;
							} else if (lines[i][q] == '>') {
								word += lines[i][q];
								p = q;
								in_line = false;
								intag = false;
							} else {
								word += lines[i][q];
							}
						}
					} else if (word == "" && intag && ch == '/' && lines[i][p + 1] == '>') {
						p += 1;
						word = "/>";
						intag = false;
						mu_showword();
						word = "";
					} else {
						if (ch == '>')
							intag = false;
						// Is this line correct? V
						if (word != "") mu_showword(); word = TrSPrintF("%c",ch); mu_showword(); word = "";
					}
				}
				if (word != "") mu_showword();
				SELF->WriteLine();
			}
		}

#pragma endregion
	}
}