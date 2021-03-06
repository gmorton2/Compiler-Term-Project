#include "headers/LexicalAnalyzer.h"
#include "headers/SyntacticAnalyzer.h"

/**
 * Controls the flow of the current state of this project. Currently, only the lexical analyzer is complete so an input
 * file will be read into the lexer, which will output the organized data to an output file.
 * @return
 */
int main() {

    ifstream fileIn;
    fileIn.open("fileName.txt", ifstream::in);

    //If source file does not exist, exit the compiler.
    if(!fileIn.is_open()){

        cout << "File does not exist or cannot be opened.\n";
        fileIn.close();
        return 0;

    }

    LexicalAnalyzer lexer;
    lexer.run(fileIn);
    /*vector<pair<string, string>>* lexerOutput = lexer.getLexerOutput();
    for (int i = 0; i < lexerOutput->size(); i++)
        cout << lexerOutput->at(i).first << " " << lexerOutput->at(i).second << endl;*/
    //True to print the production rules, false to just analyze.
    SyntacticAnalyzer syntacticAnalyzer(true, lexer.getLexerOutput());
    if(syntacticAnalyzer.run()){

        //analyzer passed, yay

    } else{
        //analyzer failed somewhere
    }

    return 0;

}
