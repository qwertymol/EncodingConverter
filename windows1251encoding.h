#ifndef WINDOWS1251ENCODING_H
#define WINDOWS1251ENCODING_H

//TODO: how organize encoding table

class Windows1251Encoding
{
public:
    static Windows1251Encoding *getInst();


private:


    Windows1251Encoding ();
    static Windows1251Encoding *instance;

};

#endif // WINDOWS1251ENCODING_H
