#ifndef ENCODER_H
#define ENCODER_H

class Encoder
{
public:
    static Encoder *getInstance () { return instance; }
    void encode (const char *file, bool from866 = false, const char *outFile = 0);

private:
    static Encoder *instance;

    Encoder ();
};

#endif // ENCODER_H
