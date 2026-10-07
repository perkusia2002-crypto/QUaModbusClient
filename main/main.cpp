#include "quamodbus.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUaModbus w;

    const QStringList args = QCoreApplication::arguments();
    if (args.size() > 1)
    {
        const QString configFile = args.at(1);
        if (!w.loadConfigFile(configFile))
        {
            qCritical() << "Failed to load configuration:" << configFile;
            return 1;
        }
    }

    w.show();
    return a.exec();
}
