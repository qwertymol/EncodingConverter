#include "encoder.h"
#include "encoding.h"

#include <QString>
#include <QFile>

Encoder *Encoder::instance = new Encoder();

void Encoder::encode (const char *file, bool from866, const char *outFile)
{
    QByteArray s (file);
    if (outFile == 0 && from866) {
        s.append(".cp1251");
        outFile = s.data ();
    } else if (outFile == 0 && !from866) {
        s.append(".cp866");
        outFile = s.data ();
    }

    QFile f(file);
    QFile fOut(outFile);

    f.open(QFile::ReadOnly);
    fOut.open(QFile::WriteOnly);

    QByteArray buf = f.readAll ();
    QByteArray bufOut;

    for(int i = 0; i < buf.length(); i++) {
        char c = buf[i];
        bufOut.append (e->convertChar (c, false));
    }

    fOut.write(bufOut);

    f.close();
    fOut.close();
}


Encoder::Encoder ()
{
    e = Encoding::getInst();
}
