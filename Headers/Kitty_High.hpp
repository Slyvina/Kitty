// Lic:
// Kitty/Headers/Kitty_High.hpp
// Kitty High (header)
// version: 24.10.05
// Copyright (C) 2019, 2020, 2023 Jeroen P. Broks
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

#pragma once

#include <SlyvQCol.hpp>

namespace Slyvina {
    namespace Kitty {

#pragma region "Class to shared pointer.
        // Remember this is just manually translated C# code, and C# only uses pointers for classes and has automated garbage collection.
        // C++ has none of that.
#define KittyClass(real,pseudo) class real; typedef std::shared_ptr<real> pseudo;
        KittyClass(_KittyOutput, KittyOutput);
        KittyClass(_KittyHigh, KittyHigh);
        class _KittyPL;



        typedef void (*KittyOutputVoidString)(_KittyOutput*, std::string);
        typedef void (*KittyOutputShow)(_KittyHigh* SELF,std::string src, bool linenumbers);
#pragma region


        struct _KittyColors {
            Units::qColor
                KeyWord = Units::qColor::Yellow,
                Identifier = Units::qColor::White,
                Number = Units::qColor::Cyan,
                String = Units::qColor::Green,
                Comment = Units::qColor::DarkGrey,
                LineNumbers = Units::qColor::DarkGrey,
                Other = Units::qColor::Grey,
                Error = Units::qColor::Red,
                Attribute = Units::qColor::Blue,
                BaseType = Units::qColor::Magenta;
        };
        _KittyColors KittyColors;

        
        class _KittyOutput {
        public:
            ~_KittyOutput() {
                //Console.ResetColor();
                QCol->Reset();
            }
            /* Due to bad experiences with abstract methods (or virutals as they are called in C++), I'll do this a different way
            abstract public void Write(string a);
            abstract public void WriteLine(string a);
            */
            KittyOutputVoidString abstract_Write{ nullptr };
            KittyOutputVoidString abstract_WriteLine{ nullptr };
            inline void Write(std::string a) { if (!abstract_Write) throw std::runtime_error("abstract_Write not set!"); abstract_Write(this, a); }
            inline void WriteLine(std::string a) { if (!abstract_WriteLine) throw std::runtime_error("abstract_Write not set!"); abstract_WriteLine(this, a); }
            inline void WriteLine() { WriteLine(""); }
            inline void Write(char c) { char ca[2]{ c,0 }; Write(ca); } // Dirty, but what works that works!
            /* Due to lack of a proper cross platform way to do this in C++ , this will be kept on hold.
            public ConsoleKeyInfo ReadKey() = > Console.ReadKey();
            public ConsoleKeyInfo ReadKey(bool b) = > Console.ReadKey(b);
            */
            void ResetColor();
            // I don't expect to need this, and if I do, I might to go a different approach as this is too reliant on C#'s approach
            //public void Write(object a) = > Write($"{a}");
            // public void WriteLine(object a) = > WriteLine($"{a}");
            Units::qColor ForegroundColor{ Units::qColor::Grey };
            Units::qColor BackgroundColor{ Units::qColor::Black };
            int WindowHeight = 25;
        };

        //class KittyCLI :KittyOutput {
        KittyOutput KittyCLI();
        

        class _KittyHigh {
        private:
            static KittyOutput _ko;
            //String _Language{ "" };
            //inline void Language(String L) { _Language = L; }
        public:
            static std::map<String, KittyHigh> Langs; //static readonly public SortedDictionary<string, KittyHigh> Langs = new SortedDictionary<string, KittyHigh>();

            static int NumLines();
            static int PagLines;
            static bool BrkLines;
            static KittyOutput Console();
            static void Console(KittyOutput ko);


            static void PageBreak();

            inline static void WriteLine(String a = "") {
                Console()->WriteLine(a);
                PageBreak();
            }

            //public abstract void Show(string src, bool linenumbers = false);
            KittyOutputShow abstract_Show{ nullptr };
            void Show(String src, bool linenumbers = false);
            //public void Show(StringBuilder src, bool linenumbers = false) = > Show(src, linenumbers);
            String Language{ "" }; //inline String Language() { return _Language; }
            static void LineNumber(int ln);

            static void Init();
            _KittyPL* PLKid{ nullptr };
        };


        class _KittyPL { //: KittyHigh {
        public:
            KittyHigh Base{ std::shared_ptr<_KittyHigh>(new _KittyHigh()) };
            VecString KeyWords = NewVecString(); //protected List<string> KeyWords = new List<string>();
            VecString BaseTypes = NewVecString(); //List<string> BaseTypes = new List<string>();
            String stringstart = "\"";
            String stringend = "\"";
            String mlstringstart = "@\"";
            String mlstringend = "\"";
            String astringstart = "'";
            String astringend = "'";
            String singcomment = "//";
            String mulcommentstart = "/*";
            String mulcommentend = "*/";
            char escape = '\\';
            bool mulcomment = true;
            bool mulcommentfullline = false; // Needed for BlitzMax where commands taking up a full line are used for multi line comments. This is not entirely fool-proof, but it'll have to do.
            bool caseinsensitive = false;
            bool supcom = true;

            _KittyPL();

        };

        /* No longer needed as class, but a few things need to be set in order nonetheless
        class KittyNiks : KittyHigh {
            public KittyNiks() { Language = "Unrecognized"; }
            public override void Show(string src, bool linenumbers = false) {
                src = src.Replace("\r\n", "\n");
                var lines = src.Split('\n');
                for (int i = 0; i < lines.Length; i++) {
                    if (linenumbers) LineNumber(i + 1);
                    Console.ForegroundColor = KittyColors.Other; WriteLine(lines[i]);
                }
            }
        }
        */
        KittyHigh KittyNiks();

        // Markup support by freezernick
        class KittyMarkup : KittyHigh
        {
            protected string stringstart = "\"";
            protected string stringend = "\"";
            protected bool mulcomment = true;
            protected string mulcommentstart = "<!--";
            protected string mulcommentend = "-->";
            protected string opentagchar = "<";
            protected string closetagchar = ">";
            protected string endtagchar = "/>";
            protected char escape = '\\';

            
            public override void Show(string src, bool linenumbers = false) {
                bool intag = false;
                string word = "";
                void showword() {
                    var col = KittyColors.Other;
                    if (word.StartsWith(opentagchar) || word.EndsWith(endtagchar) || word.EndsWith(closetagchar))
                        col = KittyColors.KeyWord;
                    if (intag)
                        col = KittyColors.Attribute;
                    Console.ForegroundColor = col;
                    Console.Write(word);
                }
                src = src.Replace("\r\n", "\n");
                var lines = src.Split('\n');
                bool mulcomm = false;
                for (int i = 0; i < lines.Length; i++) {
                    if (linenumbers) LineNumber(i + 1);
                    word = "";
                    intag = false;
                    var singstring = false;
                    var stringescape = false;
                    bool wassingstring;

                    for (int p = 0; p < lines[i].Length; p++) {
                        var ch = lines[i][p];

                        wassingstring = singstring;
                        singstring = singstring || (p < lines[i].Length - 1 && lines[i].Substring(p, stringstart.Length) == stringstart);
                        mulcomm = mulcomm || (p < lines[i].Length - 3 && lines[i].Substring(p, mulcommentstart.Length) == mulcommentstart && !singstring && mulcomment);
                        if (singstring) {
                            Console.ForegroundColor = KittyColors.String;
                            Console.Write($"{ch}");
                            if (wassingstring && p < lines[i].Length && lines[i].Substring(p, stringend.Length) == stringend && !stringescape)
                                singstring = false;
                            else
                                stringescape = ch == escape && !stringescape;
                        } else if (mulcomm) {
                            Console.ForegroundColor = KittyColors.Comment;
                            Console.Write($"{ch}");
                            if (p < lines[i].Length - 2 && lines[i].Substring(p, mulcommentend.Length) == mulcommentend) {
                                Console.Write($"{lines[i][p + 1]}");
                                Console.Write($"{lines[i][p + 2]}");
                                p = p + 2;
                                mulcomm = false;
                            }
                        } else if (word == "" && ch == '<') {
                            word += $"{ch}";
                            int q = p;
                            bool inline = true;
                            while (inline) {
                                q++;
                                if (lines[i][q] == '=') {
                                    word += lines[i][q];
                                    p = q;
                                    showword();
                                    word = "";
                                    intag = true;
                                    inline = false;
                                } else if (lines[i][q] == '>') {
                                    word += lines[i][q];
                                    p = q;
                                    inline = false;
                                    intag = false;
                                    showword();
                                    word = "";
                                } else if (lines[i][q] == ' ') {
                                    word += lines[i][q];
                                    p = q;
                                    showword();
                                    word = "";
                                    inline = false;
                                    intag = true;
                                } else {
                                    word += lines[i][q];
                                }
                            }
                        } else if (word == "" && intag && ch != ' ' && ch != '>' && ch != '/') {
                            word += $"{ch}";
                            int q = p;
                            bool inline = true;
                            while (inline) {
                                q++;
                                if (lines[i][q] == '=') {
                                    word += lines[i][q];
                                    p = q;
                                    showword();
                                    word = "";
                                    inline = false;
                                } else if (lines[i][q] == '>') {
                                    word += lines[i][q];
                                    p = q;
                                    inline = false;
                                    intag = false;
                                } else {
                                    word += lines[i][q];
                                }
                            }
                        } else if (word == "" && intag && ch == '/' && lines[i][p + 1] == '>') {
                            p += 1;
                            word = "/>";
                            intag = false;
                            showword();
                            word = "";
                        } else {
                            if (ch == '>')
                                intag = false;
                            if (word != "") showword(); word = $"{ch}"; showword(); word = "";
                        }
                    }
                    if (word != "") showword();
                    WriteLine();
                }
            }
        }
    }
}