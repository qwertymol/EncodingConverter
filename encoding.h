#ifndef ENCODING_H
#define ENCODING_H

//from cp866 to 1251 encoding

class Encoding
{
public:
    static Encoding *getInst () { return instance; }
    char convertChar(char c, bool from866);

private:
    struct SymbolsPair { unsigned char from, to; };

    Encoding ();
    static Encoding *instance;
    static SymbolsPair symbolsPair[];
};

#endif // ENCODING_H
