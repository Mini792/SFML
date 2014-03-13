#include <fstream> //Include this, because SFML doesn't natively, for some reason.

class ReadFileSeparator{ //File parser class
	public:
		std::ifstream file; //Create the stream for the file loading
		FileParser(std::string filename){ //Initialisation of the parser, argument0: path to file (can be relative to program)
			file.open(filename.c_str()); //Open the file specified for this parser
		}
		sf::String ReadFile(char Separator){ //When the person wants to read the parser
			sf::String tmp_Characters(""); //Initialise the temporary sf::String variable to return
			int tmp_CharInt; //Initialise the temporary character 8-bit value (0-255), using int
			bool tmp_LoadChar(true); //Initialise the while loop strop indicator
			char tmp_Character; //Initialise the temporary character variable holder
			
			while((tmp_LoadChar)&&(!file.eof())){ //While the loop is meant to run, and the file it not at the end of the loop,
				tmp_CharInt = file.get(); //Read the current value, and assign it to the int variable
				tmp_Character  = tmp_CharInt; //Transfer the int value, to the char value
				if(tmp_Character == Separator){ //If the character is what is defined as the seperator,
					tmp_CharInt = false; //Tell the loop "No more!"
					break; //Break the loop
				}else{ //Else,
					tmp_Characters += tmp_Character; //Add the temporary character to the temporary sf::String
				}
			}
			return tmp_Characters; //Return the sequence of characters from the sf:String
		}
};
 
